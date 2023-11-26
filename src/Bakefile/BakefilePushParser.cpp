/*
    Copyright (c) 2017-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-files/blob/main/LICENSE.txt
*/

#include "Bakefile/BakefilePushParser.hpp"

CodeSmithy::BakefilePushParser::BakefilePushParser(std::istream& input)
    : m_tokenizer(input)
{
}

std::shared_ptr<CodeSmithy::Bakefile> CodeSmithy::BakefilePushParser::parse()
{
    std::shared_ptr<Bakefile> result = std::make_shared<Bakefile>();

    BakefileToken token;
    while (m_tokenizer.getNextToken(token) == BakefileTokenizer::eTokenExtracted)
    {
    }

    return result;
}
