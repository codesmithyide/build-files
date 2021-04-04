/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILDFILES_MSBUILDPROJECTFILE_H_
#define _CODESMITHYIDE_BUILDFILES_MSBUILDPROJECTFILE_H_

#include <Ishiko/UUIDs/UUIDGenerator.h>
#include <Ishiko/Errors/Error.h>
#include <boost/filesystem/path.hpp>
#include <vector>
#include <string>

namespace CodeSmithy
{

class MSBuildProjectFile
{
public:
    void create(const boost::filesystem::path& path, const std::string& name,
        Ishiko::UUIDs::UUIDGenerator& uuidGenerator, Ishiko::Error& error);

    const std::string& name() const;
    const Ishiko::UUIDs::UUID& guid() const;
    const boost::filesystem::path path() const;

    void addFile(const std::string& path);

private:
    std::string m_name;
    Ishiko::UUIDs::UUID m_guid;
    boost::filesystem::path m_path;
    std::vector<std::string> m_files;
};

}

#include "linkoptions.h"

#endif
