 #include<stdio.h>
#define pi 3.1415926
 int main()
{
	int n,k,i;
	double x,y;
	double s;
	scanf("%d",&n);
 	for(i=1;i<=n;++i)
 	{
 		scanf("%lf%lf",&x,&y);
 		s=(x*x+y*y)*pi/100;
     		k=(int)(s+1);
    		printf("Property %d: This property will begin eroding in year %d.\n",i,k);
  	}
 		printf("END OF OUTPUT.\n");
		return 0;
 }