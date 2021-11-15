#include "Motors.h"

MOTORES::MOTORES(Motor A[3]){
    for(int i = 0; i < 3; i++)
        Motores[i] = A[i];
}

void MOTORES::Mover_Motor(Motor motor, int state_p, int state_n, int speed){
    digitalWrite(motor.ena, speed);
    digitalWrite(motor.vcc, state_p);
    digitalWrite(motor.gnd, state_n); 
}

void MOTORES::GirarAngulo(float Angulo_1, float Angulo_2){
    // Giro hacia la derecha.
    if(Angulo_1 > Angulo_2){
        MOTORES::Mover_Motor(Motores[0], 1, 0, 255);
        MOTORES::Mover_Motor(Motores[1], 0, 0, 255);
        MOTORES::Mover_Motor(Motores[2], 1, 0, 255);
    // Giro hacia la izquierda.
    } else if(Angulo_1 < Angulo_2){
        MOTORES::Mover_Motor(Motores[0], 0, 0, 255);
        MOTORES::Mover_Motor(Motores[1], 1, 0, 255);
        MOTORES::Mover_Motor(Motores[2], 0, 1, 255);
    }
}

void MOTORES::Movimientos(char *Direccion){
    if(Direccion == "DERECHA"){
        MOTORES::Mover_Motor(Motores[0], 0, 0, 255);
        MOTORES::Mover_Motor(Motores[1], 0, 0, 255);
        MOTORES::Mover_Motor(Motores[2], 0, 1, 255);
    } else if(Direccion == "IZQUIERDA"){
        MOTORES::Mover_Motor(Motores[0], 0, 0, 255);
        MOTORES::Mover_Motor(Motores[1], 0, 0, 255);
        MOTORES::Mover_Motor(Motores[2], 1, 0, 255);
    } else if(Direccion == "ATRAS"){
        MOTORES::Mover_Motor(Motores[0], 0, 1, 255);
        MOTORES::Mover_Motor(Motores[1], 0, 1, 255);
        MOTORES::Mover_Motor(Motores[2], 0, 0, 255);
    } else if(Direccion == "ADELANTE"){
        MOTORES::Mover_Motor(Motores[0], 1, 0, 255);
        MOTORES::Mover_Motor(Motores[1], 1, 0, 255);
        MOTORES::Mover_Motor(Motores[2], 0, 0, 255);
    }
}

void MOTORES::Delantero(float X, float Y, float Center, float Close){
    // Derecha.
    if(X > Center){
        MOTORES::Movimientos("DERECHA");
    // Izquierda.
    }else if(X < Center){
        MOTORES::Movimientos("IZQUIERDA");
    // Centrada.
    }else if(X == Center){
        // Acercar.
        if(Y < Close){
            MOTORES::Movimientos("ADELANTE");
        }
    }
}