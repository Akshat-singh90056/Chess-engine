#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class Game
{

public:
    Game(int W_W, int W_H);
    ~Game();

    bool init(const char *title);
    void handelEvent();
    void render();
    void renderBoard(SDL_Renderer *renderer);
    void pieceBoard(SDL_Renderer * renderer);
    void mouseMove(SDL_Event *event ,SDL_Renderer *renderer);
    void update();
    bool running()
    {
        return isRunning;
    }

    // helping fn.
    SDL_Texture *loadTexture(const char *path);

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;

    int WINDOW_W, WINDOW_H;
    bool isRunning = true;
};

#endif