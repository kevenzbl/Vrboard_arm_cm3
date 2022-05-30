#ifndef __IMU_H__
#define __IMU_H__

#include "bma2x2_support.h"
#include "bmg160_support.h"
#include "bmm150_support.h"

void imu_init(void);
void imu_run(unsigned int timestamp);

#endif
