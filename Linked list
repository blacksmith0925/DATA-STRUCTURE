#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node* add_to_list(struct node* list,int n)
{
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Error:malloc failed in add_into_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = list;  /*new_code结点指向下一结点,此时并没有对原链表进行任何修改，新结点也没有添加进链表中*/
    return new_node;
}

struct node* search_node(struct node *list,int n)
{
    struct node *p;
    for(p=list;p!=NULL;p=p->next)
    {
        if(p->value == n)
            return p;
    }
    return NULL;
}

struct node *delete_from_list(struct node *list,int n)
{
    struct node *p,*pre;
    for(pre  = NULL,p =list;(p != NULL) &&(p->value != n);pre = p,p = p->next);
    if (p == NULL)
        return list;
    if(pre == NULL)
        list = list->next;
    else
        pre ->next = p->next;
    free(p);
    return list;
}

int main() {
    struct node *first;
    first = NULL;
    first = add_to_list(first,10);   /*头指针first指向新结点new_code，此时新结点才真正添加进了链表。用函数直接更新first，而不是为first返回新的值，这样做是个技巧*/
}
