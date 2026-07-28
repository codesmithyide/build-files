// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeLabelTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeLabel.hpp"

using namespace Nuime;

NuimeLabelTests::NuimeLabelTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeLabel tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void NuimeLabelTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeLabel label("nuime:product");

    ISHIKO_TEST_FAIL_IF_NEQ(label.asString(), "nuime:product");
    ISHIKO_TEST_PASS();
}
