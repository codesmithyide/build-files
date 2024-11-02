// SPDX-FileCopyrightText: 2017-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CodeSmithy/CodeSmithyProjectFileXMLRepository.hpp"
#include <fstream>

namespace CodeSmithy
{

static const char* rootElementName = "codesmithy-project-repository";
static const char* versionElementName = "file-format-version";
static const char* repositoryNameElementName = "name";
static const char* repositoryProjectsElementName = "projects";
static const char* projectElementName = "codesmithy-project";
static const char* projectNameElementName = "name";

void ProjectRepository::create(const boost::filesystem::path& path, Ishiko::Error& error)
{
    m_db.create(path, error);

    // TODO : everything is committed immediately but I may be better off using a transaction
    // TODO : handle errors
    DiplodocusDB::XMLTreeDBNode rootNode = m_db.appendChildNode(m_db.root(), rootElementName, error);
    if (rootNode)
    {
        m_db.appendChildNode(rootNode, versionElementName, DiplodocusDB::Value::UTF8String("0.1.0"), error);
        m_nameNode =
            m_db.appendChildNode(rootNode, repositoryNameElementName, DiplodocusDB::Value::UTF8String(""), error);
        m_projectsNode = m_db.appendChildNode(rootNode, repositoryProjectsElementName, error);
    }
}

void ProjectRepository::open(const boost::filesystem::path& path, Ishiko::Error& error)
{
    m_db.open(path, error);
    DiplodocusDB::XMLTreeDBNode projectRoot = m_db.child(m_db.root(), rootElementName, error);
    m_nameNode = m_db.child(projectRoot, repositoryNameElementName, error);
    m_projectsNode = m_db.child(projectRoot, repositoryProjectsElementName, error);
}

void ProjectRepository::close()
{
    m_db.close();
}

std::string ProjectRepository::name() const
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

void ProjectRepository::setName(const std::string& name)
{
    // TODO : should setName commit immediately?
    Ishiko::Error error;
    m_db.setValue(m_nameNode, DiplodocusDB::Value::UTF8String(name), error);
}

DiplodocusDB::XMLTreeDB& ProjectRepository::db()
{
    return m_db;
}

DiplodocusDB::XMLTreeDBNode ProjectRepository::getProjectNode(const std::string& name, Ishiko::Error& error)
{
    DiplodocusDB::XMLTreeDBNode result;
    for (DiplodocusDB::XMLTreeDBNode projectNode = m_db.child(m_projectsNode, projectElementName, error);
         projectNode; 
         projectNode = m_db.nextSibling(projectNode, projectElementName, error))
    {
        DiplodocusDB::Value nameNodeValue = m_db.childValue(projectNode, projectNameElementName,
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

DiplodocusDB::XMLTreeDBNode ProjectRepository::addProjectNode(const std::string& name, Ishiko::Error& error)
{
    if (m_projectsNode)
    {
        DiplodocusDB::XMLTreeDBNode projectNode = m_db.appendChildNode(m_projectsNode, projectElementName, error);
        DiplodocusDB::XMLTreeDBNode nameNode = m_db.appendChildNode(projectNode, projectNameElementName,
            DiplodocusDB::Value::UTF8String(name), error);
        return DiplodocusDB::XMLTreeDBNode(projectNode);
    }
    else
    {
        return DiplodocusDB::XMLTreeDBNode();
    }
}

}
