#ifndef STATE_HPP
#define STATE_HPP

#include <vector>
#include <memory>


class State
{
    private:
        bool quitRequested;

    public:
        State();
        ~State();

        bool QuitRequested();
        void Update(float dt);
        void Render();
        void Input();
};

#endif