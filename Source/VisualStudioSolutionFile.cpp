/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "VisualStudioSolutionFile.h"
#include <fstream>

namespace CodeSmithy
{

void VisualStudioSolutionFile::create(const boost::filesystem::path& path, Ishiko::Error& error)
{
    std::ofstream file(path.string());

    file << "\xEF\xBB\xBF" << std::endl;
    file << "Microsoft Visual Studio Solution File, Format Version 12.00" << std::endl;
        file << "# Visual Studio Version 16" << std::endl;
        file << "VisualStudioVersion = 16.0.30413.136" << std::endl;
        file << "MinimumVisualStudioVersion = 10.0.40219.1" << std::endl;
        file << "Project(\"{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}\") = \"VS2019EmptyCppProject\", \"VS2019EmptyCppProject\\VS2019EmptyCppProject.vcxproj\", \"{F36308CC-B212-4159-B35F-1AB881130689}\"" << std::endl;
        file << "EndProject" << std::endl;
        file << "Global" << std::endl;
        file << "\tGlobalSection(SolutionConfigurationPlatforms) = preSolution" << std::endl;
        file << "\t\tDebug|x64 = Debug|x64" << std::endl;
        file << "\t\tDebug|x86 = Debug|x86" << std::endl;
        file << "\t\tRelease|x64 = Release|x64" << std::endl;
        file << "\t\tRelease|x86 = Release|x86" << std::endl;
        file << "\tEndGlobalSection" << std::endl;
        file << "\tGlobalSection(ProjectConfigurationPlatforms) = postSolution" << std::endl;
        file << "\t\t{F36308CC-B212-4159-B35F-1AB881130689}.Debug|x64.ActiveCfg = Debug|x64" << std::endl;
        file << "\t\t{F36308CC-B212-4159-B35F-1AB881130689}.Debug|x64.Build.0 = Debug|x64" << std::endl;
        file << "\t\t{F36308CC-B212-4159-B35F-1AB881130689}.Debug|x86.ActiveCfg = Debug|Win32" << std::endl;
        file << "\t\t{F36308CC-B212-4159-B35F-1AB881130689}.Debug|x86.Build.0 = Debug|Win32" << std::endl;
        file << "\t\t{F36308CC-B212-4159-B35F-1AB881130689}.Release|x64.ActiveCfg = Release|x64" << std::endl;
        file << "\t\t{F36308CC-B212-4159-B35F-1AB881130689}.Release|x64.Build.0 = Release|x64" << std::endl;
        file << "\t\t{F36308CC-B212-4159-B35F-1AB881130689}.Release|x86.ActiveCfg = Release|Win32" << std::endl;
        file << "\t\t{F36308CC-B212-4159-B35F-1AB881130689}.Release|x86.Build.0 = Release|Win32" << std::endl;
        file << "\tEndGlobalSection" << std::endl;
        file << "\tGlobalSection(SolutionProperties) = preSolution" << std::endl;
        file << "\t\tHideSolutionNode = FALSE" << std::endl;
        file << "\tEndGlobalSection" << std::endl;
        file << "\tGlobalSection(ExtensibilityGlobals) = postSolution" << std::endl;
        file << "\t\tSolutionGuid = {A84D6D42-2A06-4AE4-93F4-57A1D1BEFE2F}" << std::endl;
        file << "\tEndGlobalSection" << std::endl;
        file << "EndGlobal" << std::endl;
}

}
