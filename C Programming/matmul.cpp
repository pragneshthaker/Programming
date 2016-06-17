#include<iostream>
#include<stdlib.h>

int** memalloc(int r,int c)
{
    int i,**y;
    y =(int**) malloc(sizeof(int*)*r);
    for(i=0;i<r;i++)
        *(y+i)=(int*) malloc(sizeof(int)*c);
    return y;
}

int** product(int** a, int m, int n, int** b, int p, int q)
{
    int** x;
    int i,j,k;
    x = memalloc(m,q);
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            *(*(x+i)+j) = 0;
            for(k=0;k<n;k++)
                *(*(x+i)+j) += *(*(a+i)+k) * *(*(b+k)+j);
        }
    }
    return x;
}

using namespace std;

int main()
{
    int r1,c1,r2,c2,**a,**b,**prod,i,j;
    cout<<"Enter order of first matrix (r, c):";
    cin>>r1>>c1;
    cout<<"Enter order of second matrix (r, c):";
    cin>>r2>>c2;
    if(r1<1||c1<1||r2<1||c2<1)
    {
        cout<<"\nInvalid order of matrix!!";
        exit(0);
    }
    else if(c1!=r2)
    {
        cout<<"\nMatrix product does not exist!";
        exit(0);
    }
    a = memalloc(r1,c1);
    b = memalloc(r2,c2);
    prod = memalloc(r1,c2);
    cout<<"\nEnter matrix 1: ";
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            cin>>*(*(a+i)+j);
    cout<<"\nEnter matrix 2: ";
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
            cin>>*(*(b+i)+j);
    prod = product(a,r1,c1,b,r2,c2);
    cout<<"\n Product MATRIX:\n\n";
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            cout<<*(*(prod+i)+j)<<"  ";
        }
        cout<<"\n";
    }
    free(a);
    free(b);
    free(prod);
    return 0;
}
