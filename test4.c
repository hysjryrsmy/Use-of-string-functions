#define _CRT_SECURE_NO_WARING
#include <stdio.h>
#include <string.h>
#include <assert.h>

//strcpy; strcat; strcmp; strmcpy; strncat; strncmp  操作对象是：字符串，\0
//不能用到整形数组；浮点型数组；结构体数组
//void*  -  通用类型的指针-无类型指针


//内存操作函数
//memcpy: 不介意任何数据的复制;  只要处理 不重叠的内存拷贝就可以
//memmove : 处理内存重置的情况
//memset ： 内存设置
//memcmp ： 内存比较



//1. memcpy 内存拷贝 : void* memcpy(void* destination, const void* source,size_t num);
//函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置
//这个函数在遇到'\0'的时候并不会停下来
//如果source和destination有任何的重叠，复制的结果都是未定义的

//struct S
//{
//	char name[20];
//	int age;
//};
//
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return ret;
//}
//
///*
//int main()
//{
//	//int arr1[] = { 1,2,3,4,5 };
//	//int arr2[5] = { 0 };
//	//memcpy(arr2, arr1, sizeof(arr1));
//	//my_memcpy(arr2, arr1, sizeof(arr1));
//
//	//struct S arr3[] = { {"张三", 20},{"李四",30} };
//	//struct S arr4[3] = { 0 };
//	//my_memcpy(arr4, arr3, sizeof(arr3));
//	return 0;
//}
//*/
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	//变成：121234589
//	//my_memcpy(arr + 2, arr, 20); //不能达到目的
//	 
//	//memmove(arr + 2, arr, 20);
//	memcpy(arr + 2, arr, 20);
//
//	for ( i = 0; i < 10; i++)
//	{
//		printf("%d  ", arr[i]);
//	}
//
//	return 0;
//}



//2. memmove 内存移动 : void*memmove(void* destination, const void* source, size_t num);
// 和memcpy的差别就是memmove函数处理的源内存块和目标内存块是可以重叠的
// 如果源空间和目标空间出现重叠，就得使用memmove函数处理
/*
void* my_memmove(void* dest, void* src, size_t num)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	int count = 0;

	//if (dest < src)
	//{
	//	//从前向后拷贝
	//	while(count--)
	//	{
	//		*(char*)dest = *(char*)src;
	//		++(char*)dest;
	//		++(char*)src;
	//	}
	//}
	//else
	//{
	//	//从后向前拷贝
	//	while (count--)
	//	{
	//		*((char*)dest + count) = *((char*)src + count);
	//	}
	//}
	//return ret;

//另一种方法
	if (dest < src || dest>(char*)src + count)
	{
		//从前向后拷贝
	}
	else
	{
		//从后向前拷贝
	}


}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;

	//my_memmove(arr + 2, arr, 20);
	//my_memmove(arr, arr+2, 20);

	for (i = 0; i < 10; i++)
	{
		printf("%d  ", arr[i]);
	}

	return 0;
}
*/




//memcmp 内存比较：int memcmp (const void* ptr1, const void* ptr2, size_t num);
// 比较从ptr1和ptr2指针开始的num个字节
//size_t num : 指的是比较的字节的个数

int main()
{
	//01 00 00 00 02 00 00 00 03 00 00 00...
	//01 00 00 00 02 00 00 00 05 00 00 00...
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,5,4,3 };
	int ret = memcmp(arr1, arr2, 8);
	printf("%d\n", ret);

	return 0;
}



//
int main()
{
	//char arr[10] = "";
	//memset(arr, '#', 10);

	int arr[10] = { 0 };
	//40个字节
	//01 01 01 01 01 01 01 01 01 01 00 00 00 00 00...
	memset(arr, 1, 10);
	return 0;
}