// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeInputGroupTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeInputGroup.hpp"

using namespace Nuime;

NuimeInputGroupTests::NuimeInputGroupTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeInputGroup tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("addInput test 1", AddInputTest1);
}

void NuimeInputGroupTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeInputGroup input_group;

    ISHIKO_TEST_FAIL_IF_NEQ(input_group.inputs().size(), 0);
    ISHIKO_TEST_PASS();
}

void NuimeInputGroupTests::AddInputTest1(Ishiko::Test& test)
{
    NuimeInputGroup input_group;
    input_group.addInput(NuimeInput("src/main.cpp"));

    ISHIKO_TEST_FAIL_IF_NEQ(input_group.inputs().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(input_group.inputs()[0].asString(), "src/main.cpp");
    ISHIKO_TEST_PASS();
}
