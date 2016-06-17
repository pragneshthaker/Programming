#include<iostream>
#include<stdlib.h>

using namespace std;

class twoWayStacks
{
    int *array;
    int size;
    int top1, top2;
public:
   twoWayStacks(int n)
   {
       size = n;
       array = new int[n];
       top1 = -1;
       top2 = size;
   }


   void disp1()
   {
       int k=top1;
       while(k>=0)
       {
           cout<<array[k]<<"\n";
           k--;
       }
   }

   void disp2()
   {
       int k=top2;
       while(k<size)
       {
           cout<<array[k]<<"\n";
           k++;
       }
   }

   void push1(int x)
   {
       if (top1 < top2 - 1)
       {
           top1++;
           array[top1] = x;
       }
       else
       {
           cout << "Stack Overflow";
           return;
       }
   }

   void push2(int x)
   {
       if (top1 < top2 - 1)
       {
           top2--;
           array[top2] = x;
       }
       else
       {
           cout << "Stack Overflow";
           return;
       }
   }

   void pop1()
   {
       if (top1 >= 0 )
       {
          int x = array[top1];
          top1--;
          cout<<"\n"<<x<<" Was popped. \n";;
       }
       else
       {
           cout << "Stack UnderFlow";
           return;
       }
   }

   void pop2()
   {
       if (top2 < size)
       {
          int x = array[top2];
          top2++;
          cout<<"\n"<<x<<" Was popped. \n";
       }
       else
       {
           cout << "Stack UnderFlow";
           return;
       }
   }
};

int main()
{
    int flag=1,key;
    twoWayStacks stack2Way(5);
    while(flag)
    {
        cout<<"Menu\n1. Push into 1\n2. Push into 2\n3. Pop from 1\n4. Pop from 2\n5. Display 1\n6. display 2\n7. Exit\n";
        int x;
        cin>>x;
        switch(x)
        {
            case 1:
                cout<<"Enter Elements to be pushed into stack 1: ";
                cin>>key;
                stack2Way.push1(key);
                break;
            case 2:
                cout<<"Enter Elements to be pushed into stack 2: ";
                cin>>key;
                stack2Way.push2(key);
                break;
            case 3:
                stack2Way.pop1();
                break;
            case 4:
                stack2Way.pop2();
                break;
            case 5:
                cout<<"The stack 1 is now:\n";
                stack2Way.disp1();
                break;
            case 6:
                cout<<"The stack 2 is now:\n";
                stack2Way.disp2();
                break;
            case 7:
                exit(0);
        }
        cout<<"\nDo you want to continue? (yes -> 1, No -> 0)";
        cin>>flag;
    }
    return 0;
}
