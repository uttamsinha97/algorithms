#include<iostream>
using namespace std;
int c[10][10];

int min(int a,int b)// for finding minimum of two numbers
{
   int min;
   if(a>b)
      min=b;
   else
      min=a;
   return min;
}
int bin(int n,int k) // for binomian coefficient evaluation
{
    int i,j;
    for(i=0;i<=n;i++)
    {
       for(j=0;j<=min(i,k);j++)
       {
          if(j==0 || j==i)
             c[i][j]=1;
          else
             c[i][j]=c[i-1][j-1]+c[i-1][j];
       }
    }
    return c[n][k];
}
int main()
{
   int i,j,n,k;
   cout<<"enter a non negative integer\n";
   cin>>n;
   cout<<"enter another non negative integer\n";
   cin>>k;
   bin(n,k);
   cout<<"BINOMIAL COEFFICIENT OF C("<<n<<","<<k<<") IS "<<c[n][k]<<"\n";
  // cout<<"----------------------------------\n";
   for(i=0;i<=n;i++)
   {
      for(j=0;j<=k;j++)
      {
         cout<<c[i][j]<<"\t";
      }
      cout<<"\n";
   }
}
