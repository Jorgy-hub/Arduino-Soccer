#include "Infrarojo.h"

int DentroCampo(int IR_1, int IR_2, int IR_3, int IR_4){
    int R = digitalRead(IR_1);
    int L = digitalRead(IR_2);
    int B = digitalRead(IR_3);
    int F = digitalRead(IR_4);
    int T = R+L+B+F;

    if(T > 0){
        if(T > 1){
            if(R + F == 2)      return 10;
            else if(L + F == 2) return 15;
            else if(L + B == 2) return 12;
            else if(R + B == 2) return 8;
            else return 0;    
        } else {
            if(R == 1)      return 2;
            else if(L == 1) return 3;
            else if(B == 1) return 4;
            else if(F == 1) return 5;
            else return 0;
        }
    } else return 0;
}
