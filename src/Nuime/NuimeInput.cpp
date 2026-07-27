// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeInput.hpp"

using namespace Nuime;

NuimeInput::NuimeInput(const std::string& value)
    : m_value(value)
{
}

const std::string& NuimeInput::asString() const
{
    return m_value;
}
