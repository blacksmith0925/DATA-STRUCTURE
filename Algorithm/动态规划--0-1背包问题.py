def knapsack2(items,n,w):  #只需要一个大小为 w+1 的一维数组来动态规划解决0-1背包问题
  states = [False for x in range(0,w+1)] # 默认值 false
  states[0] = True  # 第一行的数据要特殊处理，可以利用哨兵优化
  states[items[0]] = True
  for i in range(1,n): # 动态规划
    for j in reversed(range(0,w-items[i]+1)) :# 把第 i 个物品放入背包，注意这里一定要反序，否则会出问题
      if states[j]==True: 
        states[j+items[i]] = True

  for  i in reversed(range(0,w+1)): # 输出结果
    if states[i] == True: 
      return i

weight = [2,2,4,6,3]
result = knapsack2(weight,5,16)
print(result)
