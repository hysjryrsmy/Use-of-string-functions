#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>

#include <string.h>
#include <assert.h>


//字符函数和字符串函数

//求字符串长度
//strlen

//长度不受限制的字符串函数
// strcpy : 字符串拷贝
// strcat ：字符串追加
// strcmp ：字符串比较

//长度受限制的字符串函数介绍
// strncpy
// strncat
// strncmp
 
// 字符串查找
//strstr
//strtok

//错误信息报告
//strerror

//字符操作
//

//内存操作函数
//memcpy
//memmove
//memset
//memcmp



//①.计数器的方法
//②.递归
//③.指针 - 指针



//1.strlen:求字符串长度  size_t strlen(const char* str);
//字符串以'\0'作为结束标志，strlen函数返回的是在字符串中'\0'前面出现的字符个数（不包含'\0')
//参数指向的字符串必须要以'\0'结束
//注意函数的返回值为size_t，是无符号的（易错）
//学会strlen函数的模拟实现
//递归：不创建临时变量求字符串长度

/*
#include <string.h>
#include <assert.h>

//size_t == unsigned int 不会返回负数
int my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);
	while (*str != '\0') // = while(*str)
	{
		count++;
		str++;
	}
	return count;
}

int main()
{
	//int len = my_strlen("abcdef"); //\0停止

	//错误示范
	//char arr[] = { 'a','b','c','d','e','f' };//随机值
	//int len = strlen(arr);

	//printf("%d\n", len);

	if (strlen("abc") - strlen("abcdef") > 0)
	{
		printf("hehe\n");
	}
		
	else
		printf("haha\n");
	return 0;
}
*/




//2.strcpy: char strcpy(char* destination,const char* source);

// 源字符串必须以'\0'结束
//会将源字符串中的'\0'拷贝到目标空间
//目标空间必须足够大，以确保能存放源字符串
//目标空间必须可变
//学会模拟实现

/*
char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	
	//while (*src != '\0')
	//{
	//	*dest = *src;
	//	dest++;
	//	src++;
	//}
	//*dest = *src;//'\0'

	//精简
	char* ret = dest;
	//拷贝src指向的字符串到dest指向的空间，包含'\0'	
	while (*dest++ = *src++)
	{
		;
	}
	//返回目的空间的起始地址
	return ret;
}

int main()
{
	char arr1[] = "abcdefghi";
	char arr2[] = "bit";
	
	//错误的示范
	//char* arr3 = "abcdefghi";
	//char arr3[] = {'b','i','t'}; //err

	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);

	return 0;
}
*/



//3. strcat: char* strcat(char* destination, const char* source);
//源字符串必须以'\0'结束
//目标空间必须有足够的大，能容纳下源字符串的内容
//目标空间必须可修改
//字符串自己给自己追加

/*
my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	//1.找到目的字符串的'\0'
	while (*dest != '\0')
	{
		dest++;
	}
	//2.追加
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	//char arr1[] = "hello";//写法错误：越界访问； 目的地的空间必须足够大，源头里面必须有\0

	char arr1[30] = "hello";
	char arr2[] = "world";
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}
*/




//4.strcmy : int strcmp (const char* str1, const char* str2);
//标准规定：
//第一个字符串大于第二个字符串，则返回大于0的数字
//第一个字符串等于第二个字符串，则返回0
//第一个字符串小于第二个字符串，则返回小于0的数字
//
//

/*
int main()
{
	//vs编译器下
	//大于的时候，返回1
	//等于的时候，返回0
	//小于的时候，返回-1

	char* p1 = "abcdef";//字符比较：首先是a和s比较，相等的话继续比较
	char* p2 = "sqwer";
	//int ret = strcmp(p1, p2);
	if (strcmp(p1, p2) > 0)
	{
		printf("p1 > p2\n");
	}
	else if (strcmp(p1, p2) == 0)
	{
		printf("p1 == p2\n");
	}
	else if (strcmp(p1, p2) < 0)
	{
		printf("p1<p2\n");
	}
	//printf("%d\n", ret);
	return 0;
}
*/

my_strcmp(char* str1, const char* str2)
{
	assert(str1 && str2);
	//比较
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;//相等
		}
		str1++;
		str2++;
	}
	//if (*str1 > *str2)
	//	return 1;//大于
	//else
	//	return -1;//小于
	//另一种表现形式
	return (*str1 - *str2);
}
int main()
{
	char* p1 = "abcdef";
	char* p2 = "abqwe";
	int ret = my_strcmp(p1, p2);
	printf("ret = %d\n", ret);
	return 0;
}