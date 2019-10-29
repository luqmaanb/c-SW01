/**
 * @file xSW01.h
 * @author XinaBox (support@xinabox.cc)
 * @brief 
 * @version 0.1
 * @date 2019-10-22
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef xSW01_h
#define xSW01_h

// System Includes
#include <inttypes.h>
#include <Arduino.h>
#include "xCore.h"
#include "math.h"

// Register Defines
#define BME280_REG_SOFTRESET   		0xE0

#define BME280_REG_CAL26     		0xE1
#define BME280_REG_CONTROLHUMID 	0xF2
#define BME280_REG_STATUS       	0XF3
#define BME280_REG_CONTROLMEASURE   0xF4
#define BME280_REG_CONFIG         	0xF5
#define BME280_REG_PRESSURE  		0xF7
#define BME280_REG_TEMP_MSB    		0xFA
#define BME280_REG_TEMP_CSB    		0xFB
#define BME280_REG_TEMP_LSB    		0xFC
#define BME280_REG_HUMID    		0xFD

#define BME280_DIG_T1_REG   		0x88
#define BME280_DIG_T2_REG   		0x8A
#define BME280_DIG_T3_REG   		0x8C
#define BME280_DIG_P1_REG   		0x8E
#define BME280_DIG_P2_REG   		0x90
#define BME280_DIG_P3_REG   		0x92
#define BME280_DIG_P4_REG   		0x94
#define BME280_DIG_P5_REG   		0x96
#define BME280_DIG_P6_REG   		0x98
#define BME280_DIG_P7_REG   		0x9A
#define BME280_DIG_P8_REG   		0x9C
#define BME280_DIG_P9_REG   		0x9E
    
#define BME280_DIG_H1_REG   		0xA1
#define BME280_DIG_H2_REG   		0xE1
#define BME280_DIG_H3_REG   		0xE3
#define BME280_DIG_H4_REG   		0xE4
#define BME280_DIG_H5_REG   		0xE5
#define BME280_DIG_H6_REG   		0xE7

// Oversampling Defines
#define BME_OSR_1					0x01
#define BME_OSR_2					0x02
#define BME_OSR_4					0x03
#define BME_OSR_8					0x04

// Device ID
#define BME280_REG_CHIPID      		0xD0
#define BME280_DEVICE_ID         	0x60

struct BME280_Calibration_Data
{
    public:
    
			uint16_t dig_T1;
	    int16_t  dig_T2;
	    int16_t  dig_T3;

	    uint16_t dig_P1;
	    int16_t  dig_P2;
	    int16_t  dig_P3;
	    int16_t  dig_P4;
	    int16_t  dig_P5;
	    int16_t  dig_P6;
	    int16_t  dig_P7;
	    int16_t  dig_P8;
	    int16_t  dig_P9;

	    uint8_t  dig_H1;
	    int16_t  dig_H2;
	    uint8_t  dig_H3;
	    int16_t  dig_H4;
	    int16_t  dig_H5;
	    int8_t   dig_H6;
    
};

/**@addtogroup SW01
 * 
 *  @{
 */

/**
 * @brief This class provides members to establish readings from the BME680 environmental sensor.
 * 
 * Readings include:
 * \li Ambient Temperature
 * \li Relative Humidity
 * \li Atmospheric Pressure
 */
class xSW01: public xCoreClass
{
    public:
		/**
	 	* @brief Construct a new x S W01 object
	 	* 
	 	*/
		xSW01();

		/**
	 	* @brief Construct a new x S W01 object
	 	* 
	 	* @param addr 
	 	*/
		xSW01(uint8_t addr);
		
		/**
		 * @brief 
		 * 
		 * @return true 
		 * @return false
		 */
		bool 	begin();

		/**
		 * @brief Set the Temp Cal object
		 * 
		 * @param offset 
		 */
		void 	setTempCal(float offset);

		/**
		 * @brief 
		 * 
		 */
		void 	poll(void);

		/**
		 * @brief Get the Temp C object
		 * 
		 * @return float 
		 */
		float 	getTempC(void);

		/**
		 * @brief Get the Temp F object
		 * 
		 * @return float 
		 */
		float 	getTempF(void);

		/**
		 * @brief Get the Humidity object
		 * 
		 * @return float 
		 */
		float 	getHumidity(void);

		/**
		 * @brief Get the Pressure object
		 * 
		 * @return float 
		 */
		float 	getPressure(void);

		/**
		 * @brief 
		 * 
		 * @return float 
		 */
		float 	getQNE(void);

		/**
		 * @brief Get the Altitude object
		 * 
		 * @param sea_level_pressure 
		 * @return float 
		 */
		float 	getAltitude(float sea_level_pressure);

		/**
		 * @brief Get the Dew Point object
		 * 
		 * @return float 
		 */
		float 	getDewPoint(void);	
		
	private:	
		BME280_Calibration_Data cal_data;		
		float readTemperature(void);		
		float readPressure(void);	
		float readHumidity(void);		
		void readSensorCoefficients(void);
    
		float   tempcal;							// stores the temp offset calibration
		int32_t t_fine;
		
		
		//Device I2C Address
		uint8_t BME280_I2C_ADDRESS;

		
};
/** @} */

/**@example SW01_Humidity_Measurement.ino
 * @example SW01_Altitude_Measurement.ino
 * @example SW01_Pressure_Measurement.ino
 * @example SW01_Temperature_Measurement.ino
 */
#endif
