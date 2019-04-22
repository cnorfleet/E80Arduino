#ifndef __ADCSAMPLER_h__
#define __ADCSAMPLER_h__

#include <Arduino.h>
#include "MotorDriver.h"
#include "DataSource.h"
#include "Pinouts.h"

/*
 * ADCSampler implements SD logging for the ADC channels
 */

#define NUM_PINS 16

class ADCSampler : public DataSource
{
public:
  ADCSampler(void);

  void init();

  // Managing state
  int sample [NUM_PINS];
  int readDepth;
  int IRVolts;
  int greenVolts;
  float turbidity;
  void updateSample(void);
  String printSample(void);

  // Write out
  size_t writeDataBytes(unsigned char * buffer, size_t idx);

  int lastExecutionTime = -1;

private:

  const int pinMap[NUM_PINS] =  {21,14,15,16,17,34,35,36,37,40,26,27,28,29,30,31};
  
  void calcTurb();
  
  int currentTurbidityIdx = 0;
  final const int numberOfTurbidityPoints = 50;
  float lastTurb90  = new float [50];
  float lastTurb190 = new float [50];
};
#endif