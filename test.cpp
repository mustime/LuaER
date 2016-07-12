/*************************************
 * @Author  Irvin Pang @ XXTeam
 * @E-mail  halo.irvin@gmail.com
 *************************************/

#include <cmath>
#include <unistd.h>

#include "luaER.h"

class Test
{
public:
    static double case0(int a, double b)
    {
        return pow(a, b);
    }

    static char* case1(const char* format, int a, int b)
    {
        char* ret = (char*)malloc(0x100);
        snprintf(ret, 0x100, format, a, b, a + b);
        return ret;
    }

    static int case2(const char* string)
    {
        int ret = strlen(string);
        char* s = const_cast<char*>(string);
        free(s);
        return ret;
    }
    
};

bool testcase3(const char* path)
{
    return (access(path, F_OK) == 0);
}

void clog(const char* msg)
{
    printf("[lua] %s\n", msg);
}

void msleep(int milliSec)
{
    usleep(milliSec * 1000);
}

int main()
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    
    luaER_register_global(L, "log", clog);
    luaER_register_global(L, "sleep", msleep);
    luaER_register(L, "test", "case0", Test::case0);
    luaER_register(L, "test", "case1", Test::case1);
    luaER_register(L, "test", "case2", Test::case2);
    luaER_register(L, "test", "case3", testcase3);
    
    luaL_loadfile(L, "/mnt/sdcard/test.lua");
    lua_pcall(L, 0, LUA_MULTRET, 0);
    lua_close(L);

    return 0;
}
