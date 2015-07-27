#include <stdio.h>
int main (){
	int i;
	float a,s=0;
	for(i=0;i<12;i++)
	{
		scanf("%f",&a);
		s=s+a;
	}
	s=s/12;
	printf("$%.2f\n",s);
}