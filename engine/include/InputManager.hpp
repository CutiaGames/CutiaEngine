#ifndef INPUT_MANAGER
#define INPUT_MANAGER

#include "CutiaSDL.hpp"
#include <vector>
#include <list>
#include <unordered_map>
#include <string>


class InputManager {
    public:
        InputManager();
        void gather_input(SDL_Event event);
        void clear_input();
        bool is_button_down(const std::string& button_name) const;
        bool is_button_up(const std::string& button_name) const;

    private:
        std::unordered_map<std::string, int> m_buttons;
        std::list<SDL_Event> m_updated;
        void create_keyboard_mapping();
};



#endif

