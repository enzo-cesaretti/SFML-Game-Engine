/*
** EPITECH PROJECT, 2024
** SFML-game-engine
** File description:
** Engine
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>
#include "State/State.hpp"

using std::stack;
using std::unique_ptr;

class Engine {
    public:
        Engine();
        ~Engine();

        Engine &operator=(const Engine &) = delete;
        Engine(const Engine &) = delete;

        Engine &operator=(Engine &&) = delete;
        Engine(Engine &&) = delete;

        const sf::RenderWindow &getWindow() const;
        State &getCurrentState() const;

        template <typename T, typename... Args>
        void pushState(Args &&...args);

        void pushState(unique_ptr<State> state);

        void popState();

        template <typename T, typename... Args>
        void changeState(Args &&...args);

        void exit();
        void run();

    private:
        sf::RenderWindow _window;
        stack<unique_ptr<State>> _states;

        void handleEvents();
        void tryPopState();
};

#include "Engine.inl"
