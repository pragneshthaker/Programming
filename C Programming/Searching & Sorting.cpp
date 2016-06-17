#include<iostream>
#include<cstdlib>

using namespace std;

class SortSearchAlgos
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
    void selectionSort ()
    {
        int pos;
        for (int i = 0; i < size-1; ++i)
        {
            pos = i;
            for (int j = i + 1; j < size; ++j)
            {
                if (array[j] < array[pos])
                {
                    pos = j;
                }
            }
            swap(array[i], array[pos]);
        }
    }
    void bubbleSort()
    {
       int i, j;
       for (i = 0; i < size-1; i++)
           for (j = 0; j < size-i-1; j++)
               if (array[j] > array[j+1])
                  swap(array[j], array[j+1]);
    }
    void insertionSort()
    {
       int i, key, j;
       for (i = 1; i < size; i++)
       {
           key = array[i];
           j = i-1;
           while (j >= 0 && array[j] > key)
           {
               array[j+1] = array[j];
               j = j-1;
           }
           array[j+1] = key;
       }
    }
    void merge(int low, int high, int mid)
    {
        int i, j, k;
        int* c = new int[size];
        i = low;
        k = low;
        j = mid + 1;
        while (i <= mid && j <= high)
        {
            if (array[i] < array[j])
            {
                c[k] = array[i];
                k++;
                i++;
            }
            else
            {
                c[k] = array[j];
                k++;
                j++;
            }
        }
        while (i <= mid)
        {
            c[k] = array[i];
            k++;
            i++;
        }
        while (j <= high)
        {
            c[k] = array[j];
            k++;
            j++;
        }
        for (i = low; i < k; i++)
        {
            array[i] = c[i];
        }
    }
    void mergesort(int low, int high)
    {
        int mid;
        if (low < high)
        {
            mid=low+(high-low)/2;
            mergesort(low,mid);
            mergesort(mid+1,high);
            merge(low,high,mid);
        }
        return;
    }
    void quicksort(int low, int high)
    {
        int pivot, i, j, temp;
        if (low < high)
        {
            pivot = low;
            i = low;
            j = high;
            while (i < j)
            {
                while (array[i] <= array[pivot] && i <= high)
                {
                    i++;
                }
                while (array[j] > array[pivot] && j >= low)
                {
                    j--;
                }
                if (i < j)
                {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
            temp = array[j];
            array[j] = array[pivot];
            array[pivot] = temp;
            quicksort(low, j - 1);
            quicksort(j + 1, high);
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
    SortSearchAlgos obj;
    while(flag)
    {
        cout<<"Menu\n1. Insert\n2. Selection Sort\n3. Bubble Sort\n4. Insertion Sort\n5. Merge Sort\n6. Quick Sort\n7. Display\n8. Exit\n";
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
                obj.selectionSort();
                obj.printArray();
                break;
            case 3:
                obj.bubbleSort();
                obj.printArray();
                break;
            case 4:
                obj.insertionSort();
                obj.printArray();
                break;
            case 5:
                obj.mergesort(0,SIZE-1);
                obj.printArray();
                break;
            case 6:
                obj.quicksort(0,SIZE-1);
                obj.printArray();
                break;
            case 7:
                obj.printArray();
                break;
            case 8:
                exit(0);
        }
        cout<<"\nDo you want to continue? [yes -> 1, No -> 0]";
        cin>>flag;
        system("cls");
    }
    return 0;
}
