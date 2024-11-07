// SPDX-FileCopyrightText: 2017-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_CODESMITHY_CODESMITHYBUILDFILE_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_CODESMITHY_CODESMITHYBUILDFILE_HPP

#include <string>

namespace CodeSmithy
{
    class CodeSmithyBuildFile
    {
    public:
        virtual ~CodeSmithyBuildFile() = default;

        virtual void addSourceFile(const std::string& file_path) = 0;
    };
}

#endif
