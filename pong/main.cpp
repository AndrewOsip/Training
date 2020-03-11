#include <iostream>
#include <math.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GameWindow.h"
#include "PLayer.h"
#include "Ball.h"

SDL_Event e;
SDL_Renderer *ren = nullptr;
SDL_Window *win = nullptr;

void exitPong(SDL_Event& e, bool& quit) {
    while(SDL_PollEvent(&e)) {
                if(e.type == SDL_QUIT)  quit = true;
                if(e.type == SDL_KEYDOWN) {
                    switch(e.key.keysym.scancode) {
                    case SDL_SCANCODE_ESCAPE:
                        quit = true;
                        break;
                    }
                }
            }
}

void playerControl(Player& p1, Uint8& upButton, Uint8& downButton, const Uint8 *keystates) {
    if(keystates[SDL_SCANCODE_UP] || upButton)
                p1.pos.y -= p1.speed;
            if(keystates[SDL_SCANCODE_DOWN] || downButton)
                p1.pos.y += p1.speed;
}

void botMoovement(Player& p2, Ball& b) {
    if(b.y < p2.pos.y + p2.pos.h/2) {
                p2.pos.y -= p2.speed;
            }
            if(b.y > p2.pos.y + p2.pos.h/2) {
                p2.pos.y += p2.speed;
            }

            if(b.vx > b.BALL_MAXSPEED)
                b.vx = b.BALL_MAXSPEED;

            if(b.vy > b.BALL_MAXSPEED)
                b.vy = b.BALL_MAXSPEED;
}

void ballCoordsUpdate(Ball& b) {
    b.x += b.vx;
    b.y += b.vy;
}

void bounCol(Ball& b, Player& p1, Player& p2, GameWindow& gw) {
    if(b.y < 0) {
                b.y = 0;
                b.vy *= -1;
            }
            if(b.y + b.BALL_HEIGHT >= gw.SCREEN_HEIGHT) {
                b.y = gw.SCREEN_HEIGHT - b.BALL_HEIGHT - 1;
                b.vy *= -1;
            }

            if(b.x < 0) {

                p2.score += 1;
                b.x = p1.pos.x + p1.pos.w;
                b.y = p1.pos.y + p1.pos.h/2;
                b.vx = b.BALL_INIT_SPEED;
                b.speed = b.BALL_INIT_SPEED;
            }
            if(b.x + b.BALL_WIDTH>= gw.SCREEN_WIDTH) {

                p1.score += 1;
                b.x = p2.pos.x - b.BALL_WIDTH;
                b.y = p2.pos.y + p2.pos.h/2;
                b.vx = -1 * b.BALL_INIT_SPEED;
                b.speed = b.BALL_INIT_SPEED;
            }

            if(p1.pos.y < 0) p1.pos.y = 0;
            if(p1.pos.y + p1.pos.h > gw.SCREEN_HEIGHT) p1.pos.y = gw.SCREEN_HEIGHT - p1.pos.h;
            if(p2.pos.y < 0) p2.pos.y = 0;
            if(p2.pos.y + p2.pos.h > gw.SCREEN_HEIGHT) p2.pos.y = gw.SCREEN_HEIGHT - p2.pos.h;
}

void rectUpdate(Ball& b) {
    b.b_rect.x = static_cast<int>(b.x);
    b.b_rect.y = static_cast<int>(b.y);
}

void playerColl(Ball& b, Player& p1, Player& p2) {
    if(SDL_HasIntersection(&p1.pos, &b.b_rect)) {

                b.x = p1.pos.x + p1.pos.w;

                b.speed = b.speed * b.BALL_ACCELERATE;

                float angle = b.calc_angle(p1.pos.y, b.y, p1.pos.h);
                b.vx = b.speed * cos(angle);
                b.vy = ((b.vy>0)? -1 : 1) * b.speed * sin(angle);
            }
            if(SDL_HasIntersection(&p2.pos, &b.b_rect)) {

                b.x = p2.pos.x - b.BALL_WIDTH;

                b.speed = b.speed * b.BALL_ACCELERATE;

                float angle = b.calc_angle(p2.pos.y, b.y, p2.pos.h);
                b.vx = -1 * b.speed * cos(angle);
                b.vy = ((b.vy>0)? -1 : 1) * b.speed * sin(angle);
            }
}



