#define _CRT_SECURE_NO_WARING
#include <stdio.h>
#include <string.h>


//字符分类函数
//iscntrl   任何控制字符
//isspace   空白字符：空格''，换页'\f'，换行'\n', 回车'\r' , 制表符'\t'或者垂直制表符'\v'
//isdigit   十进制数字0-9
//isxdigit  十六进制数字，包括所有十进制数字，小写字母a~f，大写字母A~F
//islower   小写字母a~z
//isupper   大写字母A~Z
//isalpha   字母a~z或A~Z
//isalnum   字母或者数字，a~z，A~Z，0~9
//ispunct   标点符号，任何不属于数字或者字母的图形字符（可打印）
//isgraph   任何图形字符
//isprint   任何可打印字符，包括图形字符和空白字符

#include <ctype.h>
//int main()
//{
//	//char ch = 'w';
//	//int ret = islower(ch);
//	//printf("%d\n", ret);
//
//	char ch = '2';
//	int ret = isdigit(ch);
//	printf("%d\n", ret);
//
//	return 0;
//}



//字符转换
//int tolower(int c); 大写转小写
//int toupper(int c); 小写转大写

//int main()
//{
//	//char ch = tolower('Q');
//	//char ch = toupper('q');
//	//putchar(ch);
//
//	char arr[] = "I Am A Student";
//	int i = 0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);
//		}
//		i++;
//	}
//	printf("%s\n", arr);
//	return 0;
//}
//也可以不判断，直接转换，因为tolower不会动小写的
int main()
{
	char arr[] = "I Am A Student";
	int i = 0;
	while (arr[i])
	{
		arr[i] = tolower(arr[i]);
		i++;
	}
	printf("%s\n", arr);
	return 0;
}