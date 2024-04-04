#include <Servo.h>

#define NUM_SERVOS 2 // 5 servos for each finger

Servo servos[NUM_SERVOS]; // create servo objects
int servoPins[NUM_SERVOS] = {8,9}; // pin locations
int servoAngles[NUM_SERVOS] = {0,0}; // angle of each servo 

void setup() {
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(servoPins[i]); // attach servos to pin locations
  }
}

void loop() {

  pow();

  // move all servos to respective angle
  // for (int i = 0; i < NUM_SERVOS; i++) {
  //   moveServo(i, servoAngles[i]); // call method
  // }
}

void moveServo(int servoIndex, int position) {
  // Limit position to avoid overextension
  position = constrain(position, 0, 180);
  // Move the servo to the desired position
  servos[servoIndex].write(position);
}

// move all servos from 0 degrees to 180 degrees
void pow() {
  for (int i = 0; i < NUM_SERVOS; i++) {
    moveServo(i, 0);
  }

  delay(1000);

  for (int i = 0; i < NUM_SERVOS; i++) {
    moveServo(i, 180);
  }

  delay(1000);
}
