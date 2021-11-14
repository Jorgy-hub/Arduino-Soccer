#include "Motors.h"

void Mover_Motor(Motor motor, int state_p, int state_n, int speed){
    digitalWrite(motor.ena, speed);
    digitalWrite(motor.vcc, state_p);
    digitalWrite(motor.gnd, state_n); 
}

void GirarAngulo(float Angulo_1, float Angulo_2, Motor motor[3]){
    // Giro hacia la derecha.
    if(Angulo_1 > Angulo_2){
        Mover_Motor(motor[0], 1, 0, 255);
        Mover_Motor(motor[1], 0, 0, 255);
        Mover_Motor(motor[1], 1, 0, 255);
    // Giro hacia la izquierda.
    } else if(Angulo_1 < Angulo_2){
        Mover_Motor(motor[0], 0, 0, 255);
        Mover_Motor(motor[1], 1, 0, 255);
        Mover_Motor(motor[1], 0, 1, 255);
    }
}

void Movimientos(float X, float Y, float Center, float Close, Motor motor[3]){
    // Derecha.
    if(X > Center){
        Mover_Motor(motor[0], 0, 0, 255);
        Mover_Motor(motor[1], 0, 0, 255);
        Mover_Motor(motor[2], 0, 1, 255);
    // Izquierda.
    }else if(X < Center){
        Mover_Motor(motor[0], 0, 0, 255);
        Mover_Motor(motor[1], 0, 0, 255);
        Mover_Motor(motor[2], 1, 0, 255);
    // Centrada.
    }else if(X == Center){
        // Acercar.
        if(Y < Close){
            Mover_Motor(motor[0], 1, 0, 255);
            Mover_Motor(motor[1], 1, 0, 255);
            Mover_Motor(motor[2], 0, 0, 255);
        }
    }
}