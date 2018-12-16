#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// b 表示模式串，m 表示模式串的长度，本函数用于获取next数组
int* getNexts(char* b, int m) {
  int* next = (int*)malloc(sizeof(int)*m);
  next[0] = -1;
  int k = -1;
  for (int i = 1; i < m; ++i) {
    while (k != -1 && b[k + 1] != b[i]) {   //如果b[k+1]！=b[i]，则需要在i-1的最长匹配前缀子串中找到i-1的次长匹配前缀子串，这个次长匹配子串就是
                                              最长匹配前缀子串的最长匹配前缀子串（有点像绕口令T T，结合图来理解）
      k = next[k];                          
    }
    if (b[k + 1] == b[i]) {
      ++k;                                  //如果b[k+1]==b[i]，可以由next[i-1]直接得到next[i]
    }
    next[i] = k;
  }
  return next;
}


// a, b 分别是主串和模式串；n, m 分别是主串和模式串的长度。本函数返回匹配子串的首字符的位置，若不匹配则返回-1
int kmp(char* a, int n, char* b, int m) {
  int* next = getNexts(b, m);
  int j = 0;
  for (int i = 0; i < n; ++i) {
    while (j > 0 && a[i] != b[j]) {         // 一直找到 a[i] 和 b[j]
      j = next[j - 1] + 1;
    }
    if (a[i] == b[j]) {
      ++j;
    }
    if (j == m) {                           // 找到匹配模式串的了
      return i - m + 1;
    }
  }
  free(next);
  return -1;
}



int main()
{
   char *a = "ababaeabac" ,*b = "abac";
   int position = kmp(a,10,b,4);
   printf("%d",position);
}
