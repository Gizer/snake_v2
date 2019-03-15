#include "display.h"

void *display(struct Data *data)
{
    while(!data->exit_t)
    {
        memset(data->field,1,sizeof(data->field));
        for(int i=0;i<data->snakeLen;++i)
        {
            data->field[data->snakeBody[i][1]][data->snakeBody[i][0]]=0;
        }
        data->field[data->fruitY][data->fruitX]=0;

        for(int i=0;i<6;i++)
        {
            for(int j=0;j<7;j++)
            {
                digitalWrite(data->ca[j],data->field[i][j]);
            }
            digitalWrite(data->an[i],1);
            usleep(2500);
            digitalWrite(data->an[i],0);
        }
    }
    pthread_exit(NULL);
}