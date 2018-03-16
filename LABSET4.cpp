//HEAPSORT
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void ascending(int arr[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        arr[i]=i+1;
    }
}
void descending(int arr[],int n)
{
    int j=0;
    for(int i=n-1;i>=0;i--)
    {
        arr[j++]=i+1;
    }
}

void random(int arr[],int n)
{

    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100000;
    }
}

void display(int arr[],int n)
{

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
}

void heapify1(int *arr,int n,int i)
{
    int largest=i;
    int l= 2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest])
        largest=l;
    if(r<n && arr[r]>arr[largest])
        largest=r;
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify1(arr,n,largest);
    }
}

void heapsort1(int arr[],int n)
{
    for(int i=n/2 -1 ; i>=0;i--)
        heapify1(arr,n,i);
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify1(arr,i,0);
    }
}

int main()
{
    int choice;
    int arr[100];
    cout<<"\n--------------HEAPSORT PROGRAM---------------\n";
    while(1)
    {
        cout<<"\nGenerate elements in \n1.Ascending Order\n2.Descending Order\n3.Random Order\n4.Exit\n";
        cin>>choice;
        int n;
        switch(choice)
        {
            case 1: cout<<"\nEnter the size of the array\n";
                     cin>>n;
                      ascending(arr,n);
                     cout<<"\nGenerated elements are\n";

                       display(arr,n);
                     heapsort1(arr,n);
                     cout<<"\nSorted Array:\n";
                     display(arr,n);
                     break;
            case 2: cout<<"\nEnter the size of the array\n";
                     cin>>n;
                     descending(arr,n);
                     cout<<"\nGenerated elements are\n";
                     display(arr,n);
                     heapsort1(arr,n);
                     cout<<"\nSorted Array:\n";
                     display(arr,n);
                     break;
            case 3: cout<<"\nEnter the size of the array\n";
                     cin>>n;
                     random(arr,n);
                     cout<<"\nGenerated elements are\n";
                     display(arr,n);
                     heapsort1(arr,n);
                     cout<<"\nSorted Array:\n";
                     display(arr,n);
                     break;
            case 4: cout<<"\nGOODBYE!\n";
                     exit(0);
            default:cout<<"Invalid choice/n";
        }
    }
}
