#include<iostream>
#include<stdlib.h>
#include<process.h>

using namespace std;

class Node
{
    int info;
    Node * next, * front, * ptr;
public:
    Node()
    {
    next=front=ptr=NULL;
    }
    Node * createNewNode(int n)
    {
        ptr=new Node;
        ptr->info=n;
        ptr->next=NULL;
        return ptr;
    }
    void Insert(Node * np)
    {
        if(front==NULL) front=np;
        else
        {
            np->next=front;
            front=np;
        }
    }
    int Delete()
    {
        if(front==NULL)
        {
            cout<<"UNDERFLOW!!\n";
            return -1;
        }
        else if(front->next==NULL)
        {
            int x=front->info;
            delete front;
            front=NULL;
            return x;
        }
        else
        {
            ptr=front;
            while((ptr->next)->next != NULL)
                ptr=ptr->next;
            int x=(ptr->next)->info;
            delete ptr->next;
            ptr->next=NULL;
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
        cout<<"\n";
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
        cout<<"Menu\n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        int x;
        cin>>x;
        switch(x)
        {
            case 1:
                cout<<"Enter Element to be added to list: ";
                cin>>inf;
                newPtr = obj.createNewNode(inf);
                if(newPtr==NULL)
                {
                    cout<<"Cannot create node!! ABORTING!!!\n";
                    system("pause");
                    exit(1);
                }
                obj.Insert(newPtr);
                break;
            case 2:
                k = obj.Delete();
                if(k!=-1)
                    cout<<k<<" was Deleted! \n";
                break;
            case 3:
                cout<<"The list is now:\n";
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

