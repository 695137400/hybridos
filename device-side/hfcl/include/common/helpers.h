/*
** HFCL - HybridOS Foundation Class Library
**
** Copyright (C) 2018 Beijing FMSoft Technologies Co., Ltd.
**
** This file is part of HFCL.
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef HFCL_COMMON_HELPERS_H_
#define HFCL_COMMON_HELPERS_H_

#include <minigui/common.h>

#include <algorithm>
#include <string>
#include <cctype>

namespace hfcl {

inline std::string& ltrim(std::string& str,
        const std::string& chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

inline std::string& rtrim(std::string& str,
        const std::string& chars = "\t\n\v\f\r ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

inline std::string& trim(std::string& str,
        const std::string& chars = "\t\n\v\f\r ")
{
    return ltrim(rtrim(str, chars), chars);
}

inline std::string& tolower(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(),
            static_cast<int(*)(int)>(std::tolower));
    return str;
}

inline std::string& toupper(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(),
            static_cast<int(*)(int)>(std::toupper));
    return str;
}

/**
 * Convert a Uchar32 to a UTF8 character, and return the
 * length in bytes of the character.
 */
int uc32_to_utf8(Uint32 uc, char* outbuf);

/**
 * utf8_to_uc32:
 * @utf8_str:       The pointer to the string in UTF-8 encoding.
 * @utf8_strlen:    The length of the string in bytes, -1 for null-terminated.
 * @uc:             The buffer to return the converted Unicode code point value;
 *                  can be NULL.
 *
 * Convert a character in UTF-8 encoding to the Unicode code point value.
 *
 * This function returns the length in bytes of the character correctly
 * encoded in UTF-8 and the Unicode code point value if @uc is not NULL.
 *
 * If and only if the return value is greater than 0,
 * the Unicode code point value returned through \a uc is valid.
 *
 * The function may return zero under one of the following conditions:
 *
 *  - Bad encoded.
 *  - The lenght in bytes of the character given by \a utf8_strlen is too small
 *      to contain a valid UTF-8 encoded character.
 *  - Encountered '\0' early when decoding the character.
 *  - utf8_strlen is 0 or utf8_str[0] is '\0'.
 */
int utf8_to_uc32(const char* utf8_str, int utf8_strlen, Uint32* uc);

int get_first_utf8_char_len(const char *mstr, int len);
int get_last_utf8_char_len(const char *mstr, int len);
int get_utf_chars_info(const char *mstr, int len, int *char_pos);
int get_utf8_char_count(const char *mstr, int len);
int get_utf8_len_by_char_count(const char *mstr, int nr_chars);

/* to be deprecated */
bool HasUCS2Char (const char *mstr, int len);
Uint16 UTF8ToUCS2 (Uint8 *utf8);
bool IsNumberUCS2Char (Uint16 inChar);
bool IsSymbolUCS2Char (Uint16 inChar);
bool IsArabicSymbolUCS2Char (Uint16 inChar);
bool IsTransformArabicUCS2Char (Uint16 inChar);

} // namespace hfcl

#endif // HFCL_COMMON_HELPERS_H_

