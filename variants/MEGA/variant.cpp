#include "Arduino.h"
#include "pinmux.inc"

const uint16_t P400_b[] = {
PIN_PWM|CHANNEL_6|PWM_CHANNEL_A|GPT_ODD_CFG,
PIN_SCL|CHANNEL_0,
PIN_INTERRUPT|CHANNEL_0,
SCI_CHANNEL|PIN_SCK|CHANNEL_0|SCI_EVEN_CFG|LAST_ITEM_GUARD
};
#define P400 P400_b

const uint16_t P408_b[] = {
PIN_PWM|CHANNEL_5|PWM_CHANNEL_B|GPT_ODD_CFG,
PIN_INTERRUPT|CHANNEL_7,
SCI_CHANNEL|PIN_CTS_RTS_SS|CHANNEL_1|SCI_EVEN_CFG,
SCI_CHANNEL|PIN_RX_MISO_SCL|CHANNEL_9|SCI_ODD_CFG|LAST_ITEM_GUARD
};
#define P408 P408_b

const uint16_t P014_b[] = {
PIN_DAC|CHANNEL_0,
PIN_ANALOG|CHANNEL_9|LAST_ITEM_GUARD
};
#define P014 P014_b

extern "C" const PinMuxCfg_t g_pin_cfg[] = { 
  { BSP_IO_PORT_03_PIN_01,    P301   }, /* (0) D0  -------------------------  DIGITAL  */
  { BSP_IO_PORT_03_PIN_02,    P302   }, /* (1) D1  */
  { BSP_IO_PORT_01_PIN_04,    P104   }, /* (2) D2  */
  { BSP_IO_PORT_01_PIN_05,    P105   }, /* (3) D3~ */
  { BSP_IO_PORT_01_PIN_06,    P106   }, /* (4) D4  */
  { BSP_IO_PORT_01_PIN_07,    P107   }, /* (5) D5~ */
  { BSP_IO_PORT_01_PIN_11,    P111   }, /* (6) D6~ */
  { BSP_IO_PORT_01_PIN_12,    P112   }, /* (7) D7  */
  { BSP_IO_PORT_03_PIN_04,    P304   }, /* (8) D8  */
  { BSP_IO_PORT_03_PIN_03,    P303   }, /* (9) D9~  */
  { BSP_IO_PORT_01_PIN_03,    P103   }, /* (10) D10~ */
  { BSP_IO_PORT_04_PIN_11,    P411   }, /* (11) D11~ */
  { BSP_IO_PORT_04_PIN_10,    P410   }, /* (12) D12 */
  { BSP_IO_PORT_01_PIN_02,    P102   }, /* (13) D13 */
  { BSP_IO_PORT_00_PIN_14,    P014   }, /* (14) A0  --------------------------  ANALOG  */
  { BSP_IO_PORT_00_PIN_00,    P000   }, /* (15) A1  */
  { BSP_IO_PORT_00_PIN_01,    P001   }, /* (16) A2  */
  { BSP_IO_PORT_00_PIN_02,    P002   }, /* (17) A3  */
  { BSP_IO_PORT_01_PIN_01,    P101   }, /* (18) A4/SDA  */
  { BSP_IO_PORT_01_PIN_00,    P100   }, /* (19) A5/SCL  */

  { BSP_IO_PORT_05_PIN_00,    P500   }, /* (20) Analog voltage measure pin  */
  { BSP_IO_PORT_04_PIN_08,    P408   }, /* (21) USB switch, drive high for RA4  */

  { BSP_IO_PORT_01_PIN_09,    P109   }, /* (22) D22 ------------------------  TX */
  { BSP_IO_PORT_01_PIN_10,    P110   }, /* (23) D23 ------------------------  RX */
  { BSP_IO_PORT_05_PIN_01,    P501   }, /* (24) D24 ------------------------- TX WIFI */
  { BSP_IO_PORT_05_PIN_02,    P502   }, /* (25) D25 ------------------------- RX WIFI */

  { BSP_IO_PORT_04_PIN_00,    P400   }, /* (26) D26  QWIC SCL */
  { BSP_IO_PORT_04_PIN_01,    P401   }, /* (27) D27  QWIC SDA */

   { BSP_IO_PORT_04_PIN_13,    P413   }, /* (28) LCD_MOSI  */
  { BSP_IO_PORT_04_PIN_15,    P415   }, /* (29) LCD_SCK  */
  { BSP_IO_PORT_04_PIN_08,    P408   }, /* (30) LCD_RESET  */
  { BSP_IO_PORT_04_PIN_12,    P412   }, /* (31) LCD_CS  */
  { BSP_IO_PORT_04_PIN_06,    P406   }, /* (32) LCD_BKL  */


  { BSP_IO_PORT_03_PIN_07,    P307   }, /* (33) BT1  */
  { BSP_IO_PORT_03_PIN_06,    P306   }, /* (34) BT2  */
  { BSP_IO_PORT_03_PIN_05,    P305   }, /* (35) BT3  */

  { BSP_IO_PORT_07_PIN_08,    P708   }, /* (36) IO  */

  
  { BSP_IO_PORT_04_PIN_00,    P400   }, /* (37) MPU_SCK  */
  { BSP_IO_PORT_04_PIN_01,    P401   }, /* (38) MPU_SDA  */

  { BSP_IO_PORT_05_PIN_03,    P503   }, /* (39) LED2  */
  { BSP_IO_PORT_05_PIN_04,    P504   }, /* (40) LED3  */
  { BSP_IO_PORT_05_PIN_05,    P505   }, /* (41) LED4  */


  { BSP_IO_PORT_00_PIN_12,    P012   }, /* (42) IO1*/
  { BSP_IO_PORT_00_PIN_13,    P013   }, /* (43) IO2*/
  { BSP_IO_PORT_00_PIN_07,    P007   }, /* (44) IO3*/
  { BSP_IO_PORT_00_PIN_08,    P008   }, /* (45) IO4*/
  { BSP_IO_PORT_00_PIN_05,    P005   }, /* (46) IO5*/
  { BSP_IO_PORT_00_PIN_06,    P006   }, /* (47) IO6*/


  { BSP_IO_PORT_01_PIN_13,    P113   }, /* (48) IO*/


  { BSP_IO_PORT_01_PIN_15,    P115   }, /* (49) SERVO_PWM_1*/
  { BSP_IO_PORT_01_PIN_14,    P114   }, /* (50) SERVO_PWM_2*/
  { BSP_IO_PORT_06_PIN_00,    P600   }, /* (51) SERVO_PWM_3*/
  { BSP_IO_PORT_06_PIN_03,    P603   }, /* (52) SERVO_PWM_4*/

  { BSP_IO_PORT_08_PIN_09,    P809   }, /* (53) Dynamixel_TX_EN*/
  { BSP_IO_PORT_02_PIN_06,    P206   }, /* (54) MCU_RX_Dynamixel*/
  { BSP_IO_PORT_02_PIN_05,    P205   }, /* (55) MCU_TX_Dynamixel*/

  { BSP_IO_PORT_06_PIN_01,    P601   }, /* (56) IO */
  { BSP_IO_PORT_06_PIN_02,    P602   }, /* (57) IO */
  { BSP_IO_PORT_08_PIN_08,    P808   }, /* (58) IO */

  { BSP_IO_PORT_02_PIN_12,    P212   }, /* (59) IN1_M4  */
  
  
  { BSP_IO_PORT_02_PIN_13,    P213   }, /* (60) IO */
  
  { BSP_IO_PORT_04_PIN_14,    P414   }, /* (61) IN2_M4  */
  { BSP_IO_PORT_02_PIN_02,    P202   }, /* (62) IN1_M3  */
  { BSP_IO_PORT_06_PIN_10,    P610   }, /* (63) IN2_M3  */
  { BSP_IO_PORT_02_PIN_03,    P203   }, /* (64) IN2_M2  */
  { BSP_IO_PORT_06_PIN_09,    P609   }, /* (65) IN1_M2  */
  { BSP_IO_PORT_06_PIN_08,    P608   }, /* (66) IN1_M1  */
  { BSP_IO_PORT_02_PIN_04,    P204   }, /* (67) IN2_M1  */

  { BSP_IO_PORT_04_PIN_04,    P404   }, /* (68) BUZZ  */

  { BSP_IO_PORT_04_PIN_09,    P409   }, /* (69) BT4  */

};

