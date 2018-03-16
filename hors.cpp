#include<iostream>
#include<string.h>
using namespace std;
int s[200];   
int r;
char p[20],t[100];
int n,m;
int strmat()
{
    int i,j,k=0;
    for(i=0;i<n;i++)
    {
        s[t[i]]=m;
        for(j=0;j<m-2;j++)
        s[p[j]]=m-1-j;
    }
    i=m-1;
    while(i<=n-1)
    {
       k=0;
       while(k<=m-1 && p[m-1-k]==t[i-k])
          k=k+1;
       if(k==m)
          return i-m+1;
       else
          i=i+s[t[i]];
    }
    return -1;
}

int main()
{
	cout<<"\n Enter the text \n";
	cin>>t;
	cout<<"\n Enter the pattern \n";
   cin>>p;
   m=strlen(p);
   n=strlen(t);
   cout<<"\n Length of the text = "<<n<<" \n";
   cout<<"\n Length of the pattern = "<<m<<"\n";
   r=strmat();
   if(r>=0)
   cout<<"\n Found at position = "<<r+1<<"\n";
   else 
   cout<<"\n pattern not matched \n";
   return 0;
}
