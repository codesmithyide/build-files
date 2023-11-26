/*
    Copyright (c) 2017-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-files/blob/main/LICENSE.txt
*/

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_BAKEFILE_BAKEFILEPUSHPARSER_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_BAKEFILE_BAKEFILEPUSHPARSER_HPP

#include "Bakefile.hpp"
#include "BakefileTokenizer.hpp"
#include <istream>
#include <memory>

namespace CodeSmithy
{
    class BakefilePushParser
    {
    public:
        BakefilePushParser(std::istream& input);

        std::shared_ptr<Bakefile> parse();

    private:
        BakefileTokenizer m_tokenizer;
    };
}

#endif
