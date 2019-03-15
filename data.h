#pragma once
#define SNAKE_MAX_LEN 21 //
#define SNAKE_START_LEN 3
#define SPEED 700000 //700ms

struct Data
{
    short an[6];
    short ca[7];
    short snakeBody[SNAKE_MAX_LEN][2];
    char direction;
    short snakeLen;
    short field[6][7];
    short headX;
    short headY;
    short exit_t;
    short onSnake;
    short temp[SNAKE_MAX_LEN][2];
    short fruitX;
    short fruitY;
};