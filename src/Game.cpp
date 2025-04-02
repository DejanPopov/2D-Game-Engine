#include "Game.h"
#include <SDL2/SDL.h>
#include <iostream>

Game::Game()
{
    isRunning = false;
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
    window = SDL_CreateWindow(NULL,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_BORDERLESS);

    // If we could not create window, we are testing if window is NULL
    if(!window)
    {
        std::cerr << "Error Creating SDL Window" << std::endl;
        return;
    }

    // -1 means use default monitor
    renderer = SDL_CreateRenderer(window, -1, 0);

    // If we could not create renderer
    if(!renderer)
    {
        std::cerr << "Error Creating SDL Renderer" << std::endl;
        return;
    }

    isRunning = true;
}

void Game::ProcessInput()
{
    // Check if user presses something on keyboard (ESC)
    SDL_Event sdlEvent;

    // & Get the adress a memory in struct, so its not passing entire struct without copying
    while(SDL_PollEvent(&sdlEvent))
    {
        switch (sdlEvent.type)
        {  
            // If users clicks X on software window
            case SDL_QUIT:
                isRunning = false;
                break;
            
            case SDL_KEYDOWN:
                if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
                {
                    isRunning = false;
                }
                break;
        }
    }
}

void Game::Update()
{
    // Paint window with solid color
    // Choose color, clear renderer and than present renederer with choosen color
    SDL_SetRenderDrawColor(renderer, 250, 0 ,0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Game::Render()
{

}

void Game::Run()
{
    while (isRunning)
    {
        ProcessInput();
        Update();
        Render();
    }
}

void Game::Destroy()
{
    // Clean up after Destroy is called
    // Clean-up is done in inverse order that we created
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}