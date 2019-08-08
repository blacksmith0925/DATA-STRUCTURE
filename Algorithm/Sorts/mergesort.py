# // 归并排序算法, A 是数组，n 表示数组大小
# merge_sort(A, n) {
#   merge_sort_c(A, 0, n-1)
# }

# // 递归调用函数
# merge_sort_c(A, p, r) {
#   // 递归终止条件
#   if p >= r  then return

#   // 取 p 到 r 之间的中间位置 q
#   q = (p+r) / 2
#   // 分治递归
#   merge_sort_c(A, p, q)
#   merge_sort_c(A, q+1, r)
#   // 将 A[p...q] 和 A[q+1...r] 合并为 A[p...r]
#   merge(A[p...r], A[p...q], A[q+1...r])
# }

# merge(A[p...r], A[p...q], A[q+1...r]) {
#   var i := p，j := q+1，k := 0 // 初始化变量 i, j, k
#   var tmp := new array[0...r-p] // 申请一个大小跟 A[p...r] 一样的临时数组
#   while i<=q AND j<=r do {
#     if A[i] <= A[j] {
#       tmp[k++] = A[i++] // i++ 等于 i:=i+1
#     } else {
#       tmp[k++] = A[j++]
#     }
#   }
  
#   // 判断哪个子数组中有剩余的数据
#   var start := i，end := q
#   if j<=r then start := j, end:=r
  
#   // 将剩余的数据拷贝到临时数组 tmp
#   while start <= end do {
#     tmp[k++] = A[start++]
#   }
  
#   // 将 tmp 中的数组拷贝回 A[p...r]
#   for i:=0 to r-p do {
#     A[p+i] = tmp[i]
#   }
# }

def merge_sort(list1):
    merge_sort_between(list1,0,len(list1)-1)
def merge_sort_between(list1,low,high):
    if low < high:
        mid = low + (high - low)//2
        merge_sort_between(list1,low,mid)
        merge_sort_between(list1,mid+1,high)
        merge(list1,low,mid,high)

def merge(list1,low,mid,high):
    list2 = []
    i = low
    j = mid+1
    while i<=mid and j<=high:
        if list1[i] <= list1[j]:
            list2.append(list1[i])
            i +=1
        else:
            list2.append(list1[j])
            j +=1
    if i > mid:
        for num in list1[j:high+1]:
            list2.append(num)
    else:
        for num in list1[i:mid+1]:
            list2.append(num)
    list1[low:high+1] = list2 

list1 = [1,55,54,78,62,9,47,2]
merge_sort(list1)
print(list1)
