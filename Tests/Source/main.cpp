/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "MSBuildProjectFileTests.h"
#include "MSBuildFiltersFileTests.h"
#include "VisualStudioSolutionFileTests.h"
#include <Ishiko/TestFramework/TestFrameworkCore.h>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("CodeSmithyBuildFiles");

    theTestHarness.environment().setTestOutputDirectory("../../TestOutput");
    theTestHarness.environment().setReferenceDataDirectory("../../ReferenceData");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<MSBuildProjectFileTests>();
    theTests.append<MSBuildFiltersFileTests>();
    theTests.append<VisualStudioSolutionFileTests>();

    return theTestHarness.run();
}
