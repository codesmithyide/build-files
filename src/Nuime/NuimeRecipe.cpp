// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeRecipe.hpp"

using namespace Nuime;

NuimeRecipe::NuimeRecipe(const NuimeTarget& target, const std::vector<NuimeInput>& inputs)
    : m_target(target), m_inputs(inputs)
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
