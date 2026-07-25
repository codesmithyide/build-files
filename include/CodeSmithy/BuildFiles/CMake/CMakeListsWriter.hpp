// SPDX-FileCopyrightText: 2017-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_CMAKE_CMAKELISTSWRITER_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_CMAKE_CMAKELISTSWRITER_HPP

#include <boost/filesystem.hpp>
#include <Ishiko/Errors.hpp>
#include <Ishiko/FileSystem.hpp>
#include <string>

namespace CodeSmithy
{
    class CMakeListsWriter
    {
    public:
        CMakeListsWriter(const boost::filesystem::path& output_file, Ishiko::Error& error);
        void close();

        void writeAddLibraryCommand();
        void writeCMakeMinimumRequiredCommand(const std::string& version);
        void writeProjectCommand();

    private:
        Ishiko::TextFile m_output_file;
    };
}

#endif
