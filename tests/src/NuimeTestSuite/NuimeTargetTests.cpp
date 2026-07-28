// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeTargetTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeTarget.hpp"

using namespace Nuime;

NuimeTargetTests::NuimeTargetTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeTarget tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("addLabel test 1", AddLabelTest1);
}

void NuimeTargetTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeTarget target("lib");

    ISHIKO_TEST_FAIL_IF_NEQ(target.name(), "lib");
    ISHIKO_TEST_FAIL_IF_NEQ(target.labels().size(), 0);
    ISHIKO_TEST_PASS();
}

void NuimeTargetTests::AddLabelTest1(Ishiko::Test& test)
{
    NuimeTarget target("lib");
    target.addLabel(NuimeLabel("nuime:product"));

    ISHIKO_TEST_FAIL_IF_NEQ(target.labels().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(target.labels()[0].asString(), "nuime:product");
    ISHIKO_TEST_PASS();
}
