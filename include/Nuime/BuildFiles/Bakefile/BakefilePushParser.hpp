// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_BAKEFILE_BAKEFILEPUSHPARSER_HPP
#define GUARD_NUIME_BUILDFILES_BAKEFILE_BAKEFILEPUSHPARSER_HPP

#include "Bakefile.hpp"
#include <boost/utility/string_view.hpp>

namespace Nuime
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
            bakefile,
            filepath,
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
