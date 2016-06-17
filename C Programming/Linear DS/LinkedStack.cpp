#include<iostream>
#include<stdlib.h>
#include<process.h>

using namespace std;

class Node
{
    int info;
    Node * next, * top, * ptr;
public:
    Node()
    {
    next=top=ptr=NULL;
    }
    Node * createNewNode(int n)
    {
        ptr=new Node;
        ptr->info=n;
        ptr->next=NULL;
        return ptr;
    }
    void Push(Node * np)
    {
        if(top==NULL) top=np;
        else
        {
            np->next=top;
            top=np;
        }
    }
    int Pop()
    {
        if(top==NULL)
        {
            cout<<"UNDERFLOW!!\n";
            return -1;
        }
        else
        {
            int x = top->info;
            ptr=top;
            top=top->next;
            delete ptr;
            return x;
        }
    }
    void Display(Node * np)
    {
        if(top==NULL)
        {
            cout<<" EMPTY!!!";
            return;
        }
        cout<<"[TOP]->";
        while(np!=NULL)
        {
            cout<<np->info<<"->";
            np=np->next;
        }
        cout<<"[NULL]\n";
    }
    Node * getTop()
    {
        return top;
    }
};

int main()
{
    Node obj;
    Node * newPtr = NULL;
    int inf, flag=1,k;
    while(flag)
    {
        cout<<"Menu\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        int x;
        cin>>x;
        switch(x)
        {
            case 1:
                cout<<"Enter Elements to be pushed into stack: ";
                cin>>inf;
                newPtr = obj.createNewNode(inf);
                if(newPtr==NULL)
                {
                    cout<<"Cannot create node!! ABORTING!!!\n";
                    system("pause");
                    exit(1);
                }
                obj.Push(newPtr);
                break;
            case 2:
                k = obj.Pop();
                if(k!=-1)
                    cout<<k<<" was Popped! \n";
                break;
            case 3:
                cout<<"The stack is now:\n";
                obj.Display(obj.getTop());
                break;
            case 4:
                exit(0);
        }
        cout<<"\nDo you want to continue? [yes -> 1, No -> 0]";
        cin>>flag;
        system("cls");
    }
    return 0;
}
