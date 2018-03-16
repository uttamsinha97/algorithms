//RECURSIVE BINARY AND LINEAR SEARCH

#include <iostream>
#include <stdlib.h>
using namespace std;
int k,c,n;

void random(int a[],int n)
{
      srand(time(NULL));
      for(int i=0;i<n;i++)
      a[i]=rand();
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
void binarysearch(int arr[],int s,int e)
{
    c++;
    int mpos=(s+e)/2;
    if(s>e||e<s)
    {
        cout<<"No match found";
        return;
    }
    if(arr[mpos]==k)
        cout<<endl<<k<<" found at position "<<mpos<<endl;
    else if(arr[mpos]>k)
        binarysearch(arr,s,mpos-1);
    else if(arr[mpos]<k)
        binarysearch(arr,mpos+1,e);
    return;
}

void linearsearch(int arr[])
{
    for(int i=0;i<n;i++)
    {
        c++;
        if(arr[i]==k)
        {
            cout<<k<<" found at position "<<i<<endl;
            return;
        }
    }
    cout<<k<<" not found";
}

void display(int arr[])
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void arrSort(int arr[])
{
    int temp,i,j;
    for(i=1;i<=n;i++)
    {
	    for(j=1;j<=(n-i);j++)
	    {
		    if(arr[j]>arr[j+1])
		    {
			    temp=arr[j];
			    arr[j]=arr[j+1];
			    arr[j+1]=temp;
		    }
	    }
    }
}
int main()
{
    int ch;
    while(1)
    {
        cout<<"\nEnter your choice of array elements: ";
        cout<<"\n\t1.Ascending order\n\t2.Descending order\n\t3.Random Numbers\n\t4.Exit\n";
        cin>>ch;
        int arr[n];
        switch(ch)
        {
           case 1:cout << "Enter the number of elements: " << endl;
                    cin>>n;
                    ascending(arr,n);
                    cout<<"Array Elements: \n";
                     display(arr);
                    break;
            case 2:
                    cout << "Enter the number of elements: " << endl;
                    cin>>n;
                    descending(arr,n);
                    cout<<"Array Elements: \n";
                     display(arr);
                     break;
            case 3:
                    cout << "Enter the number of elements: " << endl;
                    cin>>n;
                    random(arr,n);
                    cout<<"Array Elements: \n";
                     display(arr);
                     break;
            case 4: exit(0);
            cout<<"\nbye!\n";
            default: cout<<"Invalid choice";
        }
        cout<<"\nEnter the type of search you want to perform ?\n\t1.Linear Search\n\t2.Binary Search\n";
        cin>>ch;
        switch(ch)
        {
            case 1:   cout<<"Enter the key element: ";
                        cin>>k;
                     c=0;
                     linearsearch(arr);
                     cout<<"\nNumber of comparisions: "<<c<<endl;
                     break;
            case 2:   cout<<"Enter the key element: ";
                        cin>>k;
                     if(n>1)
                        arrSort(arr);
                     cout<<"Sorted Array Elements: \n";
                     display(arr);
                     c=0;
                     binarysearch(arr,0,n-1);
                     cout<<"\nNumber of comparisions: "<<c<<endl;
                     break;
            default: cout<<"Invalid choice";
        }
    }
    return 0;
}
