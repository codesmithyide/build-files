// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeLabel.hpp"

using namespace Nuime;

NuimeLabel::NuimeLabel(const std::string& value)
    : m_value(value)
{
}

const std::string& NuimeLabel::asString() const
{
    return m_value;
}
