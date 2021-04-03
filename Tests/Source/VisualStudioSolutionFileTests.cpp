/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "VisualStudioSolutionFileTests.h"
#include "CodeSmithy/BuildFiles/VisualStudioSolutionFile.h"
#include <Ishiko/UUIDs/PrecomputedUUIDGenerator.h>

using namespace CodeSmithy;
using namespace Ishiko;
using namespace Ishiko::Tests;
using namespace Ishiko::UUIDs;

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

    PrecomputedUUIDGenerator uuidGenerator(
        {"f36308cc-b212-4159-b35f-1ab881130689", "a84d6d42-2a06-4ae4-93f4-57a1d1befe2f" });

    VisualStudioSolutionFile solutionFile;

    Error error;
    solutionFile.create(outputPath, uuidGenerator, error);

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

    PrecomputedUUIDGenerator uuidGenerator(
        {"ccbf91ad-0cc4-4005-be29-f72251f0383d", "0fc49f24-86ed-421e-b72a-3cf918c2c879" });

    VisualStudioSolutionFile solutionFile;

    Error error;
    solutionFile.create(outputPath, uuidGenerator, error);

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(
        test.environment().getReferenceDataPath("VisualStudio/VS2019EmptyCppProject2/VS2019EmptyCppProject.sln"));

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}
