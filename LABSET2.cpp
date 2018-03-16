//MERGESORT
#include<stdlib.h>
#include<iostream>
using namespace std;
int comp=0;

void merge(int*b,int*c,int*a,int p,int q)
{
    int i,j,k;
    i=j=k=0;
    while(i<p && j<q)
    {
        comp++;
        if(b[i]<c[j])
        {
            a[k]=b[i];
            i=i+1;
        }
        else
        {
            a[k]=c[j];
            j=j+1;
        }
        k=k+1;
    }
    if(i==p)
    {
        while(j<q)
        {
            a[k++]=c[j];
            j++;
        }
    }
    else
    {
        while(i<p)
        {
            a[k++]=b[i];
            i++;
        }
    }
}
void mergesort(int*a,int n)
{
    int b[10],c[10],i=0,j;
    if(n>1)
    {
        for(i=0;(i<n/2);i++)
        {
            b[i]=a[i];
        }
        int k=i;
        for(j=(n/2),i=0;j<n;j++,i++)
        {
            c[i]=a[j];
        }
        mergesort(b,k);
        mergesort(c,i);
        merge(b,c,a,k,i);
    }
}
void display(int a[],int n)
{

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}
void ascending(int a[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
}
void descending(int a[],int n)
{
    int j=0;
    for(int i=n-1;i>=0;i--)
    {
        a[j++]=i+1;
    }
}
void random(int a[],int n)
{

    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100000;
    }
}
int main()
{
    int a[50],n,choice;

   while(1)
   {
       cout<<"\nEnter the type of input \n\n1.ascending\n2.descending\n3.random\n4.exit\n\n";
       cin>>choice;
       switch(choice)
       {
            case 1: cout<<"\nEnter the size of the array:\n";
                    cin>>n;
                    ascending(a,n);
                    cout<<"\nElements of the array are:\n";
                    display(a,n);
                    mergesort(a,n);
                    cout<<"\n\nElements in sorted order:\n";
                    display(a,n);
                    cout<<"\n\nNo. of comparisons are:\n"<<comp;
                    break;
            case 2: cout<<"\nEnter the size of the array:\n";
                    cin>>n;
                    descending(a,n);
                    cout<<"\nElements of the array are:\n";
                    display(a,n);
                    mergesort(a,n);
                    cout<<"\n\nElements in sorted order:\n";
                    display(a,n);
                    cout<<"\n\nNo. of comparisons are:\n"<<comp;
                    break;
            case 3: cout<<"\nEnter the size of the array:\n";
                    cin>>n;
                    random(a,n);
                    cout<<"\nElements of the array are:\n";
                    display(a,n);
                    mergesort(a,n);
                    cout<<"\n\nElements in sorted order:\n";
                    display(a,n);
                    cout<<"\n\nNo. of comparisons are:\n"<<comp;
                    break;
            case 4: cout<<"\nGoodbye!\n\n";
                    exit(1);
                    default: cout<<"\n\ninvalid choice\n\n";
       }
   }
    cout<<"\n\n";
    return 0;
}

