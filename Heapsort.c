//
//  Heapsort.c
//  Heapsort
//
//  Created by Tyler Liu on 2016/09/19.
//  Copyright © 2016 Tyler Liu. All rights reserved.
//

#include <stdio.h>
//TODO generate size 500000 data (int)
//int array[size];
int i, j, start, end, temp, size;
FILE *f;

int main (){
    //input method
    f = fopen("Heapsort.in", "r");
    fscanf(f, "%d", &size);
    int array[size];
    for (i = 0; i < size; i ++){
        fscanf(f, "%d", &array[i]);
    }
    fclose(f);

    
    for (i = size / 2 - 1; i >= 0; i--){
        start = i;
        end = size-1;
        while ( 1 ){
            int left = start*2 + 1;
            int right =  left + 1;
            
            int largest = start;
            if (left <= end && array[largest] < array[left]) {
                largest = left;
            }
            if (right <= end && array[largest] < array[right]) {
                largest = right;
            }
            if (largest == start){
                break;
            }
            
            //swap
            temp = array[start];
            array[start] = array[largest];
            array[largest] = temp;
            
            start = largest;
        }
        
    }
    
    for(i = size - 1; i >= 0; i --){
        
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        
        start = 0;
        end = i-1;
        while ( 1 ){
            int left = start*2 + 1;
            int right =  left + 1;
            
            int largest = start;
            if (left <= end && array[largest] < array[left]) {
                largest = left;
            }
            if (right <= end && array[largest] < array[right]) {
                largest = right;
            }
            if (largest == start){
                break;
            }
            
            temp = array[start];
            array[start] = array[largest];
            array[largest] = temp;
            
            start = largest;
        }
        
    }
    
    /*int ans = 0;
     for (i = 0; i < size ; i++ )
     ans = ans + abs(i-array[i]);
     printf("%d\n", ans);*/
    
    /*for (i = 0; i < size ; i++ )
        printf("%d\n", array[i]);
    */
    
    f = fopen("Heapsort.out", "w");
    for (i = 0; i < size; i++){
        fprintf(f, "%d\n", array[i]);
    }
    fclose(f);

    return 0;
}
