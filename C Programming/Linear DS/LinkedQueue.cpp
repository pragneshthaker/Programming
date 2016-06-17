#include<iostream>
#include<stdlib.h>
#include<process.h>

using namespace std;

class Node
{
    int info;
    Node * next, * front, *rear, * ptr;
public:
    Node()
    {
    next=front=rear=ptr=NULL;
    }
    Node * createNewNode(int n)
    {
        ptr=new Node;
        ptr->info=n;
        ptr->next=NULL;
        return ptr;
    }
    void EnQueue(Node * np)
    {
        if(front==NULL) front=rear=np;
        else
        {
            rear->next=np;
            rear=np;
        }
    }
    int DeQueue()
    {
        if(front==NULL)
        {
            cout<<"UNDERFLOW!!\n";
            return -1;
        }
        else if(front->next==NULL)
        {
            rear=NULL;
            int x = front->info;
            ptr=front;
            front=front->next;
            delete ptr;
            return x;
        }
        else
        {
            int x = front->info;
            ptr=front;
            front=front->next;
            delete ptr;
            return x;
        }
    }
    void Display(Node * np)
    {
        if(front==NULL)
        {
            cout<<" EMPTY!!!";
            return;
        }
        cout<<"[Front]->";
        while(np!=NULL)
        {
            cout<<np->info<<"->";
            np=np->next;
        }
        cout<<"[Rear]\n";
    }
    Node * getFront()
    {
        return front;
    }
};

int main()
{
    Node obj;
    Node * newPtr = NULL;
    int inf, flag=1,k;
    while(flag)
    {
        cout<<"Menu\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        int x;
        cin>>x;
        switch(x)
        {
            case 1:
                cout<<"Enter Element to be Enqueued: ";
                cin>>inf;
                newPtr = obj.createNewNode(inf);
                if(newPtr==NULL)
                {
                    cout<<"Cannot create node!! ABORTING!!!\n";
                    system("pause");
                    exit(1);
                }
                obj.EnQueue(newPtr);
                break;
            case 2:
                k = obj.DeQueue();
                if(k!=-1)
                    cout<<k<<" was Dequeued! \n";
                break;
            case 3:
                cout<<"The Queue is now:\n";
                obj.Display(obj.getFront());
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

