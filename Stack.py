class stack(object):
    def __init__(self,length):
        self.length = length     //初始化长度
        self.count = 0
        self.items = []

    def push(self,x):           //入栈
        if self.count == self.length:
            return False
        self.items.append(x)
        self.count+=1
        return True

    def pop(self):              //出栈，返回栈顶值
        if self.count == 0:
            return None
        tmp = self.items[self.count-1]
        self.items = self.items[0:self.count-1]
        self.count-=1
        return tmp

    def print(self):            //打印当前栈中的内容
        print(self.items)

if __name__ == "__main__":
    stack1 = stack(20)

    stack1.push(0)
    stack1.push(1)
    stack1.push(2)
    stack1.push(3)
    stack1.push(4)
    stack1.print()

    num = stack1.pop()
    print(num)
    stack1.print()
    num = stack1.pop()
    print(num)
    stack1.print()
