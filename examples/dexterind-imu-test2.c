#pragma config(Sensor, S1,     DIMU,                sensorI2CCustomFastSkipStates)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
 * dexterind-imu.h provides an API for the Dexter Industries IMU Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Dexter Industries for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 07 August 2011
 * version 0.1
 */

#include "dexterind-imu.h"

float xvals[500];
float yvals[500];
float zvals[500];

task main(){

  displayCenteredTextLine(0, "Dexter Ind.");
  displayCenteredBigTextLine(1, "IMU");
  displayCenteredTextLine(3, "Test 2");
  displayCenteredTextLine(5, "Connect sensor");
  displayCenteredTextLine(6, "to S1");
  sleep(2000);
  eraseDisplay();

  // Fire up the gyro and initialize it. Only needs to be done once.
  //DIMUconfigGyro(DIMU, DIMU_GYRO_RANGE_500);
  if (!DIMUconfigAccel(DIMU, DIMU_ACC_RANGE_2G))
    playSound(soundException);

  if(!DIMUconfigGyro(DIMU, DIMU_GYRO_RANGE_250, true))
    playSound(soundException);

  for (short i = 0; i < 500; i++){

    // Read the GYROSCOPE
    // There are 3 ways to do this:

    // All at once, very convenient if you need all 3
    DIMUreadGyroAxes(DIMU, xvals[i], yvals[i], zvals[i]);
    sleep(5);
  }

  for (short i = 0; i< 500; i++) {
    writeDebugStream("%f, %f",  xvals[i], yvals[i]);
    writeDebugStreamLine(", %f", zvals[i]);
    sleep(2);
  }
}