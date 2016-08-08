/*************************************
 * @Author  Irvin Pang
 * @E-mail  halo.irvin@gmail.com
 *************************************/

#ifndef __LUA_ER_H__
#define __LUA_ER_H__

extern "C"
{
	#include <lua/lua.h>
	#include <lua/lualib.h>
	#include <lua/lauxlib.h>
}

namespace LuaER
{
/*
 * By default, LuaER support only primitive data type(i.e. fundamental types)
 * However, it's simple to use other data structs/classes by implementing
 * 'get'/'put' pair with your own. e.g.: 
 * 
 *     template<>
 *     Texture* Value::get(lua_State* L, int index)
 *     {
 *         void* raw = (void*)lua_touserdata(L, index);
 *         Texture* texture = magic(raw);
 *         return texture;
 *     }
 */
class Value
{
public:
	template<typename Type>
	static Type get(lua_State* L, int index);

	template<typename Type>
	static void put(lua_State* L, Type value);

};

/*
 * GLUE CODE
 * support functions up to 7 argument
 * TODO: argument check
 */
class Invoke
{
public:
	/* void return */
	static int call(lua_State* L, void (*func)())
	{
		(*func)();
		return 0;
	}

	template<typename Argument1>
	static int call(lua_State* L, void (*func)(Argument1))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		(*func)(p1);
		return 0;
	}

