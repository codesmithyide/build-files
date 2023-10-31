/*
    Copyright (c) 2020-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_VISUALSTUDIO_VISUALSTUDIOSOLUTIONFILE_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_VISUALSTUDIO_VISUALSTUDIOSOLUTIONFILE_HPP

#include "../MSBuild/MSBuildProjectFile.hpp"
#include <Ishiko/UUIDs/UUIDGenerator.h>
#include <Ishiko/Errors.hpp>
#include <boost/filesystem/path.hpp>

namespace CodeSmithy
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
