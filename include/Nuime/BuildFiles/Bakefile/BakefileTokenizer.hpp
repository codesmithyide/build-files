// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_BAKEFILE_BAKEFILETOKENIZER_HPP
#define GUARD_NUIME_BUILDFILES_BAKEFILE_BAKEFILETOKENIZER_HPP

#include "BakefileToken.hpp"
#include <istream>

namespace Nuime
{
    class BakefileTokenizer
    {
    public:
        enum EState
        {
            eTokenExtracted = 0,
            eEnd = 1
        };

    public:
        BakefileTokenizer(std::istream& input);
        ~BakefileTokenizer();

        int getNextToken(BakefileToken& token);

    private:
        std::istream& m_input;
    };
}

#endif
