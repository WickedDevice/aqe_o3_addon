/*
 * interpolation.c
 *
 *  Created on: Oct 21, 2012
 *      Author: vic
 */

#include "interpolation.h"
#include "egg_bus.h"
#include <float.h>

#define INTERPOLATION_X_INDEX 0
#define INTERPOLATION_Y_INDEX 1
#define INTERPOLATION_TERMINATOR 0xff

// these are the conversion factors required to turn into floating point values (multiply table values by these)
const float x_scaler[EGG_BUS_NUM_HOSTED_SENSORS] = {0.015f};
const float y_scaler[EGG_BUS_NUM_HOSTED_SENSORS] = {1.35f};
const float independent_scaler[EGG_BUS_NUM_HOSTED_SENSORS] = {0.001f};
const uint32_t independent_scaler_inverse[EGG_BUS_NUM_HOSTED_SENSORS] = { 1000L };

// get_x_or_get_y = 0 returns x value from table, get_x_or_get_y = 1 returns y value from table
uint8_t getTableValue(uint8_t sensor_index, uint8_t table_index, uint8_t get_x_or_get_y){

    // the values MUST be provided in ascending order of x-value
    const uint8_t o3_ppb[][2] = {
            {4,7},
            {5,9},
            {6,10},
            {7,11},
            {13,18},
            {20,25},
            {27,32},
            {34,39},
            {40,46},
            {47,52},
            {54,60},
            {60,66},
            {68,74},
            {135,155},
            {201,247},
            {INTERPOLATION_TERMINATOR, INTERPOLATION_TERMINATOR}
    };

    // sensor index 0 is the O3 sensor
    uint8_t return_value = 0;
    if(sensor_index == 0){
        return_value = o3_ppb[table_index][get_x_or_get_y];
    }

    return return_value;
}

uint8_t * get_p_x_scaler(uint8_t sensor_index){
    return (uint8_t *) &(x_scaler[sensor_index]);
}

uint8_t * get_p_y_scaler(uint8_t sensor_index){
    return (uint8_t *) &(y_scaler[sensor_index]);
}

uint8_t * get_p_independent_scaler(uint8_t sensor_index){
    return (uint8_t *) &(independent_scaler[sensor_index]);
}

uint32_t get_independent_scaler_inverse(uint8_t sensor_index){
    return independent_scaler_inverse[sensor_index];
}
