// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeTestSuite.hpp"
#include "NuimeTestSuite/NuimeBuildFileTests.hpp"

NuimeTestSuite::NuimeTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : Ishiko::TestSequence(number, "Nuime test suite", context)
{
    append<NuimeBuildFileTests>();
}
