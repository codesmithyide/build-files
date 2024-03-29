/*
    Copyright (c) 2020-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "VisualStudio/VisualStudioSolutionFile.hpp"
#include <Ishiko/UUIDs.hpp>
#include <Ishiko/IO.hpp>
#include <Ishiko/Text.hpp>
#include <Ishiko/Errors.hpp>
#include <boost/filesystem/operations.hpp>
#include <fstream>

namespace CodeSmithy
{

VisualStudioSolutionFile::VisualStudioSolutionFile()
{
}

void VisualStudioSolutionFile::create(const boost::filesystem::path& path, Ishiko::UUIDGenerator& uuidGenerator,
    Ishiko::Error& error)
{
    std::ofstream file(path.string());
    if (Ishiko::FailIfCreateFileError(file, error))
    {
        return;
    }

    Ishiko::UUID extensibilityUUID = uuidGenerator.generate(error);
    if (error)
    {
        // TODO: test and delete file?
        return;
    }
    std::string extensibilityUUIDString = extensibilityUUID.toString();
    Ishiko::ASCII::ToUpperCase(extensibilityUUIDString);

    file << "\xEF\xBB\xBF" << std::endl;
    file << "Microsoft Visual Studio Solution File, Format Version 12.00" << std::endl;
    file << "# Visual Studio Version 16" << std::endl;
    file << "VisualStudioVersion = 16.0.30413.136" << std::endl;
    file << "MinimumVisualStudioVersion = 10.0.40219.1" << std::endl;
    file << "Global" << std::endl;
    file << "\tGlobalSection(SolutionProperties) = preSolution" << std::endl;
    file << "\t\tHideSolutionNode = FALSE" << std::endl;
    file << "\tEndGlobalSection" << std::endl;
    file << "\tGlobalSection(ExtensibilityGlobals) = postSolution" << std::endl;
    file << "\t\tSolutionGuid = {" << extensibilityUUIDString << "}" << std::endl;
    file << "\tEndGlobalSection" << std::endl;
    file << "EndGlobal" << std::endl;
}

void VisualStudioSolutionFile::create(const boost::filesystem::path& path, const MSBuildProjectFile& projectFile,
    Ishiko::UUIDGenerator& uuidGenerator, Ishiko::Error& error)
{
    std::ofstream file(path.string());

    Ishiko::UUID cppProjectTypeUUID("8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942");
    std::string cppProjectTypeUUIDString = cppProjectTypeUUID.toString();
    Ishiko::ASCII::ToUpperCase(cppProjectTypeUUIDString);

    boost::filesystem::path relativePath = boost::filesystem::relative(projectFile.path(), path.parent_path());

    Ishiko::UUID projectUUID = projectFile.guid();
    std::string projectUUIDString = projectUUID.toString();
    Ishiko::ASCII::ToUpperCase(projectUUIDString);

    Ishiko::UUID extensibilityUUID = uuidGenerator.generate(error);
    if (error)
    {
        // TODO: test and delete file?
        return;
    }
    std::string extensibilityUUIDString = extensibilityUUID.toString();
    Ishiko::ASCII::ToUpperCase(extensibilityUUIDString);

    file << "\xEF\xBB\xBF" << std::endl;
    file << "Microsoft Visual Studio Solution File, Format Version 12.00" << std::endl;
    file << "# Visual Studio Version 16" << std::endl;
    file << "VisualStudioVersion = 16.0.30413.136" << std::endl;
    file << "MinimumVisualStudioVersion = 10.0.40219.1" << std::endl;
    file << "Project(\"{" << cppProjectTypeUUIDString << "}\") = \"" << projectFile.name() << "\", \"" << relativePath.string() << "\", \"{" << projectUUIDString << "}\"" << std::endl;
    file << "EndProject" << std::endl;
    file << "Global" << std::endl;
    file << "\tGlobalSection(SolutionConfigurationPlatforms) = preSolution" << std::endl;
    file << "\t\tDebug|x64 = Debug|x64" << std::endl;
    file << "\t\tDebug|x86 = Debug|x86" << std::endl;
    file << "\t\tRelease|x64 = Release|x64" << std::endl;
    file << "\t\tRelease|x86 = Release|x86" << std::endl;
    file << "\tEndGlobalSection" << std::endl;
    file << "\tGlobalSection(ProjectConfigurationPlatforms) = postSolution" << std::endl;
    file << "\t\t{" << projectUUIDString << "}.Debug|x64.ActiveCfg = Debug|x64" << std::endl;
    file << "\t\t{" << projectUUIDString << "}.Debug|x64.Build.0 = Debug|x64" << std::endl;
    file << "\t\t{" << projectUUIDString << "}.Debug|x86.ActiveCfg = Debug|Win32" << std::endl;
    file << "\t\t{" << projectUUIDString << "}.Debug|x86.Build.0 = Debug|Win32" << std::endl;
    file << "\t\t{" << projectUUIDString << "}.Release|x64.ActiveCfg = Release|x64" << std::endl;
    file << "\t\t{" << projectUUIDString << "}.Release|x64.Build.0 = Release|x64" << std::endl;
    file << "\t\t{" << projectUUIDString << "}.Release|x86.ActiveCfg = Release|Win32" << std::endl;
    file << "\t\t{" << projectUUIDString << "}.Release|x86.Build.0 = Release|Win32" << std::endl;
    file << "\tEndGlobalSection" << std::endl;
    file << "\tGlobalSection(SolutionProperties) = preSolution" << std::endl;
    file << "\t\tHideSolutionNode = FALSE" << std::endl;
    file << "\tEndGlobalSection" << std::endl;
    file << "\tGlobalSection(ExtensibilityGlobals) = postSolution" << std::endl;
    file << "\t\tSolutionGuid = {" << extensibilityUUIDString << "}" << std::endl;
    file << "\tEndGlobalSection" << std::endl;
    file << "EndGlobal" << std::endl;
}

}
