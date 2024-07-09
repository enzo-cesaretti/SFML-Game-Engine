/*
** EPITECH PROJECT, 2024
** SFML-game-engine
** File description:
** State
*/

#pragma once

#include <SFML/Graphics.hpp>

class State {
    public:
        virtual ~State() = default;

        virtual void handleEvents(sf::Event event) = 0;
        virtual void handleInputs() = 0;

        virtual void update(sf::Time deltaTime) = 0;
        virtual void fixedUpdate(sf::Time deltaTime) = 0;
        virtual void render(sf::RenderTarget &renderer) = 0;
};
