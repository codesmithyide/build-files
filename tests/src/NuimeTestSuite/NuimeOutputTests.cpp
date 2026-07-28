// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeOutputTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeOutput.hpp"

using namespace Nuime;

NuimeOutputTests::NuimeOutputTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeOutput tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void NuimeOutputTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeOutput output("IshikoErrors");

    ISHIKO_TEST_FAIL_IF_NEQ(output.asString(), "IshikoErrors");
    ISHIKO_TEST_PASS();
}
