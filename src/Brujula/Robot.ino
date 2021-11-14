#include "Brujula.h"
#include "Motores.h"

// Seeker.
float SEEKER_PATEAR = 150.00;             
float SEEKER_CENTRO = 125.00;

// Declarar Motores.
Motor MOTOR_ATRAS     = Motor{15,16,17};
Motor MOTOR_DERECHO   = Motor{18,19,20};
Motor MOTOR_IZQUIERDO = Motor{21,22,23};

// Configuraciones.
HMC5883L Brujula;
AltSoftSerial BTSerial; 
bool DELANTERO = false;
float BRUJULA_CENTER = 0;

void setup(){
    Serial.begin(9600);
    BTSerial.begin(9600); 
    Brujula.initialize();
    Main::Initialize(4,3, 15, 9);
    InfraredSeeker::Initialize();

    // Valores Iniciales.
    BRUJULA_CENTER = Angulo(Brujula);
}

void loop(){
    
}

void Main::Initialize(int inputs, int inputs_s, int outputs, int outputs_s){
    for(int i = inputs; i < inputs+inputs_s; i++){
        pinMode(i, INPUT);
    }
    for(int o = outputs; i < outputs+outputs_s; O++){
        pinMode(o, OUTPUT);
    }
}