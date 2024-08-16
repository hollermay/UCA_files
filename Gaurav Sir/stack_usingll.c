#include <stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <limits.h>
//Implement a stack using linked list


int N=0;
struct Node{
    int item;
    struct Node*next;
};

struct Node* head;


void push(int item)
{
    struct Node* oldHead = head;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->item = item;
    N++;
    head->next = oldHead;
}


int pop()
{
    if(N==0) return INT_MIN;
    struct Node*temp = head;
    int item = temp->item;
    head = head->next;
    free(temp);
    N--;
    return item;
}

bool isEmpty(){
    return N==0;
}

int size(){
    return N;
}

void testStack(){
    push(1);
    push(2);
    push(3);

    assert(pop()==3);
    assert(size()==3);
    assert(isEmpty()==false);

    assert(pop()==2);
    assert(size()==1);
    assert(isEmpty()==false);

    assert(pop()==1);
    assert(size()==1);
    assert(isEmpty()==true);
}

int main(){
    testStack();
    return 0;
}

