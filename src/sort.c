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
	int min = 0;
	for(int i=0;i<len-1;i++)
	{
		min = i;
		for(int j=i+1;j<len;j++)
		{
			if(arr[min]>arr[j])
			{
				min = j;
			}
		}
		if(min !=i)
		{
			temp   = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
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
/*
算法:快速排序
输入参数:
arr[]:需要排序的数组
len  :排序数组的长度
时间复杂度:o(nlogn)
空间复杂度:O(log2n)
其他：下层递归的实现，依赖上层操作的结果。（只有父节点操作完成，才能对子节点进行递归）
*/
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
/*
算法:归并排序
输入参数:
arr[]:需要排序的数组
len  :排序数组的长度
时间复杂度:o(nlogn)
空间复杂度:O(n)
其他：上层递归的操作，依赖下层递归的结果。（只有子节点全部操作完成，才可以操作父节点）
*/
void merge1(int arr[],uint32_t start,uint32_t mid,uint32_t end)
{
	int *temp = (int *)malloc((end-start+1)*sizeof(int));
	int i = start;
	int j = mid+1;
	int k = 0;
	while(i<=mid && j<=end)
	{
		if(arr[i]<arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}
	while(i<=mid)
	{
		temp[k++] = arr[i++];
	}
	while(j<=end)
	{
		temp[k++] = arr[j++];
	}
	for(int l=0;l<k;l++)
	{
		arr[start+l] = temp[l];
	}
	free(temp);
}
void merge_sort1(int arr[],uint32_t start,uint32_t end)
{
	if(start>=end) return;

	uint32_t mid = (start + end)/2;

	merge_sort1(arr,start,mid);
	merge_sort1(arr,mid+1,end);
	merge1(arr,start,mid,end);
}
void merge2(int arr[],int len)
{
	int *temp = (int *)malloc(len*sizeof(int));
	int start = 0;
	int mid = len/2-1;//为数组下标 所以减1
	int end = len-1;
	int i = start;
	int j = mid+1;
	int k = 0;
	while(i<=mid && j<=end)
	{
		if(arr[i]<arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	while(i<=mid)  temp[k++] = arr[i++];
	while(j<=end)  temp[k++] = arr[j++];
	for(int i=0;i<k;i++)  arr[i] = temp[i];
	free(temp);
}
void merge_sort2(int arr[],uint32_t len)
{
	if(len<=1) return;

	uint32_t mid = len/2;

	merge_sort2(arr,mid);
	merge_sort2(arr+mid,len-mid);
	merge2(arr,len);
}
void kmq_merge(int temp[],int arr[],int len)
{


}
void kmq_sort(int arr[],int len)
{

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
	int rows    =  sizeof(arr)/sizeof(arr[0]);
	int columns =  sizeof(arr[0])/sizeof(arr[0][0]);
/*
	// printf("&arr=%x\n", &arr);
	// printf("&arr+1=%x\n", &arr+1);
	// printf("arr=%x\n", arr);
	// printf("arr+1=%x\n", arr+1);
	// printf("&arr[0]=%x\n", &arr[0]);
	// printf("&arr[0]+1=%x\n", &arr[0]+1);
	// printf("arr[0]=%x\n", arr[0]);
	// printf("&arr[0][0]=%x\n", &arr[0][0]);
	// printf("&arr[0][0]+1=%x\n", &arr[0][0]+1);
	// printf("&arr[1]=%x\n", &arr[1]);
	// printf("arr[1]=%x\n", arr[1]);
	// printf("sizeof(arr)=%d\n", sizeof(arr));
	// printf("sizeof(arr[0])=%d\n", sizeof(arr[0]));
*/
	for(int i=0;i<rows ;i++)
	{
		for(int j=0; j<columns; j++)
		{
			printf("%d,", arr[i][j]);
		}
		printf("\n");
	}
	printf("%s\n","test start..." );
	for(int i=0; i<rows; i++)
	{
		merge_sort2(arr[i],columns);
		//merge_sort(arr[i],0,columns-1);
	}
	printf("%s\n","test end" );
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<columns; j++)
		{
			printf("%d,", arr[i][j]);
		}
		printf("\n");
	}

	return true;
}