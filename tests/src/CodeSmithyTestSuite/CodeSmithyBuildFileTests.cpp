// SPDX-FileCopyrightText: 2016-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CodeSmithyBuildFileTests.hpp"
#include "CodeSmithy/BuildFiles/CodeSmithy/CodeSmithyBuildFile.hpp"

using namespace CodeSmithy;
using namespace boost::filesystem;

CodeSmithyProjectFileTests::CodeSmithyProjectFileTests(const Ishiko::TestNumber& number,
    const Ishiko::TestContext& context)
    : TestSequence(number, "CodeSmithyProjectFile tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void CodeSmithyProjectFileTests::ConstructorTest1(Ishiko::Test& test)
{
    CodeSmithyProjectFile project_file;

    ISHIKO_TEST_PASS();
}
