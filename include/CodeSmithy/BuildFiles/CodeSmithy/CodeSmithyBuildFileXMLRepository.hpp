// SPDX-FileCopyrightText: 2017-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_CODESMITHY_CODESMITHYBUILDFILEXMLREPOSITORY_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_CODESMITHY_CODESMITHYBUILDFILEXMLREPOSITORY_HPP

#include "CodeSmithyBuildFile.hpp"
#include <DiplodocusDB/EmbeddedDocumentDB.hpp>
#include <boost/filesystem/path.hpp>
#include <string>

namespace CodeSmithy
{
    // This class allows to store one or more projects in a file.
    class CodeSmithyBuildFileXMLRepository
    {
    public:
        void create(const boost::filesystem::path& path, Ishiko::Error& error);
        void open(const boost::filesystem::path& path, Ishiko::Error& error);
        void close();

        std::string name() const;
        void setName(const std::string& name);

        // TODO: need to find a better way to encapsulate the XMLTreeDB
        DiplodocusDB::XMLTreeDB& db();

        std::unique_ptr<CodeSmithyBuildFile> getBuildFileNode(const std::string& name, Ishiko::Error& error);
        DiplodocusDB::XMLTreeDBNode addProjectNode(const std::string& name, Ishiko::Error& error);

    private:
        class BuildFileAdapter : public CodeSmithyBuildFile
        {
        public:
            explicit BuildFileAdapter(DiplodocusDB::XMLTreeDBNode build_file_node) noexcept;

        private:
            DiplodocusDB::XMLTreeDBNode m_build_file_node;
        };

        // TODO : mutable because used in name(), fix that
        mutable DiplodocusDB::XMLTreeDB m_db;
        // TODO : mutable because used in name(), fix that
        mutable DiplodocusDB::XMLTreeDBNode m_nameNode;
        DiplodocusDB::XMLTreeDBNode m_projectsNode;
    };
}

#endif
