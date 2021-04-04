/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "MSBuildFiltersFile.h"
#include <Ishiko/Errors/StreamUtilities.h>
#include <fstream>

using namespace Ishiko;

namespace CodeSmithy
{

namespace
{

void Write(std::ostream& output, const std::vector<std::string>& headerFiles,
    const std::vector<std::string>& sourceFiles)
{
    output << "\xEF\xBB\xBF<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
    output << "<Project ToolsVersion=\"4.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">" << std::endl;
    output << "  <ItemGroup>" << std::endl;
    output << "    <Filter Include=\"Source Files\">" << std::endl;
    output << "      <UniqueIdentifier>{4FC737F1-C7A5-4376-A066-2A32D752A2FF}</UniqueIdentifier>" << std::endl;
    output << "      <Extensions>cpp;c;cc;cxx;c++;cppm;ixx;def;odl;idl;hpj;bat;asm;asmx</Extensions>" << std::endl;
    output << "    </Filter>" << std::endl;
    output << "    <Filter Include=\"Header Files\">" << std::endl;
    output << "      <UniqueIdentifier>{93995380-89BD-4b04-88EB-625FBE52EBFB}</UniqueIdentifier>" << std::endl;
    output << "      <Extensions>h;hh;hpp;hxx;h++;hm;inl;inc;ipp;xsd</Extensions>" << std::endl;
    output << "    </Filter>" << std::endl;
    output << "    <Filter Include=\"Resource Files\">" << std::endl;
    output << "      <UniqueIdentifier>{67DA6AB6-F800-4c08-8B7A-83BB121AAD01}</UniqueIdentifier>" << std::endl;
    output << "      <Extensions>rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx;tiff;tif;png;wav;mfcribbon-ms</Extensions>" << std::endl;
    output << "    </Filter>" << std::endl;
    output << "  </ItemGroup>" << std::endl;
    for (const std::string& file : headerFiles)
    {
        output << "  <ItemGroup>" << std::endl;
        output << "    <ClInclude Include=\"" << file << "\">" << std::endl;
        output << "      <Filter>Header Files</Filter>" << std::endl;
        output << "    </ClInclude>" << std::endl;
        output << "  </ItemGroup>" << std::endl;
    }
    for (const std::string& file : sourceFiles)
    {
        output << "  <ItemGroup>" << std::endl;
        output << "    <ClCompile Include=\"" << file << "\">" << std::endl;
        output << "      <Filter>Source Files</Filter>" << std::endl;
        output << "    </ClCompile>" << std::endl;
        output << "  </ItemGroup>" << std::endl;
    }
    output << "</Project>";
}

}

void MSBuildFiltersFile::create(const boost::filesystem::path& path, Ishiko::Error& error)
{
    std::ofstream file(path.string());
    if (FailOnFileCreationError(error, file))
    {
        return;
    }

    Write(file, m_headerFiles, m_sourceFiles);
    
    m_path = path;
}

void MSBuildFiltersFile::addHeaderFile(const std::string& path)
{
    m_headerFiles.emplace_back(path);
}

void MSBuildFiltersFile::addSourceFile(const std::string& path)
{
    m_sourceFiles.emplace_back(path);
}

void MSBuildFiltersFile::commit()
{
    std::ofstream file(m_path.string());
    Write(file, m_headerFiles, m_sourceFiles);
}

}
