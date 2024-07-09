/*
** EPITECH PROJECT, 2024
** SFML-game-engine
** File description:
** Engine
*/

#include "Engine.hpp"
#include <iostream>
#include "Config.h"

Engine::Engine() : _window({1920, 1080}, "SFML-game-engine")
{
    _window.setPosition({_window.getPosition().x, 0});
    _window.setFramerateLimit(MAX_FPS);
}

Engine::~Engine()
{
}

const sf::RenderWindow &Engine::getWindow() const
{
    return _window;
}

State &Engine::getCurrentState() const
{
    return *_states.top();
}

void Engine::pushState(std::unique_ptr<State> state)
{
    _states.push(std::move(state));
}

void Engine::popState()
{
    tryPopState();
}

void Engine::run()
{
    const sf::Time timePerUpdate = sf::seconds(1.0f / float(TPS));
    unsigned ticks = 0;

    sf::Clock timer;
    sf::Time lastTime = sf::Time::Zero;
    sf::Time lag = sf::Time::Zero;

    while (_window.isOpen() && !_states.empty()) {
        State &state = getCurrentState();

        sf::Time time = timer.getElapsedTime();
        sf::Time elapsed = time - lastTime;
        lastTime = time;
        lag += elapsed;

        state.handleInputs();
        state.update(elapsed);

        while (lag >= timePerUpdate) {
            ticks++;
            lag -= timePerUpdate;
            state.fixedUpdate(elapsed);
        }

        _window.clear();
        state.render(_window);
        _window.display();

        handleEvents();
        // tryPopState();
    }
}

void Engine::handleEvents()
{
    sf::Event event;

    while (_window.pollEvent(event)) {
        getCurrentState().handleEvents(event);
        switch (event.type) {
            case sf::Event::Closed:
                _window.close();
                break;
            default:
                break;
        }
    }
}

void Engine::tryPopState()
{
    if (_states.empty())
        return;
    _states.pop();
}
