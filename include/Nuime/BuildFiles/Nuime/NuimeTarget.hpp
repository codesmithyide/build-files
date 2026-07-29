// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMETARGET_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMETARGET_HPP

#include "NuimeLabel.hpp"
#include <string>
#include <vector>

namespace Nuime
{
    class NuimeTarget
    {
    public:
        explicit NuimeTarget(const std::string& name);

        const std::string& name() const;

        const std::vector<NuimeLabel>& labels() const;
        void addLabel(const NuimeLabel& label);
        bool hasLabel(const std::string& label) const;

    private:
        std::string m_name;
        std::vector<NuimeLabel> m_labels;
    };
}

#endif
