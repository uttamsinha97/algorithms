//TOPOLOGICAL SORTING(31-08-17)


#include<iostream>
using namespace std;
int temp[100],k=0;
void topo(int n,int indegree[],int a[][100])
{
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            indegree[i]=-1;
            temp[++k]=i;
            for(int j=1;j<=n;j++)
                if(indegree[j]!=0 && a[i][j]==1)
                    indegree[j]--;
            i=0;
        }
    }
}
int main()
{   int i,j,n,indegree[100],a[100][100];
    cout<<"Enter the no of vertices:\n";
    cin>>n;
    for( i=1;i<=n;i++)
    {
        indegree[i]=0;
    }
    cout<<"Enter the adjacency matrix:\n";
     for(i=1;i<=n;i++)
     {
         for(j=1;j<=n;j++)
         {
             cout<<"a["<<i<<"]["<<j<<"]=";
             cin>>a[i][j];
             if(a[i][j]==1)
              indegree[j]++;
         }
     }

    cout<<"\nThe entered matrix is:\n";
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
     topo(n,indegree,a);
     if(k!=n)
       cout<<"\n Topological sorting not possible\n\n";
     else
     {
	     cout<<"\n\nTopological sorting order:\n";
	     for(i=1;i<=n;i++)
      {
          cout<<temp[i];
          if(i!=n)
          {
              cout<<"------->";
          }
      }
      cout<<"\n";
     }
      return 0;
}
