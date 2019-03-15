#include <termios.h>

#include "data.h"
#include "display.h"
#include "move.h"
#include "fruitAndDeath.h"

void offAll(short *an, short *ca)
{
    for(short i=0;i<7;i++)
    {
        digitalWrite(ca[i],0);
    }
    for(short i=0;i<6;i++)
    {
        digitalWrite(an[i],0);
    }
}

void onAll(short *an, short *ca)
{
    for(short i=0;i<7;i++)
    {
        digitalWrite(ca[i],0);
    }
    for(short i=0;i<6;i++)
    {
        digitalWrite(an[i],1);
    }
}

void caon(short *ca)
{
    for(short i=0;i<7;i++)
        digitalWrite(ca[i],1);
}

void setupPins(short *an, short *ca)
{
    wiringPiSetup();
    for(short i=0;i<7;i++)
    {
        pinMode(ca[i],OUTPUT);
        digitalWrite(ca[i],0);
    }
    for(short i=0;i<6;i++)
    {
        pinMode(an[i],OUTPUT);
        digitalWrite(an[i],1);
    }
}

int main()
{
    pthread_t threads[3];
    
    struct Data data;
    data.an[0]=0;data.an[1]=2;data.an[2]=3;data.an[3]=21;data.an[4]=22;data.an[5]=23;
    data.ca[0]=1;data.ca[1]=4;data.ca[2]=5;data.ca[3]=6;data.ca[4]=26;data.ca[5]=27;data.ca[6]=28;
    memset(data.snakeBody,0,sizeof(data.snakeBody));
    data.direction='r';
    data.snakeLen=SNAKE_START_LEN;
    data.headX=0;
    data.headY=0;
    data.exit_t=0;
    data.fruitX=3;
    data.fruitY=2;

    setupPins(data.an, data.ca);
    offAll(data.an, data.ca);
    srand(time(NULL));

    static struct termios oldt, newt;
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);        
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);

    pthread_create(&threads[0], NULL, display, &data);
    pthread_create(&threads[1], NULL, move, &data);
    pthread_create(&threads[2], NULL, fad, &data);

    while(!data.exit_t)
    {
        switch (getchar())
        {
            case 's':
            {
                if(data.direction!='u')
                    data.direction='d';
                break;
            }
            case 'w':
            {
                if(data.direction!='d')
                    data.direction='u';
                break;
            }
            case 'a':
            {
                if(data.direction!='r')
                    data.direction='l';
                break;
            }
            case 'd':
            {
                if(data.direction!='l')
                    data.direction='r';
                break;
            }
            case 'l':
            {
                data.exit_t=1;
                sleep(2);
                break;
            }
        }
        usleep(100000);
    }
    printf("\n");
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}