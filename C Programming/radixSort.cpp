#include<iostream>
#include<cstdlib>

using namespace std;

class Radix
{
    int *array;
    int size;
public:
    void setSize(int n)
    {
        size=n;
    }

    void createArray()
    {
        array = new int[size];
        int val;
        for(int i=0;i<size;i++)
        {
            cout<<"Enter "<<i+1<<"th element: ";
            cin>>val;
            array[i]=val;
        }
    }

    int getMax()
    {
        int max = array[0];
        for (int i = 1; i < size; i++)
            if (array[i] > max)
                max = array[i];
        return max;
    }

    void countSortDecimal(int exp)
    {
        int output[size];
        int i, count[10] = {0};
        for (i = 0; i < size; i++)
            count[(array[i] / exp) % 10]++;
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (i = size - 1; i >= 0; i--)
        {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }
        for (i = 0; i < size; i++)
            array[i] = output[i];
    }

    void countSortBinary(int exp)
    {
        int output[size];
        int i, count[2] = {0};
        for (i = 0; i < size; i++)
            count[(array[i] >> exp) & 1]++;
        count[1] += count[0];
        for (i = size - 1; i >= 0; i--)
        {
            output[count[(array[i] >> exp) & 1] - 1] = array[i];
            count[(array[i] >> exp) & 1]--;
        }
        for (i = 0; i < size; i++)
            array[i] = output[i];
    }

    void radixSortDecimal()
    {
        int m = getMax();
        for (int exp = 1; m / exp > 0; exp *= 10)
            countSortDecimal(exp);
    }

    void radixSortBinary()
    {
        int m = getMax();
        int exp=0;
        for (int i = m; i > 0; i = i >> 1)
        {
            countSortBinary(exp);
            exp++;
        }
    }

    void printArray()
    {
        cout<<"The array is now: ";
        for(int i=0;i<size;i++)
        {
            cout<<array[i]<<"\n";
        }
    }
};

int main()
{
    int flag=1,SIZE,key,pos;
    Radix obj;
    while(flag)
    {
        cout<<"Menu\n1. Insert\n2. Radix Sort (decimal)\n3. Radix Sort (binary)\n4. Exit\n";
        int x;
        cin>>x;
        switch(x)
        {
            case 1:
                cout<<"Enter size of array";
                cin>>SIZE;
                obj.setSize(SIZE);
                cout<<"Enter Element to be added: ";
                obj.createArray();
                break;
            case 2:
                obj.radixSortDecimal();
                obj.printArray();
                break;
            case 3:
                obj.radixSortBinary();
                obj.printArray();
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
