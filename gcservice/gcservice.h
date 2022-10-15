#pragma once

#include <gc.h>
#include <type_traits>

namespace gcservice
{
template<typename T>
T* allocateGc()
{
    return static_cast<T*>(GC_MALLOC(sizeof(T)));
}

template<
        typename T,
        typename TAnon = std::enable_if_t<std::is_trivially_destructible_v<T>>,
        typename ... TCtorArgs
        >
T* allocateClassGC(TCtorArgs&& ... args)
{
    void* rawPtr = GC_MALLOC(sizeof(T));
    return new (rawPtr) T(std::forward<TCtorArgs>(args)...);
}
};