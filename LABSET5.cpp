//QUICKSORT(24-0-2017)
#include<iostream>
#include<stdlib.h>
using namespace std;
int comp=0;
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
        a[i]=rand()%1000;
    }
}
void display(int a[],int n)
{

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}
int partition(int a[],int l,int r)
{
    int p,i,j;
    p=a[l];
    i=l+1;
    j=r;
    while(i<j)
    {
        while(a[i]<p)
        {
            i++;
            comp++;
        }
        while(a[j]>p)
        {
            j--;
            comp++;
        }
        if(i<j)
        {

           swap(a[i],a[j]);
        }
        else
        {

           swap(a[l],a[j]);
        }
    }
    return j;
}
void quicksort(int a[],int l,int r)
{
    int s;
    if(l<r)
    {
        s=partition(a,l,r);
        quicksort(a,l,s-1);
        quicksort(a,s+1,r);
    }
}
int main()
{
    int choice,n,a[100];
    while(1)
    {
        cout<<"Enter your choice of array element:\n\n1.Ascending order\n2.Descending order\n3.Random order\n4.Exit\n";
        cin>>choice;
        switch(choice)
        {
         case 1:cout<<"\nEnter the size of the array:\n";
                cin>>n;
                ascending(a,n);
                cout<<"\nThe ascending elements are:\n";
                display(a,n);
                quicksort(a,0,n-1);
                cout<<"\nSORTED ARRAY:\n";
                display(a,n);
                cout<<"\n\nNo. of comparisons: "<<comp<<"\n";
                break;
         case 2:cout<<"\nEnter the size of the array:\n";
                 cin>>n;
                 descending(a,n);
                 cout<<"\nThe descending elements are:\n";
                 display(a,n);
                 quicksort(a,0,n-1);
                 cout<<"\nSORTED ARRAY:\n";
                 display(a,n);
                 cout<<"\n\nNo. of comparisons: "<<comp<<"\n";
                 break;
         case 3:cout<<"\nEnter the size of the array:\n";
                 cin>>n;
                 random(a,n);
                 cout<<"\nThe random elements are:\n";
                 display(a,n);
                 quicksort(a,0,n-1);
                 cout<<"\nSORTED ARRAY:\n";
                 display(a,n);
                 cout<<"\n\nNo. of comparisons: "<<comp<<"\n";
                 break;
        case 4: cout<<"GOODBYE!\n";
                 exit(0);
        default: cout<<"\nINVALID CHOICE\n\n";

        }
    }
}
