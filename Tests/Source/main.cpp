/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "MSBuildProjectFileTests.h"
#include "VisualStudioSolutionFileTests.h"
#include <Ishiko/TestFramework/TestFrameworkCore.h>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("CodeSmithyBuildFiles");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<MSBuildProjectFileTests>();
    theTests.append<VisualStudioSolutionFileTests>();

    return theTestHarness.run();
}
