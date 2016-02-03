//
//  main.c
//  BubbleSort
//
//  Created by chenyufeng on 16/1/28.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//


#include <stdio.h>

typedef int BOOL;
#define true 1
#define false 0

int *bubbleSort01(int arr[],int len);
int *bubbleSort02(int arr[],int len);
void bubbleSort03(int arr[],int len);
void bubbleSort04(int *arr,int len);
void swap(int *a,int *b);

int main(int argc, const char * argv[]) {

    int array[7] = {150,111,1000,99,300,10,189};

    /**
     *指针向后移位；
     */

    //    int *p = bubbleSort02(array, 7);
    //
    //    for (int i = 0; i < 7; i++) {
    //        printf("%d ",*(p+i));
    //    }

    /**
     *  可以使用传引用的方式，实现如下;
     这里不需要返回值，直接打印即可,推荐使用这种方式，方便；
     */
    bubbleSort01(array, 7);
    for (int i = 0; i < 7; i++) {
        printf("%d ",array[i]);
    }

    return 0;
}

//常规的冒泡；
int *bubbleSort01(int arr[],int len){

    int temp;
    for (int i = 0; i < len; i++){
        for (int j = 1; j < len - i; j++) {
            if (arr[j - 1] > arr[j]) {

//                temp = arr[j - 1];
//                arr[j - 1] = arr[j];
//                arr[j] = temp;

                //这里也可以使用swap交换函数；
                swap(&arr[j - 1], &arr[j]);
            }
        }
    }
    return arr;
}

//优化，设置一个标志，如果这一趟发生了交换，则为true，否则为false；
int *bubbleSort02(int arr[],int len){

    BOOL flag = true;
    int temp;
    while (flag) {
        flag = false;
        for (int i = 1; i < len; i++) {
            if (arr[i - 1] > arr[i]) {

                //如果某一趟没有没有交换元素，则表示排序完成；
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                flag = true;
            }
        }
        len--;//最大的元素已经完成；
    }
    
    return arr;
}


//常规的冒泡，不需要返回值；
void bubbleSort03(int *arr,int len){

    int temp;
    for (int i = 0; i < len; i++){
        for (int j = 1; j < len - i; j++) {
            if (arr[j - 1] > arr[j]) {

                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//优化，设置一个标志，如果这一趟发生了交换，则为true，否则为false；返回值为void；
void bubbleSort04(int *arr,int len){

    BOOL flag = true;
    int temp;
    while (flag) {
        flag = false;
        for (int i = 1; i < len; i++) {
            if (arr[i - 1] > arr[i]) {

                //如果某一趟没有没有交换元素，则表示排序完成；
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                flag = true;
            }
        }
        len--;//最大的元素已经完成；
    }
}


void swap(int *a,int *b){

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}











