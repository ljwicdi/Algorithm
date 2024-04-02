#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct _node
{
    int data;
    struct _node * next;
} NODE;

typedef struct _queue
{
    NODE * front;
    NODE * rear;
    int numOfData;
} QUEUE;



void Init(QUEUE * q)
{
    q->front = NULL;
    q->rear = NULL;
    q->numOfData = 0;
}

bool IsEmpty(QUEUE * q)
{
    if(q->front == NULL)
        return true;
    else
        return false;
}
void Enqueue(QUEUE * q, int data)
{
    NODE * newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;

    if(q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->numOfData++;
}

int Dequeue(QUEUE * q)
{
    if(IsEmpty(q))
        cout<<"비어있음"<<endl;

    int data;
    NODE * delNode;
    delNode = q->front;
    data = delNode->data;

    q->front = q->front->next;
    free(delNode);
    q->numOfData--;
    return data;
}

int main(void)
{
    int lastMember;
    int CardNumber;
    cin>>CardNumber;
    QUEUE * q = (QUEUE *)malloc(sizeof(QUEUE));
    Init(q);
    for(int i=1;i<=CardNumber;i++)
    {
        Enqueue(q,i);
    }
    while(q->numOfData>1)
    {
        int goingTail;

        Dequeue(q);
        goingTail = Dequeue(q);
        Enqueue(q, goingTail);
    }
    lastMember = Dequeue(q);
    cout<<lastMember<<endl;
    return 0;
}