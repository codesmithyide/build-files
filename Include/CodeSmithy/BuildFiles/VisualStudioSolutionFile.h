/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILDFILES_VISUALSTUDIOSOLUTIONFILE_H_
#define _CODESMITHYIDE_BUILDFILES_VISUALSTUDIOSOLUTIONFILE_H_

#include <Ishiko/UUIDs/UUIDGenerator.h>
#include <Ishiko/Errors/Error.h>
#include <boost/filesystem/path.hpp>

namespace CodeSmithy
{

class VisualStudioSolutionFile
{
public:
    VisualStudioSolutionFile();
    void create(const boost::filesystem::path& path, Ishiko::UUIDs::UUIDGenerator& uuidGenerator,
        Ishiko::Error& error);
};

}

#include "linkoptions.h"

#endif
