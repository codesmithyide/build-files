// SPDX-FileCopyrightText: 2017-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_TESTS_CODESMITHYTESTSUITE_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_TESTS_CODESMITHYTESTSUITE_HPP

#include <Ishiko/TestFramework.hpp>

class CodeSmithyTestSuite : public Ishiko::TestSequence
{
public:
    CodeSmithyTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);
};

#endif
