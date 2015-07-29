#include <iostream>
#include <iomanip>
using namespace std;
int function(int i){
	int sum;
	if (i == 1||i == 0)
		sum = 1;
	else sum=i*(function(i-1));
	return sum;
}
int main(){
	int i,j;
	double final=0;
	cout<<"n e"<<endl;
	cout<<"- -----------"<<endl;
	for(i=0;i<10;i++){
		j=function(i);
		final=final+1/(j*1.0);
		if(i<3)
		cout<<i<<" "<<final<<endl;
		else cout <<setprecision(9) <<std::fixed<<i<<" "<<final<<endl;
	}
	return 0;
}