int main()
{

    GameWindow gw;

    gw.Initialise(&ren,&win);

    SDL_Texture *squareTex = IMG_LoadTexture(ren, "/home/andrew/Sdl2/img/pong_board.png");
    SDL_QueryTexture(squareTex, nullptr, nullptr, &gw.board_width, &gw.board_height);

    SDL_Color whiteColor{255, 255, 255, 255};

    Ball b;

    b.b_rect.w = b.BALL_HEIGHT;
    b.b_rect.h = b.BALL_HEIGHT;

    // Define Players
    Player p1;
    Player p2;

    // Define Ball
    b.x = gw.SCREEN_WIDTH / 2;
    b.y = gw.SCREEN_HEIGHT / 2;
    b.speed = b.BALL_INIT_SPEED;
    b.vx = (rand() % 2 == 0)? b.BALL_INIT_SPEED : -1 * b.BALL_INIT_SPEED;
    b.vy = -0.5f;

    p1.score = p2.score = 0;
    p1.pos.w = p2.pos.w = gw.board_width;
    p1.pos.h = p2.pos.h = 150;
    p1.speed = 10;
    p2.speed = 2;

    p1.pos.x = gw.board_width/2 + 10;
    p2.pos.x = gw.SCREEN_WIDTH - p2.pos.w- 10 - p2.pos.w/2;

    p1.pos.y = gw.SCREEN_HEIGHT/2 - p1.pos.h/2;
    p2.pos.y = gw.SCREEN_HEIGHT/2 - p2.pos.h/2;

    bool quit = false;
    char buffer[512];
    const Uint8 *keystates = SDL_GetKeyboardState(nullptr);

    while(!quit) {

        exitPong(e, quit);

        Uint8 upButton = 0;
        Uint8 downButton = 0;

        playerControl( p1, upButton, downButton, keystates);
        botMoovement(p2, b);

        ballCoordsUpdate(b);
        bounCol(b, p1, p2, gw);

        rectUpdate(b);

        playerColl(b, p1, p2);

        SDL_RenderClear(ren);

        SDL_RenderCopy(ren, squareTex, nullptr, &p1.pos);
        SDL_RenderCopy(ren, squareTex, nullptr, &p2.pos);

        // Draw the center line
        gw.renderTexture(squareTex, ren, gw.SCREEN_WIDTH/2 - gw.CENTER_WIDTH/2, 0, gw.CENTER_WIDTH, gw.SCREEN_HEIGHT);

        // Draw the Ball
        gw.renderTexture(squareTex, ren, b.x, b.y, b.BALL_WIDTH, b.BALL_HEIGHT);

        // Display the score
        sprintf(buffer, "%d", p1.score);
        SDL_Texture *p1score = gw.renderText(buffer, "/home/andrew/Sdl2/fonts/sample.ttf", whiteColor, 40, ren);
        sprintf(buffer, "%d", p2.score);
        SDL_Texture *p2score = gw.renderText(buffer, "/home/andrew/Sdl2/fonts/sample.ttf", whiteColor, 40, ren);

        int width;
        SDL_QueryTexture(p1score, nullptr, nullptr, &width, nullptr);

        gw.renderTexture(p1score, ren, gw.SCREEN_WIDTH/2 - width - 10, 10);
        gw.renderTexture(p2score, ren, gw.SCREEN_WIDTH/2 + 10, 10);

        SDL_DestroyTexture(p1score);
        SDL_DestroyTexture(p2score);

        SDL_RenderPresent(ren);
    }

    SDL_DestroyTexture(squareTex);
    gw.Cleanup(&ren, &win);

    return 0;
}

