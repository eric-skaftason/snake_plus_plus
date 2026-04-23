#include <SFML/Window/Keyboard.hpp>

struct KeyStates {
    bool up;
    bool down;
    bool left;
    bool right;
};

class UserInput {
private:
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;

public:
    void updateKeys() {
        while (window)
    }

    KeyStates pollInput() {
        KeyStates ks;
        ks.up = this->up;
        ks.down = this->down;
        ks.left = this->left;
        ks.right = this->right;

        return ks;
    }



};