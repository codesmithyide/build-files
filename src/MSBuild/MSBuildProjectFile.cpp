/*
    Copyright (c) 2020-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "MSBuild/MSBuildProjectFile.hpp"
#include <Ishiko/UUIDs.hpp>
#include <Ishiko/IO.hpp>
#include <Ishiko/Errors.hpp>
#include <fstream>

namespace CodeSmithy
{

namespace
{

void WriteProjectConfiguration(std::ostream& output, const char* configuration, const char* architecture)
{
    output << "    <ProjectConfiguration Include=\"" << configuration << "|" << architecture << "\">" << std::endl;
    output << "      <Configuration>" << configuration << "</Configuration>" << std::endl;
    output << "      <Platform>" << architecture  << "</Platform>" << std::endl;
    output << "    </ProjectConfiguration>" << std::endl;
}

void Write(std::ostream& output, const Ishiko::UUID& projectUUID, const std::string& name,
    const std::vector<std::string>& headerFiles, const std::vector<std::string>& sourceFiles)
{
    output << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
    output << "<Project DefaultTargets=\"Build\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">" << std::endl;
    output << "  <ItemGroup Label=\"ProjectConfigurations\">" << std::endl;
    WriteProjectConfiguration(output, "Debug", "Win32");
    WriteProjectConfiguration(output, "Release", "Win32");
    WriteProjectConfiguration(output, "Debug", "x64");
    WriteProjectConfiguration(output, "Release", "x64");
    output << "  </ItemGroup>" << std::endl;
    output << "  <PropertyGroup Label=\"Globals\">" << std::endl;
    output << "    <VCProjectVersion>16.0</VCProjectVersion>" << std::endl;
    output << "    <Keyword>Win32Proj</Keyword>" << std::endl;
    output << "    <ProjectGuid>{" << projectUUID << "}</ProjectGuid>" << std::endl;
    output << "    <RootNamespace>" << name << "</RootNamespace>" << std::endl;
    output << "    <WindowsTargetPlatformVersion>10.0</WindowsTargetPlatformVersion>" << std::endl;
    output << "  </PropertyGroup>" << std::endl;
    output << "  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.Default.props\" />" << std::endl;
    output << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\" Label=\"Configuration\">" << std::endl;
    output << "    <ConfigurationType>Application</ConfigurationType>" << std::endl;
    output << "    <UseDebugLibraries>true</UseDebugLibraries>" << std::endl;
    output << "    <PlatformToolset>v142</PlatformToolset>" << std::endl;
    output << "    <CharacterSet>Unicode</CharacterSet>" << std::endl;
    output << "  </PropertyGroup>" << std::endl;
    output << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\" Label=\"Configuration\">" << std::endl;
    output << "    <ConfigurationType>Application</ConfigurationType>" << std::endl;
    output << "    <UseDebugLibraries>false</UseDebugLibraries>" << std::endl;
    output << "    <PlatformToolset>v142</PlatformToolset>" << std::endl;
    output << "    <WholeProgramOptimization>true</WholeProgramOptimization>" << std::endl;
    output << "    <CharacterSet>Unicode</CharacterSet>" << std::endl;
    output << "  </PropertyGroup>" << std::endl;
    output << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\" Label=\"Configuration\">" << std::endl;
    output << "    <ConfigurationType>Application</ConfigurationType>" << std::endl;
    output << "    <UseDebugLibraries>true</UseDebugLibraries>" << std::endl;
    output << "    <PlatformToolset>v142</PlatformToolset>" << std::endl;
    output << "    <CharacterSet>Unicode</CharacterSet>" << std::endl;
    output << "  </PropertyGroup>" << std::endl;
    output << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\" Label=\"Configuration\">" << std::endl;
    output << "    <ConfigurationType>Application</ConfigurationType>" << std::endl;
    output << "    <UseDebugLibraries>false</UseDebugLibraries>" << std::endl;
    output << "    <PlatformToolset>v142</PlatformToolset>" << std::endl;
    output << "    <WholeProgramOptimization>true</WholeProgramOptimization>" << std::endl;
    output << "    <CharacterSet>Unicode</CharacterSet>" << std::endl;
    output << "  </PropertyGroup>" << std::endl;
    output << "  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.props\" />" << std::endl;
    output << "  <ImportGroup Label=\"ExtensionSettings\">" << std::endl;
    output << "  </ImportGroup>" << std::endl;
    output << "  <ImportGroup Label=\"Shared\">" << std::endl;
    output << "  </ImportGroup>" << std::endl;
    output << "  <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">" << std::endl;
    output << "    <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << std::endl;
    output << "  </ImportGroup>" << std::endl;
    output << "  <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\">" << std::endl;
    output << "    <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << std::endl;
    output << "  </ImportGroup>" << std::endl;
    output << "  <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\">" << std::endl;
    output << "    <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << std::endl;
    output << "  </ImportGroup>" << std::endl;
    output << "  <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\">" << std::endl;
    output << "    <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << std::endl;
    output << "  </ImportGroup>" << std::endl;
    output << "  <PropertyGroup Label=\"UserMacros\" />" << std::endl;
    output << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">" << std::endl;
    output << "    <LinkIncremental>true</LinkIncremental>" << std::endl;
    output << "  </PropertyGroup>" << std::endl;
    output << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\">" << std::endl;
    output << "    <LinkIncremental>false</LinkIncremental>" << std::endl;
    output << "  </PropertyGroup>" << std::endl;
    output << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\">" << std::endl;
    output << "    <LinkIncremental>true</LinkIncremental>" << std::endl;
    output << "  </PropertyGroup>" << std::endl;
    output << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\">" << std::endl;
    output << "    <LinkIncremental>false</LinkIncremental>" << std::endl;
    output << "  </PropertyGroup>" << std::endl;
    output << "  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">" << std::endl;
    output << "    <ClCompile>" << std::endl;
    output << "      <WarningLevel>Level3</WarningLevel>" << std::endl;
    output << "      <SDLCheck>true</SDLCheck>" << std::endl;
    output << "      <PreprocessorDefinitions>WIN32;_DEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << std::endl;
    output << "      <ConformanceMode>true</ConformanceMode>" << std::endl;
    output << "    </ClCompile>" << std::endl;
    output << "    <Link>" << std::endl;
    output << "      <SubSystem>Console</SubSystem>" << std::endl;
    output << "      <GenerateDebugInformation>true</GenerateDebugInformation>" << std::endl;
    output << "    </Link>" << std::endl;
    output << "  </ItemDefinitionGroup>" << std::endl;
    output << "  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\">" << std::endl;
    output << "    <ClCompile>" << std::endl;
    output << "      <WarningLevel>Level3</WarningLevel>" << std::endl;
    output << "      <FunctionLevelLinking>true</FunctionLevelLinking>" << std::endl;
    output << "      <IntrinsicFunctions>true</IntrinsicFunctions>" << std::endl;
    output << "      <SDLCheck>true</SDLCheck>" << std::endl;
    output << "      <PreprocessorDefinitions>WIN32;NDEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << std::endl;
    output << "      <ConformanceMode>true</ConformanceMode>" << std::endl;
    output << "    </ClCompile>" << std::endl;
    output << "    <Link>" << std::endl;
    output << "      <SubSystem>Console</SubSystem>" << std::endl;
    output << "      <EnableCOMDATFolding>true</EnableCOMDATFolding>" << std::endl;
    output << "      <OptimizeReferences>true</OptimizeReferences>" << std::endl;
    output << "      <GenerateDebugInformation>true</GenerateDebugInformation>" << std::endl;
    output << "    </Link>" << std::endl;
    output << "  </ItemDefinitionGroup>" << std::endl;
    output << "  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\">" << std::endl;
    output << "    <ClCompile>" << std::endl;
    output << "      <WarningLevel>Level3</WarningLevel>" << std::endl;
    output << "      <SDLCheck>true</SDLCheck>" << std::endl;
    output << "      <PreprocessorDefinitions>_DEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << std::endl;
    output << "      <ConformanceMode>true</ConformanceMode>" << std::endl;
    output << "    </ClCompile>" << std::endl;
    output << "    <Link>" << std::endl;
    output << "      <SubSystem>Console</SubSystem>" << std::endl;
    output << "      <GenerateDebugInformation>true</GenerateDebugInformation>" << std::endl;
    output << "    </Link>" << std::endl;
    output << "  </ItemDefinitionGroup>" << std::endl;
    output << "  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\">" << std::endl;
    output << "    <ClCompile>" << std::endl;
    output << "      <WarningLevel>Level3</WarningLevel>" << std::endl;
    output << "      <FunctionLevelLinking>true</FunctionLevelLinking>" << std::endl;
    output << "      <IntrinsicFunctions>true</IntrinsicFunctions>" << std::endl;
    output << "      <SDLCheck>true</SDLCheck>" << std::endl;
    output << "      <PreprocessorDefinitions>NDEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << std::endl;
    output << "      <ConformanceMode>true</ConformanceMode>" << std::endl;
    output << "    </ClCompile>" << std::endl;
    output << "    <Link>" << std::endl;
    output << "      <SubSystem>Console</SubSystem>" << std::endl;
    output << "      <EnableCOMDATFolding>true</EnableCOMDATFolding>" << std::endl;
    output << "      <OptimizeReferences>true</OptimizeReferences>" << std::endl;
    output << "      <GenerateDebugInformation>true</GenerateDebugInformation>" << std::endl;
    output << "    </Link>" << std::endl;
    output << "  </ItemDefinitionGroup>" << std::endl;
    if (!headerFiles.empty())
    {
        output << "  <ItemGroup>" << std::endl;
        for (const std::string& file : headerFiles)
        {
            output << "    <ClInclude Include=\"" << file << "\" />" << std::endl;
        }
        output << "  </ItemGroup>" << std::endl;
    }
    if (!sourceFiles.empty())
    {
        output << "  <ItemGroup>" << std::endl;
        for (const std::string& file : sourceFiles)
        {
            output << "    <ClCompile Include=\"" << file << "\" />" << std::endl;
        }
        output << "  </ItemGroup>" << std::endl;
    }
    if (headerFiles.empty() && sourceFiles.empty())
    {
        output << "  <ItemGroup></ItemGroup>" << std::endl;
    }
    output << "  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.targets\" />" << std::endl;
    output << "  <ImportGroup Label=\"ExtensionTargets\">" << std::endl;
    output << "  </ImportGroup>" << std::endl;
    output << "</Project>" << std::endl;
}

}

void MSBuildProjectFile::create(const boost::filesystem::path& path, const std::string& name,
    Ishiko::UUIDGenerator& uuidGenerator, Ishiko::Error& error)
{
    std::ofstream file(path.string());
    if (Ishiko::FailIfCreateFileError(file, error))
    {
        return;
    }

    Ishiko::UUID projectUUID = uuidGenerator.generate(error);
    if (error)
    {
        // TODO: test and delete file?
        return;
    }

    Write(file, projectUUID, name, m_headerFiles, m_sourceFiles);

    m_name = name;
    m_guid = projectUUID;
    m_path = path;
}

const std::string& MSBuildProjectFile::name() const
{
    return m_name;
}

const Ishiko::UUID& MSBuildProjectFile::guid() const
{
    return m_guid;
}

const boost::filesystem::path MSBuildProjectFile::path() const
{
    return m_path;
}

void MSBuildProjectFile::addHeaderFile(const std::string& path)
{
    m_headerFiles.emplace_back(path);
}

void MSBuildProjectFile::addSourceFile(const std::string& path)
{
    m_sourceFiles.emplace_back(path);
}

void MSBuildProjectFile::commit()
{
    std::ofstream file(m_path.string());
    Write(file, m_guid, m_name, m_headerFiles, m_sourceFiles);
}

}
