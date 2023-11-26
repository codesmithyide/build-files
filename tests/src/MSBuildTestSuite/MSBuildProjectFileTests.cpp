/*
    Copyright (c) 2020-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "MSBuildProjectFileTests.h"
#include "CodeSmithy/BuildFiles/MSBuild/MSBuildProjectFile.hpp"
#include <Ishiko/UUIDs.hpp>

using namespace CodeSmithy;
using namespace Ishiko;

MSBuildProjectFileTests::MSBuildProjectFileTests(const TestNumber& number, const TestContext& environment)
    : TestSequence(number, "MSBuildProjectFile tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("create test 1", CreateTest1);
    append<HeapAllocationErrorsTest>("create test 2", CreateTest2);
    append<HeapAllocationErrorsTest>("addSourceFile test 1", AddSourceFileTest1);
    append<HeapAllocationErrorsTest>("addHeaderFile test 1", AddHeaderFileTest1);
    append<HeapAllocationErrorsTest>("addHeaderFile and addSourceFile test 1", AddHeaderAndSourceFilesTest1);
}

void MSBuildProjectFileTests::ConstructorTest1(Test& test)
{
    MSBuildProjectFile projectFile;

    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.name(), "");
    ISHIKO_TEST_FAIL_IF_NOT(projectFile.guid().isNil());
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.path(), "");
    ISHIKO_TEST_PASS();
}

void MSBuildProjectFileTests::CreateTest1(Test& test)
{
    boost::filesystem::path outputPath = test.context().getOutputPath(
        "MSBuildProjectFileTests_CreateTest1.vcxproj");

    PrecomputedUUIDGenerator uuidGenerator({"f36308cc-b212-4159-b35f-1ab881130689"});

    MSBuildProjectFile projectFile;

    Error error;
    projectFile.create(outputPath, "VS2019EmptyCppProject", uuidGenerator, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.name(), "VS2019EmptyCppProject");
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.guid(), "f36308cc-b212-4159-b35f-1ab881130689");
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.path(), outputPath);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputPath,
        "VisualStudio/VS2019EmptyCppProject1/VS2019EmptyCppProject/VS2019EmptyCppProject.vcxproj");
    ISHIKO_TEST_PASS();
}

void MSBuildProjectFileTests::CreateTest2(Test& test)
{
    boost::filesystem::path outputPath = test.context().getOutputPath(
        "MSBuildProjectFileTests_CreateTest2.vcxproj");

    PrecomputedUUIDGenerator uuidGenerator({"ccbf91ad-0cc4-4005-be29-f72251f0383d"});

    MSBuildProjectFile projectFile;

    Error error;
    projectFile.create(outputPath, "VS2019EmptyCppProject", uuidGenerator, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.name(), "VS2019EmptyCppProject");
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.guid(), "ccbf91ad-0cc4-4005-be29-f72251f0383d");
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.path(), outputPath);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputPath,
        "VisualStudio/VS2019EmptyCppProject2/VS2019EmptyCppProject/VS2019EmptyCppProject.vcxproj");
    ISHIKO_TEST_PASS();
}

void MSBuildProjectFileTests::AddSourceFileTest1(Test& test)
{
    boost::filesystem::path outputPath = test.context().getOutputPath(
        "MSBuildProjectFileTests_AddSourceFileTest1.vcxproj");

    PrecomputedUUIDGenerator uuidGenerator({"e64cb64d-8de9-4788-87df-f2ec55ab77c4"});

    Error error;
    MSBuildProjectFile projectFile;
    projectFile.create(outputPath, "VS2019CppProjectOneSourceFile", uuidGenerator, error);
    projectFile.addSourceFile("main.cpp");
    projectFile.commit();

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.name(), "VS2019CppProjectOneSourceFile");
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.guid(), "e64cb64d-8de9-4788-87df-f2ec55ab77c4");
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.path(), outputPath);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputPath,
        "VisualStudio/VS2019CppProjectOneSourceFile/VS2019CppProjectOneSourceFile/VS2019CppProjectOneSourceFile.vcxproj");
    ISHIKO_TEST_PASS();
}

void MSBuildProjectFileTests::AddHeaderFileTest1(Test& test)
{
    boost::filesystem::path outputPath = test.context().getOutputPath(
        "MSBuildProjectFileTests_AddHeaderFileTest1.vcxproj");

    PrecomputedUUIDGenerator uuidGenerator({ "15600bbd-c6ad-4e80-b7c9-28bca1cf6970" });

    Error error;
    MSBuildProjectFile projectFile;
    projectFile.create(outputPath, "VS2019CppProjectOneHeaderFile", uuidGenerator, error);
    projectFile.addHeaderFile("Header.h");
    projectFile.commit();

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.name(), "VS2019CppProjectOneHeaderFile");
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.guid(), "15600bbd-c6ad-4e80-b7c9-28bca1cf6970");
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.path(), outputPath);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputPath,
        "VisualStudio/VS2019CppProjectOneHeaderFile/VS2019CppProjectOneHeaderFile/VS2019CppProjectOneHeaderFile.vcxproj");
    ISHIKO_TEST_PASS();
}

void MSBuildProjectFileTests::AddHeaderAndSourceFilesTest1(Test& test)
{
    boost::filesystem::path outputPath = test.context().getOutputPath(
        "MSBuildProjectFileTests_AddHeaderAndSourceFilesTest1.vcxproj");

    PrecomputedUUIDGenerator uuidGenerator({ "fd8d6e70-1327-4454-8c04-4a619b59a896" });

    Error error;
    MSBuildProjectFile projectFile;
    projectFile.create(outputPath, "VS2019CppProjectMultipleFiles", uuidGenerator, error);
    projectFile.addHeaderFile("Header1.h");
    projectFile.addHeaderFile("Header2.h");
    projectFile.addSourceFile("Source1.cpp");
    projectFile.addSourceFile("Source2.cpp");
    projectFile.commit();

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.name(), "VS2019CppProjectMultipleFiles");
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.guid(), "fd8d6e70-1327-4454-8c04-4a619b59a896");
    ISHIKO_TEST_FAIL_IF_NEQ(projectFile.path(), outputPath);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputPath,
        "VisualStudio/VS2019CppProjectMultipleFiles/VS2019CppProjectMultipleFiles/VS2019CppProjectMultipleFiles.vcxproj");
    ISHIKO_TEST_PASS();
}
