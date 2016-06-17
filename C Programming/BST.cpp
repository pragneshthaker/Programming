#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

class Node
{
    int data;
    Node* left;
    Node* right;
public:
    int getData()
    {
        return data;
    }
    void setData(int x)
    {
        data=x;
    }
    Node* getLeft()
    {
        return left;
    }
    void setLeft(Node* y)
    {
        left=y;
    }
    Node* getRight()
    {
        return right;
    }
    void setRight(Node* y)
    {
        right=y;
    }
};

class BST
{
    Node *root, *ptr;
public:
    BST()
    {
        root=ptr=NULL;
    }
    Node * createNewNode(int n)
    {
        ptr=new Node;
        ptr->setData(n);
        ptr->setLeft(NULL);
        ptr->setRight(NULL);
        return ptr;
    }
    Node* findParent(Node* t,int x)
    {
        if(t==NULL)
        {
            cout<<"The BST is Empty!!\n";
            return NULL;
        }
        else if(t->getData()==x)
            return t;
        else if(t->getData()<x)
        {
            if(t->getRight()==NULL||t->getRight()->getData()==x)
                return t;
            else
                return findParent(t->getRight(),x);
        }
        else
        {
            if(t->getLeft()==NULL||t->getLeft()->getData()==x)
                return t;
            else
                return findParent(t->getLeft(),x);
        }
    }
    Node* findMin(Node* t)
    {
        if(t->getLeft()==NULL)
            return t;
        else findMin(t->getLeft());
    }
    Node* findMax(Node* t)
    {
        if(t->getRight()==NULL)
            return t;
        else findMax(t->getRight());
    }
    void insert(Node* newNode)
    {
        Node* parent = findParent(root,newNode->getData());
        if(parent==NULL)
        {
            root=newNode;
            return;
        }
        else if(parent->getData() > newNode->getData())
        {
            if(parent->getLeft()!=NULL)
            {
                cout<<"Duplicate entry NOT allowed!!\n";
                return;
            }
            else
            {
                parent->setLeft(newNode);
                return;
            }
        }
        else
        {
            if(parent->getRight()!=NULL)
            {
                cout<<"Duplicate entry NOT allowed!!\n";
                return;
            }
            else
            {
                parent->setRight(newNode);
                return;
            }
        }
    }
    Node* find(int x)
    {
        if(root==NULL||root->getData()==x)
            return root;
        Node* tmp=findParent(root,x);
        if(x > tmp->getData())
            return tmp->getRight();
        else
            return tmp->getLeft();
    }
    void inOrder(Node* t)
    {
        if(t->getLeft()!=NULL)
            inOrder(t->getLeft());
        cout<<t->getData()<<", ";
        if(t->getRight()!=NULL)
            inOrder(t->getRight());
    }
    void preOrder(Node* t)
    {
        cout<<t->getData()<<", ";
        if(t->getLeft()!=NULL)
            preOrder(t->getLeft());
        if(t->getRight()!=NULL)
            preOrder(t->getRight());
    }
    void postOrder(Node* t)
    {
        if(t->getLeft()!=NULL)
            postOrder(t->getLeft());
        if(t->getRight()!=NULL)
            postOrder(t->getRight());
        cout<<t->getData()<<", ";
    }
    Node* findSuccessor(Node* t)
    {
        if(t->getRight()!=NULL)
            return findMin(t->getRight());
        else return NULL;
    }
    void deleteNode(int x)
    {
        if(root==NULL)
        {
            cout<<"Empty Tree!!! \n";
            return;
        }
        Node *n,*np,*s,*sp;
        n=find(x);
        if(n==NULL)
        {
            cout<<"Element NOT found!! \n";
            return;
        }
        np=findParent(root,x);
        s=findSuccessor(n);
        if(s!=NULL)
            sp=findParent(root,s->getData());
        if(root==n)
        {
            cout<<"Deletion of ROOT case.\n";
            if(root->getLeft()==NULL&&root->getRight()==NULL)
            {
                delete root;
                root=NULL;
            }
            else if(root->getRight()==NULL)
            {
                Node* tmp=root;
                root=root->getLeft();
                delete tmp;
            }
            else if(root->getLeft()==NULL)
            {
                Node* tmp=root;
                root=root->getRight();
                delete tmp;
            }
            else
            {
                if(sp==root)
                {
                    s->setLeft(root->getLeft());
                    delete root;
                    root=s;
                }
                else
                {
                    sp->setLeft(s->getRight());
                    s->setLeft(root->getLeft());
                    s->setRight(root->getRight());
                    delete root;
                    root=s;
                }
            }
            return;
        }
        if(n->getLeft()==NULL && n->getRight()==NULL)
        {
            cout<<"Leaf node condition.\n";
            if(np->getData() > n->getData())
                np->setLeft(NULL);
            else
                np->setRight(NULL);
            delete n;
            return;
        }
        if(n->getRight()==NULL)
        {
            cout<<"No right child case.\n";
            if(np->getData()>n->getData())
                np->setLeft(n->getLeft());
            else
                np->setRight(n->getLeft());
            delete n;
            return;
        }
        if(sp==n)
        {
            cout<<"Immediate successor case.\n";
            if(np->getData() > n->getData())
                np->setLeft(s);
            else
                np->setRight(s);
            s->setLeft(n->getLeft());
            delete n;
            return;
        }
        else
        {
            cout<<"NOT immediate successor case.\n";
            if(np->getData() > n->getData())
                np->setLeft(s);
            else
                np->setRight(s);
            s->setLeft(n->getLeft());
            sp->setLeft(s->getRight());
            s->setRight(n->getRight());
            delete n;
            return;
        }
    }
    void display(Node *current, int indent)
    {
        if (current != NULL)
        {
            display(current->getRight(), indent + 4);
            if (indent > 0)
                cout << setw(indent) << " ";
            cout << current->getData() << "\n";
            display(current->getLeft(), indent + 4);
        }
    }
    Node* getRoot()
    {
        return root;
    }
};