extern "C" {
    unsigned int PINCOUNT_fn() {
        return (sizeof(g_pin_cfg) / sizeof(g_pin_cfg[0]));
    }
}

int32_t getPinIndex(bsp_io_port_pin_t p) {
  int max_index = PINS_COUNT;
  int rv = -1;
  for(int i = 0; i < max_index; i++) {
    if(g_pin_cfg[i].pin == p) {
      rv = i;
      break;
    }
  }
  return rv;
}

#define BSP_PRV_PRCR_KEY                (0xA500U)
#define BSP_PRV_PRCR_PRC1_UNLOCK        ((BSP_PRV_PRCR_KEY) | 0x2U)
#define BSP_PRV_PRCR_LOCK               ((BSP_PRV_PRCR_KEY) | 0x0U)
// if _USBStart is called, this will swap the USB port over the ESP one
void configure_usb_mux() {
  R_SYSTEM->PRCR = (uint16_t) BSP_PRV_PRCR_PRC1_UNLOCK;
  (*((volatile uint32_t *) &R_SYSTEM->VBTBKR[1])) = 40;
  R_SYSTEM->PRCR = (uint16_t) BSP_PRV_PRCR_LOCK;

  pinMode(21, OUTPUT);
  digitalWrite(21, HIGH);
}

