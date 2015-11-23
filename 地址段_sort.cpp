#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>

int select_combine_b(int a[],int b[],int c[],int d[],int n)
{
	printf("select_combine_b\n");
	int i=0,j=0,k=0;
	a[i]=c[i];
	b[i]=d[i];
	for(i=1;i<n;i++)
	{
		if(b[k]>=c[i]||(b[k]+1)==c[i])
		{
			if(b[k]>=d[i])
			{
				continue;
			}
			b[k]=d[i];
		}
		else
		{
			k++;
			a[k]=c[i];
			b[k]=d[i];
		}

	}

	return k+1;
}


int select_combine_a(int a[],int b[],int c[],int d[],int n)
{
	printf("select_combine_a\n");
	int i=0,j=0,k=0;
	c[j]=a[i];
	d[j]=b[i];
	//printf("c%d ",c[j]);
	//printf("d%d\n",d[j]);	
	for(i=0;i<n;i++)
	{
		if(c[j]==a[i])
		{
			d[j]=b[i];
		}
		else{
			j++;
			c[j]=a[i];
			d[j]=b[i];
		}
	}
	return j+1;
}


void select_sort_a(int a[],int b[],int n)
{
	int i,j,k;
	int temp;
	for(i=0;i<n-1;i++){
		k = i;
		//在无序区中选择最小元素a[k]
		for(j=i+1;j<n;j++)
			if(a[j] < a[k])
			  k = j;
		//如果a[j]不是最小值，与a[k]交换
		if(k!=i){
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
			temp = b[i];
			b[i] = b[k];
			b[k] = temp;

		}
	}
}

void select_sort_c(int a[],int count,int count_temp)
{
	int i,j,k;
	int temp;
	printf("count_temp:%d\n",count_temp);
	printf("count:%d\n",count);
	for(i=count_temp;i<count-1+count_temp;i++){
		k = i;
		//在无序区中选择最小元素a[k]
		for(j=i+1;j<count+count_temp;j++)
			if(a[j] < a[k])
			  k = j;
		//如果a[j]不是最小值，与a[k]交换
		if(k!=i){
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}
}


void select_sort_b(int a[],int b[],int n)
{
	int i,j,k,l;
	int temp;
	int count=1;
	int count_temp=0;
	for(l=1;l<n;l++)
	{
		printf("l:%d\n",l);
		if(a[l-1]==a[l])
		{	
			count++;
		}
		else
		{
			select_sort_c(b,count,count_temp);
			count_temp+=count;
			count=1;
		}
	}
}


int main(void)
{
	int i,j;
	int c[10],d[10];
	memset(c,0,10);
	memset(d,0,10);
	//获取10个100以内的随机数
	int a[10] = {140,55,90,4,1,1,1,120,140,4};
	int b[10] = {220,72,110,25,11,6,2,130,160,22};
	/*for(i=0;i<10;i++){
	  a[i] = rand() % 100;
	  b[i] = rand() % 100;
	  printf("a=%4d ",a[i]);
	  printf("b=%4d\n",b[i]);
	}*/
	for(i=0;i<10;i++){
	  printf("a=%4d ",a[i]);
	  printf("b=%4d\n",b[i]);
	}
	select_sort_a(a,b,10);
	select_sort_b(a,b,10);
	printf("select_sort\n");
	for(i=0;i<10;i++){
	  printf("a=%4d ",a[i]);
	  printf("b=%4d\n",b[i]);
	}
	j = select_combine_a(a,b,c,d,10);
	for(i=0;i<j;i++){
	  printf("c=%4d ",c[i]);
	  printf("d=%4d\n",d[i]);
	}
	j = select_combine_b(a,b,c,d,j);
	for(i=0;i<j;i++){
	  printf("a=%4d ",a[i]);
	  printf("b=%4d\n",b[i]);
	}
	printf("\n");
	return 0;
}
