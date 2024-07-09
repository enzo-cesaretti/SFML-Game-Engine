#include "Engine.hpp"

template <typename T, typename... Args>
void Engine::pushState(Args &&...args)
{
    pushState(std::make_unique<T>(std::forward<Args>(args)...));
}

template <typename T, typename... Args>
void Engine::changeState(Args &&...args)
{
    popState();
    pushState<T>(std::forward<Args>(args)...);
}
