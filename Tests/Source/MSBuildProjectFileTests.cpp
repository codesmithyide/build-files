/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "MSBuildProjectFileTests.h"
#include "CodeSmithy/BuildFiles/MSBuildProjectFile.h"

using namespace Ishiko::Tests;

MSBuildProjectFileTests::MSBuildProjectFileTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "MSBuildProjectFile tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void MSBuildProjectFileTests::ConstructorTest1(Test& test)
{
    CodeSmithy::MSBuildProjectFile projectFile;

    ISHTF_PASS();
}
