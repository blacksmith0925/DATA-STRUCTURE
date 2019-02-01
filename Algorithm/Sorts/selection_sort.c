#include <stdio.h>
#include <stdlib.h>

int* selectionSort(int* array,int array_length) {
   for (int i = 0; i < array_length-1; i++) {
       int minIndex = i;
       for (int j = i; j < array_length; j++) {
           if (array[j] < array[minIndex]) //找到最小的数
               minIndex = j; //将最小数的索引保存
       }
       int temp = array[minIndex];
       array[minIndex] = array[i];
       array[i] = temp;
   }
   return array;
}

int main()
{
    int array[8] = {21,4,534,3,62,6,73,1};
    selectionSort(array,8);
    for(int i=0;i<8;i++){
        printf("%d ",array[i]);
    }
}
