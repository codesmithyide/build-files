// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_MSBUILD_MSBUILDFILTERSFILE_HPP
#define GUARD_NUIME_BUILDFILES_MSBUILD_MSBUILDFILTERSFILE_HPP

#include <Ishiko/Errors.hpp>
#include <boost/filesystem/path.hpp>
#include <vector>
#include <string>

namespace Nuime
{
    class MSBuildFiltersFile
    {
    public:
        void create(const boost::filesystem::path& path, Ishiko::Error& error);

        void addHeaderFile(const std::string& path);
        void addSourceFile(const std::string& path);

        void commit();

    private:
        boost::filesystem::path m_path;
        std::vector<std::string> m_headerFiles;
        std::vector<std::string> m_sourceFiles;
    };
}

#endif
