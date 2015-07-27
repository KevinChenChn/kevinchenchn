#include<stdio.h>
typedef struct cl 
{
	int r,g,b;
	int avr;
} CL;
int main(){
	CL setCL[16],temp;
	int i,k,m,n;
	for(i=0;i<16;i+=1)
	{
		scanf("%d%d%d",&setCL[i].r,&setCL[i].g,&setCL[i].b);
		setCL[i].avr=setCL[i].r*setCL[i].r+setCL[i].g*setCL[i].g+setCL[i].b*setCL[i].b;
	}
	while(scanf("%d%d%d",&temp.r,&temp.g,&temp.b)){
		if(temp.r==-1)break;
		k=0;
		m=setCL[k].avr-2*(setCL[k].r*temp.r+setCL[k].g*temp.g+setCL[k].b*temp.b);
		for(i=1;i<16;i+=1)
		{
			n=setCL[i].avr-2*(setCL[i].r*temp.r+setCL[i].g*temp.g+setCL[i].b*temp.b);
			if(m>n)
			{
				m=n;
				k=i;
			}
		}
	printf("(%d,%d,%d) maps to (%d,%d,%d)\n",temp.r,temp.g,temp.g,setCL[k].r,setCL[k].g,setCL[k].b);
	}
	printf("\n");
	return 0;

}