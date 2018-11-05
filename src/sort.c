#include "sort.h"


/*
算法:选择排序
输入参数:
arr[]:需要排序的数组
len  :排序数组的长度
时间复杂度:O(n2)
空间复杂度:O(1)
*/
void select_sort(int arr[],uint32_t len)
{
	int temp;
	for(int i=0;i<len-1;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(arr[j]>arr[i])
			{
				temp   = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
/*
算法:冒泡排序
输入参数:
arr[]:需要排序的数组
len  :排序数组的长度
时间复杂度:O(n2)
空间复杂度:O(1)
*/
void bubble_sort(int arr[],uint32_t len)
{
	int temp;
	for(int i=0;i<len-1;i++)
	{
		for(int j=0;j<len-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp   = arr[j];
				arr[j]   = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
void quick_sort(int arr[],uint32_t len)
{
	int i = 0;
	int j = len-1;
	int temp;
	if(len<2)
	{
		return;
	}
	while(i<j)
	{
		while(arr[j]>=arr[0]&&j>i)
		{
			j--;
		}
		while(arr[i]<=arr[0]&&i<j)
		{
			i++;
		}
		temp = arr[j];
		arr[j] = arr[i];
		arr[i] = temp;
	}
	if(i==j)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
	}
	quick_sort(arr,i);
	quick_sort(arr+i+1,len-i-1);

}
bool test_sort(void)
{
	int arr[][6] = \
	{
		{1,1,3,3,2,2},
		{1,1,1,1,2,1},
		{2,2,2,2,2,1},
		{1,2,3,4,5,6},
		{6,5,4,3,2,1},
		{4,5,6,3,2,1},

	};

	printf("&arr=%x\n", &arr);
	printf("&arr+1=%x\n", &arr+1);
	printf("arr=%x\n", arr);
	printf("arr+1=%x\n", arr+1);
	printf("&arr[0]=%x\n", &arr[0]);
	printf("&arr[0]+1=%x\n", &arr[0]+1);
	printf("arr[0]=%x\n", arr[0]);
	printf("&arr[0][0]=%x\n", &arr[0][0]);
	printf("&arr[0][0]+1=%x\n", &arr[0][0]+1);
	printf("&arr[1]=%x\n", &arr[1]);
	printf("arr[1]=%x\n", arr[1]);
	printf("sizeof(arr)=%d\n", sizeof(arr));
	printf("sizeof(arr[0])=%d\n", sizeof(arr[0]));

	for(int i=0;i<sizeof(arr)/sizeof(arr[0]) ;i++)
	{
		for(int j=0;j<sizeof(arr[j])/sizeof(arr[j][0]) ;j++)
		{
			printf("%d,", arr[i][j]);
		}
		printf("\n");
	}
	printf("%s\n","test start..." );
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]) ;i++)
	{
		quick_sort(arr[i],sizeof(arr[i])/sizeof(arr[i][0]));
	}
	printf("%s\n","test end" );
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]) ;i++)
	{
		for(int j=0;j<sizeof(arr[j])/sizeof(arr[j][0]) ;j++)
		{
			printf("%d,", arr[i][j]);
		}
		printf("\n");
	}

	return true;
}