#include "FspTimer.h"

__attribute__((weak)) void __maybe_start_usb() {}

void usb_post_initialization() {
  ((R_USB_FS0_Type*)R_USB_FS0_BASE)->USBMC_b.VDCEN = 1;
}

void enableSubclockInputPins() {
  R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_CGC);
  R_SYSTEM->SOSCCR_b.SOSTP = 1;
  R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_CGC);
}

void initVariant() {
  __maybe_start_usb();
  // bootloader configures LED_BUILTIN as PWM output, deconfigure it to avoid spurious signals
  pinMode(LED_BUILTIN, OUTPUT);
  //pinMode(LEDB, OUTPUT);
  //pinMode(LEDR, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  //digitalWrite(LEDB, LOW);
  //digitalWrite(LEDR, LOW);
  FspTimer::set_initial_timer_channel_as_pwm(GPT_TIMER, GET_CHANNEL(getPinCfgs(3, PIN_CFG_REQ_PWM)[0]));
  FspTimer::set_initial_timer_channel_as_pwm(GPT_TIMER, GET_CHANNEL(getPinCfgs(5, PIN_CFG_REQ_PWM)[0]));
  FspTimer::set_initial_timer_channel_as_pwm(GPT_TIMER, GET_CHANNEL(getPinCfgs(6, PIN_CFG_REQ_PWM)[0]));
  FspTimer::set_initial_timer_channel_as_pwm(GPT_TIMER, GET_CHANNEL(getPinCfgs(9, PIN_CFG_REQ_PWM)[0]));
  FspTimer::set_initial_timer_channel_as_pwm(GPT_TIMER, GET_CHANNEL(getPinCfgs(10, PIN_CFG_REQ_PWM)[0]));
  FspTimer::set_initial_timer_channel_as_pwm(GPT_TIMER, GET_CHANNEL(getPinCfgs(11, PIN_CFG_REQ_PWM)[0]));
}
