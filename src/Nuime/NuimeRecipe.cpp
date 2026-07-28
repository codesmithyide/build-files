// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeRecipe.hpp"

using namespace Nuime;

NuimeRecipe::NuimeRecipe(const NuimeTarget& target, const std::vector<NuimeInput>& inputs,
    const std::vector<NuimeOutput>& outputs)
    : m_target(target), m_inputs(inputs), m_outputs(outputs)
{
}

const NuimeTarget& NuimeRecipe::target() const
{
    return m_target;
}

const std::vector<NuimeInput>& NuimeRecipe::inputs() const
{
    return m_inputs;
}

const std::vector<NuimeOutput>& NuimeRecipe::outputs() const
{
    return m_outputs;
}
