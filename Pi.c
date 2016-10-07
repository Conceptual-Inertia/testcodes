//
//  main.c
//  Pi
//
//  Created by Tyler on 2016/09/20.
//  Copyright © 2016 Tyler Liu. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define size 10001

int p[size], o1[size], o2[size];//from high digit to low

void odivide (int a){
    int r = 0, q;
    for (int i = 0; i < size; i ++){
        q = o2[i]+ 1000000 * r;
        r =q % a;
        o2[i] = q / a;
    }
}

void o1div16 (){
    int r = 0, q;
    for (int i = 0; i < size; i ++){
        q = o1[i]+ 1000000 * r;
        r =q & 15;
        o1[i] = q >> 4;
    }
}

void addo2(int init){
    
    int su;
    int b = 0;
    for (int i = size-1; i >= 0; i --){
        su = o1[i] + o2[i] + b;
        b = su / 1000000;
        o1[i] = su % 1000000;
        o2[i] = 0;
    }
    o2[0] =init;
    
}

void subtract(int init){
    int di;
    int b = 0;//if backing b == -1
    for (int i = size-1; i >= 0; i --){
        di = o1[i] + b - o2[i] + 1000000;
        b = di / 1000000 - 1;
        o1[i] = di % 1000000;
        o2[i] = 0;
    }

    o2[0] = init;
}

void addo1(){
    
    int su;
    int b = 0;
    for (int i = size-1; i >= 0; i --){
        su = p[i] + o1[i] + b;
        b = su / 1000000;
        p[i] = su % 1000000;
        o1[i] = 0;
    }
}

void calc(int k){
    //assume o2 at 4
    odivide((k << 3) + 1);
    addo2(2);
    odivide((k << 3) + 4);
    subtract(1);
    odivide((k << 3) + 5);
    subtract(1);
    odivide((k << 3) + 6);
    subtract(4);
    
    //o1 divide
    for (int i = 0; i < k; i ++){
        o1div16();
    }
    addo1();
}


int main(int argc, const char * argv[]) {
    //BBP
    o2[0] = 4;
    
    
    for (int i = 0; i < 1000; i ++ ){
        calc(i);
    }

    printf("%d.", p[0]);
    for (int i = 1; i < size; i ++){
        if (p[i]<100000) printf("0");
        if (p[i]<10000) printf("0");
        if (p[i]<1000) printf("0");
        if (p[i]<100) printf("0");
        if (p[i]<10) printf("0");
        if (p[i]<1) printf("0");
        printf("%d", p[i]);
    }
    printf("\n");
}
