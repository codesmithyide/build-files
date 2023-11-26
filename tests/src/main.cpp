/*
    Copyright (c) 2017-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#include "BakefileTestSuite.hpp"
#include "MSBuildProjectFileTests.h"
#include "MSBuildFiltersFileTests.h"
#include "VisualStudioSolutionFileTests.h"
#include "CodeSmithy/BuildFiles/linkoptions.h"
#include <Ishiko/TestFramework.hpp>

int main(int argc, char* argv[])
{
    Ishiko::TestHarness::CommandLineSpecification commandLineSpec;
    Ishiko::Configuration configuration = commandLineSpec.createDefaultConfiguration();
    Ishiko::CommandLineParser::parse(commandLineSpec, argc, argv, configuration);

    Ishiko::TestHarness theTestHarness("CodeSmithyBuildFiles", configuration);

    theTestHarness.context().setDataDirectory("../../data");
    theTestHarness.context().setOutputDirectory("../../output");
    theTestHarness.context().setReferenceDirectory("../../reference");

    Ishiko::TestSequence& theTests = theTestHarness.tests();
    theTests.append<BakefileTestSuite>();
    theTests.append<MSBuildProjectFileTests>();
    theTests.append<MSBuildFiltersFileTests>();
    theTests.append<VisualStudioSolutionFileTests>();

    return theTestHarness.run();
}
