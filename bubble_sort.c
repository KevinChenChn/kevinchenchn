/*
 * =====================================================================================
 *
 *       Filename:  bubble_sort.c
 *
 *    Description:  冒泡排序
 *
 *        Version:  1.0
 *        Created:  2014年11月17日 11时15分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  latency (mn), lovemax_tvfxq@126.com
 *        Company:  brilliant engineer
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//冒泡排序
void bubble_sort(int a[],int n)
{
	//交换标志位noswap
	int i,j,noswap;
	//交换中间变量
	int temp;
	//最多进行n-1趟排序
	for(i=0;i<n-1;i++){
		//交换标志位置1
		noswap = 1;
		//每趟从后往前比较
		for(j=n-1;j>i;j--)
		  //小的放前面
		  if(a[j] < a[j-1]){
			temp = a[j];
			a[j] = a[j-1];
			a[j-1] = temp;
			//交换标志位置0
			noswap = 0;
		   }
		//交换标志位为1
		if(noswap)
		  //说明本趟未发生交换，退出循环
		  break;
	}
}

int main(void)
{
	int i;
	int a[10];
	//获取10个100以内的随机数
	for(i=0;i<10;i++){
	  a[i] = rand() % 100;
	  printf("%4d",a[i]);
	}
	printf("\n");
	bubble_sort(a,10);
	for(i=0;i<10;i++)
	  printf("%4d",a[i]);
	printf("\n");
	return 0;
}
