//
//  main.c
//  Pi
//
//  Created by Tyler on 2016/09/20.
//  Copyright © 2016 Tyler Liu. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define size 10000

int p[size], o[size];//from high digit to low


void odivide (int a){
    int r = 0, q;
    for (int i = 0; i < size; i ++){
        q = (o[i]+ 10 * r) / a;
        r =(o[i]+ 10 * r) % a;
        o[i] = q;
    }
}

void add(int a){
    if ((a & 3) == 3){//subtraction
        int di;
        int b = 0;//if backing b == -1
        for (int i = size-1; i >= 0; i --){
            di = p[i] + b - o[i] + 10;
            b = di / 10 - 1;
            p[i] = di % 10;
            o[i] = 0;
        }
    }
    else{
        int su;
        int b = 0;
        for (int i = size-1; i >= 0; i --){
            su = p[i] + o[i] + b;
            b = su / 10;
            p[i] = su % 10;
            o[i] = 0;
        }
    }
    o[0] =4;
    
}

int main(int argc, const char * argv[]) {
    p[0] = 4;
    o[0] = 4;
    
    for (int i = 3; i < 100000; i += 2 ){
        odivide(i);
        add(i);
    }

    printf("%d.", p[0]);
    for (int i = 1; i < size; i ++){
        printf("%d", p[i]);
    }
    printf("\n");
}
