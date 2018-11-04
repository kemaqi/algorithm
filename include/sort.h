#ifndef _SORT_H__
#define _SORT_H__
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
bool test_sort(void);
void select_sort(int arr[],uint32_t len);
void bubble_sort(int arr[],uint32_t len);
void quick_sort(int arr[],uint32_t len);

#endif