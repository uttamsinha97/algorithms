//INSERTION SORT

#include<iostream>
#include<stdlib.h>
using namespace std;
int comp=0;
void insertion(int*a,int n)
{
    int v,i,j;
    for(i=0;i<n;i++)
    {
        v=a[i];
        j=i-1;
        while(j>=0&&a[j]>v)
        {
            comp++;
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=v;
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
       cout<<"\nEnter the type of input \n\n1. ascending\n 2.descending\n3.random\n4.exit\n\n";
       cin>>choice;
       switch(choice)
       {
           case 1:
                    cout<<"Enter the size of the array:\n";
                    cin>>n;
                    ascending(a,n);
                    cout<<"\nElements of the array are:\n";
                    display(a,n);
                    insertion(a,n);
                    cout<<"\n\nElements in sorted order:\n";
                    display(a,n);
                    cout<<"\n\nNo. of comparisons are:\n"<<comp;
                    break;
            case 2:
                    cout<<"Enter the size of the array:\n";
                    cin>>n;
                    descending(a,n);
                    cout<<"\nElements of the array are:\n";
                    display(a,n);
                    insertion(a,n);
                    cout<<"\n\nElements in sorted order:\n";
                    display(a,n);
                    cout<<"\n\nNo. of comparisons are:\n"<<comp;
                    break;
            case 3:
                    cout<<"Enter the size of the array:\n";
                    cin>>n;
                    random(a,n);
                    cout<<"\nElements of the array are:\n";
                    display(a,n);
                    insertion(a,n);
                    cout<<"\n\nElements in sorted order:\n";
                    display(a,n);
                    cout<<"\n\nNo. of comparisons are:\n"<<comp;
                    break;
            case 4: cout<<"\n\nGoodbye!\n\n";
                    exit(0);
                    default: cout<<"\n\ninvalid choice\n\n";
       }
   }

    cout<<"\n\n";
    return 0;

}

