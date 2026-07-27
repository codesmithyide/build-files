// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeInputTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeInput.hpp"

using namespace Nuime;

NuimeInputTests::NuimeInputTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeInput tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void NuimeInputTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeInput input;

    ISHIKO_TEST_PASS();
}
