// SPDX-FileCopyrightText: 2017-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_BAKEFILE_BAKEFILE_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_BAKEFILE_BAKEFILE_HPP

#include "BakefileTarget.hpp"
#include <vector>
#include <memory>

namespace CodeSmithy
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
