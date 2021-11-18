#include <Brujula.h>

void BRUJULA::Initialize(){
    Brujula.initialize();
    Angulo_Inicial = Angulo(Brujula);
}

float BRUJULA::Angulo(){
    Brujula.getHeading(&mx, &my, &mz);
    float RES = atan2(my, mx);
    RES = RES * (180.0/3.141592653589793238463);
    RES = RES - DECLINACION_MAGNETICA;

    if(RES < 0) RES = RES + 360;
    return RES;
}