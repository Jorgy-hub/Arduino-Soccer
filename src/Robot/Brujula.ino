#include <Brujula.h>

int16_t mx, my, mz;
float DECLINACION_MAGNETICA = 0.12;

float Angulo(HMC5883L Brujula){
    Brujula.getHeading(&mx, &my, &mz);
    float RES = atan2(my, mx);
    RES = RES * (180.0/3.141592653589793238463);
    RES = RES - DECLINACION_MAGNETICA;

    if(RES < 0) RES = RES + 360;
    return RES;
}