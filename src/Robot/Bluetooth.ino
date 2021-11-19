#include <Bluetooth.h>

void BLTOOTH::Initialize(){
    ConfigBT.begin(38400); 
}

int BLTOOTH::ChecarDelantero(float X, float Y){
    float N1 = Power(X , 2, 0);
    float N2 = Power(Y , 2, 0);
    float Z1 = Power(X+Y, 2, 1);
    float Z2 = ConfigBT.read();
    ConfigBT.write(z);
    if(Z1 < Z2)
        return 1;
    else 
        return 0;
}

float BLTOOTH::Power(float N, float P, int TYPE){
    float T = 1;
    float Error = 0.0001;
    for(int i = 0; i < P; i++)
        if(TYPE == 0)
            T *= N;
        else {
            T = N;
            while ((T - N / T) > Error)
                T =   (T + N / T) / P;
        }
    return T;
}