	template<typename Argument1, typename Argument2>
	static int call(lua_State* L, void (*func)(Argument1, Argument2))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		Argument2 p2 = Value::get<Argument2>(L, 2);
		(*func)(p1, p2);
		return 0;
	}

	template<typename Argument1, typename Argument2, typename Argument3>
	static int call(lua_State* L, void (*func)(Argument1, Argument2, Argument3))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		Argument2 p2 = Value::get<Argument2>(L, 2);
		Argument3 p3 = Value::get<Argument3>(L, 3);
		(*func)(p1, p2, p3);
		return 0;
	}

	template<typename Argument1, typename Argument2, typename Argument3, typename Argument4>
	static int call(lua_State* L, void (*func)(Argument1, Argument2, Argument3, Argument4))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		Argument2 p2 = Value::get<Argument2>(L, 2);
		Argument3 p3 = Value::get<Argument3>(L, 3);
		Argument4 p4 = Value::get<Argument4>(L, 4);
		(*func)(p1, p2, p3, p4);
		return 0;
	}

	template<typename Argument1, typename Argument2, typename Argument3, typename Argument4, typename Argument5>
	static int call(lua_State* L, void (*func)(Argument1, Argument2, Argument3, Argument4, Argument5))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		Argument2 p2 = Value::get<Argument2>(L, 2);
		Argument3 p3 = Value::get<Argument3>(L, 3);
		Argument4 p4 = Value::get<Argument4>(L, 4);
		Argument5 p5 = Value::get<Argument5>(L, 5);
		(*func)(p1, p2, p3, p4, p5);
		return 0;
	}

	template<typename Argument1, typename Argument2, typename Argument3, typename Argument4, typename Argument5, typename Argument6>
	static int call(lua_State* L, void (*func)(Argument1, Argument2, Argument3, Argument4, Argument5, Argument6))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		Argument2 p2 = Value::get<Argument2>(L, 2);
		Argument3 p3 = Value::get<Argument3>(L, 3);
		Argument4 p4 = Value::get<Argument4>(L, 4);
		Argument5 p5 = Value::get<Argument5>(L, 5);
		Argument6 p6 = Value::get<Argument6>(L, 6);
		(*func)(p1, p2, p3, p4, p5, p6);
		return 0;
	}

	template<typename Argument1, typename Argument2, typename Argument3, typename Argument4, typename Argument5, typename Argument6, typename Argument7>
	static int call(lua_State* L, void (*func)(Argument1, Argument2, Argument3, Argument4, Argument5, Argument6, Argument7))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		Argument2 p2 = Value::get<Argument2>(L, 2);
		Argument3 p3 = Value::get<Argument3>(L, 3);
		Argument4 p4 = Value::get<Argument4>(L, 4);
		Argument5 p5 = Value::get<Argument5>(L, 5);
		Argument6 p6 = Value::get<Argument6>(L, 6);
		Argument7 p7 = Value::get<Argument7>(L, 7);
		(*func)(p1, p2, p3, p4, p5, p6, p7);
		return 0;
	}

	template<typename Argument1, typename Argument2, typename Argument3, typename Argument4, typename Argument5, typename Argument6, typename Argument7, typename Argument8>
	static int call(lua_State* L, void (*func)(Argument1, Argument2, Argument3, Argument4, Argument5, Argument6, Argument7, Argument8))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		Argument2 p2 = Value::get<Argument2>(L, 2);
		Argument3 p3 = Value::get<Argument3>(L, 3);
		Argument4 p4 = Value::get<Argument4>(L, 4);
		Argument5 p5 = Value::get<Argument5>(L, 5);
		Argument6 p6 = Value::get<Argument6>(L, 6);
		Argument7 p7 = Value::get<Argument7>(L, 7);
		Argument8 p8 = Value::get<Argument8>(L, 8);
		(*func)(p1, p2, p3, p4, p5, p6, p7, p8);
		return 0;
	}

	/* single return */
	template<typename Return>
	static int call(lua_State* L, Return (*func)())
	{
		Return ret = (*func)();
		Value::put<Return>(L, ret);
		return 1;
	}

	template<typename Return, typename Argument1>
	static int call(lua_State* L, Return(*func)(Argument1))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		Return ret = (*func)(p1);
		Value::put<Return>(L, ret);
		return 1;
	}

	template<typename Return, typename Argument1, typename Argument2>
	static int call(lua_State* L, Return (*func)(Argument1, Argument2))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		Argument2 p2 = Value::get<Argument2>(L, 2);
		Return ret = (*func)(p1, p2);
		Value::put<Return>(L, ret);
		return 1;
	}

	template<typename Return, typename Argument1, typename Argument2, typename Argument3>
	static int call(lua_State* L, Return (*func)(Argument1, Argument2, Argument3))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		Argument2 p2 = Value::get<Argument2>(L, 2);
		Argument3 p3 = Value::get<Argument3>(L, 3);
		Return ret = (*func)(p1, p2, p3);
		Value::put<Return>(L, ret);
		return 1;
	}

	template<typename Return, typename Argument1, typename Argument2, typename Argument3, typename Argument4>
	static int call(lua_State* L, Return (*func)(Argument1, Argument2, Argument3, Argument4))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		Argument2 p2 = Value::get<Argument2>(L, 2);
		Argument3 p3 = Value::get<Argument3>(L, 3);
		Argument4 p4 = Value::get<Argument4>(L, 4);
		Return ret = (*func)(p1, p2, p3, p4);
		Value::put<Return>(L, ret);
		return 1;
	}

	template<typename Return, typename Argument1, typename Argument2, typename Argument3, typename Argument4, typename Argument5>
	static int call(lua_State* L, Return (*func)(Argument1, Argument2, Argument3, Argument4, Argument5))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		Argument2 p2 = Value::get<Argument2>(L, 2);
		Argument3 p3 = Value::get<Argument3>(L, 3);
		Argument4 p4 = Value::get<Argument4>(L, 4);
		Argument5 p5 = Value::get<Argument5>(L, 5);
		Return ret = (*func)(p1, p2, p3, p4, p5);
		Value::put<Return>(L, ret);
		return 1;
	}

	template<typename Return, typename Argument1, typename Argument2, typename Argument3, typename Argument4, typename Argument5, typename Argument6>
	static int call(lua_State* L, Return (*func)(Argument1, Argument2, Argument3, Argument4, Argument5, Argument6))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		Argument2 p2 = Value::get<Argument2>(L, 2);
		Argument3 p3 = Value::get<Argument3>(L, 3);
		Argument4 p4 = Value::get<Argument4>(L, 4);
		Argument5 p5 = Value::get<Argument5>(L, 5);
		Argument6 p6 = Value::get<Argument6>(L, 6);
		Return ret = (*func)(p1, p2, p3, p4, p5, p6);
		Value::put<Return>(L, ret);
		return 1;
	}

	template<typename Return, typename Argument1, typename Argument2, typename Argument3, typename Argument4, typename Argument5, typename Argument6, typename Argument7>
	static int call(lua_State* L, Return (*func)(Argument1, Argument2, Argument3, Argument4, Argument5, Argument6, Argument7))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		Argument2 p2 = Value::get<Argument2>(L, 2);
		Argument3 p3 = Value::get<Argument3>(L, 3);
		Argument4 p4 = Value::get<Argument4>(L, 4);
		Argument5 p5 = Value::get<Argument5>(L, 5);
		Argument6 p6 = Value::get<Argument6>(L, 6);
		Argument7 p7 = Value::get<Argument7>(L, 7);
		Return ret = (*func)(p1, p2, p3, p4, p5, p6, p7);
		Value::put<Return>(L, ret);
		return 1;
	}

	template<typename Return, typename Argument1, typename Argument2, typename Argument3, typename Argument4, typename Argument5, typename Argument6, typename Argument7, typename Argument8>
	static int call(lua_State* L, Return (*func)(Argument1, Argument2, Argument3, Argument4, Argument5, Argument6, Argument7, Argument8))
	{
		Argument1 p1 = Value::get<Argument1>(L, 1);
		Argument2 p2 = Value::get<Argument2>(L, 2);
		Argument3 p3 = Value::get<Argument3>(L, 3);
		Argument4 p4 = Value::get<Argument4>(L, 4);
		Argument5 p5 = Value::get<Argument5>(L, 5);
		Argument6 p6 = Value::get<Argument6>(L, 6);
		Argument7 p7 = Value::get<Argument7>(L, 7);
		Argument8 p8 = Value::get<Argument8>(L, 8);
		Return ret = (*func)(p1, p2, p3, p4, p5, p6, p7, p8);
		Value::put<Return>(L, ret);
		return 1;
	}
	
};

