/*
    Copyright (c) 2017-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-files/blob/main/LICENSE.txt
*/

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_BAKEFILE_BAKEFILEPUSHPARSER_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_BAKEFILE_BAKEFILEPUSHPARSER_HPP

#include "Bakefile.hpp"
#include <boost/utility/string_view.hpp>

namespace CodeSmithy
{
    class BakefilePushParser
    {
    public:
        class Callbacks
        {
        public:
            virtual ~Callbacks() = default;

            virtual void onHeader(boost::string_view path);
            virtual void onSource(boost::string_view path);
            virtual void onTargetStart(boost::string_view id);
            virtual void onToolset(boost::string_view value);
        };

    public:
        BakefilePushParser(Callbacks& callbacks);

        bool onData(boost::string_view data, bool eod);

    private:
        enum class ParsingMode
        {
            assignment,
            file,
            headers,
            identifier,
            sources,
            target,
            target_id,
            toolset,
            toolsets,
            toolsets_value,
            whitespace
        };

        bool tokenEquals(const char* start, const char* end, const char* token) const;

        std::vector<ParsingMode> m_parsing_mode_stack;
        std::string m_fragmented_data;
        Callbacks& m_callbacks;
    };
}

#endif
