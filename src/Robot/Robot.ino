#include "Brujula.h"
#include "Motores.h"
#include "Infrarojo.h"

float SEEKER_PATEAR = 150.00;             
float SEEKER_CENTRO = 125.00;

// M O T O R E S
Motor MOTOR_ATRAS     = Motor{15,16,17};
Motor MOTOR_DERECHO   = Motor{18,19,20};
Motor MOTOR_IZQUIERDO = Motor{21,22,23};
Motor Motores[3] = {MOTOR_ATRAS, MOTOR_DERECHO, MOTOR_IZQUIERDO};

AltSoftSerial BTSerial; 

void setup(){
    Serial.begin(9600);
    BTSerial.begin(9600); 
    // Iniciar Librerias.
    BRUJULA::Initialize();
    MAIN::Initialize(4,4,15,9);
    MOTORES::Initialize(Motores);
    InfraredSeeker::Initialize();     
}

// Metodo: Sistema de Prioridades.
// 1. No salir del Campo.
// 2. Modo de Juego mediante Bluetooth.
// 3. Orientarse: Aprender del Campo.
// 4. Realizar Jugada: Delantero o Defensa.
void loop(){
    int DELANTERO = ProcesarInfo(BTSerial);
    int INFRAROJOS = DentroCampo(4,5,6,7);

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
                MOTORES::Defensa();
            break;
            case 1:
                MOTORES::Delantero();
            break;
        }
    }
}

void MAIN::Initialize(int inputs, int inputs_s, int outputs, int outputs_s){
    for(int i = inputs; i < inputs+inputs_s; i++){
        pinMode(i, INPUT);
    }
    for(int o = outputs; i < outputs+outputs_s; O++){
        pinMode(o, OUTPUT);
    }
}