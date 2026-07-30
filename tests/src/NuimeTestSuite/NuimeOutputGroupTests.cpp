// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeOutputGroupTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeOutputGroup.hpp"

using namespace Nuime;

NuimeOutputGroupTests::NuimeOutputGroupTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeOutputGroup tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("addLabel test 1", AddLabelTest1);
    append<Ishiko::HeapAllocationErrorsTest>("hasLabel test 1", HasLabelTest1);
    append<Ishiko::HeapAllocationErrorsTest>("setBase test 1", SetBaseTest1);
    append<Ishiko::HeapAllocationErrorsTest>("addOutput test 1", AddOutputTest1);
}

void NuimeOutputGroupTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeOutputGroup output_group;

    ISHIKO_TEST_FAIL_IF_NEQ(output_group.labels().size(), 0);
    ISHIKO_TEST_FAIL_IF_NEQ(output_group.base(), "");
    ISHIKO_TEST_FAIL_IF_NEQ(output_group.outputs().size(), 0);
    ISHIKO_TEST_PASS();
}

void NuimeOutputGroupTests::AddLabelTest1(Ishiko::Test& test)
{
    NuimeOutputGroup output_group;
    output_group.addLabel(NuimeLabel("nuime:code:cpp-source"));

    ISHIKO_TEST_FAIL_IF_NEQ(output_group.labels().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(output_group.labels()[0].asString(), "nuime:code:cpp-source");
    ISHIKO_TEST_PASS();
}

void NuimeOutputGroupTests::HasLabelTest1(Ishiko::Test& test)
{
    NuimeOutputGroup output_group;
    output_group.addLabel(NuimeLabel("nuime:code:cpp-source"));

    ISHIKO_TEST_FAIL_IF_NOT(output_group.hasLabel("nuime:code:cpp-source"));
    ISHIKO_TEST_FAIL_IF(output_group.hasLabel("nuime:code:cpp-header"));
    ISHIKO_TEST_PASS();
}

void NuimeOutputGroupTests::SetBaseTest1(Ishiko::Test& test)
{
    NuimeOutputGroup output_group;
    output_group.setBase("../../lib");

    ISHIKO_TEST_FAIL_IF_NEQ(output_group.base(), "../../lib");
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
