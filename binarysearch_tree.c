#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* bsearch_tree(struct node* tree,int value){
    struct node* p = tree;
    while(p != NULL){
        if(value < p->data){
            p = p->left;
        }else if(value > p->data){
            p = p->right;
        }else{
            return p;
        }
    }
    return NULL;
}

int main()
{
    //构建一棵二叉查找树
    struct node node1 = {1,NULL,NULL};
    struct node node2 = {2,NULL,NULL};
    struct node node3 = {3,NULL,NULL};
    struct node node4 = {4,NULL,NULL};
    struct node node5 = {5,NULL,NULL};
    struct node* tree = &node4;
    node4.left = &node2;
    node4.right = &node5;
    node2.left = &node1;
    node2.right = &node3;
    
    //查找value=3
    int value = 3;
    struct node* result = bsearch_tree(tree,value);
    printf("%d",result->data);

    return 0;
}
