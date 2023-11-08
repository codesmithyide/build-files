/*
    Copyright (c) 2020-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "MSBuildProjectFileTests.h"
#include "MSBuildFiltersFileTests.h"
#include "VisualStudioSolutionFileTests.h"
#include "CodeSmithy/BuildFiles/linkoptions.h"
#include <Ishiko/TestFramework.hpp>

int main(int argc, char* argv[])
{
    Ishiko::TestHarness theTestHarness("CodeSmithyBuildFiles");

    theTestHarness.context().setOutputDirectory("../../TestOutput");
    theTestHarness.context().setReferenceDirectory("../../ReferenceData");

    Ishiko::TestSequence& theTests = theTestHarness.tests();
    theTests.append<MSBuildProjectFileTests>();
    theTests.append<MSBuildFiltersFileTests>();
    theTests.append<VisualStudioSolutionFileTests>();

    return theTestHarness.run();
}
