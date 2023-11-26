/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-files/blob/main/LICENSE.txt
*/

#include "BakefileTestSuite.hpp"

#include "BakefileTestSuite/BakefileTargetTests.h"
#include "BakefileTestSuite/BakefileTests.h"
#include "BakefileTestSuite/BakefileTokenTests.h"
#include "BakefileTestSuite/BakefileTokenizerTests.h"
#include "BakefileTestSuite/BakefileParserTests.h"

BakefileTestSuite::BakefileTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : Ishiko::TestSequence(number, "Bakefile test suite", context)
{
    append<BakefileTargetTests>();
    append<BakefileTests>();
    append<BakefileTokenTests>();
    append<BakefileTokenizerTests>();
    append<BakefileParserTests>();
}
