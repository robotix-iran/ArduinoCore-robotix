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

  // Use Serial to debug.
  DEBUG_SERIAL.begin(115200);

  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(57600);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
}

void loop() {
  // put your main code here, to run repeatedly:

  DEBUG_SERIAL.print("PROTOCOL ");
  DEBUG_SERIAL.print(DXL_PROTOCOL_VERSION, 1);
  DEBUG_SERIAL.print(", ID ");
  DEBUG_SERIAL.print(DXL_ID);
  DEBUG_SERIAL.print(": ");
  if(dxl.ping(DXL_ID) == true){
    DEBUG_SERIAL.print("ping succeeded!");
    DEBUG_SERIAL.print(", Model Number: ");
    DEBUG_SERIAL.println(dxl.getModelNumber(DXL_ID));
  }else{
    DEBUG_SERIAL.print("ping failed!, err code: ");
    DEBUG_SERIAL.println(dxl.getLastLibErrCode());
  }
  delay(500);

  FindServos();
}


DYNAMIXEL::InfoFromPing_t ping_info[32];
void FindServos(void) {
  Serial.println("  Try Protocol 2 - broadcast ping: ");
  Serial.flush(); // flush it as ping may take awhile... 
      
  if (uint8_t count_pinged = dxl.ping(DXL_BROADCAST_ID, ping_info, 
    sizeof(ping_info)/sizeof(ping_info[0]))) {
    Serial.print("Detected Dynamixel : \n");
    for (int i = 0; i < count_pinged; i++)
    {
      Serial.print("    ");
      Serial.print(ping_info[i].id, DEC);
      Serial.print(", Model:");
      Serial.print(ping_info[i].model_number);
      Serial.print(", Ver:");
      Serial.println(ping_info[i].firmware_version, DEC);
      //g_servo_protocol[i] = 2;
    }
  }else{
    Serial.print("Broadcast returned no items : ");
    Serial.println(dxl.getLastLibErrCode());
  }
}