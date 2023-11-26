/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-files/blob/main/LICENSE.txt
*/

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_TESTS_MSBUILDTESTSUITE_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_TESTS_MSBUILDTESTSUITE_HPP

#include <Ishiko/TestFramework.hpp>

class MSBuildTestSuite : public Ishiko::TestSequence
{
public:
    MSBuildTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);
};

#endif
