#ifndef BRUJULA_H
#define BRUJULA_H
#include <Wire.h>
#include "HMC5883L.h"

/**
 * @brief Funcion utilizada para obtener el Angulo actual en el que esta la Brujula.
 * @param Brujula 
 * @return float 
 */
float Angulo(HMC5883L Brujula);

#endif