#include<iostream>
#include<stdlib.h>
#define SIZE 10

using namespace std;

void enQueue(int qu[],int x,int* f,int* r)
{
    if(*r == SIZE-1)
    {
        cout<<"queue overflow!!";
        return;
    }
    else
    {
        (*r)++;
        qu[*r]=x;
        if(*r == 0)
            *f = 0;
    }
}

void deQueue(int st[],int* f,int* r)
{
    if(*f==-1)
    {
        cout<<"Stack Underflow!!";
    }
    else
    {
        cout<<st[*f]<<"is dequeued.\n";
        if(*f == *r)
            *f = *r = -1;
        (*f)++;
    }
}

void disp(int st[],int f,int r)
{
    while(f<=r)
    {
        cout<<st[f]<<"<-- ";
        f++;
    }
}

int main()
{
    int queue1[SIZE],front=-1,rear=-1,key,flag=1;
    while(flag)
    {
        cout<<"Menu\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        int x;
        cin>>x;
        switch(x)
        {
            case 1:
                cout<<"Enter Elements to be enqueued: ";
                cin>>key;
                enQueue(queue1,key,&front,&rear);
                break;
            case 2:
                deQueue(queue1,&front,&rear);
                break;
            case 3:
                cout<<"The queue is now:\n";
                disp(queue1,front,rear);
                break;
            case 4:
                exit(0);
        }
        cout<<"\nDo you want to continue? (yes -> 1, No -> 0) ";
        cin>>flag;
    }
    return 0;
}

