// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeTargetTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeTarget.hpp"

using namespace Nuime;

NuimeTargetTests::NuimeTargetTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeTarget tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void NuimeTargetTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeTarget target("lib");

    ISHIKO_TEST_FAIL_IF_NEQ(target.asString(), "lib");
    ISHIKO_TEST_PASS();
}
