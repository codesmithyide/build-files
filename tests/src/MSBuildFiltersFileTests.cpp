/*
    Copyright (c) 2021-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "MSBuildFiltersFileTests.h"
#include "CodeSmithy/BuildFiles/MSBuild/MSBuildFiltersFile.hpp"

using namespace CodeSmithy;
using namespace Ishiko;

MSBuildFiltersFileTests::MSBuildFiltersFileTests(const TestNumber& number, const TestContext& environment)
    : TestSequence(number, "MSBuildFiltersFile tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("create test 1", CreateTest1);
    append<HeapAllocationErrorsTest>("create test 2", CreateTest2);
    append<HeapAllocationErrorsTest>("addSourceFile test 1", AddSourceFileTest1);
    append<HeapAllocationErrorsTest>("addHeaderFile test 1", AddHeaderFileTest1);
    append<HeapAllocationErrorsTest>("addHeaderFile and addSourceFile test 1", AddHeaderAndSourceFilesTest1);
}

void MSBuildFiltersFileTests::ConstructorTest1(Test& test)
{
    MSBuildFiltersFile filtersFile;

    ISHIKO_TEST_PASS();
}

void MSBuildFiltersFileTests::CreateTest1(Test& test)
{
    boost::filesystem::path outputPath = test.context().getOutputPath(
        "MSBuildFiltersFileTests_CreateTest1.vcxproj.filters");

    MSBuildFiltersFile filtersFile;

    Error error;
    filtersFile.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputPath,
        "VisualStudio/VS2019EmptyCppProject1/VS2019EmptyCppProject/VS2019EmptyCppProject.vcxproj.filters");
    ISHIKO_TEST_PASS();
}

void MSBuildFiltersFileTests::CreateTest2(Test& test)
{
    boost::filesystem::path outputPath = test.context().getOutputPath(
        "MSBuildFiltersFileTests_CreateTest2.vcxproj.filters");

    MSBuildFiltersFile filtersFile;

    Error error;
    filtersFile.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputPath,
        "VisualStudio/VS2019EmptyCppProject2/VS2019EmptyCppProject/VS2019EmptyCppProject.vcxproj.filters");
    ISHIKO_TEST_PASS();
}

void MSBuildFiltersFileTests::AddSourceFileTest1(Test& test)
{
    boost::filesystem::path outputPath = test.context().getOutputPath(
        "MSBuildFiltersFileTests_AddSourceFileTest1.vcxproj.filters");

    MSBuildFiltersFile filtersFile;

    Error error;
    filtersFile.create(outputPath, error);
    filtersFile.addSourceFile("main.cpp");
    filtersFile.commit();

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputPath,
        "VisualStudio/VS2019CppProjectOneSourceFile/VS2019CppProjectOneSourceFile/VS2019CppProjectOneSourceFile.vcxproj.filters");
    ISHIKO_TEST_PASS();
}

void MSBuildFiltersFileTests::AddHeaderFileTest1(Test& test)
{
    boost::filesystem::path outputPath = test.context().getOutputPath(
        "MSBuildFiltersFileTests_AddHeaderFileTest1.vcxproj.filters");

    MSBuildFiltersFile filtersFile;

    Error error;
    filtersFile.create(outputPath, error);
    filtersFile.addHeaderFile("Header.h");
    filtersFile.commit();

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputPath,
        "VisualStudio/VS2019CppProjectOneHeaderFile/VS2019CppProjectOneHeaderFile/VS2019CppProjectOneHeaderFile.vcxproj.filters");
    ISHIKO_TEST_PASS();
}

void MSBuildFiltersFileTests::AddHeaderAndSourceFilesTest1(Test& test)
{
    boost::filesystem::path outputPath = test.context().getOutputPath(
        "MSBuildFiltersFileTests_AddHeaderAndSourceFilesTest1.vcxproj.filters");

    MSBuildFiltersFile filtersFile;

    Error error;
    filtersFile.create(outputPath, error);
    filtersFile.addHeaderFile("Header1.h");
    filtersFile.addHeaderFile("Header2.h");
    filtersFile.addSourceFile("Source1.cpp");
    filtersFile.addSourceFile("Source2.cpp");
    filtersFile.commit();

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputPath,
        "VisualStudio/VS2019CppProjectMultipleFiles/VS2019CppProjectMultipleFiles/VS2019CppProjectMultipleFiles.vcxproj.filters");
    ISHIKO_TEST_PASS();
}
