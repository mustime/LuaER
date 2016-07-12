# LuaER

## What is LuaER
LuaER is short for *Lua Easier Register*. It's design for simpifing C/C++ function registration for Lua.

## How to use
Let say you have write the following log function for Android:

```cpp
#include <android/log.h>

namespace xx {
class Logger {
public:
    static void D(const char*tag, const char* message) {
        __android_log_write(ANDROID_LOG_DEBUG, tag, message);
    }
};
}

```

To register `xx::Logger::D` function, you just need to do this

```cpp
// register as global function
luaER_register_global(L, "logD", xx::Logger::D);
// or register as lib function
luaER_register(L, "xx", "logD", xx::Logger::D);
```

That's much easier, right? In Lua script, try:

```lua
-- for luaER_register_global(L, "logD", xx::Logger::D)
logD("tag", "hello from the other side")
-- for luaER_register(L, "xx", "logD", xx::Logger::D)
xx.logD("tag", "hello from the outside")
```

For more detail and samples, look into the source and test code. : )

## Limitation
* By default, auto register only support C++ primitive data type(i.e. fundamental types). But you could easily add one by yourself like this:

    ```cpp
    template<>
    Texture* Value::get(lua_State* L, int index) {
       void* raw = (void*)lua_touserdata(L, index);
       Texture* texture = magic(raw);
       return texture;
    }
    ```
    
    And now you could just register functions with parameter `Texture*`.

* Instance methods are ***NOT*** supported. If you want to auto-register instance methods for classes, try [tolua++](https://github.com/LuaDist/toluapp).

* LuaER supports functions up to 7 arguments, which's quite enough for Lua function, I think : P. Beyond that you need to write extra code, which is fine because it's nothing more than copy and patse.

## TODOs

* Arguments safe-check.
* C++11 lambda function support.

## License
Copyright (C) 2016 [Irvin Pang](https://github.com/mustime)  
Licensed under the [MIT License](https://opensource.org/licenses/MIT)