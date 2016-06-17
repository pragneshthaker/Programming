#include<iostream>
#include<stdlib.h>
#define SIZE 10

using namespace std;

void push(int st[],int x,int* top)
{
    if(*top==SIZE-1)
    {
        cout<<"stack overflow!!";
        return;
    }
    else
    {
        (*top)++;
        st[*top]=x;
    }

}

void pop(int st[],int* top)
{
    if(*top==-1)
    {
        cout<<"Stack Underflow!!";
    }
    else
    {
        cout<<st[*top]<<"is popped\n";
        (*top)--;
    }
}

void disp(int st[],int top)
{
    cout<<st[top]<<"<--\n";
    while(top>0)
    {
        top--;
        cout<<st[top]<<"\n";
    }
}

int main()
{
    int stack[SIZE],top=-1,key,flag=1;
    while(flag)
    {
        cout<<"Menu\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        int x;
        cin>>x;
        switch(x)
        {
            case 1:
                cout<<"Enter Elements to be pushed into stack: ";
                cin>>key;
                push(stack,key,&top);
                break;
            case 2:
                pop(stack,&top);
                break;
            case 3:
                cout<<"The stack is now:\n";
                disp(stack,top);
                break;
            case 4:
                exit(0);
        }
        cout<<"\nDo you want to continue? (yes -> 1, No -> 0)";
        cin>>flag;
    }
    return 0;
}
