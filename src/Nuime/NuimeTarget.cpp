// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeTarget.hpp"

using namespace Nuime;

NuimeTarget::NuimeTarget(const std::string& value)
    : m_value(value)
{
}

const std::string& NuimeTarget::asString() const
{
    return m_value;
}
