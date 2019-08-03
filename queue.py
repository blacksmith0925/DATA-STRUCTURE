class queue(object):
    def __init__(self,length):
        self.length = length
        self.head = 0
        self.tail = 0
        self.items = [0]*self.length

    def enqueue(self,x):
        if self.tail == self.length:    #队列已满,需要进行数据搬移
            if self.head == 0:          #队列已经没有能搬移的空闲空间了
                return False
            i = 0                       #开始进行数据搬移
            for data in self.items[self.head:self.tail]:
                self.items[i] = data
                i += 1
            self.tail = self.tail - self.head
            self.head = 0
        self.items[self.tail] = x
        self.tail+=1
        return True

    def dequeue(self):
        if self.head == self.tail:      #表示队列为空
            return None
        tmp = self.items[self.head]
        self.head += 1
        return tmp

    def print(self):
        print(self.items[self.head:self.tail])

if __name__ == "__main__":
    queue1 = queue(5)

    queue1.enqueue(0)
    queue1.enqueue(1)
    queue1.enqueue(2)
    queue1.enqueue(3)
    queue1.enqueue(4)
    queue1.print()

    num = queue1.dequeue()
    print(num)
    queue1.print()

    queue1.enqueue(5)
    queue1.print()
    
    num = queue1.dequeue()
    print(num)
    queue1.print()
