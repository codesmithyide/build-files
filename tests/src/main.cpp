// SPDX-FileCopyrightText: 2017-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "BakefileTestSuite.hpp"
#include "CodeSmithyTestSuite.hpp"
#include "MSBuildTestSuite.hpp"
#include "VisualStudioSolutionFileTests.h"
#include "CodeSmithy/BuildFiles/linkoptions.hpp"
#include <Ishiko/TestFramework.hpp>

int main(int argc, char* argv[])
{
    Ishiko::TestHarness::CommandLineSpecification commandLineSpec;
    Ishiko::Configuration configuration = commandLineSpec.createDefaultConfiguration();
    configuration.set("context.data", "../../data");
    configuration.set("context.output", "../../output");
    configuration.set("context.reference", "../../reference");
    Ishiko::CommandLineParser::parse(commandLineSpec, argc, argv, configuration);

    Ishiko::TestHarness theTestHarness("CodeSmithyBuildFiles", configuration);

    Ishiko::TestSequence& theTests = theTestHarness.tests();
    theTests.append<BakefileTestSuite>();
    theTests.append<CodeSmithyTestSuite>();
    theTests.append<MSBuildTestSuite>();
    theTests.append<VisualStudioSolutionFileTests>();

    return theTestHarness.run();
}
