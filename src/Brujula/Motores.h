#ifndef MOTORES_H
#define MOTORES_H
#include <Arduino.h>

// Structura Motor usada para crear nuevos motores ya estableciendo ambos pines.
struct Motor {
    int gnd;
    int vcc;
    int ena;
};

/**
 * @brief Funcion para Mover ambos lados de Motores solo con las Velocidades.
 * @param motor 
 * @param state_p Establecer en 255 o 0 para Detener o Avanzar.
 * @param state_n Establecer en 255 o 0 para Detener o Avanzar.
 * @param speed   Velocidad del enable del Puente H.
 */
void MoverMotor(Motor motor, int state_p, int state_n, int speed);

/**
 * @brief Funcion para girar el robot hacia un angulo especifico.
 * 
 * @param Angulo_1 Angulo Actual.
 * @param Angulo_2 Angulo a girar.
 * @param motor 
 */
void GirarAngulo(float Angulo_1, float Angulo_2, Motor motor[3]);

/**
 * @brief Funcion para mover el robot hacia los diferentes lados.
 * 
 * @param X 
 * @param Y 
 * @param Center 
 * @param CenterTolerance 
 * @param Close 
 * @param CloseTolerance 
 * @param motor 
 */
void Movimientos(float X, float Y, float Center, float Close, Motor motor[3]);

#endif