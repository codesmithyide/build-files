// SPDX-FileCopyrightText: 2017-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CodeSmithy/CodeSmithyBuildFileXMLRepository.hpp"
#include <fstream>

using namespace CodeSmithy;

namespace
{
    const char* k_root_element_name = "codesmithy-build-file-repository";
    const char* k_version_element_name = "file-format-version";
    const char* k_repository_name_element_name = "name";
    const char* k_build_files_element_name = "build-files";
    const char* k_build_file_element_name = "build-file";
    const char* k_build_file_name_element_name = "name";
    const char* k_projects_element_name = "projects";
    const char* k_project_element_name = "project";
    const char* k_project_name_element_name = "name";

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
        m_nameNode = m_db.appendChildNode(root_node, k_repository_name_element_name,
            DiplodocusDB::Value::UTF8String(""), error);
        m_projectsNode = m_db.appendChildNode(root_node, k_build_files_element_name, error);
    }
}

void CodeSmithyBuildFileXMLRepository::open(const boost::filesystem::path& path, Ishiko::Error& error)
{
    m_db.open(path, error);
    DiplodocusDB::XMLTreeDBNode projectRoot = m_db.child(m_db.root(), k_root_element_name, error);
    m_nameNode = m_db.child(projectRoot, k_repository_name_element_name, error);
    m_projectsNode = m_db.child(projectRoot, k_build_files_element_name, error);
}

void CodeSmithyBuildFileXMLRepository::close()
{
    m_db.close();
}

std::string CodeSmithyBuildFileXMLRepository::name() const
{
    std::string result;
    if (m_nameNode)
    {
        // TODO: need to cache the name to avoid error
        Ishiko::Error error;
        result = m_db.value(m_nameNode, error).asUTF8String();
    }
    return result;
}

void CodeSmithyBuildFileXMLRepository::setName(const std::string& name)
{
    // TODO : should setName commit immediately?
    Ishiko::Error error;
    m_db.setValue(m_nameNode, DiplodocusDB::Value::UTF8String(name), error);
}

DiplodocusDB::XMLTreeDB& CodeSmithyBuildFileXMLRepository::db()
{
    return m_db;
}

std::unique_ptr<CodeSmithyBuildFile> CodeSmithyBuildFileXMLRepository::getBuildFileNode(const std::string& name,
    Ishiko::Error& error)
{
    DiplodocusDB::XMLTreeDBNode result;
    for (DiplodocusDB::XMLTreeDBNode projectNode = m_db.child(m_projectsNode, k_build_file_element_name, error);
         projectNode; 
         projectNode = m_db.nextSibling(projectNode, k_build_file_element_name, error))
    {
        DiplodocusDB::Value nameNodeValue = m_db.childValue(projectNode, k_build_file_name_element_name,
            DiplodocusDB::DataType(DiplodocusDB::PrimitiveDataType::unicodeString), error);
        if (error)
        {
            break;
        }
        if (nameNodeValue.asUTF8String() == name)
        {
            result = projectNode;
            break;
        }
    }
    return std::unique_ptr<BuildFileAdapter>(new BuildFileAdapter(m_db, result));
}

DiplodocusDB::XMLTreeDBNode CodeSmithyBuildFileXMLRepository::addBuildFileNode(const std::string& name,
    Ishiko::Error& error)
{
    if (m_projectsNode)
    {
        DiplodocusDB::XMLTreeDBNode projectNode = m_db.appendChildNode(m_projectsNode, k_build_file_element_name, error);
        DiplodocusDB::XMLTreeDBNode nameNode = m_db.appendChildNode(projectNode, k_build_file_name_element_name,
            DiplodocusDB::Value::UTF8String(name), error);
        return DiplodocusDB::XMLTreeDBNode(projectNode);
    }
    else
    {
        return DiplodocusDB::XMLTreeDBNode();
    }
}

DiplodocusDB::XMLTreeDBNode CodeSmithyBuildFileXMLRepository::getBuildFileRawNode(const std::string& name,
    Ishiko::Error& error)
{
    DiplodocusDB::XMLTreeDBNode result;
    for (DiplodocusDB::XMLTreeDBNode projectNode = m_db.child(m_projectsNode, k_build_file_element_name, error);
        projectNode;
        projectNode = m_db.nextSibling(projectNode, k_build_file_element_name, error))
    {
        DiplodocusDB::Value nameNodeValue = m_db.childValue(projectNode, k_build_file_name_element_name,
            DiplodocusDB::DataType(DiplodocusDB::PrimitiveDataType::unicodeString), error);
        if (error)
        {
            break;
        }
        if (nameNodeValue.asUTF8String() == name)
        {
            result = projectNode;
            break;
        }
    }
    return result;
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

void CodeSmithyBuildFileXMLRepository::BuildFileAdapter::addSourceFile(const std::string& project_name,
    const std::string& file_path)
{
    // TODO: handle errors
    Ishiko::Error error;
    DiplodocusDB::XMLTreeDBNode source_files_node = m_db.child(m_build_file_node, "source-files", error);
    if (!source_files_node)
    {
        source_files_node = m_db.appendChildNode(m_build_file_node, "source-files", error);
    }
    m_db.appendChildNode(source_files_node, "file", DiplodocusDB::Value::UTF8String(file_path), error);
}
