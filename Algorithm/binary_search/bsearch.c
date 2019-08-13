#include <stdio.h>
#include <stdlib.h>

int b_search(int value,int* A,int array_length){
    int low = 0;
    int high = array_length - 1;

    while(low<=high){                     //注意是low<=high 而不是 low<high
        int mid = low+(high-low)/2;
        if(A[mid] == value){
            return mid;
        }else if(A[mid]<value){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int A[10] = {8,11,19,23,27,33,45,55,67,98};
    int array_length = 10;
    int pos = b_search(19,A,array_length);
    printf("the position is:%d\n",pos);
}
