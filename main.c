//
//  main.c
//  Bubblesort
//
//  Created by Tyler on 2016/09/20.
//  Copyright © 2016 Tyler Liu. All rights reserved.
//

#include <stdio.h>
#define size 1000

//int array[size];
int i, j, temp;
int size;
FILE *f;

int main(int argc, const char * argv[]) {
    // input
    
    f = fopen("Bubblesort.in", "r");
    fscanf(f, "%d", &size);
    int array[size];
    for (i = 0; i < size; i ++){
        fscanf(f, "%d", &array[i]);
    }
    fclose(f);

    for (i = 0 ; i < size - 1; i ++)
        for (j = 0; j < size - 1; j ++)
            if (array[j]< array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
    //output
    
    f = fopen("Bubblesort.out", "w");
    for (i = 0; i < size; i++){
        fprintf(f, "%d\n", array[i]);
    }
    fclose(f);

    return 0;
}
