#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

//查找数据
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

//插入数据
void insert(struct node* tree,int insert_value){
    //创建节点
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = insert_value;
        new_node->left = NULL;
        new_node->right = NULL;
    if(tree==NULL){
        tree = new_node;
        return;
    }
    struct node* p = tree;
    while(p!=NULL){
        if(p->data < insert_value){
            if(p->right == NULL){
                p->right = new_node;
                return;
            }else{   //p->data > insert_value
                p = p->right;
            }
        }else{
            if(p->left == NULL){
                p->left = new_node;
                return;
            }else{
                p = p->left;
            }
        }
    }
    return;
}

//删除数据
void delete(struct node* tree,int delete_value){
    struct node* del_node=tree;    //指向要删除的节点
    struct node* del_node_father;      //指向要删除节点的父节点
    while(del_node != NULL && del_node->data != delete_value){      //先找到要删除的节点以及其父节点
        del_node_father = del_node;
        if(del_node->data > delete_value){
            del_node = del_node->left;
        }else{
            del_node = del_node->right;
        }
    }
    if(del_node == NULL) return;

    //要删除的节点有两个子节点
    if(del_node->left != NULL && del_node->right != NULL){
        struct node* minpp = del_node;
        struct node* minp = del_node->right;
        while(minp->left != NULL){
            minpp = minp;
            minp = minp->left;
        }
        del_node->data = minp->data;
        del_node = minp;            //这里的处理很巧妙，往后执行自然被删掉了
        del_node_father = minpp;
    }


    //要删除的节点是叶子节点或只有一个子节点
    struct node* child;
    if(del_node->left!=NULL){
        child = del_node->left;
    }
    else if(del_node->right!=NULL){
        child = del_node->right;
    }else{
        child = NULL;
    }
    if(del_node_father->left == del_node){
        del_node_father->left = child;
    }else{
        del_node_father->right = child;
    }
    free(del_node);
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

    //查找value = 3
    int value = 3;
    struct node* result = bsearch_tree(tree,value);
    printf("%d\n",result->data);

    //插入数据value = 6
    int insert_value = 6;
    insert(tree,insert_value);
    printf("%d\n",tree->right->right->data);

    //删除数据
    int delete_value = 5;
    delete(tree,delete_value);
    printf("%d\n",tree->right->data);

    return 0;
}
