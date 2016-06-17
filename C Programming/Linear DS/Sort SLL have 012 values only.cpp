#include<iostream>
#include<cstdlib>

using namespace std;
// program to sort link list contains only 3 distict values 0,1,2 in one pass
class Node
{
    int info;
    Node* next;
public:
    int getInfo()
    {
        return info;
    }
    void setInfo(int x)
    {
        info=x;
    }
    Node* getNext()
    {
        return next;
    }
    void setNext(Node* y)
    {
        next=y;
    }
};

class OrderLinkedList
{
    Node *front, *ptr,* rear;
public:
    OrderLinkedList()
    {
        front=ptr=rear=NULL;
    }
    Node * createNewNode(int n)
    {
        ptr=new Node;
        ptr->setInfo(n);
        ptr->setNext(NULL);
        return ptr;
    }
    void Insert(Node * np)
    {
        if(front==NULL)
            front=rear=np;
        else
        {
            rear->setNext(np);
            rear=np;
        }
    }
    void Display(Node * np)
    {
         if(front==NULL)
        {
            cout<<" EMPTY!!!";
            return;
        }
        cout<<"[FRONT]-> ";
        while(np!=NULL)
        {
            cout<<np->getInfo()<<"->";
            np=np->getNext();
        }
        cout<<"\b\b <-[REAR]\n";
    }
    void sortList()
    {
        if(front == NULL || front->getNext() == NULL)
            return;

        Node* t1 = front;
        int count = 1;

        while(t1->getNext() != NULL)
        {
            t1 = t1->getNext();
            count++;
        }

        Node *curr = front;
        Node *prev = front;

        for(int i=0; i<count; i++)
        {
            Node* temp = curr;
            curr = curr->getNext();

            if(temp->getInfo() == 0)
            {
                if(prev != temp)
                {
                    temp->setNext(front);
                    front = temp;
                    prev->setNext(curr);
                }
            }
            else if(temp->getInfo() == 2)
            {
                rear->setNext(temp);
                temp->setNext(NULL);
                rear = temp;
                if(prev == temp)
                    front = prev = curr;
                else
                    prev->setNext(curr);
            }
            else
            {
                if(prev != temp)
                    prev = prev->getNext();
            }
        }
    }
    Node * getFront()
    {
        return front;
    }
};

int main()
{
    OrderLinkedList obj;
    Node * newPtr = NULL,* k;
    int inf, flag=1,j;
    while(flag)
    {
        cout<<"Menu\n1. Insert\n2. Sort\n3. Display\n4. Exit\n";
        int x;
        cin>>x;
        switch(x)
        {
            case 1:
                cout<<"Enter Element (0, 1 or 2) to be added to list: ";
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
                obj.sortList();
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
