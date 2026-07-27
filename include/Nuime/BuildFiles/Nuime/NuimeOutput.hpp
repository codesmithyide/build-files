// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMEOUTPUT_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMEOUTPUT_HPP

#include <string>

namespace Nuime
{
    class NuimeOutput
    {
    public:
        explicit NuimeOutput(const std::string& value);

        const std::string& asString() const;

    private:
        std::string m_value;
    };
}

#endif
