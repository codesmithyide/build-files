// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMEINPUT_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMEINPUT_HPP

#include <string>

namespace Nuime
{
    class NuimeInput
    {
    public:
        explicit NuimeInput(const std::string& value);

        const std::string& asString() const;

    private:
        std::string m_value;
    };
}

#endif
