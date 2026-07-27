// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "MSBuildTestSuite.hpp"
#include "MSBuildTestSuite/MSBuildProjectFileTests.h"
#include "MSBuildTestSuite/MSBuildFiltersFileTests.h"

MSBuildTestSuite::MSBuildTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : Ishiko::TestSequence(number, "MSBuild test suite", context)
{
    append<MSBuildProjectFileTests>();
    append<MSBuildFiltersFileTests>();
}
