import queue


class ACNode:
    data = None
    isEndingChar = False
    length = -1  # 当 isEndingChar=true 时，记录模式串长度
    fail = None  # 失败指针
    def __init__(self, data):
        self.data = data
        self.children = []
        for i in range(0, 26):
            self.children.append(None)

    def __repr__(self):
        return str(self.data)


class Trie:
    def __init__(self):
        self.root = ACNode('/')

    # 往 Trie 树中插入一个字符串
    def insert(self, text):
        p = self.root
        for i in range(0, len(text)):
            index = ord(text[i]) - ord('a')
            if (p.children[index] == None):
                newNode = ACNode(text[i])
                p.children[index] = newNode
            p = p.children[index]
        p.isEndingChar = True
        p.length = len(text)    #当isEndingChar=True，即模式串的最后一个字符时，属性length记录模式串的长度

    # 在 Trie 树中查找一个字符串
    def find(self, pattern):
        p = self.root
        for i in range(0, len(pattern)):
            index = ord(pattern[i]) - ord('a')
            if p.children[index] == None:
                return False  # 不存在 pattern
            p = p.children[index]
        if p.isEndingChar == False:
            return False  # 不能完全匹配，只是前缀
        else:
            return True  # 找到 pattern

    #构建AC自动机
    def buildFailurePointer(self):
        queue1 = queue.Queue()
        self.root.fail = None
        queue1.put(self.root)
        while not queue1.empty():
            p = queue1.get()
            for i in range(0, 26):
                pc = p.children[i]
                if pc == None:      #此子节点不存在
                    continue
                if p == self.root:  #root的子节点的fail指针全部指向root
                    pc.fail = self.root
                else:               #利用p的fail指针求其子节点pc的fail指针
                    q = p.fail
                    while (q != None):
                        qc = q.children[ord(pc.data) - ord('a')]
                        if qc != None:
                            pc.fail = qc
                            break
                        q = q.fail
                    if q == None:
                        pc.fail = self.root
                queue1.put(pc)

    #字符串查找
    def match(self, text):  # text 是主串
        n = len(text)
        p = self.root
        for i in range(0, n):
            idx = ord(text[i]) - ord('a')
            while p.children[idx] == None and p != self.root:
                p = p.fail  # 失败指针发挥作用的地方
            p = p.children[idx]
            if p == None:
                p = self.root  # 如果没有匹配的，从 root 开始重新匹配
            tmp = p
            while tmp != self.root:  # 打印出可以匹配的模式串
                if tmp.isEndingChar == True:
                    pos = i - tmp.length + 1
                    print(" 匹配起始下标 ", pos, "; 长度 ", tmp.length)
                tmp = tmp.fail


trie1 = Trie()
trie1.insert("yui")
trie1.insert("dfg")
trie1.insert("io")
trie1.insert("zxc")

trie1.buildFailurePointer()

trie1.match("qwertyuiopasdfghjklzxcvbnm")
