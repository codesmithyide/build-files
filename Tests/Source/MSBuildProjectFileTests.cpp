/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "MSBuildProjectFileTests.h"
#include "CodeSmithy/BuildFiles/MSBuildProjectFile.h"
#include <Ishiko/UUIDs/PrecomputedUUIDGenerator.h>

using namespace CodeSmithy;
using namespace Ishiko;
using namespace Ishiko::Tests;
using namespace Ishiko::UUIDs;

MSBuildProjectFileTests::MSBuildProjectFileTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "MSBuildProjectFile tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<FileComparisonTest>("create test 1", CreateTest1);
    append<FileComparisonTest>("create test 2", CreateTest2);
}

void MSBuildProjectFileTests::ConstructorTest1(Test& test)
{
    MSBuildProjectFile projectFile;

    ISHTF_FAIL_IF_NEQ(projectFile.name(), "");
    ISHTF_FAIL_IF_NOT(projectFile.guid().isNil());
    ISHTF_FAIL_IF_NEQ(projectFile.path(), "");
    ISHTF_PASS();
}

void MSBuildProjectFileTests::CreateTest1(FileComparisonTest& test)
{
    boost::filesystem::path outputPath = test.environment().getTestOutputPath(
        "MSBuildProjectFileTests_CreateTest1.vcxproj");

    PrecomputedUUIDGenerator uuidGenerator({"f36308cc-b212-4159-b35f-1ab881130689"});

    MSBuildProjectFile projectFile;

    Error error;
    projectFile.create(outputPath, "VS2019EmptyCppProject", uuidGenerator, error);

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.environment().getReferenceDataPath(
        "VisualStudio/VS2019EmptyCppProject1/VS2019EmptyCppProject/VS2019EmptyCppProject.vcxproj"));

    ISHTF_FAIL_IF(error);
    ISHTF_FAIL_IF_NEQ(projectFile.name(), "VS2019EmptyCppProject");
    ISHTF_FAIL_IF_NEQ(projectFile.guid(), "f36308cc-b212-4159-b35f-1ab881130689");
    ISHTF_FAIL_IF_NEQ(projectFile.path(), outputPath);
    ISHTF_PASS();
}

void MSBuildProjectFileTests::CreateTest2(FileComparisonTest& test)
{
    boost::filesystem::path outputPath = test.environment().getTestOutputPath(
        "MSBuildProjectFileTests_CreateTest2.vcxproj");

    PrecomputedUUIDGenerator uuidGenerator({"ccbf91ad-0cc4-4005-be29-f72251f0383d"});

    MSBuildProjectFile projectFile;

    Error error;
    projectFile.create(outputPath, "VS2019EmptyCppProject", uuidGenerator, error);

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.environment().getReferenceDataPath(
        "VisualStudio/VS2019EmptyCppProject2/VS2019EmptyCppProject/VS2019EmptyCppProject.vcxproj"));

    ISHTF_FAIL_IF(error);
    ISHTF_FAIL_IF_NEQ(projectFile.name(), "VS2019EmptyCppProject");
    ISHTF_FAIL_IF_NEQ(projectFile.guid(), "ccbf91ad-0cc4-4005-be29-f72251f0383d");
    ISHTF_FAIL_IF_NEQ(projectFile.path(), outputPath);
    ISHTF_PASS();
}
