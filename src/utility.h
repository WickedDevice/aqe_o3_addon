/*
 * utility.h
 *
 *  Created on: Jul 24, 2012
 *      Author: vic
 */

#ifndef UTILITY_H_
#define UTILITY_H_

/* TWI constants and prototypes */
#define TWI_SLAVE_ADDRESS               3   // must be less than 127
#define TWI_BUFFER_SIZE                 8
#define TWI_GET_NUM_SENSORS_ATTACHED    0x00 // no parameters
#define TWI_GET_RAW_SENSOR_VALUE        0x11 // parameter = sensor index
#define TWI_GET_CALUCLATED_SENSOR_VALUE 0x22 // parameter = sensor index

#define POWER_LED_PORT PORTB
#define POWER_LED_DDR  DDRB
#define POWER_LED_PIN  2
// macro to work with Power LED
#define POWER_LED 1
#define POWER_LED_INIT() do{ \
        POWER_LED_DDR  |= _BV(POWER_LED_PIN); \
        POWER_LED_PORT &= ~_BV(POWER_LED_PIN); \
    }while(0)
#define POWER_LED_ON() do{ \
        POWER_LED_PORT |= _BV(POWER_LED_PIN); \
    }while(0)
#define POWER_LED_OFF() do{ \
        POWER_LED_PORT &= ~_BV(POWER_LED_PIN); \
    }while(0)
#define POWER_LED_TOGGLE() do{ \
        POWER_LED_PORT ^= _BV(POWER_LED_PIN); \
    }while(0)


#define STATUS_LED 0
#define STATUS_LED_PORT PORTB
#define STATUS_LED_DDR  DDRB
#define STATUS_LED_PIN  1
// macro to work with Status LED
#define STATUS_LED_INIT() do{ \
        STATUS_LED_DDR  |= _BV(STATUS_LED_PIN); \
        STATUS_LED_PORT &= ~_BV(STATUS_LED_PIN); \
    }while(0)
#define STATUS_LED_ON() do{ \
        STATUS_LED_PORT |= _BV(STATUS_LED_PIN); \
    }while(0)
#define STATUS_LED_OFF() do{ \
        STATUS_LED_PORT &= ~_BV(STATUS_LED_PIN); \
    }while(0)
#define STATUS_LED_TOGGLE() do{ \
        STATUS_LED_PORT ^= _BV(STATUS_LED_PIN); \
    }while(0)

#define ENABLE_O3_HEATER_PORT PORTD
#define ENABLE_O3_HEATER_DDR  DDRD
#define ENABLE_O3_HEATER_PIN  0
// macro to work with O3 Heater Enable
#define O3_HEATER_INIT() do{ \
        ENABLE_O3_HEATER_DDR  |= _BV(ENABLE_O3_HEATER_PIN); \
        ENABLE_O3_HEATER_PORT &= ~_BV(ENABLE_O3_HEATER_PIN); \
    }while(0)
#define ENABLE_O3_HEATER() do{ \
        ENABLE_O3_HEATER_PORT |= _BV(ENABLE_O3_HEATER_PIN); \
    }while(0)
#define DISABLE_O3_HEATER() do{ \
        ENABLE_O3_HEATER_PORT &= ~_BV(ENABLE_O3_HEATER_PIN); \
    }while(0)
#define ENABLE_O3_HEATER_TOGGLE() do{ \
        ENABLE_O3_HEATER_PORT ^= _BV(ENABLE_O3_HEATER_PIN); \
    }while(0)

#define O3_R1_DDR  DDRC
#define O3_R1_PORT PORTC
#define O3_R1_PIN  7
// GND output
#define O3_R2_DISABLE() do{ \
        O3_R1_DDR  |= _BV(O3_R1_PIN);\
        O3_R1_PORT &= ~_BV(O3_R1_PIN);\
    } while(0);
// high impedance input
#define O3_R2_ENABLE() do{ \
        O3_R1_DDR  &= ~_BV(O3_R1_PIN);\
        O3_R1_PORT &= ~_BV(O3_R1_PIN);\
    } while(0);

#define O3_R2_DDR  DDRD
#define O3_R2_PORT PORTD
#define O3_R2_PIN  1
// GND output
#define O3_R3_DISABLE() do{ \
        O3_R2_DDR  |= _BV(O3_R2_PIN);\
        O3_R2_PORT &= ~_BV(O3_R2_PIN);\
    } while(0);
// high impedance input
#define O3_R3_ENABLE() do{ \
        O3_R2_DDR  &= ~_BV(O3_R2_PIN);\
        O3_R2_PORT &= ~_BV(O3_R2_PIN);\
    } while(0);

// low side resistances in ohms
#define O3_SENSOR_R1 1800L
#define O3_SENSOR_R2 18000L
#define O3_SENSOR_R3 180000L

// divider switchover ADC values
#define O3_R1R2R3_THRESHOLD   860L
#define O3_R1R2_THRESHOLD     675L

#define O3_VCC_TENTH_VOLTS   50L
#define ADC_VCC_TENTH_VOLTS  50L

/* Utility constants and prototypes */
void blinkLEDs(uint8_t n, uint8_t which_led);
void delay_sec(uint8_t n);
uint16_t byte2uint16(uint8_t high_byte, uint8_t low_byte);
uint8_t uint16_high_byte(uint16_t uint16);
uint8_t uint16_low_byte(uint16_t uint16);

void big_endian_copy_uint32_to_buffer(uint32_t value, uint8_t * buffer);

uint32_t get_r1(uint8_t sensor_index);
uint32_t get_r2(uint8_t sensor_index);
uint32_t get_r3(uint8_t sensor_index);

uint16_t get_r1r2r3_threshold(uint8_t sensor_index);
uint16_t get_r1r2_threshold(uint8_t sensor_index);

uint8_t get_sensor_vcc(uint8_t sensor_index);
void SENSOR_R2_ENABLE(uint8_t sensor_index);
void SENSOR_R3_ENABLE(uint8_t sensor_index);
void SENSOR_R2_DISABLE(uint8_t sensor_index);
void SENSOR_R3_DISABLE(uint8_t sensor_index);

#endif /* UTILITY_H_ */