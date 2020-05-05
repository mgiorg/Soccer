/**
 * imu.cpp
 * @author Massimo Giordano
 */

#include "imu.hpp"

Imu::Imu(): bno(55) {
  bno.begin(bno.OPERATION_MODE_IMUPLUS);

  heading = 0;
}

void Imu::init() {

}

void Imu::read() {
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  heading = euler.x();  //Lettura dell'asse x

  if(heading > 180) {
    heading -= 360;
  }
  /**
   * Questo passagio serve per portare la lettura della bussola
   * da 0 % 360 a -180 % +180
   */
}

int Imu::getHeading() {
  return heading;
}
