// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMEINPUTGROUP_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMEINPUTGROUP_HPP

#include "NuimeInput.hpp"
#include <vector>

namespace Nuime
{
    class NuimeInputGroup
    {
    public:
        const std::vector<NuimeInput>& inputs() const;
        void addInput(const NuimeInput& input);

    private:
        std::vector<NuimeInput> m_inputs;
    };
}

#endif
