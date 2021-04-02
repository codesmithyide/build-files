/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "VisualStudioSolutionFileTests.h"
#include "CodeSmithy/BuildFiles/VisualStudioSolutionFile.h"

using namespace Ishiko::Tests;

VisualStudioSolutionFileTests::VisualStudioSolutionFileTests(const TestNumber& number,
    const TestEnvironment& environment)
    : TestSequence(number, "VisualStudioSolutionFile tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void VisualStudioSolutionFileTests::ConstructorTest1(Test& test)
{
    CodeSmithy::VisualStudioSolutionFile solutionFile;

    ISHTF_PASS();
}
