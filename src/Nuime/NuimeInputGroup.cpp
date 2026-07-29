// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeInputGroup.hpp"

using namespace Nuime;

const std::vector<NuimeInput>& NuimeInputGroup::inputs() const
{
    return m_inputs;
}

void NuimeInputGroup::addInput(const NuimeInput& input)
{
    m_inputs.push_back(input);
}
