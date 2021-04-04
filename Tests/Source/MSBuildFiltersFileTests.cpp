/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "MSBuildFiltersFileTests.h"
#include "CodeSmithy/BuildFiles/MSBuildFiltersFile.h"

using namespace CodeSmithy;
using namespace Ishiko;
using namespace Ishiko::Tests;

MSBuildFiltersFileTests::MSBuildFiltersFileTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "MSBuildFiltersFile tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<FileComparisonTest>("create test 1", CreateTest1);
    append<FileComparisonTest>("create test 2", CreateTest2);
    append<FileComparisonTest>("addSourceFile test 1", AddSourceFileTest1);
    append<FileComparisonTest>("addHeaderFile test 1", AddHeaderFileTest1);
}

void MSBuildFiltersFileTests::ConstructorTest1(Test& test)
{
    MSBuildFiltersFile filtersFile;

    ISHTF_PASS();
}

void MSBuildFiltersFileTests::CreateTest1(FileComparisonTest& test)
{
    boost::filesystem::path outputPath = test.environment().getTestOutputPath(
        "MSBuildFiltersFileTests_CreateTest1.vcxproj.filters");

    MSBuildFiltersFile filtersFile;

    Error error;
    filtersFile.create(outputPath, error);

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.environment().getReferenceDataPath(
        "VisualStudio/VS2019EmptyCppProject1/VS2019EmptyCppProject/VS2019EmptyCppProject.vcxproj.filters"));

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}

void MSBuildFiltersFileTests::CreateTest2(FileComparisonTest& test)
{
    boost::filesystem::path outputPath = test.environment().getTestOutputPath(
        "MSBuildFiltersFileTests_CreateTest2.vcxproj.filters");

    MSBuildFiltersFile filtersFile;

    Error error;
    filtersFile.create(outputPath, error);

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.environment().getReferenceDataPath(
        "VisualStudio/VS2019EmptyCppProject2/VS2019EmptyCppProject/VS2019EmptyCppProject.vcxproj.filters"));

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}

void MSBuildFiltersFileTests::AddSourceFileTest1(FileComparisonTest& test)
{
    boost::filesystem::path outputPath = test.environment().getTestOutputPath(
        "MSBuildFiltersFileTests_AddSourceFileTest1.vcxproj.filters");

    MSBuildFiltersFile filtersFile;

    Error error;
    filtersFile.create(outputPath, error);
    filtersFile.addSourceFile("main.cpp");
    filtersFile.commit();

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.environment().getReferenceDataPath(
        "VisualStudio/VS2019CppProjectOneSourceFile/VS2019CppProjectOneSourceFile/VS2019CppProjectOneSourceFile.vcxproj.filters"));

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}

void MSBuildFiltersFileTests::AddHeaderFileTest1(FileComparisonTest& test)
{
    boost::filesystem::path outputPath = test.environment().getTestOutputPath(
        "MSBuildFiltersFileTests_AddHeaderFileTest1.vcxproj.filters");

    MSBuildFiltersFile filtersFile;

    Error error;
    filtersFile.create(outputPath, error);
    filtersFile.addHeaderFile("Header.h");
    filtersFile.commit();

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.environment().getReferenceDataPath(
        "VisualStudio/VS2019CppProjectOneHeaderFile/VS2019CppProjectOneHeaderFile/VS2019CppProjectOneHeaderFile.vcxproj.filters"));

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}
