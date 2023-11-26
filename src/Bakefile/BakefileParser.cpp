/*
    Copyright (c) 2017-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-files/blob/main/LICENSE.txt
*/

#include "Bakefile/BakefileParser.hpp"

CodeSmithy::BakefileParser::BakefileParser(std::istream& input)
    : m_tokenizer(input)
{
}

CodeSmithy::BakefileParser::~BakefileParser()
{
}

std::shared_ptr<CodeSmithy::Bakefile> CodeSmithy::BakefileParser::parse()
{
    std::shared_ptr<Bakefile> result = std::make_shared<Bakefile>();

    BakefileToken token;
    while (m_tokenizer.getNextToken(token) == BakefileTokenizer::eTokenExtracted)
    {
    }

    return result;
}
