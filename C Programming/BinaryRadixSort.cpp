
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

unsigned int findMax(unsigned int *a,int N)
{
    unsigned int max = a[0];
    for(int i=1;i<N;i++)
      if(max<a[i])
        max=a[i];
    
    return max;
}

void binRadixSort(unsigned int *a,int N){

    
    unsigned int *b[4];
    b[0]=a;//now b[0] is holding the orignal array
    int i,j;
    for(i=1;i<4;i++){
        b[i]= (unsigned int*)malloc(sizeof(unsigned int)*N);
    }

    int H0;
    // hold the upper bound of the array thathold bit '0'
    //Section 2 initialize H0 and number of pass required
    H0 = N-1;
    int len = sizeof(unsigned int)*8;
    unsigned int ander =1; // a number that we use to perform the and
    //operation to extract perticular bit

    int k0,k1,k2,k3;
    k0=0;
    k1=k0+1;
    k2=k0+2;
    k3=k0+3;
    int maximum = findMax(a,N);

    len = ceil(log(maximum)/log(2));
    cout<< " value of Len is ::::"<<len;
    
    int j0=0,j1=0;//variable to hold the count where we need to store a number with
    //perticular bit is 0 in j0 and 1 in j1
    for(i=0;i<len;i++)
    {
      //int j;
      j0=j1=0;
      for(j=0;j<=H0;j++){
        if(!(b[k0][j]&ander))
        {
          b[k2][j0] = b[k0][j];
          j0++;
        }
        else
        {
          b[k3][j1] = b[k0][j];
          j1++;
        }
    }
    for(;j<N;j++){
        if(!(b[k1][j-H0-1]&ander))
        {
            b[k2][j0] = b[k1][j-H0-1];
            j0++;
        }
        else
        {
            b[k3][j1] = b[k1][j-H0-1];
            j1++;
        }
    }
      
    ander = ander*2;
    cout<<ander<<endl;
    H0=j0-1;
    
    //write a code so that in the next iteration we are
    k0 = k2;
    k1 = k3;
    k2 = (k2+2)%4;
    k3 = (k3+2)%4;
    
    // find the number of binary digit in the number and initailize the nuber to perform and operation
    //
  }
    
  //copy the sorted array in the orignal array
    for(j=0;j<=H0;j++)
        a[j]=b[k0][j];
    for(;j<N;j++)
        a[j]=b[k1][j-H0-1];
    
    cout<<endl<<endl;
}
int main()
{
      unsigned int *a;
      int N; // Number of elment in the array
      int i;
      // clrscr();
      //initialize
      
      //section 1
      //initialize the array
      //**********************************************
      cout<<"Enter the Array Size";
      cin>>N;
      a = (unsigned int*)malloc(sizeof(unsigned int)*N);
      
      //*****************************************
      
      //get the input of the array
      for(i=0;i<N;i++){
          cout<<"enter A["<<i<<"]:";
          cin>>a[i];
      }
      binRadixSort(a,N);
      for(i=0;i<N;i++)
          cout<<"A["<<i<<"]:"<<a[i]<<endl;
      
      return 0;

}
