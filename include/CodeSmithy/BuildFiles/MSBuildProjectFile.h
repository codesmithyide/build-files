/*
    Copyright (c) 2020-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILDFILES_MSBUILDPROJECTFILE_H_
#define _CODESMITHYIDE_BUILDFILES_MSBUILDPROJECTFILE_H_

#include <Ishiko/UUIDs/UUIDGenerator.h>
#include <Ishiko/Errors.hpp>
#include <boost/filesystem/path.hpp>
#include <vector>
#include <string>

namespace CodeSmithy
{

class MSBuildProjectFile
{
public:
    void create(const boost::filesystem::path& path, const std::string& name,
        Ishiko::UUIDGenerator& uuidGenerator, Ishiko::Error& error);

    const std::string& name() const;
    const Ishiko::UUID& guid() const;
    const boost::filesystem::path path() const;

    void addHeaderFile(const std::string& path);
    void addSourceFile(const std::string& path);

    void commit();

private:
    std::string m_name;
    Ishiko::UUID m_guid;
    boost::filesystem::path m_path;
    std::vector<std::string> m_headerFiles;
    std::vector<std::string> m_sourceFiles;
};

}

#include "linkoptions.h"

#endif
