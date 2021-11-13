#include "Utils.h"

/**
 * Checar si uno de los Vectores esta relativamente cerca del otro.
 * @params {[]double} Robot
 * @params {[]double} Pelota
 */
bool Checar_Arreglo(float Robot[2] , float Pelota[2]){
    int c = 0;
    for(int i = 0; i < 2; i++){
        double c1 = (Robot[i]*30);
        double c2 = (Pelota[i]*30);
        double m = c2-c1;
        if(m < 5 && m > -5) c++;
    }
    if(c > 0)
        return false;
    else 
        return true;
}

/**
 * Aqui poner la Deteccion de quien esta mas cerca de la Pelota.
 */
bool Checar_Defensa(){
    double c = 0;
    if(c == 0)
        return false;
    else 
        return true;
};
