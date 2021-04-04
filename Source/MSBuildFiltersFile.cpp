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

void MSBuildFiltersFile::create(const boost::filesystem::path& path, Ishiko::Error& error)
{
    std::ofstream file(path.string());
    if (FailOnFileCreationError(error, file))
    {
        return;
    }

    file << "\xEF\xBB\xBF<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
    file << "<Project ToolsVersion=\"4.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">" << std::endl;
    file << "  <ItemGroup>" << std::endl;
    file << "    <Filter Include=\"Source Files\">" << std::endl;
    file << "      <UniqueIdentifier>{4FC737F1-C7A5-4376-A066-2A32D752A2FF}</UniqueIdentifier>" << std::endl;
    file << "      <Extensions>cpp;c;cc;cxx;c++;cppm;ixx;def;odl;idl;hpj;bat;asm;asmx</Extensions>" << std::endl;
    file << "    </Filter>" << std::endl;
    file << "    <Filter Include=\"Header Files\">" << std::endl;
    file << "      <UniqueIdentifier>{93995380-89BD-4b04-88EB-625FBE52EBFB}</UniqueIdentifier>" << std::endl;
    file << "      <Extensions>h;hh;hpp;hxx;h++;hm;inl;inc;ipp;xsd</Extensions>" << std::endl;
    file << "    </Filter>" << std::endl;
    file << "    <Filter Include=\"Resource Files\">" << std::endl;
    file << "      <UniqueIdentifier>{67DA6AB6-F800-4c08-8B7A-83BB121AAD01}</UniqueIdentifier>" << std::endl;
    file << "      <Extensions>rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx;tiff;tif;png;wav;mfcribbon-ms</Extensions>" << std::endl;
    file << "    </Filter>" << std::endl;
    file << "  </ItemGroup>" << std::endl;
    file << "</Project>";
}

}
