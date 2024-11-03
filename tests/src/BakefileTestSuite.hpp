// SPDX-FileCopyrightText: 2017-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_TESTS_BAKEFILETESTSUITE_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_TESTS_BAKEFILETESTSUITE_HPP

#include <Ishiko/TestFramework.hpp>

class BakefileTestSuite : public Ishiko::TestSequence
{
public:
    BakefileTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);
};

#endif
