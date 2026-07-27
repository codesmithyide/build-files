// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeRecipeTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeRecipe.hpp"

using namespace Nuime;

NuimeRecipeTests::NuimeRecipeTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeRecipe tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void NuimeRecipeTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeRecipe recipe;

    ISHIKO_TEST_PASS();
}
