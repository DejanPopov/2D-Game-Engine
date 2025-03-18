// Protection Guard
#ifndef GAME_H
#define GAME_H

class Game
{
    private:
        //....

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