/*******************************************************************************
* Copyright 2016 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <Dynamixel2Arduino.h>

#define DXL_SERIAL Serial3
#define DEBUG_SERIAL Serial
#define DXL_DIR_PIN 53

#define TIMEOUT 10    //default communication timeout 10ms
const uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 2.0;
uint8_t option = 0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

void setup() {
  // put your setup code here, to run once:
  
  // Use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);   //Set debugging port baudrate to 115200bps
  while(!DEBUG_SERIAL);         //Wait until the serial port for terminal is opened
  
  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(57600);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
}

void loop() {
  // put your main code here, to run repeatedly:

  bool ret = false;
  DEBUG_SERIAL.println();
  DEBUG_SERIAL.println("Reboot DYNAMIXEL? [y/n]");

  DEBUG_SERIAL.read();
  while(DEBUG_SERIAL.available()==0);
  option = DEBUG_SERIAL.read();

  switch(option) {
    case 'y':
    case 'Y':
      ret = dxl.reboot(DXL_ID, TIMEOUT);
      break;
    default:
      break;
  }
  if(ret) {
    DEBUG_SERIAL.println("Reboot Succeeded!");
  } else {
    DEBUG_SERIAL.println("Reboot Failed!");
  }

  delay(1000);
}