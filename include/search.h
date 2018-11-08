#ifndef _SEARCH_H__
#define _SEARCH_H__
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
bool test_search(void);
void sequence_search(int arr[],uint32_t len,uint32_t key);
void binary_search(int arr[],uint32_t len,uint32_t key);

#endif