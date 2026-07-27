// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_VISUALSTUDIO_VISUALSTUDIOSOLUTIONFILE_HPP
#define GUARD_NUIME_BUILDFILES_VISUALSTUDIO_VISUALSTUDIOSOLUTIONFILE_HPP

#include "../MSBuild/MSBuildProjectFile.hpp"
#include <Ishiko/UUIDs/UUIDGenerator.h>
#include <Ishiko/Errors.hpp>
#include <boost/filesystem/path.hpp>

namespace Nuime
{
    class VisualStudioSolutionFile
    {
    public:
        VisualStudioSolutionFile();
        void create(const boost::filesystem::path& path, Ishiko::UUIDGenerator& uuidGenerator, Ishiko::Error& error);
        void create(const boost::filesystem::path& path, const MSBuildProjectFile& projectFile,
            Ishiko::UUIDGenerator& uuidGenerator, Ishiko::Error& error);
    };
}

#endif
