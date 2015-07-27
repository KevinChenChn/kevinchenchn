#include <iostream>
#include <iomanip>

using namespace std;
int main(){
	int k,m,n,i=0;
	float l;
	cin>>k;
	while(k--){
	cin>>m>>n;
	if((int)m%2==0||(int)n%2==0){
		l=m*n;
		i+=1;
		cout<<"Scenario #"<<(int)i<<":"<<endl;
		cout << fixed << showpoint << setprecision(2) <<l<<endl;
		cout<<endl;
	}
	else{
		l=m*n-1+1.41;
		i+=1;
		cout<<"Scenario #"<<(int)i<<":"<<endl;

		cout << fixed << showpoint << setprecision(2) <<l<<endl;
		cout<<endl;
	}
}
	
}