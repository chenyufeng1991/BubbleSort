//
//  main.c
//  BubbleSort
//
//  Created by chenyufeng on 16/1/28.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

#include <stdio.h>

int *bubbleSort01(int arr[],int len);
int main(int argc, const char * argv[]) {

    int array[5] = {3,4,0,9,2};
    int *p = bubbleSort01(array, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d ",*(p+i));
    }

    return 0;
}

int *bubbleSort01(int arr[],int len){

    int temp;
    for (int i = 0; i < len; i++){
        for (int j = i; j < len - i; j++) {
            if (arr[j - 1] > arr[j]) {

                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}