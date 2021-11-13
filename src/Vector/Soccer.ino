#include <Wire.h>
#include <HTInfraredSeeker.h> 

#include "Motors.h"
#include "Seeker.h"

// Definir Motores aqui con sus Pins.
Motor MOTOR_CENTRAL   = Motor{15,16};
Motor MOTOR_DERECHO   = Motor{17,18};
Motor MOTOR_IZQUIERDO = Motor{19,20};

// Definir Seeker con sus valores.
Seeker SEEKER = Seeker{0,0};

// Variables Esenciales.
float Pelota[2] = {0,0};
float Vector_Main[2];
float *Start_Vector;

bool Moviendo = false;

int main(){
    Serial.begin(9600);
    InfraredSeeker::Initialize();
    InfraredResult IR_Start = InfraredSeeker::ReadAC();
    SEEKER.Direction = IR_Start.Direction;
    SEEKER.Strength = IR_Start.Strength;
    Start_Vector = Seeker_Dir(SEEKER, Pelota);
    Mover_Vector(Start_Vector);
    while(true){
        InfraredResult IR_LOOP = InfraredSeeker::ReadAC();
        SEEKER.Direction = IR_LOOP.Direction;
        SEEKER.Strength = IR_LOOP.Strength;
        float *VECTOR_LOOP = Seeker_Dir(SEEKER, Pelota);
        if(Checar_Arreglo(Vector_Main, VECTOR_LOOP) == false && Moviendo == false){
            float Nueva_X = VECTOR_LOOP[0] - Vector_Main[0];
            float Nueva_Y = VECTOR_LOOP[1] - Vector_Main[1];
            Pelota[0] = Nueva_X;
            Pelota[1] = Nueva_X; 
            // Reposicionar nueva pelota.
        }else if(Checar_Arreglo(Vector_Main, VECTOR_LOOP) == true && Moviendo == false) {
            if(Checar_Defensa() == true)
                // Funcion Defensa.
                Serial.println("Defensa.");
            else
                Serial.println("Delantero.");
                // Funcion Delantero.
        }  
    }
}

/**
 * Reposicionar Vectores.
 * @params {*double} Vector
 */
void Mover_Vector(float *Vector){
    for(int i = 0; i < 2; i++){
        Vector_Main[i] = Vector[i];
    }
}
