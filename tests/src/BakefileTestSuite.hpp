/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-files/blob/main/LICENSE.txt
*/

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_TESTS_BAKEFILETESTSUITE_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_TESTS_BAKEFILETESTSUITE_HPP

#include <Ishiko/TestFramework.hpp>

class BakefileTestSuite : public Ishiko::TestSequence
{
public:
    BakefileTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);
};

#endif
