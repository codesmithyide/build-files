// SPDX-FileCopyrightText: 2017-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_CODESMITHY_CODESMITHYBUILDFILE_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_CODESMITHY_CODESMITHYBUILDFILE_HPP

#include <memory>
#include <string>

namespace CodeSmithy
{
    class CodeSmithyBuildFile
    {
    public:
        class Project
        {
        };

        virtual ~CodeSmithyBuildFile() = default;

        virtual void addProject(const std::string& name) = 0;
        //virtual std::shared_ptr<Project> getProject(const std::string& name) = 0;

        virtual void addTarget(const std::string& project_name, const std::string& target_name) = 0;

        virtual void addSourceFile(const std::string& project_name, const std::string& file_path) = 0;
    };
}

#endif
