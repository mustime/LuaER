/*************************************
 * @Author  Irvin Pang
 * @E-mail  halo.irvin@gmail.com
 *************************************/

#include "LuaER.h"

namespace LuaER 
{

template<>
bool Value::get(lua_State* L, int index)
{
	return lua_toboolean(L, index);
}

template<>
char Value::get(lua_State* L, int index)
{
	return static_cast<char>(lua_tointeger(L, index));
}

template<>
short Value::get(lua_State* L, int index)
{
	return static_cast<short>(lua_tointeger(L, index));
}

template<>
int Value::get(lua_State* L, int index)
{
	return lua_tointeger(L, index);
}

template<>
long Value::get(lua_State* L, int index)
{
	return static_cast<long>(lua_tonumber(L, index));
}

template<>
float Value::get(lua_State* L, int index)
{
	return static_cast<float>(lua_tonumber(L, index));
}

template<>
double Value::get(lua_State* L, int index)
{
	return static_cast<double>(lua_tonumber(L, index));
}

template<>
const char* Value::get(lua_State* L, int index)
{
 	return lua_tostring(L, index);
}

template<>
void Value::put(lua_State* L, bool value)
{
	lua_pushboolean(L, value);
}

template<>
void Value::put(lua_State* L, char value)
{
	lua_pushnumber(L, value);
}

template<>
void Value::put(lua_State* L, short value)
{
	lua_pushnumber(L, value);
}

template<>
void Value::put(lua_State* L, int value)
{
	lua_pushnumber(L, value);
}

template<>
void Value::put(lua_State* L, long value)
{
	lua_pushnumber(L, value);
}

template<>
void Value::put(lua_State* L, float value)
{
	lua_pushnumber(L, value);
}

template<>
void Value::put(lua_State* L, double value)
{
	lua_pushnumber(L, value);
}

template<>
void Value::put(lua_State* L, char* value)
{
	lua_pushstring(L, value);
}

template<>
void Value::put(lua_State* L, const char* value)
{
	lua_pushstring(L, value);
}

}
