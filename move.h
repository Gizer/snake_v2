#pragma once
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include "data.h"

void updateBody();
void moveU();
void moveD();
void moveR();
void moveL();
void *move(struct Data *arg);
struct Data *data;