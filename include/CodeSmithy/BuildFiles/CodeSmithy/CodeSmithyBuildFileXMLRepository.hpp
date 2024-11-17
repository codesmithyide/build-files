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

        std::unique_ptr<CodeSmithyBuildFile> getBuildFile(Ishiko::Error& error);

        DiplodocusDB::XMLTreeDBNode getBuildFileRawNode(Ishiko::Error& error);

    private:
        class BuildFileAdapter : public CodeSmithyBuildFile
        {
        public:
            explicit BuildFileAdapter(DiplodocusDB::XMLTreeDB& db,
                DiplodocusDB::XMLTreeDBNode build_file_node) noexcept;

            void addProject(const std::string& name) override;

            void addTarget(const std::string& project_name, const std::string& target_name) override;

            void addSourceFile(const std::string& project_name, const std::string& file_path) override;

        private:
            DiplodocusDB::XMLTreeDB& m_db;
            DiplodocusDB::XMLTreeDBNode m_build_file_node;
        };

        // TODO : mutable because used in name(), fix that
        mutable DiplodocusDB::XMLTreeDB m_db;
        // TODO : mutable because used in name(), fix that
        mutable DiplodocusDB::XMLTreeDBNode m_name_node;
        DiplodocusDB::XMLTreeDBNode m_projects_node;
    };
}

#endif
