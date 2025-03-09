#include <chrono>
#include <foresteamnd/Utils>
#include <fstream>
#include <iostream>
#include <list>
#include <string.h>
#include <thread>

extern "C" {
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
}

#include "Primes.h"
#include "Timer.h"

static int lTimerStart(lua_State* L) {
	lua_pushinteger(L, TimerStart());
	return 1;
}
static int lTimerEnd(lua_State* L) {
	int64_t timer = luaL_checkinteger(L, -1);
	lua_pushnumber(L, TimerEnd(timer));
	return 1;
}

static int lPrimes(lua_State* L) {
	int64_t n = luaL_checkinteger(L, -1);
	lua_pushnumber(L, Primes(n));
	return 1;
}

// Library open function
extern "C" int luaopen_librut(lua_State* L) {
	static const luaL_Reg librut[] = {
		{"TimerStart", lTimerStart},
		{"TimerEnd", lTimerEnd},
		{"Primes", lPrimes},
		{nullptr, nullptr} // Sentinel item
	};

	luaL_newlib(L, librut);
	return 1;
}