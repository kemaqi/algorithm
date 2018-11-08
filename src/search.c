#include "search.h"
/*
算法:顺序查找
输入参数:
arr[]:需要查找的数组
len  :查找数组的长度
时间复杂度:O(n)
空间复杂度:O(1)
其他：
*/
void sequence_search(int arr[],uint32_t len,uint32_t key)
{
	for(int i=0;i<len;i++)
	{
		if(arr[i]==key)
		{
			 printf("arr[%d]=%d\n",i,key);
			 return;
		}
	}
}
/*
算法:二分查找
输入参数:
arr[]:需要查找的数组
len  :查找数组的长度
时间复杂度:O(log2 n)
空间复杂度:O(1)
其他：
*/
void binary_search(int arr[],uint32_t len,uint32_t key)
{
	uint32_t left = 0;
	uint32_t right= len-1;
	uint32_t mid ;
	printf("%s\n","start" );
	while(left<=right)
	{
		mid = (left+right)/2;
		if(arr[mid]<key)
		{
			left = mid+1;
		}
		else if(arr[mid]==key)
		{
            printf("arr[%d]=%d\n",mid,key);
            return;
		}
		else
		{
			right = mid-1;
		}
		
	}

}

bool test_find(void)
{
	int arr[]={1,2,3,4,5,6};
	int arr1[]={1,2,3,4,5,6,7};
	uint32_t len = sizeof(arr)/sizeof(int);
	uint32_t len1 = sizeof(arr1)/sizeof(int);
	binary_search(arr,len,1);
	binary_search(arr,len,2);
	binary_search(arr,len,3);
	binary_search(arr,len,4);
	binary_search(arr,len,5);
	binary_search(arr,len,6);
	binary_search(arr,len,7);
	binary_search(arr,len,8);
	binary_search(arr1,len1,1);
	binary_search(arr1,len1,2);
	binary_search(arr1,len1,3);
	binary_search(arr1,len1,4);
	binary_search(arr1,len1,5);
	binary_search(arr1,len1,6);
	binary_search(arr1,len1,7);
	binary_search(arr1,len1,8);

	sequence_search(arr,len,1);
	sequence_search(arr,len,2);
	sequence_search(arr,len,3);
	sequence_search(arr,len,4);
	sequence_search(arr,len,5);
	sequence_search(arr,len,6);
	sequence_search(arr,len,7);
	sequence_search(arr,len,8);
	sequence_search(arr1,len1,1);
	sequence_search(arr1,len1,2);
	sequence_search(arr1,len1,3);
	sequence_search(arr1,len1,4);
	sequence_search(arr1,len1,5);
	sequence_search(arr1,len1,6);
	sequence_search(arr1,len1,7);
	sequence_search(arr1,len1,8);
	return true;
}