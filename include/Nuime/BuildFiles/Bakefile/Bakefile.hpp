// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_BAKEFILE_BAKEFILE_HPP
#define GUARD_NUIME_BUILDFILES_BAKEFILE_BAKEFILE_HPP

#include "BakefileTarget.hpp"
#include <vector>
#include <memory>

namespace Nuime
{
    class Bakefile
    {
    public:
        Bakefile();
        ~Bakefile();

        std::vector<std::shared_ptr<BakefileTarget> >& targets();

    private:
        std::vector<std::shared_ptr<BakefileTarget>> m_targets;
    };
}

#endif
