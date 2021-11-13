#include "Motors.h"

/**
 * Funcion para Mover ambos lados de Motores solo con las Velocidades.
 * @params {Motor} motor 
 * @params {int} speed_p
 * @params {int} speed_n
 */
void Mover_Motor(Motor motor, int speed_p, int speed_n){
    digitalWrite(motor.vcc, speed_p);
    digitalWrite(motor.gnd, speed_n);
}

/**
 * Funcion utilizada para mover el Robot a un vector en especifico.
 * Aqui se establecen las velocidades y movimientos para controlar el Robot.
 * @params {*double} Inicio
 * @params {*dobule} Final
 */
void Mover_Robot(float Inicio[2], float Final[2]){
    // Hacia en frente.
    if(Inicio[0] == Final[0] && Inicio[1] < Final[1]){
      
    }
    // Hacia atras.
    else if(Inicio[0] == Final[0] && Inicio[1] > Final[1]){
    
    }
    // Hacia la izquierda.
    else if(Inicio[0] > Final[0] && Inicio[1] == Final[1]){
    
    }
    // Hacia la derecha.
    else if(Inicio[0] < Final[0] && Inicio[1] == Final[1]){
    
    }
    // Diagonal hacia en frente e izquierda.
    else if(Inicio[0] > Final[0] && Inicio[1] < Final[1]){
    
    }
    // Diagonal hacia en frente y derecha.
    else if(Inicio[0] < Final[0] && Inicio[1] < Final[1]){
    
    }
    // Diagonal hacia atras e izquierda.
    else if(Inicio[0] > Final[0] && Inicio[1] > Final[1]){
    
    }
    // Diagonal hacia atras y derecha.
    else if(Inicio[0] < Final[0] && Inicio[1] > Final[1]){
    
    }
};
