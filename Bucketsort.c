//
//  main.c
//  Bucketsort
//
//  Created by Tyler Liu on 2016/09/19.
//  Copyright © 2016 Tyler Liu. All rights reserved.
//

#include <stdio.h>
#define maxvalue 100000
//int array[size];
int temp[maxvalue];
int i, j, t;
int size;
FILE *f;

int main(){
    //TODO input
    
    f = fopen("Bucketsort.in", "r");
    fscanf(f, "%d", &size);
    int array[size];
    for (i = 0; i < size; i ++){
        fscanf(f, "%d", &array[i]);
    }
    fclose(f);
    
    for (i = 0; i < size; i ++){
        temp[array[i]]++;
    }
    t = 0;
    for(i = 0; i < maxvalue; i++){
        int value = temp[i];
        for (j = 1; j<= value; j++){
            array[t] = i;
            t++;
        }
    }
    
    //TODO output
    
    f = fopen("Bucketsort.out", "w");
    for (i = 0; i < size; i++){
        fprintf(f, "%d\n", array[i]);
    }
    fclose(f);
    
    return 0;
}
