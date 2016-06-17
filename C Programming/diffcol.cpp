#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int r,*c,**a,i,j,n;
    cout<<"Enter the no. of rows: ";
    cin>>r;
    cout<<"Enter the maximum possible no. of columns: ";
    cin>>n;
    c =(int*) malloc(sizeof(int)*n);
    a =(int**) malloc(sizeof(int*)*r);
    for(i=0;i<r;i++)
    {
        cout<<"Enter no. of columns in row "<<i+1<<": ";
        cin>>*(c+i);
        *(a+i)=(int*) malloc(sizeof(int) * *(c+i));
        cout<<"Enter the values into row "<<i+1<<": ";
        for(j=0;j<*(c+i);j++)
        {
            cin>>*(*(a+i)+j);
        }
    }
    cout<<"The matrix is:\n\n";
    for(i=0;i<r;i++)
    {
        for(j=0;j<*(c+i);j++)
            cout<<*(*(a+i)+j)<<" ";
        cout<<"\n";
    }
    free(a);
}
