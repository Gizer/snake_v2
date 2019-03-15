#include "fruitAndDeath.h"

void *fad(struct Data *data)
{
    while(!data->exit_t)
    {
        usleep(SPEED);
        if(data->headX==data->fruitX && data->headY==data->fruitY && data->snakeLen<SNAKE_MAX_LEN)
        {
            do
            {
                data->fruitX=rand()%7;
                data->fruitY=rand()%6;
                for(int i=0;i<data->snakeLen;i++)
                {
                    if(data->fruitX==data->snakeBody[i][0] && data->fruitY==data->snakeBody[i][1])
                        {
                            data->onSnake=1;
                            break;
                        }
                    else
                        data->onSnake=0;
                }
                usleep(5000);
            }while(data->onSnake);
            ++data->snakeLen;
        }

        for(int i=1;i<data->snakeLen;i++)
        {
            if(data->headX==data->snakeBody[i][0] && data->headY==data->snakeBody[i][1])
            {
                data->exit_t=1;
                printf("\nZjebales, wcisnij 'l'\n");
                break;
            }
        }
    }
    pthread_exit(NULL);
}