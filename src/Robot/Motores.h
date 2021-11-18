#ifndef MOTORES_H
#define MOTORES_H
#include <Arduino.h>

// Structura Motor usada para crear nuevos motores ya estableciendo ambos pines.
struct Motor {
    int gnd;
    int vcc;
    int ena;
};

class MOTORES {
    Motor Motores[3];
    public:
        /**
         * @brief Iniciar Motores establecidos.
         * @param A 
         */
        void Initialize(Motor A[3]);
        /**
        * @brief Funcion para girar el robot hacia un angulo especifico.
        * 
        * @param Angulo_1 Angulo Actual.
        * @param Angulo_2 Angulo a girar.
        * @param motor 
        */
        void GirarAngulo(float Angulo_1, float Angulo_2);
        /**
        * @brief Funcion para Mover ambos lados de Motores solo con las Velocidades.
        * @param motor 
        * @param state_p Establecer en 255 o 0 para Detener o Avanzar.
        * @param state_n Establecer en 255 o 0 para Detener o Avanzar.
        * @param speed   Velocidad del enable del Puente H.
        */
        void MoverMotor(Motor motor, int state_p, int state_n, int speed);
        /**
         * @brief Movimientos Basicos del Robot.
         * @param Direccion 
         */
        void Movimientos(char *Direccion);
        /**
         * @brief Jugada de Delantero.
         * @param X 
         * @param Y 
         * @param Center 
         * @param Close 
         */
        void Delantero(float X, float Y, float Center, float Close);
        /**
         * @brief Jugada de Defensa.
         * @param X 
         * @param Center 
         */
        void Defensa(float X, float Center);
};

#endif