int main()
{
    BST obj;
    Node * newPtr = NULL,*k =NULL;
    int data, flag=1,j;
    while(flag)
    {
        cout<<"Menu\n1. Insert\n2. IN-ORDER Traversal\n3. PRE-ORDER Traversal\n4. POST-ORDER Traversal\n5. Search\n6. Find Min & Max\n7. Delete\n8. Display\n9. Exit\n";
        int x;
        cin>>x;
        switch(x)
        {
            case 1:
                cout<<"Enter Element to be added to TREE: ";
                cin>>data;
                newPtr = obj.createNewNode(data);
                if(newPtr==NULL)
                {
                    cout<<"Cannot create node!! ABORTING!!!\n";
                    system("pause");
                    exit(1);
                }
                obj.insert(newPtr);
                break;
            case 2:
                cout<<"IN-ORDER Traversal:\n\n";
                obj.inOrder(obj.getRoot());
                break;
            case 3:
                cout<<"PRE-ORDER Traversal:\n\n";
                obj.preOrder(obj.getRoot());
                break;
            case 4:
                cout<<"POST-ORDER Traversal:\n\n";
                obj.postOrder(obj.getRoot());
                break;
            case 5:
                cout<<"Enter element to be searched for: ";
                cin>>j;
                k=obj.find(j);
                if(k!=NULL)
                    cout<<k->getData()<<" is Found! \n";
                else
                    cout<<"Node not found!!\n";
                break;
            case 6:
                cout<<"\nMINIMUM = "<<obj.findMin(obj.getRoot())->getData();
                cout<<"\nMAXIMUM = "<<obj.findMax(obj.getRoot())->getData();
                break;
            case 7:
                cout<<"Enter the node to be deleted from tree: ";
                cin>>j;
                obj.deleteNode(j);
                cout<<"The BST is now:\n\n";
                obj.display(obj.getRoot(),4);
                break;
            case 8:
                cout<<"The BST is now:\n\n";
                obj.display(obj.getRoot(),4);
                break;
            case 9:
                exit(0);
        }
        cout<<"\nDo you want to continue? [yes -> 1, No -> 0]";
        cin>>flag;
        system("cls");
    }
    return 0;
}
