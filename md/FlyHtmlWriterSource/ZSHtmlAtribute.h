//-----------------------------------------------------------------------------
// ZSHtmlAtribut.h
//-----------------------------------------------------------------------------
#ifndef ZS_HTML_ATRIBUT_H
#define ZS_HTML_ATRIBUT_H

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <utility>

using namespace std;

//-----------------------------------------------------------------------------
inline char* FindSprChar(char* s) {
	if (!s || *s == '\0') return nullptr;
	while (1) {
		if (*s == '\n' || *s == '\t' || *s == '\0') return s;
		++s;
	}
}

inline char* ScipSprChar(char* s) {
	if (!s || *s == '\0') return nullptr;
	while (1) {
		if (*s == '\0') return nullptr;
		if (*s == '\n' || *s == '\t' || *s == ' ') { ++s; continue; }
		break;
	}
	return s;
}

//-----------------------------------------------------------------------------
// Атрибут HTML-тега: имя и значение в виде строк 
//-----------------------------------------------------------------------------
struct FLY_HTML_WRITER_API ZSHtmlAttr{
	string n = "";	// Имя атрибута
	string v = "";	// Значение атрибута

	ZSHtmlAttr(const char* sn = nullptr, const char* sv = nullptr) {
		n = sn ? sn : "";
		v = sv ? sv : "";
	}

	ZSHtmlAttr& operator << (const char* ss) {
		if (!ss) { n = ""; v = ""; return *this; }
		char *se, *s = (char*)ss;
		for (int j = 0; j < 2; j++) {
			se = FindSprChar(s); if (!se) break;
			(j ? v : n).assign(s, se - s);
			s = ScipSprChar(se); if (!s) break;
		}
		return *this;
	}
};

//-----------------------------------------------------------------------------
#endif //#ifndef ZS_HTML_ATRIBUT_H