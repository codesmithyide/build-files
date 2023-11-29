/*
    Copyright (c) 2017-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-files/blob/main/LICENSE.txt
*/

#include "Bakefile/BakefileTokenizer.hpp"

CodeSmithy::BakefileTokenizer::BakefileTokenizer(std::istream& input)
    : m_input(input)
{
}

CodeSmithy::BakefileTokenizer::~BakefileTokenizer()
{
}

int CodeSmithy::BakefileTokenizer::getNextToken(BakefileToken& token)
{
    const int bufferSize = 1024;
    std::string buffer;
    buffer.reserve(bufferSize);
    while (m_input.get(&buffer[0], bufferSize))
    {
    }

    return eEnd;
}
