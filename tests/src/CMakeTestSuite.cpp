// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CMakeTestSuite.hpp"
#include "CMakeTestSuite/CMakeListsWriterTests.hpp"

CMakeTestSuite::CMakeTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : Ishiko::TestSequence(number, "CMake test suite", context)
{
    append<CMakeListsWriterTests>();
}
