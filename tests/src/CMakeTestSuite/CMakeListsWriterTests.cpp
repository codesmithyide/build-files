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
}

void CMakeListsWriterTests::ConstructorTest1(Ishiko::Test& test)
{
    CMakeListsWriter cmakelists_writer;

    ISHIKO_TEST_PASS();
}
