class Game {
private:
    void processInput();
    void update();
    void render();

    void handleCollisions();
    void reset();
public:
    Game();
    ~Game();

};