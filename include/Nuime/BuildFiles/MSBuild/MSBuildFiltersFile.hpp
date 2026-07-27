/*
    Copyright (c) 2021-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_MSBUILD_MSBUILDFILTERSFILE_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_MSBUILD_MSBUILDFILTERSFILE_HPP

#include <Ishiko/Errors.hpp>
#include <boost/filesystem/path.hpp>
#include <vector>
#include <string>

namespace CodeSmithy
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
