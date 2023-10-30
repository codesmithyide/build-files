/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "VisualStudioSolutionFileTests.h"
#include "CodeSmithy/BuildFiles/MSBuildProjectFile.h"
#include "CodeSmithy/BuildFiles/VisualStudioSolutionFile.h"
#include <Ishiko/UUIDs/PrecomputedUUIDGenerator.h>
#include <boost/filesystem/operations.hpp>

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
    append<FileComparisonTest>("create test 3", CreateTest3);
    append<FileComparisonTest>("create test 4", CreateTest4);
    append<FileComparisonTest>("create test 5", CreateTest5);
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

    PrecomputedUUIDGenerator uuidGenerator({"43bd9e93-d09a-4e66-9ff1-770ecb43c1b7"});

    VisualStudioSolutionFile solutionFile;

    Error error;
    solutionFile.create(outputPath, uuidGenerator, error);

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(
        test.environment().getReferenceDataPath("VisualStudio/VS2019BlankSolution/BlankSolution.sln"));

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}

void VisualStudioSolutionFileTests::CreateTest2(FileComparisonTest& test)
{
    boost::filesystem::path projectOutputPath = test.environment().getTestOutputPath(
        "VisualStudioSolutionFileTests_CreateTest2/VS2019EmptyCppProject/VS2019EmptyCppProject.vcxproj");
    boost::filesystem::create_directories(projectOutputPath.parent_path());
    boost::filesystem::path solutionOutputPath = test.environment().getTestOutputPath(
        "VisualStudioSolutionFileTests_CreateTest2/VS2019EmptyCppProject.sln");

    PrecomputedUUIDGenerator uuidGenerator(
        { "f36308cc-b212-4159-b35f-1ab881130689", "a84d6d42-2a06-4ae4-93f4-57a1d1befe2f" });

    Error error;
    MSBuildProjectFile projectFile;
    projectFile.create(projectOutputPath, "VS2019EmptyCppProject", uuidGenerator, error);

    ISHTF_ABORT_IF(error);

    VisualStudioSolutionFile solutionFile;

    solutionFile.create(solutionOutputPath, projectFile, uuidGenerator, error);

    test.setOutputFilePath(solutionOutputPath);
    test.setReferenceFilePath(
        test.environment().getReferenceDataPath("VisualStudio/VS2019EmptyCppProject1/VS2019EmptyCppProject.sln"));

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}

void VisualStudioSolutionFileTests::CreateTest3(FileComparisonTest& test)
{
    boost::filesystem::path projectOutputPath = test.environment().getTestOutputPath(
        "VisualStudioSolutionFileTests_CreateTest3/VS2019EmptyCppProject/VS2019EmptyCppProject.vcxproj");
    boost::filesystem::create_directories(projectOutputPath.parent_path());
    boost::filesystem::path solutionOutputPath = test.environment().getTestOutputPath(
        "VisualStudioSolutionFileTests_CreateTest3/VS2019EmptyCppProject.sln");

    PrecomputedUUIDGenerator uuidGenerator(
        { "ccbf91ad-0cc4-4005-be29-f72251f0383d", "0fc49f24-86ed-421e-b72a-3cf918c2c879" });

    Error error;
    MSBuildProjectFile projectFile;
    projectFile.create(projectOutputPath, "VS2019EmptyCppProject", uuidGenerator, error);

    ISHTF_ABORT_IF(error);

    VisualStudioSolutionFile solutionFile;

    solutionFile.create(solutionOutputPath, projectFile, uuidGenerator, error);

    test.setOutputFilePath(solutionOutputPath);
    test.setReferenceFilePath(
        test.environment().getReferenceDataPath("VisualStudio/VS2019EmptyCppProject2/VS2019EmptyCppProject.sln"));

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}

void VisualStudioSolutionFileTests::CreateTest4(FileComparisonTest& test)
{
    boost::filesystem::path projectOutputPath = test.environment().getTestOutputPath(
        "VisualStudioSolutionFileTests_CreateTest4/VS2019CppProjectOneSourceFile/VS2019CppProjectOneSourceFile.vcxproj");
    boost::filesystem::create_directories(projectOutputPath.parent_path());
    boost::filesystem::path solutionOutputPath = test.environment().getTestOutputPath(
        "VisualStudioSolutionFileTests_CreateTest4/VS2019CppProjectOneSourceFile.sln");

    PrecomputedUUIDGenerator uuidGenerator(
        { "e64cb64d-8de9-4788-87df-f2ec55ab77c4", "167f186e-b706-42d0-912d-611e82e08e83" });

    Error error;
    MSBuildProjectFile projectFile;
    projectFile.create(projectOutputPath, "VS2019CppProjectOneSourceFile", uuidGenerator, error);

    ISHTF_ABORT_IF(error);

    VisualStudioSolutionFile solutionFile;

    solutionFile.create(solutionOutputPath, projectFile, uuidGenerator, error);

    test.setOutputFilePath(solutionOutputPath);
    test.setReferenceFilePath(
        test.environment().getReferenceDataPath(
            "VisualStudio/VS2019CppProjectOneSourceFile/VS2019CppProjectOneSourceFile.sln"));

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}

void VisualStudioSolutionFileTests::CreateTest5(FileComparisonTest& test)
{
    boost::filesystem::path projectOutputPath = test.environment().getTestOutputPath(
        "VisualStudioSolutionFileTests_CreateTest5/VS2019CppProjectOneHeaderFile/VS2019CppProjectOneHeaderFile.vcxproj");
    boost::filesystem::create_directories(projectOutputPath.parent_path());
    boost::filesystem::path solutionOutputPath = test.environment().getTestOutputPath(
        "VisualStudioSolutionFileTests_CreateTest5/VS2019CppProjectOneHeaderFile.sln");

    PrecomputedUUIDGenerator uuidGenerator(
        { "15600bbd-c6ad-4e80-b7c9-28bca1cf6970", "8793b1ee-ce48-4565-8369-0996a24ea272" });

    Error error;
    MSBuildProjectFile projectFile;
    projectFile.create(projectOutputPath, "VS2019CppProjectOneHeaderFile", uuidGenerator, error);

    ISHTF_ABORT_IF(error);

    VisualStudioSolutionFile solutionFile;

    solutionFile.create(solutionOutputPath, projectFile, uuidGenerator, error);

    test.setOutputFilePath(solutionOutputPath);
    test.setReferenceFilePath(
        test.environment().getReferenceDataPath(
            "VisualStudio/VS2019CppProjectOneHeaderFile/VS2019CppProjectOneHeaderFile.sln"));

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}
