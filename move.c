#include "move.h"

void updateBody()
{
    for(int i=0;i<data->snakeLen;++i)
    {
        data->temp[i+1][0]=data->snakeBody[i][0];
        data->temp[i+1][1]=data->snakeBody[i][1];
    }
    data->temp[0][0]=data->headX;
    data->temp[0][1]=data->headY;
    memcpy(&data->snakeBody, &data->temp, sizeof data->temp);
}

void moveU()
{
    if(data->headY<1)
        data->headY=5;
    else
        --data->headY;
    updateBody(data);
}
void moveD()
{
    if(data->headY>4)
        data->headY=0;
    else
        ++data->headY;
    updateBody(data);
}
void moveL()
{
    if(data->headX<1)
        data->headX=6;
    else
        --data->headX;
    updateBody(data);
}
void moveR()
{
    if(data->headX>5)
        data->headX=0;
    else
        ++data->headX;
    updateBody(data);
}

void *move(struct Data *arg)
{
    data = arg;
    while(!data->exit_t)
    {
        usleep(SPEED);
        switch(data->direction)
        {
            case 'l':
            {
                moveL(data);
                break;
            }
            case 'r':
            {
                moveR(data);
                break;
            }
            case 'u':
            {
                moveU(data);
                break;
            }
            case 'd':
            {
                moveD(data);
                break;
            }
        }
    }
    pthread_exit(NULL);
}