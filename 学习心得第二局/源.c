//先来写个代码

/*#include<stdio.h>
int main()
{
	printf("c:\test\test.c");
	return 0;
}
//你这样打印会是啥？为啥啊？因为printf（"这里面有转义字符"）；转义字符？就是转变了原来的意思


*/
#include<stdio.h>
int main()
{
	printf("are you ok??)\n");//    ？？）当者三个符号出现在打印括号里会打印为 are you ok]    所以为防止打印成这我们可以 are you ok\?\?) 就会得到想要的打印结果are you ok？？）
	//printf("%s", """); 想打印这个是不行的，前两个""会连结，留下第三个"这是什么玩意？
	printf("%s\n", "\"");
	printf("%c\n", '\'');
	printf("c:\\test\\test.c\n");
	printf("\a");//   \a（蜂鸣）转义字符，会响一下
	printf("11111");
	printf("22222");//     \n是换行符，不加\n的后果   上一行代码和这一行打印会在一起
	printf("\n");
	printf("%d\n", '\130'); //将8（0-7共八个数）进制转化为10进制的数（0-9）
	printf("%d\n", '\x40'); //将16（0-9，a,b,c,d,e）进制转化为10进制的数   a为10，b为11，以此类推 ； 16进制（0-15）
	return 0;
}








/*  
——————————————————————————————————————————————————————————————————————————————————————————
 

 C为了解决生活中的问题，必须有能力描述出来吧.数学中数字分为整数，分数（等）；C把他们成为基本数据类型


  基本数据类型包括整数类型（相当于数学中的整数，不同的是C中每个类型是一个集合）和浮点类型（数学中小数）


   整数类型	                                            浮点类型
   char	                 字符型                           float           单精度浮点型
   unsigned char	     无符号字符型                     double           双精度浮点型
   signed char	         有符号字符型                           
   int	                 整形                            单精度和双精度，双精度更准确（相当于我喜欢人和我喜欢女人的区别）
   unsigned int	         无符号整形                  
   short	             短整型                          插一嘴，double用的相对比较多
   unsigned short	     无符号短整型
   long	                 长整型
   unsigned long	     无符号长整型

   有符号无符号因为它们每个类型的都是一个集合（有正有负），所以无符号XX型代表没有负数（相当于数学上的正整数）

   插一嘴，int,char用的比较多

   为什么出现这么多类型呢？一句话杀鸡用啥牛刀？我要存放一个小一点的数，就用short；大一点就用long；提高利用率

   前面也说了，你可以把他们当成数学上的集合，集合写在纸上占空间吧，相对应这整数类型和浮点类型占多少空间呢？

   在C中，有个计算类型或者变量所占空间大小的一个东西：sizeof（关键字——操作符）单位是字节

   字节？计算机最小单位是比特位（bit）；一字节（byte） = 8bit ；1KB = 1024byte ； 1MB = 1024KB ; 1GB = 1024MB ; 1TB = 1024GB等等

*/


//#include<stdio.h>
//int main()
//{
//	printf("%d\n", sizeof(char));//1
//	printf("%d\n", sizeof(unsigned char));//1
//	printf("%d\n", sizeof(signed char));//1
//	printf("%d\n", sizeof(int));//4
//	printf("%d\n", sizeof(unsigned int));//4
//	printf("%d\n", sizeof(short));//2
//	printf("%d\n", sizeof(unsigned short));//2
//	printf("%d\n", sizeof(long));//4   C语言规定：只要sizeof(long) >= sizeof(int) = 4 就为长整型，所以在这计算的sizeof(long)结果为4 
//	printf("%d\n", sizeof(unsigned long));//4
//	printf("%d\n", sizeof(float));//4
//	printf("%d\n", sizeof(double));//8
//	return 0;
//
//}



