#include <stdio.h>
#include <stdlib.h>

int* bubble_sorts(int* array,int array_length){
    int tmp = 0;
    for(int i=0;i<array_length;i++){
        int flag = 0;
        for(int j=0;j<array_length-i-1;j++){
            if(array[j]>array[j+1]){
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
                flag = 1;           //标志发生了交换
            }
        }
        if(flag==0){                //若在某次冒泡的过程中发现没有数据交换，说明已经排序完成了
            break;
        }
    }
    return array;
}

int main()
{
    int array[8] = {21,4,534,3,62,6,73,1};
    bubble_sorts(array,8);
    for(int i=0;i<8;i++){
        printf("%d ",array[i]);
    }
}
