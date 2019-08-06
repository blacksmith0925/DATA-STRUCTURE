#include <stdio.h>
#include <stdlib.h>

int* insertionsort(int* array,int array_length){
    if(array_length<=1){
        return;
    }
    for(int i=1;i<array_length;i++){
        int value = array[i];                //保存当前值，否则后面数据移动过程中会被覆盖掉
        int j=i-1;
        for(;j>=0;j--){
            if(value <array[j]){
                array[j+1] = array[j];       //数据移动
            }else{
                break;
            }
        }
        array[j+1] = value;
    }
}

int main()
{
    int array[8] = {21,4,534,3,62,6,73,1};
    insertionsort(array,8);
    for(int i=0;i<array_length;i++){
        printf("%d ",array[i]);
    }
}

