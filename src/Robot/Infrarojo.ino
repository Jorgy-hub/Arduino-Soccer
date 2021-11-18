#include "Infrarojo.h"

int DentroCampo(int IRs[4]){
    int l = 1;
    for(int i = 2; i <= 5; i++){
        int IR = digitalRead(IR[i-2]);
        if(IR == 1) l *= i;
    }
    return l;
}