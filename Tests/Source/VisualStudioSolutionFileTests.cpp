/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "VisualStudioSolutionFileTests.h"
#include "CodeSmithy/BuildFiles/VisualStudioSolutionFile.h"

using namespace CodeSmithy;
using namespace Ishiko;
using namespace Ishiko::Tests;

VisualStudioSolutionFileTests::VisualStudioSolutionFileTests(const TestNumber& number,
    const TestEnvironment& environment)
    : TestSequence(number, "VisualStudioSolutionFile tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<FileComparisonTest>("create test 1", CreateTest1);
    append<FileComparisonTest>("create test 2", CreateTest2);
}

void VisualStudioSolutionFileTests::ConstructorTest1(Test& test)
{
    VisualStudioSolutionFile solutionFile;

    ISHTF_PASS();
}

void VisualStudioSolutionFileTests::CreateTest1(FileComparisonTest& test)
{
    boost::filesystem::path outputPath = test.environment().getTestOutputPath(
        "VisualStudioSolutionFileTests_CreateTest1.sln");

    VisualStudioSolutionFile solutionFile;

    Error error;
    solutionFile.create(outputPath, error);

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(
        test.environment().getReferenceDataPath("VisualStudio/VS2019EmptyCppProject1/VS2019EmptyCppProject.sln"));

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}

void VisualStudioSolutionFileTests::CreateTest2(FileComparisonTest& test)
{
    boost::filesystem::path outputPath = test.environment().getTestOutputPath(
        "VisualStudioSolutionFileTests_CreateTest2.sln");

    VisualStudioSolutionFile solutionFile;

    Error error;
    solutionFile.create(outputPath, error);

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(
        test.environment().getReferenceDataPath("VisualStudio/VS2019EmptyCppProject2/VS2019EmptyCppProject.sln"));

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}
