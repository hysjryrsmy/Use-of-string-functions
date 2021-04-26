#define _CRT_SECURE_NO_WARING
#include <stdio.h>

#include <string.h>
//#include <assert.h>

//NULL - 空指针
//NUL/Null - '\0' 


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




// 1. strncpy: char* strncpy(char* strDest, const char* strSource,size_t count);
//strcpy: char* strcpy(char* strDestination, const char* strSource);
//拷贝num个字符从源字符串到目标空间
//如果源字符串的长度小于num，则拷贝完源字符串之后，在目标的后边追加0，直到num个

//int main()
//{
//	char arr1[10] = "abcdef";
//	char arr2[] = "hello bit";
//	strncpy(arr1, arr2, 6);
//	return 0;
//}

//char* _cdecl strncpy(char* dest, const char* source, size_t count)
//{
//	char* start = dest;
//	while (count && (*dest++ = *source++))  //copy string
//		count--;
//	if (count)                              //pad out with zeroes
//		while (--count)
//			*dest++ = '\0';
//	return (start);
//}



// 2. strncat：char* strncat(char* strDest, const char* strSource, size_t count);

//int main()
//{
//	char arr1[30] = "hello";//字符串追加，主动放'\0'
//	char arr2[] = "world";
//	strncat(arr1, arr2, 3); //如果是8超过字符串长度，依然追加world\0
//	printf("%s\n", arr1);
//
//	return 0;
//}

//char* _cdecl strncat(char* front, const char* back, size_t count)
//{
//	char* start = front;
//	while (*front++)
//		;
//	front--;
//	while (count--)
//		if (!(*front++ = *back++))
//			return (start);
//
//	*front = '\0';
//	return (start);
//}



// 3. strncmp : int strncmp (const char* str1, const char* str2, size_t count);
/*
int main()
{
	// strncmp - 字符串比较
	const char* p1 = "abcdef"; //加上const说明p1指向的内容不能被修改，一旦修改就报语法错误，这样更加科学
	char* p2 = "abcqwer";
	//int ret = strcmy(p1, p2); //返回值-1小于0
	int ret = strncmy(p1, p2, 3);//相等，返回值为0
	printf("%d\n", ret);

	return 0;
}
*/



// 4. strstr : char* strstr (const char*string, const char*strCharSet); - 查找字符串
//string : '\0'结束的字符串（被查找的）
//strCharSet ： 以'\0'结束的要查找的字符串
/*
int main()
{
	char* p1 = "abcdefghi"; //defghi
	char* p1 = "abcdefabcdef"; //defabcdef
	char* p2 = "def";
	char* ret = strstr(p1, p2);//p1字符串中p2这个字符串第一次出现的位置
	if (ret == NULL)
	{
		printf("子串不存在\n");
	}
	else
		printf("%s\n", ret);
	return 0;
}
*/

//实现strstr
//kmp算法
/*
char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
	char* s1 = p1;
	char* s2 = p2;
	char* cur = (char*)p1;// cur是用来记录有可能成功的位置
	if (*p2 == '\0')
	{
		return p1;
	}
	//
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)p2;
		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cur; //找到子串
		}
		if (*s1 == '\0') 
		cur++;
	}
	return NULL; //找不到子串
}

int main()
{
	char* p1 = "abbbcdef"; 
	//char* p2 = ""; //p2指的是空字符串，没有字符，第一个指的字符是'\0'
	char* p2 = "bbc";

	char* ret = my_strstr(p1, p2);
	if (ret == NULL)
	{
		printf("子串不存在\n");
	}
	else
		printf("%s\n", ret);
	return 0;
}
*/

//库里面的方式
//char* _cdecl strstr(const char* str1, const char* str2)
//{
//	char* cp = (char*)str1;
//	char* s1, * s2;
//
//	if (!*str2)
//		return ((char*)str1);
//
//	while (*cp) 
//	{
//		s1 = cp;
//		s2 = (char*)str2;
//
//		while (*s1 && s2 && !(*s1 - *s2))	
//			s1++, s2++;
//		if (!*s2)
//			return (cp);
//
//		cp++;		
//	}
//	return(NULL);
//}




// 5. strtok : char* strtok (char* str, const char* sep);
//sep参数是个字符串，定义了用作分隔符的字符集合
//第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记
//strtok函数找到str中的下一个标记，并将其用\0结尾，返回一个指向这个标记的指针。
//（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并    且可修改
// strtok函数的第一个参数不为NULL，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置
// strtok函数的第一个参数为NULL，函数将在同一个字符串中被保存的位置开始，查找下一个标记。
// 如果字符串中不存在更多的标记，则返回NULL指针。

/*
int main()
{
	//char arr[] = "zpw@bitedu.tech";
	//char* p = "@.";
	
	//点分十进制的表现方式
	char arr[] = "192.168.31.121";
	char* p = ".";

	//zpw\0bitedu.tech
	char buf[1024] = { 0 };
	strcpy(buf, arr);
	//切割buf中的字符串

	char* ret = NULL;  

	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
	{
		printf("%s\n", ret);
	}

	//char* ret = strtok(arr, p);
	//printf("%s\n", ret);

	//ret = strtok(NULL, p);
	//printf("%s\n", ret);

	//ret = strtok(NULL, p);
	//printf("%s\n", ret);

	return 0;
}
*/





//6. strerror ： char* strerror(int errnum);
// 返回错误码：所对应的错误信息
//
#include <errno.h> //必须包含的头文件	
int mian()
{
	//错误码   错误信息
	//0-      No error
	//1-      Operation not permitted
	//2-      No such file or directory
	//...
	//errno是一个全局的错误变量
	//当C语言的库函数在执行过程中，发生了错误，就会把对应的错误码，赋值到errno中 

	//char* str = strerror(errno);
	//printf("%s\n", str);


	//打开文件
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		printf("open file seccess\n");
	}

	return 0;
}




