/*************************************************** 
 This is a library for the FaBo Humidity I2C Brick.

  http://fabo.io/208.html

 author:FaBo<info@fabo.io>
 maintainer:Akira Sasaki<akira@fabo.io>

 Released under APACHE LICENSE, VERSION 2.0
  http://www.apache.org/licenses/
 ****************************************************/

#ifndef FABOHUMIDITY_HTS221_H
#define FABOHUMIDITY_HTS221_H

#include <Arduino.h>
#include <Wire.h>

// I2C Slave Address
#define HTS221_SLAVE_ADDRESS 0x5F
// Who am i device identifier
#define HTS221_DEVICE_ID 0xBC

// AV_CONF
// Averaged humidity samples configuration
#define HTS221_AVGH_4   0b000
#define HTS221_AVGH_8   0b001
#define HTS221_AVGH_16  0b010
#define HTS221_AVGH_32  0b011 // defalut
#define HTS221_AVGH_64  0b100
#define HTS221_AVGH_128 0b101
#define HTS221_AVGH_256 0b110
#define HTS221_AVGH_512 0b111
// Averaged temperature samples configuration
#define HTS221_AVGT_2   0b000000
#define HTS221_AVGT_4   0b001000
#define HTS221_AVGT_8   0b010000
#define HTS221_AVGT_16  0b011000 // defalut
#define HTS221_AVGT_32  0b100000
#define HTS221_AVGT_64  0b101000
#define HTS221_AVGT_128 0b110000
#define HTS221_AVGT_256 0b111000

// CTRL_REG1
// Power Down control
#define HTS221_PD  0b10000000
// Block Data Update control
#define HTS221_BDU 0b100
// Output Data Rate control
#define HTS221_ODR_ONE   0b00
#define HTS221_ODR_1HZ   0b01
#define HTS221_ODR_7HZ   0b10
#define HTS221_ODR_125HZ 0b11

// CTRL_REG2
// Reboot memory content
#define HTS221_BOOT  0b10000000
// Heater
#define HTS221_HEATER  0b10
// One shot enable
#define HTS221_ONE_SHOT  0b1

// CTRL_REG3
// DRDY pin is no connect in FaBo Brick
#define HTS221_CTRL_REG3_DEFAULT 0x00

// STATUS_REG
// Humidity Data Available
#define HTS221_H_DA 0x2
// Temperature Data Available
#define HTS221_T_DA 0x1

// Register Address
#define HTS221_WHO_AM_I 0x0F
#define HTS221_AV_CONF 0x10
#define HTS221_CTRL_REG1 0x20
#define HTS221_CTRL_REG2 0x21
#define HTS221_CTRL_REG3 0x22
#define HTS221_STATUS_REG 0x27
#define HTS221_HUMIDITY_OUT_L 0x28
#define HTS221_HUMIDITY_OUT_H 0x29
#define HTS221_TEMP_OUT_L 0x2A
#define HTS221_TEMP_OUT_H 0x2B

#define HTS221_H0_RH_X2 0x30
#define HTS221_H1_RH_X2 0x31
#define HTS221_T0_DEGC_X8 0x32
#define HTS221_T1_DEGC_X8 0x33
#define HTS221_T1_T0_MSB 0x35
#define HTS221_H0_T0_OUT_L 0x36
#define HTS221_H0_T0_OUT_H 0x37
#define HTS221_H1_T0_OUT_L 0x3A
#define HTS221_H1_T0_OUT_H 0x3B
#define HTS221_T0_OUT_L 0x3C
#define HTS221_T0_OUT_H 0x3D
#define HTS221_T1_OUT_L 0x3E
#define HTS221_T1_OUT_H 0x3F


class FaBoHumidity_HTS221 {
  public:
    FaBoHumidity_HTS221(uint8_t addr = HTS221_SLAVE_ADDRESS);
    bool begin(void);
    bool checkDevice(void);
    void powerOn(void);
    void configDevice(void);
    void readCoef(void);
    double getHumidity(void);
    double getTemperature(void);
  private:
    uint8_t _i2caddr;
    uint8_t _H0_rH_x2, _H1_rH_x2;
    uint16_t _T0_degC_x8, _T1_degC_x8;
    int16_t _H0_T0_OUT, _H1_T0_OUT;
    int16_t _T0_OUT, _T1_OUT;
    uint8_t readI2c(uint8_t registerAddr);
    void writeI2c(uint8_t registerAddr, uint8_t data);
};

#endif // FABOHUMIDITY_HTS221_H
