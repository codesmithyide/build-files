// SPDX-FileCopyrightText: 2017-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_CMAKE_CMAKELISTSWRITER_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_CMAKE_CMAKELISTSWRITER_HPP

namespace CodeSmithy
{
    class CMakeListsWriter
    {
    public:
        void writeAddLibraryCommand();
        void writeCMakeMinimumRequiredCommand();
        void writeProjectCommand();
    };
}

#endif
