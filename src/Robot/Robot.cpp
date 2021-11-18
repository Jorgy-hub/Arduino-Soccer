#include <HTInfraredSeeker.h>
#include "Brujula.h"
#include "Motores.h"
#include "Infrarojo.h"
#include <Bluetooth.h>

// S E E K E R
float SEEKER_PATEAR = 150.00;             
float SEEKER_CENTRO = 125.00;

// M O T O R E S
Motor MOTOR_ATRAS     = Motor{15,16,17};
Motor MOTOR_DERECHO   = Motor{18,19,20};
Motor MOTOR_IZQUIERDO = Motor{21,22,23};
Motor Motores[3] = {MOTOR_ATRAS, MOTOR_DERECHO, MOTOR_IZQUIERDO};

void setup(){
    Serial.begin(9600);
    Initialize(4,4,15,9);
    BLTOOTH::Initialize();
    BRUJULA::Initialize();
    MOTORES::Initialize(Motores);
    InfraredSeeker::Initialize();     
}

void loop(){
    int INFRAROJOS = DentroCampo({4,5,6,7});
    int DELANTERO  = 0;

    InfraredResult InfraredBall = InfraredSeeker::ReadAC();
    float X = InfraredResult.Direction;
    float Y = InfraredResult.Strength;

    if(INFRAROJOS != 0){
        switch (INFRAROJOS){
            case 2:
                MOTORES::Movimientos("IZQUIERDA");
                delay(1000);
            break;
            case 3:
                MOTORES::Movimientos("DERECHA");
                delay(1000);
            break;
            case 4:
                MOTORES::Movimientos("ATRAS");
                delay(1000);
            break;
            case 5:
                MOTORES::Movimientos("ADELANTE");
                delay(1000);
            break;
            case 8:
                MOTORES::Movimientos("IZQUIERDA");
                delay(1000);
                MOTORES::Movimientos("ADELANTE");
                delay(1000);
            break;
            case 10:
                MOTORES::Movimientos("IZQUIERDA");
                delay(1000);
                MOTORES::Movimientos("ATRAS");
                delay(1000);
            break; 
            case 12:
                MOTORES::Movimientos("DERECHA");
                delay(1000);
                MOTORES::Movimientos("ADELANTE");
                delay(1000);
            break;
            case 15:
                MOTORES::Movimientos("DERECHA");
                delay(1000);
                MOTORES::Movimientos("ATRAS");
                delay(1000);
            break;
        }
    } else {
        switch (DELANTERO) {
            case 0:    
                MOTORES::Defensa(X, SEEKER_CENTRO);    
            break;
            case 1:
                MOTORES::Delantero(X, Y, SEEKER_CENTRO, SEEKER_PATEAR);
            break;
        }
    }
}

void Initialize(int inputs, int inputs_s, int outputs, int outputs_s){
    for(int i = inputs; i < inputs+inputs_s; i++){
        pinMode(i, INPUT);
    }
    for(int o = outputs; i < outputs+outputs_s; O++){
        pinMode(o, OUTPUT);
    }
}