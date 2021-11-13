#include "Seeker.h"

float DIRECTION_CONSTANT_X = 50.00;
float DIRECTION_CONSTANT_Y = 50.00;
float SEEKER_CENTER_POINT = 120.00;

float *Seeker_Dir(Seeker seeker, float Pelota[2]){
    static float Vector[2];
    
    float X = seeker.Direction;
    float Y = seeker.Strength;

    float W = (SEEKER_CENTER_POINT-X)/DIRECTION_CONSTANT_X;
    float H = -(Y)/DIRECTION_CONSTANT_Y;

    Vector[0] = Pelota[0] + H;
    Vector[1] = Pelota[1] + W;
    return Vector;
};
