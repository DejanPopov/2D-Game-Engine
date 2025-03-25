#include "Game.h"
#include <SDL2/SDL.h>
#include <iostream>

Game::Game()
{
    std::cout << "Game Constructor called!" << std::endl;
}

Game::~Game()
{
    std::cout << "Game Destructor called!" << std::endl;
}

void Game::Initialize()
{
    // We want to initialise everything
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
    {
        // return from this function dont do anything
        std::cerr << "Error Initializing SDL" << std::endl;
        return;
    }
    // Raw pointer to the struct ( SDL_Window*)
    // window is going to be a pointer to adress where struct is allocated
    SDL_Window* window = SDL_CreateWindow
    (
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_BORDERLESS
    );

    // If we could not create window
    if(!window)
    {
        std::cerr << "Error Creating SDL Window" << std::endl;
        return;
    }

    // -1 means use default monitor
    SDL_Renderer* renderer = SDL_CreateRenderer
    (
        window,
        -1, 
        0
    );

    // If we could not create renderer
    if(!renderer)
    {
        std::cerr << "Error Creating SDL Renderer" << std::endl;
        return;
    }
}

void Game::Run()
{

}

void Game::ProcessInput()
{

}

void Game::Update()
{

}

void Game::Render()
{

}

void Game::Destroy()
{

}