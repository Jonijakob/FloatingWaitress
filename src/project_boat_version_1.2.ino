#include <nRF24L01.h>
#include <RF24.h> 
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Servo.h> 
#include <SPI.h>

#define enA 8
#define sev 7
#define in1 34
#define in2 36
#define trig 22
#define echo 24
 
byte addresses[][6] = {"0"};
 float callMPU();
 float ultra();
 float x_axis=90;
 float dist;
 float nrf();
 void steering_c();
 void motion_c();

Servo berry; 
MPU6050 mpu6050(Wire);
RF24 myRadio (53, 49);

void setup() {
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT); 
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
 
  berry.attach(sev);
  Serial.begin(9600);
  
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
   myRadio.begin();  
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openWritingPipe( addresses[0]);
  
 
}

void loop() {
  x_axis=callMPU();
  dist=ultra();
  motion_c(dist);
  steering_c(x_axis);
  nrf();
}
 
