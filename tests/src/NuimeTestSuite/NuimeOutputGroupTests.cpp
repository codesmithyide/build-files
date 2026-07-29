// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeOutputGroupTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeOutputGroup.hpp"

using namespace Nuime;

NuimeOutputGroupTests::NuimeOutputGroupTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeOutputGroup tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void NuimeOutputGroupTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeOutputGroup output_group;

    ISHIKO_TEST_PASS();
}
