#pragma once

#include <memory>

namespace Loom
{
    //----------------------------------------
    // UniquePtr
    //----------------------------------------
    template<typename T>
    using UniquePtr = std::unique_ptr<T>;

    template<typename T, typename... Args>
    constexpr UniquePtr<T> MakeUnique(Args&&... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    //----------------------------------------
    // SharePtr
    //----------------------------------------
    template<typename T>
    using SharedPtr = std::shared_ptr<T>;

    template<typename T, typename... Args>
    constexpr SharedPtr<T> MakeShared(Args&&... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    //----------------------------------------
    // WeakPtr
    //----------------------------------------
    template<typename T>
    using WeakPtr = std::weak_ptr<T>;
}