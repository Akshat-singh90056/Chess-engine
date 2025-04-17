// Header Files...

#include "game.h"

// Globle variable...

SDL_Texture *boardTextur;
SDL_Texture *pieceTextur;
int mousePosX, mousePosY;

bool isMouseMove = false;

// constructor

Game::Game(int W_W, int W_H)
{
    WINDOW_W = W_W;
    WINDOW_H = W_H;
}

// distuctor

Game::~Game() {}

// functions....

bool Game::init(const char *title)
{

    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        return false;
    }

    window = SDL_CreateWindow(title, WINDOW_W, WINDOW_H, SDL_WINDOW_RESIZABLE);
    if (!window)
    {
        return false;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer)
    {
        return false;
    }

    boardTextur = loadTexture("assets/board.png");
    pieceTextur = loadTexture("assets/pieces.png");

    isRunning = true;
    return true;
}

void Game::handelEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            isRunning = false;
        }
        else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
        {
            mouseMove(&event, renderer);
            isMouseMove = true;
        }
    }
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // all render will be here

    renderBoard(renderer);

    if (isMouseMove)
    {
        SDL_FRect grid = {mousePosX * 64, mousePosY * 64, 64, 64};
        SDL_SetRenderDrawColor(renderer, 223, 0, 0, 0);
        SDL_RenderFillRect(renderer, &grid);
    }

    SDL_RenderPresent(renderer);
}

void Game::renderBoard(SDL_Renderer *renderer)
{
    SDL_FRect srcRect = {0, 0, 512, 512};
    SDL_FRect disRect = {0, 0, 512, 512};

    SDL_RenderTexture(renderer, boardTextur, &srcRect, &disRect);
}

void Game::pieceBoard(SDL_Renderer *renderer)
{
}

void Game::mouseMove(SDL_Event *event, SDL_Renderer *renderer)
{
    float mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    mousePosX = (int)mouseX / 64;
    mousePosY = (int)mouseY / 64;
}

SDL_Texture *Game::loadTexture(const char *path)
{
    SDL_Surface *surface = IMG_Load(path);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);

    return texture;
}

void Game::update()
{
}