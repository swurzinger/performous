#pragma once

#include <iostream>
#include <map>
#include <string>
#include <unicode/tblcoll.h>
#include <unicode/uclean.h>
#include <unicode/ucsdet.h>
#define _TURN_OFF_PLATFORM_STRING
#include "details/basic_types.h"

typedef std::map<std::string, std::string> songMetadata;

struct UnicodeUtil {
	UnicodeUtil() {}
	~UnicodeUtil() {};
	static void collate (songMetadata& stringmap);
	static std::string getCharset(std::string const& str);
	static void convertToUTF8 (std::stringstream &_stream, std::string _filename);
	static std::string convertToUTF8 (std::string const& str);
	static icu::RuleBasedCollator m_dummyCollator;
	static icu::RuleBasedCollator m_sortCollator;
	static UErrorCode m_staticIcuError;
	static utf16string convertToUTF16(std::string const& str);
};
