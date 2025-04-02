// Protection Guard
#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game
{
    private:
    
        SDL_Window*   window;
        SDL_Renderer* renderer;
        bool          isRunning;

    public:

        // Class constructor and destructor
        Game();  // Constructor
        ~Game(); // Destructor

        // Functions prototypes
        void Initialize();
        void Run();
        void ProcessInput();
        void Update();
        void Render();
        void Destroy();
};

#endif