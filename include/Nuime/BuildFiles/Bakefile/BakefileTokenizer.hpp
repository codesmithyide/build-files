/*
    Copyright (c) 2017-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-files/blob/main/LICENSE.txt
*/

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_BAKEFILE_BAKEFILETOKENIZER_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_BAKEFILE_BAKEFILETOKENIZER_HPP

#include "BakefileToken.hpp"
#include <istream>

namespace CodeSmithy
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
