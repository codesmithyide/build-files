// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeOutputGroupTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeOutputGroup.hpp"

using namespace Nuime;

NuimeOutputGroupTests::NuimeOutputGroupTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeOutputGroup tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("addOutput test 1", AddOutputTest1);
}

void NuimeOutputGroupTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeOutputGroup output_group;

    ISHIKO_TEST_FAIL_IF_NEQ(output_group.outputs().size(), 0);
    ISHIKO_TEST_PASS();
}

void NuimeOutputGroupTests::AddOutputTest1(Ishiko::Test& test)
{
    NuimeOutputGroup output_group;
    output_group.addOutput(NuimeOutput("example"));

    ISHIKO_TEST_FAIL_IF_NEQ(output_group.outputs().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(output_group.outputs()[0].asString(), "example");
    ISHIKO_TEST_PASS();
}
