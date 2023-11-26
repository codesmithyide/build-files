/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-files/blob/main/LICENSE.txt
*/

#include "MSBuildTestSuite.hpp"
#include "MSBuildTestSuite/MSBuildProjectFileTests.h"
#include "MSBuildTestSuite/MSBuildFiltersFileTests.h"

MSBuildTestSuite::MSBuildTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : Ishiko::TestSequence(number, "MSBuild test suite", context)
{
    append<MSBuildProjectFileTests>();
    append<MSBuildFiltersFileTests>();
}
