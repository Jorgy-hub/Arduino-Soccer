#ifndef BRUJULA_H
#define BRUJULA_H
#include <Wire.h>
#include "HMC5883L.h"

class BRUJULA{
    HMC5883L Brujula;
    int16_t mx, my, mz;
    float Angulo_Update;
    float Angulo_Inicial;  
    float DECLINACION_MAGNETICA = 0.12;
    public: 
        /**
        * @brief Funcion para iniciar la Brujula.
        */
        void Initialize();
        /**
        * @brief Funcion utilizada para obtener el Angulo actual en el que esta la Brujula.
        * @return float 
        */
        float Angulo();
};

#endif