#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#include <AltSoftSerial.h>

class BLTOOTH {
    AltSoftSerial BTSerial;
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
        bool ChecarDelantero(float X, float Y);
};

#endif