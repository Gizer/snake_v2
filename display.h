#pragma once
#include <pthread.h>
#include <unistd.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <string.h>
#include "data.h"

void *display(struct Data *data);