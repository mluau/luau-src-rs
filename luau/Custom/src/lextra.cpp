#include "lua.h"
#include "lapi.h"
#include "lgc.h"
#include "lobject.h"
#include "lstate.h"
#include "lgc.h"

extern "C" const void* lua_getmetatablepointer(lua_State* L, int objindex)
{
    const TValue* obj = luaA_toobject(L, objindex);
    if (!obj)
        return NULL;

    switch (ttype(obj))
    {
    case LUA_TTABLE:
        return hvalue(obj)->metatable;
    case LUA_TUSERDATA:
        return uvalue(obj)->metatable;
    default:
        return NULL;
    }
}

extern "C" const char* lua_gcstatename(int state)
{
    return luaC_statename(state);
}

extern "C" int64_t lua_gcallocationrate(lua_State* L) {
    return luaC_allocationrate(L);
}

extern "C" void lua_gcdump(lua_State* L, void* file, const char* (*categoryName)(lua_State* L, uint8_t memcat))
{
    luaC_dump(L, file, categoryName);
}
