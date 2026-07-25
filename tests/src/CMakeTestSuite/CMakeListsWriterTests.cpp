// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CMakeListsWriterTests.hpp"
#include "CodeSmithy/BuildFiles/CMake/CMakeListsWriter.hpp"

using namespace CodeSmithy;
using namespace boost::filesystem;

CMakeListsWriterTests::CMakeListsWriterTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "CMakeListsWriter tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("writeCMakeMinimumRequiredCommand test 1",
        WriteCMakeMinimumRequiredCommandTest1);
    append<Ishiko::HeapAllocationErrorsTest>("writeProjectCommand test 1", WriteProjectCommandTest1);
    append<Ishiko::HeapAllocationErrorsTest>("writeAddLibraryCommand test 1", WriteAddLibraryCommandTest1);
    append<Ishiko::HeapAllocationErrorsTest>("writeAddLibraryCommand test 2", WriteAddLibraryCommandTest2);
}

void CMakeListsWriterTests::ConstructorTest1(Ishiko::Test& test)
{
    const path output_path = test.context().getOutputPath("CMakeListsWriterTests_ConstructorTest1.txt");

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteCMakeMinimumRequiredCommandTest1(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteCMakeMinimumRequiredCommandTest1.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeCMakeMinimumRequiredCommand("3.10");

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteProjectCommandTest1(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteProjectCommandTest1.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeProjectCommand("MyProject");

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteAddLibraryCommandTest1(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteAddLibraryCommandTest1.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeAddLibraryCommand("MyLibrary", {});

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteAddLibraryCommandTest2(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteAddLibraryCommandTest2.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeAddLibraryCommand("MyLibrary", {"source1.cpp", "source2.cpp"});

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}
