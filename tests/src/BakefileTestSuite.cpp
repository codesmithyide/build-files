// SPDX-FileCopyrightText: 2017-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "BakefileTestSuite.hpp"
#include "BakefileTestSuite/BakefileTargetTests.h"
#include "BakefileTestSuite/BakefileTests.h"
#include "BakefileTestSuite/BakefileTokenTests.h"
#include "BakefileTestSuite/BakefileTokenizerTests.h"
#include "BakefileTestSuite/BakefilePushParserTests.hpp"

BakefileTestSuite::BakefileTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : Ishiko::TestSequence(number, "Bakefile test suite", context)
{
    append<BakefileTargetTests>();
    append<BakefileTests>();
    append<BakefileTokenTests>();
    append<BakefileTokenizerTests>();
    append<BakefilePushParserTests>();
}
