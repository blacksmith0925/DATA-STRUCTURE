class TrieNode:
    data = None
    isEndingChar = False
    children = [None for i in range(0,26)]
    def __init__(self,data):
        self.data = data

    def __repr__(self):
        return str(self.data)

class Trie:
    def __init__(self):
        self.root = TrieNode('/')

    # 往 Trie 树中插入一个字符串
    def insert(self,text):
        p = self.root
        for i in range(0,len(text)):
            index = ord(text[i]) - ord('a')
            if (p.children[index] == None):
                newNode = TrieNode(text[i])
                p.children[index] = newNode
            p = p.children[index]
        p.isEndingChar = True

    # 在 Trie 树中查找一个字符串
    def find(self,pattern):
        p = self.root;
        for i in range(0,len(pattern)):
            index = ord(pattern[i]) - ord('a')
            if p.children[index] == None: 
                return False        #不存在 pattern
            p = p.children[index]
        if p.isEndingChar == False:
            return False            #不能完全匹配，只是前缀
        else:
            return True             #找到 pattern


trie1 = Trie()
trie1.insert("abc")
trie1.insert("def")
trie1.insert("hig")

result = trie1.find("abc")

if result:
    print("已查找到模式串")
else:
    print("未查找到模式串")
  
