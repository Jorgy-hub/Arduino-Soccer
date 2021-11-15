#ifndef INFRAROJO_H
#define INFRAROJO_H
#include <Arduino.h>

/**
 * @brief En esta pequeña libreria de Infrarojos Regresaremos un Valor unico para la deteccion del campo y cada valor unico tendra su propia accion.
 * Ecuacion = Numero de Infrarojo * Numero de Infrarojo con el que coincide
 * 2 = Derecha.
 * 3 = Izquierda.
 * 4 = Atras.
 * 5 = Adelante.
 * 8 = Derecha y Atras.
 * 10 = Derecha y Adelante.
 * 12 = Izquierda y Atras.
 * 15 = Izquierda y Adelante.
 * @param IR_1 
 * @param IR_2 
 * @param IR_3 
 * @param IR_4 
 * @param Detect 
 * @return int 
 */
int DentroCampo(int IR_1, int IR_2, int IR_3, int IR_4, int Detect);

#endif