#ifndef MOTORS_H
#define MOTORS_H
#include <Arduino.h>

// Structura Motor usada para crear nuevos motores ya estableciendo ambos pines.
struct Motor {
    int gnd;
    int vcc;
};

// Funciones para Control de Motores.
void Mover_Motor(Motor motor, int speed_p, int speed_n);
void Mover_Robot(double Inicio[2], double Final[2]);

#endif
