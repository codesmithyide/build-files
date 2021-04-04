/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILDFILES_MSBUILDFILTERSFILE_H_
#define _CODESMITHYIDE_BUILDFILES_MSBUILDFILTERSFILE_H_

#include <Ishiko/Errors/Error.h>
#include <boost/filesystem/path.hpp>

namespace CodeSmithy
{

class MSBuildFiltersFile
{
public:
    void create(const boost::filesystem::path& path, Ishiko::Error& error);
};

}

#include "linkoptions.h"

#endif
