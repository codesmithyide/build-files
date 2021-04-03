/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "MSBuildFiltersFileTests.h"
#include "CodeSmithy/BuildFiles/MSBuildFiltersFile.h"

using namespace CodeSmithy;
using namespace Ishiko::Tests;

MSBuildFiltersFileTests::MSBuildFiltersFileTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "MSBuildFiltersFile tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void MSBuildFiltersFileTests::ConstructorTest1(Test& test)
{
    MSBuildFiltersFile projectFile;

    ISHTF_PASS();
}
