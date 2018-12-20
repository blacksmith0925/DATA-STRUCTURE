#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct TrieNode{
    char data;
    struct TrieNode *children[26];
    int isEndingChar;
};

// 往 Trie 树中插入一个字符串
void insert(struct TrieNode *root,char* text) {

    struct TrieNode *p = root;
    for (int i = 0; i < strlen(text); ++i) {
      int index = text[i] - 'a';
      if (p->children[index] == NULL) {
        struct TrieNode *newNode=(struct TrieNode *)calloc(1,sizeof(struct TrieNode));
        newNode->data = text[i];
        p->children[index] = newNode;
      }
      p = p->children[index];
      p->isEndingChar = 0;
    }
    p->isEndingChar = 1;
    printf("字符串%s已经成功插入Trie树\n",text);
}

// 在 Trie 树中查找一个字符串
int find(struct TrieNode *root,char* pattern) {
    struct TrieNode *p = root;
    for (int i = 0; i < strlen(pattern); ++i) {
      int index = pattern[i] - 'a';
      if (p->children[index] == NULL) {
        return 0; // 不存在 pattern
      }
      p = p->children[index];
    }
    if (p->isEndingChar == 0) return 0; // 不能完全匹配，只是前缀
    else return 1; // 找到 pattern
}

int main(){
    struct TrieNode* root = calloc(1,sizeof(struct TrieNode));
    root->data ='/';
    root->isEndingChar =0;

    insert(root,"abc");
    insert(root,"def");
    insert(root,"ghi");
    int result = find(root,"abc");

    if(result){
        printf("已查找到模式串");
    }else{
        printf("未查找到模式串");
    }
}

