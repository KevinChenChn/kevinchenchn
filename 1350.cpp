#include <iostream>  
#include <cstring>  
using namespace std;  
  
int main()  
{  
   int t,a[100],n;
   cin>>t;
   while(t--)
	{
		cin>>n;
     		memset(a,0,sizeof(a));
		int i,j;
        			for(i=0;i<=n;i++)
			  {
				for(j=i;j<=n;j+=i)
				{
					if(a[j])
					a[j]=0;
					else
					a[j]=1;
				}
   			  }
	
	int cnt=0;
	for(i=0;i<=n;i++)
		{
			if(a[i])
			cnt++;
		}	
	cout<<cnt<<endl;
	}
      return 0;
}
