/*
** EPITECH PROJECT, 2024
** SFML-game-engine
** File description:
** DefaultState
*/

#include "State/DefaultState.hpp"
#include <iostream>
#include "Macro.h"

DefaultState::DefaultState(Engine &engine)
{
    _engine = &engine;
}

void DefaultState::handleEvents(sf::Event event UNUSED)
{
}

void DefaultState::handleInputs()
{
}

void DefaultState::update(sf::Time deltaTime UNUSED)
{
}

void DefaultState::fixedUpdate(sf::Time deltaTime UNUSED)
{
}

void DefaultState::render(sf::RenderTarget &renderer UNUSED)
{
}
