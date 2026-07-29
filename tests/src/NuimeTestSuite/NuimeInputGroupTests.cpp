// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeInputGroupTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeInputGroup.hpp"

using namespace Nuime;

NuimeInputGroupTests::NuimeInputGroupTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeInputGroup tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void NuimeInputGroupTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeInputGroup input_group;

    ISHIKO_TEST_PASS();
}
