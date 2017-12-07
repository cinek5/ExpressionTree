#include "stdafx.h"
#include "Argsmap.h"
#include <string>
namespace {
	map<string, int> create_map() {
		map<string, int> m;
		m["+"] = 2;
		m["-"] = 2;
		m["/"] = 2;
		m["sin"] = 1;
		m["cos"] = 1;
		m["*"] = 2;
		return m;
	}
}

map<string, int> const Argsmap::m = create_map();