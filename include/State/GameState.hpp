/*
** EPITECH PROJECT, 2024
** SFML-game-engine
** File description:
** GameState
*/

#pragma once

#include "State/DefaultState.hpp"

class GameState : public DefaultState {
    public:
        GameState(Engine &engine);
        ~GameState();

        void handleEvents(sf::Event event) override;
        void handleInputs() override;

        void update(sf::Time deltaTime) override;
        void fixedUpdate(sf::Time deltaTime) override;
        void render(sf::RenderTarget &renderer) override;

    private:
        sf::RectangleShape _player;
};
