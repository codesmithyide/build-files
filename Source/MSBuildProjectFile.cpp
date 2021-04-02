/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "MSBuildProjectFile.h"
#include <fstream>

namespace CodeSmithy
{

void MSBuildProjectFile::create(const boost::filesystem::path& path, Ishiko::Error& error)
{
    std::ofstream file(path.string());

    file << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
    file << "<Project DefaultTargets=\"Build\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">" << std::endl;
    file << "  <ItemGroup Label=\"ProjectConfigurations\">" << std::endl;
    file << "    <ProjectConfiguration Include=\"Debug|Win32\">" << std::endl;
    file << "      <Configuration>Debug</Configuration>" << std::endl;
    file << "      <Platform>Win32</Platform>" << std::endl;
    file << "    </ProjectConfiguration>" << std::endl;
    file << "    <ProjectConfiguration Include=\"Release|Win32\">" << std::endl;
    file << "      <Configuration>Release</Configuration>" << std::endl;
    file << "      <Platform>Win32</Platform>" << std::endl;
    file << "    </ProjectConfiguration>" << std::endl;
    file << "    <ProjectConfiguration Include=\"Debug|x64\">" << std::endl;
    file << "      <Configuration>Debug</Configuration>" << std::endl;
    file << "      <Platform>x64</Platform>" << std::endl;
    file << "    </ProjectConfiguration>" << std::endl;
    file << "    <ProjectConfiguration Include=\"Release|x64\">" << std::endl;
    file << "      <Configuration>Release</Configuration>" << std::endl;
    file << "      <Platform>x64</Platform>" << std::endl;
    file << "    </ProjectConfiguration>" << std::endl;
    file << std::endl;
    file << "  </ItemGroup>" << std::endl;
    file << "  <PropertyGroup Label=\"Globals\">" << std::endl;
    file << "    <VCProjectVersion>16.0</VCProjectVersion>" << std::endl;
    file << "    <Keyword>Win32Proj</Keyword>" << std::endl;
    file << "    <ProjectGuid>{f36308cc-b212-4159-b35f-1ab881130689}</ProjectGuid>" << std::endl;
    file << "    <RootNamespace>VS2019EmptyCppProject</RootNamespace>" << std::endl;
    file << "    <WindowsTargetPlatformVersion>10.0</WindowsTargetPlatformVersion>" << std::endl;
    file << "  </PropertyGroup>" << std::endl;
    file << "  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.Default.props\" />" << std::endl;
    file << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\" Label=\"Configuration\">" << std::endl;
    file << "    <ConfigurationType>Application</ConfigurationType>" << std::endl;
    file << "    <UseDebugLibraries>true</UseDebugLibraries>" << std::endl;
    file << "    <PlatformToolset>v142</PlatformToolset>" << std::endl;
    file << "    <CharacterSet>Unicode</CharacterSet>" << std::endl;
    file << "  </PropertyGroup>" << std::endl;
    file << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\" Label=\"Configuration\">" << std::endl;
    file << "    <ConfigurationType>Application</ConfigurationType>" << std::endl;
    file << "    <UseDebugLibraries>false</UseDebugLibraries>" << std::endl;
    file << "    <PlatformToolset>v142</PlatformToolset>" << std::endl;
    file << "    <WholeProgramOptimization>true</WholeProgramOptimization>" << std::endl;
    file << "    <CharacterSet>Unicode</CharacterSet>" << std::endl;
    file << "  </PropertyGroup>" << std::endl;
    file << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\" Label=\"Configuration\">" << std::endl;
    file << "    <ConfigurationType>Application</ConfigurationType>" << std::endl;
    file << "    <UseDebugLibraries>true</UseDebugLibraries>" << std::endl;
    file << "    <PlatformToolset>v142</PlatformToolset>" << std::endl;
    file << "    <CharacterSet>Unicode</CharacterSet>" << std::endl;
    file << "  </PropertyGroup>" << std::endl;
    file << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\" Label=\"Configuration\">" << std::endl;
    file << "    <ConfigurationType>Application</ConfigurationType>" << std::endl;
    file << "    <UseDebugLibraries>false</UseDebugLibraries>" << std::endl;
    file << "    <PlatformToolset>v142</PlatformToolset>" << std::endl;
    file << "    <WholeProgramOptimization>true</WholeProgramOptimization>" << std::endl;
    file << "    <CharacterSet>Unicode</CharacterSet>" << std::endl;
    file << "  </PropertyGroup>" << std::endl;
    file << std::endl;
    file << "  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.props\" />" << std::endl;
    file << "  <ImportGroup Label=\"ExtensionSettings\">" << std::endl;
    file << "  </ImportGroup>" << std::endl;
    file << "  <ImportGroup Label=\"Shared\" >" << std::endl;
    file << "  </ImportGroup>" << std::endl;
    file << "    <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">" << std::endl;
    file << "      <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << std::endl;
    file << "    </ImportGroup>" << std::endl;
    file << "    <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\">" << std::endl;
    file << "      <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << std::endl;
    file << "    </ImportGroup>" << std::endl;
    file << "    <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\">" << std::endl;
    file << "      <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << std::endl;
    file << "    </ImportGroup>" << std::endl;
    file << "    <ImportGroup Label=\"PropertySheets\" Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\">" << std::endl;
    file << "      <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />" << std::endl;
    file << "    </ImportGroup>" << std::endl;
    file << std::endl;
    file << "  <PropertyGroup Label=\"UserMacros\" />" << std::endl;
    file << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">" << std::endl;
    file << "    <LinkIncremental>true</LinkIncremental>" << std::endl;
    file << "  </PropertyGroup>" << std::endl;
    file << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\">" << std::endl;
    file << "    <LinkIncremental>false</LinkIncremental>" << std::endl;
    file << "  </PropertyGroup>" << std::endl;
    file << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\">" << std::endl;
    file << "    <LinkIncremental>true</LinkIncremental>" << std::endl;
    file << "  </PropertyGroup>" << std::endl;
    file << "  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\">" << std::endl;
    file << "    <LinkIncremental>false</LinkIncremental>" << std::endl;
    file << "  </PropertyGroup>" << std::endl;
    file << std::endl;
    file << "  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">" << std::endl;
    file << "    <ClCompile>" << std::endl;
    file << "      <WarningLevel>Level3</WarningLevel>" << std::endl;
    file << "      <SDLCheck>true</SDLCheck>" << std::endl;
    file << "      <PreprocessorDefinitions>WIN32;_DEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << std::endl;
    file << "      <ConformanceMode>true</ConformanceMode>" << std::endl;
    file << "    </ClCompile>" << std::endl;
    file << "    <Link>" << std::endl;
    file << "      <SubSystem>Console</SubSystem>" << std::endl;
    file << "      <GenerateDebugInformation>true</GenerateDebugInformation>" << std::endl;
    file << "    </Link>" << std::endl;
    file << "  </ItemDefinitionGroup>" << std::endl;
    file << "  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\">" << std::endl;
    file << "    <ClCompile>" << std::endl;
    file << "      <WarningLevel>Level3</WarningLevel>" << std::endl;
    file << "      <FunctionLevelLinking>true</FunctionLevelLinking>" << std::endl;
    file << "      <IntrinsicFunctions>true</IntrinsicFunctions>" << std::endl;
    file << "      <SDLCheck>true</SDLCheck>" << std::endl;
    file << "      <PreprocessorDefinitions>WIN32;NDEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << std::endl;
    file << "      <ConformanceMode>true</ConformanceMode>" << std::endl;
    file << "    </ClCompile>" << std::endl;
    file << "    <Link>" << std::endl;
    file << "      <SubSystem>Console</SubSystem>" << std::endl;
    file << "      <EnableCOMDATFolding>true</EnableCOMDATFolding>" << std::endl;
    file << "      <OptimizeReferences>true</OptimizeReferences>" << std::endl;
    file << "      <GenerateDebugInformation>true</GenerateDebugInformation>" << std::endl;
    file << "    </Link>" << std::endl;
    file << "  </ItemDefinitionGroup>" << std::endl;
    file << "  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|x64'\">" << std::endl;
    file << "    <ClCompile>" << std::endl;
    file << "      <WarningLevel>Level3</WarningLevel>" << std::endl;
    file << "      <SDLCheck>true</SDLCheck>" << std::endl;
    file << "      <PreprocessorDefinitions>_DEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << std::endl;
    file << "      <ConformanceMode>true</ConformanceMode>" << std::endl;
    file << "    </ClCompile>" << std::endl;
    file << "    <Link>" << std::endl;
    file << "      <SubSystem>Console</SubSystem>" << std::endl;
    file << "      <GenerateDebugInformation>true</GenerateDebugInformation>" << std::endl;
    file << "    </Link>" << std::endl;
    file << "  </ItemDefinitionGroup>" << std::endl;
    file << "  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|x64'\">" << std::endl;
    file << "    <ClCompile>" << std::endl;
    file << "      <WarningLevel>Level3</WarningLevel>" << std::endl;
    file << "      <FunctionLevelLinking>true</FunctionLevelLinking>" << std::endl;
    file << "      <IntrinsicFunctions>true</IntrinsicFunctions>" << std::endl;
    file << "      <SDLCheck>true</SDLCheck>" << std::endl;
    file << "      <PreprocessorDefinitions>NDEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>" << std::endl;
    file << "      <ConformanceMode>true</ConformanceMode>" << std::endl;
    file << "    </ClCompile>" << std::endl;
    file << "    <Link>" << std::endl;
    file << "      <SubSystem>Console</SubSystem>" << std::endl;
    file << "      <EnableCOMDATFolding>true</EnableCOMDATFolding>" << std::endl;
    file << "      <OptimizeReferences>true</OptimizeReferences>" << std::endl;
    file << "      <GenerateDebugInformation>true</GenerateDebugInformation>" << std::endl;
    file << "    </Link>" << std::endl;
    file << "  </ItemDefinitionGroup>" << std::endl;
    file << std::endl;
    file << "  <ItemGroup></ItemGroup>" << std::endl;
    file << "  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.targets\" />" << std::endl;
    file << "  <ImportGroup Label=\"ExtensionTargets\">" << std::endl;
    file << "  </ImportGroup>" << std::endl;
    file << "</Project>" << std::endl;
}

}
