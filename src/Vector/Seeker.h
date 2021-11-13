#ifndef SEEKER_H
#define SEEKER_H

struct Seeker {
    float Direction;
    float Strength;
};

float *Seeker_Dir(Seeker seeker, float Pelota[2]);

#endif
