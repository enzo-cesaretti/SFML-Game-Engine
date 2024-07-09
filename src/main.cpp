/*
** EPITECH PROJECT, 2024
** SFML-game-engine
** File description:
** main
*/

#include <iostream>
#include "Engine.hpp"
#include "State/GameState.hpp"

int main()
{
    try {
        Engine engine;
        engine.pushState<DefaultState>(engine);
        engine.pushState<GameState>(engine);
        engine.popState();
        engine.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
