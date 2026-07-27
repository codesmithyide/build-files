// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMETARGET_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMETARGET_HPP

#include <string>

namespace Nuime
{
    class NuimeTarget
    {
    public:
        explicit NuimeTarget(const std::string& value);

        const std::string& asString() const;

    private:
        std::string m_value;
    };
}

#endif
