#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#define rx 2
#define tx 3
#include <AltSoftSerial.h>

class BLTOOTH {
    SoftwareSerial ConfigBT(rx, tx); 
    public: 
        /**
        * @brief Iniciar Motores establecidos.
        */
        void Initialize();
        /**
         * @brief Checar si el actual Robot sera el Delantero o el Defensa.
         * @param X 
         * @param Y 
         * @return true 
         * @return false 
         */
        int ChecarDelantero(float X, float Y);
        /**
         * @brief Funcion para elevar floats a una potencia.
         * TYPE = 0 es Elevar.
         * Type = 1 es Raiz de.
         * @param N 
         * @param P 
         * @param TYPE 
         * @return float 
         */
        float Power(float N, float P, int TYPE);
};

#endif