/*
** EPITECH PROJECT, 2024
** SFML-game-engine
** File description:
** DefaultState
*/

#pragma once

#include <memory>
#include <stack>
#include "State/State.hpp"

using std::make_unique;
using std::stack;
using std::unique_ptr;

class Engine;

class DefaultState : public State {
    public:
        DefaultState() = default;
        DefaultState(Engine &engine);

        virtual ~DefaultState() = default;

        virtual void handleEvents(sf::Event event);
        virtual void handleInputs();

        virtual void update(sf::Time deltaTime);
        virtual void fixedUpdate(sf::Time deltaTime);
        virtual void render(sf::RenderTarget &renderer);

    protected:
        Engine *_engine;
};