/** all lua->C calls registered by LuaER eventually come to Sentinel::wrapper **/
template<typename Function>
class Sentinel
{
public:
	static int wrapper(lua_State* L)
	{
		void* userdata = lua_touserdata(L, lua_upvalueindex(1));
		Function* func = static_cast<Function*>(userdata);
		return Invoke::call(L, *func);
	}

};

}; // namespace LuaER

template<typename Function>
void luaER_register_global(lua_State* L, const char* name, Function func)
{
	// push func as userdata
	size_t size = sizeof(Function);
	void* userdata = lua_newuserdata(L, size);
	memcpy(userdata, &func, size);
	// push function call
	lua_pushcclosure(L, LuaER::Sentinel<Function>::wrapper, 1);
	// register as global function call
	lua_setglobal(L, name);
}

template<typename Function>
void luaER_register(lua_State* L, const char* libname, const char* name, Function func)
{
	size_t size = sizeof(Function);
	void* userdata = lua_newuserdata(L, size);
	memcpy(userdata, &func, size);

	/* check whether lib already exists */
	luaL_findtable(L, LUA_REGISTRYINDEX, "_LOADED", 1);
	lua_getfield(L, -1, libname);
	if (!lua_istable(L, -1))
	{
		lua_pop(L, 1);
		// try global variable (and create one if it does not exist)
		if (luaL_findtable(L, LUA_GLOBALSINDEX, libname, 1) != NULL)
			luaL_error(L, "name conflict for module " LUA_QS, libname);
		// new table
		lua_pushvalue(L, -1);
		lua_setfield(L, -3, libname);
	}
	lua_remove(L, -2);
	// move library table to below upvalues
	lua_insert(L, -2);
	
	lua_pushvalue(L, -1);
	lua_pushcclosure(L, LuaER::Sentinel<Function>::wrapper, 1);
	lua_setfield(L, -3, name);

	lua_pop(L, 1);
}

#endif // __LUA_ER_H__
