/*
** EPITECH PROJECT, 2024
** SFML-game-engine
** File description:
** GameState
*/

#include "State/GameState.hpp"
#include "Macro.h"

GameState::GameState(Engine &engine) : DefaultState(engine)
{
    _player.setSize({100, 100});
    _player.setFillColor(sf::Color::Red);
    _player.setPosition({100, 100});
}

GameState::~GameState()
{
}

void GameState::handleEvents(sf::Event event UNUSED)
{
}

void GameState::handleInputs()
{
}

void GameState::update(sf::Time deltaTime UNUSED)
{
}

void GameState::fixedUpdate(sf::Time deltaTime UNUSED)
{
}

void GameState::render(sf::RenderTarget &renderer)
{
    renderer.draw(_player);
}
