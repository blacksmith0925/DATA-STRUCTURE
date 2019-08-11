# // 快速排序，A 是数组，n 表示数组的大小
# quick_sort(A, n) {
#   quick_sort_c(A, 0, n-1)
# }
# // 快速排序递归函数，p,r 为下标
# quick_sort_c(A, p, r) {
#   if p >= r then return
  
#   q = partition(A, p, r) // 获取分区点
#   quick_sort_c(A, p, q-1)
#   quick_sort_c(A, q+1, r)
# }
# partition(A, p, r) {
#   pivot := A[r]
#   i := p
#   for j := p to r-1 do {
#     if A[j] < pivot {
#       swap A[i] with A[j]
#       i := i+1
#     }
#   }
#   swap A[i] with A[r]
#   return i
#   }
def quick_sort(A):
	quick_sort_c(A,0,len(A)-1)

def quick_sort_c(A,p,r):
	if p >=r:
		return
	q=partition(A,p,r)			#获取分区点
	quick_sort_c(A,p,q-1)
	quick_sort_c(A,q,r)

def partition(A,p,r):
	pivot = A[r]
	i = p
	for j in range(p,r):
		if A[j] < pivot:
			tmp = A[i]
			A[i] = A[j]
			A[j] = tmp
			i += 1
	tmp = A[i]
	A[i] = A[r]
	A[r] = tmp
	return i

list1 = [1,55,54,78,62,9,47,2]
quick_sort(list1)
print(list1)
