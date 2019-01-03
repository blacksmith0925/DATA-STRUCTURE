#include <stdio.h>
#include <stdlib.h>

int maxW=0; // 存储背包中物品总重量的最大值
// cw 表示当前已经装进去的物品的重量和；i 表示考察到哪个物品了；
// w 背包能承受的重量；items 表示每个物品的重量；n 表示物品个数
// 假设背包可承受重量 100，物品个数 10，物品重量存储在数组 a 中，那可以这样调用函数：
// f(0, 0, a, 10, 100)
void f(int i, int cw, int* items, int n, int w) {
  if (cw == w || i == n) { // cw==w 表示装满了 ;i==n 表示已经考察完所有的物品
    if (cw > maxW) maxW = cw;
    return;
  }

  f(i+1, cw, items, n, w);

  if (cw + items[i] <= w) {// 已经超过可以背包承受的重量的时候，就不要再装了
    f(i+1,cw + items[i], items, n, w);
  }
}

int main()
{
    int a[10] = {10,20,30,40,50,60,70,80,90,100};
    f(0, 0, a, 10,135);
    printf("%d",maxW);
}
