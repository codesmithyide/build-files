// SPDX-FileCopyrightText: 2017-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CodeSmithy/CodeSmithyBuildFileXMLRepository.hpp"
#include <fstream>

using namespace CodeSmithy;

namespace
{
    const char* k_root_element_name = "codesmithy-build-file";
    const char* k_version_element_name = "file-format-version";
    const char* k_build_file_name_element_name = "name";
    const char* k_projects_element_name = "projects";
    const char* k_project_element_name = "project";
    const char* k_project_name_element_name = "name";
    const char* k_targets_element_name = "targets";
    const char* k_target_element_name = "target";
    const char* k_target_name_element_name = "name";
    const char* k_inputs_element_name = "inputs";
}

void CodeSmithyBuildFileXMLRepository::create(const boost::filesystem::path& path, Ishiko::Error& error)
{
    m_db.create(path, error);

    // TODO : everything is committed immediately but I may be better off using a transaction
    // TODO : handle errors
    DiplodocusDB::XMLTreeDBNode root_node = m_db.appendChildNode(m_db.root(), k_root_element_name, error);
    if (root_node)
    {
        m_db.appendChildNode(root_node, k_version_element_name, DiplodocusDB::Value::UTF8String("0.1.0"), error);
        m_name_node = m_db.appendChildNode(root_node, k_build_file_name_element_name,
            DiplodocusDB::Value::UTF8String(""), error);
        m_projects_node = m_db.appendChildNode(root_node, k_projects_element_name, error);
    }
}

void CodeSmithyBuildFileXMLRepository::open(const boost::filesystem::path& path, Ishiko::Error& error)
{
    m_db.open(path, error);
    DiplodocusDB::XMLTreeDBNode projectRoot = m_db.child(m_db.root(), k_root_element_name, error);
    m_name_node = m_db.child(projectRoot, k_build_file_name_element_name, error);
    m_projects_node = m_db.child(projectRoot, k_projects_element_name, error);
}

void CodeSmithyBuildFileXMLRepository::close()
{
    m_db.close();
}

std::string CodeSmithyBuildFileXMLRepository::name() const
{
    std::string result;
    if (m_name_node)
    {
        // TODO: need to cache the name to avoid error
        Ishiko::Error error;
        result = m_db.value(m_name_node, error).asUTF8String();
    }
    return result;
}

void CodeSmithyBuildFileXMLRepository::setName(const std::string& name)
{
    // TODO : should setName commit immediately?
    Ishiko::Error error;
    m_db.setValue(m_name_node, DiplodocusDB::Value::UTF8String(name), error);
}

DiplodocusDB::XMLTreeDB& CodeSmithyBuildFileXMLRepository::db()
{
    return m_db;
}

std::unique_ptr<CodeSmithyBuildFile> CodeSmithyBuildFileXMLRepository::getBuildFile(Ishiko::Error& error)
{
    DiplodocusDB::XMLTreeDBNode build_file_node = m_db.child(m_db.root(), k_root_element_name, error);
    return std::unique_ptr<BuildFileAdapter>(new BuildFileAdapter(m_db, build_file_node));
}

DiplodocusDB::XMLTreeDBNode CodeSmithyBuildFileXMLRepository::getBuildFileRawNode(Ishiko::Error& error)
{
    return m_db.child(m_db.root(), k_root_element_name, error);
}

CodeSmithyBuildFileXMLRepository::BuildFileAdapter::BuildFileAdapter(DiplodocusDB::XMLTreeDB& db,
    DiplodocusDB::XMLTreeDBNode build_file_node) noexcept
    : m_db(db), m_build_file_node(build_file_node)
{
}

void CodeSmithyBuildFileXMLRepository::BuildFileAdapter::addProject(const std::string& name)
{
    // TODO: handle errors
    Ishiko::Error error;
    DiplodocusDB::XMLTreeDBNode projects_node = m_db.child(m_build_file_node, k_projects_element_name, error);
    if (!projects_node)
    {
        projects_node = m_db.appendChildNode(m_build_file_node, k_projects_element_name, error);
    }
    DiplodocusDB::XMLTreeDBNode project_node = m_db.appendChildNode(projects_node, k_project_element_name, error);
    m_db.appendChildNode(project_node, k_project_name_element_name, DiplodocusDB::Value::UTF8String(name), error);
}

void CodeSmithyBuildFileXMLRepository::BuildFileAdapter::addTarget(const std::string& project_name,
    const std::string& target_name)
{
    // TODO: handle errors
    Ishiko::Error error;
    DiplodocusDB::XMLTreeDBNode projects_node = m_db.child(m_build_file_node, k_projects_element_name, error);
    DiplodocusDB::XMLTreeDBNode project_node = m_db.child(projects_node, k_project_element_name, error);
    DiplodocusDB::XMLTreeDBNode targets_node = m_db.appendChildNode(project_node, k_targets_element_name, error);
    DiplodocusDB::XMLTreeDBNode target_node = m_db.appendChildNode(targets_node, k_target_element_name, error);
    m_db.appendChildNode(target_node, k_target_name_element_name, DiplodocusDB::Value::UTF8String(target_name), error);
}

void CodeSmithyBuildFileXMLRepository::BuildFileAdapter::addSourceFile(const std::string& project_name,
    const std::string& file_path)
{
    // TODO: handle errors
    Ishiko::Error error;

    DiplodocusDB::XMLTreeDBNode projects_node = m_db.child(m_build_file_node, k_projects_element_name, error);
    DiplodocusDB::XMLTreeDBNode project_node = m_db.child(projects_node, k_project_element_name, error);
    DiplodocusDB::XMLTreeDBNode targets_node = m_db.child(project_node, k_targets_element_name, error);
    DiplodocusDB::XMLTreeDBNode target_node = m_db.child(targets_node, k_target_element_name, error);

    DiplodocusDB::XMLTreeDBNode inputs_node = m_db.child(target_node, k_inputs_element_name, error);
    if (!inputs_node)
    {
        inputs_node = m_db.appendChildNode(target_node, k_inputs_element_name, error);
    }
    m_db.appendChildNode(inputs_node, "file", DiplodocusDB::Value::UTF8String(file_path), error);
}
