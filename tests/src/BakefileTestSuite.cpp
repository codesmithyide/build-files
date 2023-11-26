/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-files/blob/main/LICENSE.txt
*/

#include "BakefileTestSuite.hpp"

#include "BakefileTests/BakefileTargetTests.h"
#include "BakefileTests/BakefileTests.h"
#include "BakefileTests/BakefileTokenTests.h"
#include "BakefileTests/BakefileTokenizerTests.h"
#include "BakefileTests/BakefileParserTests.h"

BakefileTestSuite::BakefileTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : Ishiko::TestSequence(number, "Bakefile test suite", context)
{
    append<BakefileTargetTests>();
    append<BakefileTests>();
    append<BakefileTokenTests>();
    append<BakefileTokenizerTests>();
    append<BakefileParserTests>();
}
