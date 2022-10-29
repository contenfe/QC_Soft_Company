#include <iostream>

typedef int TYPE;

typedef struct node
{
    TYPE Data;
    struct node *next;
} List, *LinkList;

void InitLinkList(List *p)
{
    p = (LinkList)malloc(sizeof(List));

    if (p == nullptr)
    {
        exit(-1);
    }
}
