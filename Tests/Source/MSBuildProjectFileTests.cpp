/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "MSBuildProjectFileTests.h"
#include "CodeSmithy/BuildFiles/MSBuildProjectFile.h"

using namespace CodeSmithy;
using namespace Ishiko;
using namespace Ishiko::Tests;

MSBuildProjectFileTests::MSBuildProjectFileTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "MSBuildProjectFile tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<FileComparisonTest>("create test 1", CreateTest1);
}

void MSBuildProjectFileTests::ConstructorTest1(Test& test)
{
    MSBuildProjectFile projectFile;

    ISHTF_PASS();
}

void MSBuildProjectFileTests::CreateTest1(FileComparisonTest& test)
{
    boost::filesystem::path outputPath = test.environment().getTestOutputPath(
        "MSBuildProjectFileTests_CreateTest1.sln");

    MSBuildProjectFile projectFile;

    Error error;
    projectFile.create(outputPath, error);

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.environment().getReferenceDataPath(
        "VisualStudio/VS2019EmptyCppProject/VS2019EmptyCppProject/VS2019EmptyCppProject.vcxproj"));

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}
