#include <iostream>
using namespace std;
int main(){
	float m,i,k;
	while(cin>>m)
	{	k=2;
		i=0;
		if(m>=0.01&&m<=5.20)
		{while(1){
			i+=1/k;
		            if(m>i)  k+=1;
			
			else {
				cout<<k-1<<" card(s)"<<endl;
				break;
			}
		}
		
	}
}

}