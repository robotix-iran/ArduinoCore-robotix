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
 

const uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 2.0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

//This namespace is required to use Control table item names
using namespace ControlTableItem;

void setup() {
  // put your setup code here, to run once:
  
  // Use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);
  
  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(57600);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  // Get DYNAMIXEL information
  dxl.ping(DXL_ID);

  // Turn off torque when configuring items in EEPROM area
  dxl.torqueOff(DXL_ID);
  dxl.setOperatingMode(DXL_ID, OP_CURRENT);
  dxl.torqueOn(DXL_ID);
}

void loop() {
  // put your main code here, to run repeatedly:
   
  // Please refer to e-Manual(http://emanual.robotis.com/docs/en/parts/interface/dynamixel_shield/) for available range of value. 
  // Set Goal Current using RAW unit
  dxl.setGoalCurrent(DXL_ID, 200);
  delay(1000);
  // Print present current
  DEBUG_SERIAL.print("Present Current(raw) : ");
  DEBUG_SERIAL.println(dxl.getPresentCurrent(DXL_ID));
  delay(1000);

  // Set Goal Current using mA unit
  dxl.setGoalCurrent(DXL_ID, 25.8, UNIT_MILLI_AMPERE);
  delay(1000);
  DEBUG_SERIAL.print("Present Current(mA) : ");
  DEBUG_SERIAL.println(dxl.getPresentCurrent(DXL_ID, UNIT_MILLI_AMPERE));
  delay(1000);

  // Set Goal Current using percentage (-100.0 [%] ~ 100.0[%])
  dxl.setGoalCurrent(DXL_ID, -10.2, UNIT_PERCENT);
  delay(1000);
  DEBUG_SERIAL.print("Present Current(ratio) : ");
  DEBUG_SERIAL.println(dxl.getPresentCurrent(DXL_ID, UNIT_PERCENT));
  delay(1000);
}
