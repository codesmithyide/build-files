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
    NuimeTarget target("lib");
    std::vector<NuimeInput> inputs;
    inputs.push_back(NuimeInput("src/Error.cpp"));
    inputs.push_back(NuimeInput("src/Exception.cpp"));
    std::vector<NuimeOutput> outputs;
    outputs.push_back(NuimeOutput("IshikoErrors"));

    NuimeRecipe recipe(target, inputs, outputs);

    ISHIKO_TEST_FAIL_IF_NEQ(recipe.target().name(), "lib");
    ISHIKO_TEST_FAIL_IF_NEQ(recipe.inputs().size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(recipe.inputs()[0].asString(), "src/Error.cpp");
    ISHIKO_TEST_FAIL_IF_NEQ(recipe.inputs()[1].asString(), "src/Exception.cpp");
    ISHIKO_TEST_FAIL_IF_NEQ(recipe.outputs().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(recipe.outputs()[0].asString(), "IshikoErrors");
    ISHIKO_TEST_PASS();
}
