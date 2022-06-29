#define _CRT_SECURE_NO_WARNINGS

////求一下最大公约数(辗转相除法)  24  18举例 ： 最大公约数不会大于18
//#include<stdio.h>
//int main()
//{
//	int number_1 = 0;
//	int number_2 = 0;
//	scanf("%d%d", &number_1, &number_2);
//	int middle = 0;
//	while (middle = number_1 % number_2)
//	{
//		number_1 = number_2;
//		number_2 = middle;
//	}
//	printf("最大公约数为：%d", number_2);
//	return 0;
//}

////求100-200直接的素数（除了 1 和它本身以外，不能被任何整数整除的数）
//#include<stdio.h>
//#include<math.h>//sqrt开平方函数头文件
//int main()
//{
//	int number = 0;
//	int count = 0;
//	//for (number = 100; number <= 200; number++) {
//	for (number = 101; number <= 200; number += 2) {//优化  偶数肯定不是素数
//		int number_1 = 0;
//		int flag = 1;
//		//for (number_1 = 2; number_1 < number; number_1++) {
//		for (number_1 = 2; number_1 <= sqrt(number); number_1++) {
//			//  2 -> number-1是否有可以被整除
//			if (number % number_1 == 0) {
//				flag = 0;
//				break;
//			}
//		}
//		//if (number == number_1) {   // 第一种写法
//		if (flag == 1) {//第二种写法
//			printf("%d  ", number);//素数
//			count++;
//		}
//	}
//	printf("素数个数：%d\n", count);
//	return 0;
//}

// goto语句的使用   模拟实现一分钟自动关机程序
//#include<stdio.h>
//#include<stdlib.h>//system头文件
//#include<string.h>//strcmp头文件
//int main()
//{
	//char input[20] = { 0 };
	//system("shutdown -s -t 60");//system执行系统命令   shutdown关闭  -s(site)设置   -t（time）时间  60(60秒)
//again :
	//printf("您的电脑将60秒后被怪兽强制关机，请问你此时，是否相信光？\n");
	//scanf("%s", input);
	//if (strcmp(input, "我相信光") == 0) {  // strcmp比较两个字符串是否相等
	//	system("shutdown -a");// shutdown -a取消
	//}
//	else {
//		goto again;
//	}
//	return 0;
//}
//goto语句真正适用与多种嵌套循环，break只能结束当前循环；goto语句解决的问题，循环也可以解决
//#include<stdio.h>
//#include<stdlib.h>//system头文件
//#include<string.h>//strcmp头文件
//int main() {
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");//system执行系统命令   shutdown关闭  -s(site)设置   -t（time）时间  60(60秒)
//	while (1) {
//		printf("您的电脑将60秒后被怪兽强制关机，请问你此时，是否相信光？\n");
//		scanf("%s", input);
//		if (strcmp(input, "我相信光") == 0) {  // strcmp比较两个字符串是否相等
//			system("shutdown -a");// shutdown -a取消
//			break;
//		}
//	}
//	return 0;
//}
//goto语句只能在函数内部使用，不能跨函数


/*
   下面就讲一下函数

   函数分为：1.库函数（C语言自己带的函数）  2.自定义函数
*/
//#include<stdio.h>
//#include<string.h>//库函数  strcpy头文件
//int main() {
//	char number[20] = { 0 };
//	char number_1[] = "1314521";
//	strcpy(number, number_1);//strcpy字符串拷贝
//	printf("%s\n", number);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>//memset头文件
//int main()
//{
//	char greeting[] = "Hello World";
//	memset(greeting, 'O', 6);//memset内存设置函数
//	printf("%s\n", greeting);
//	return 0;
//}

//自定义函数
//传值：
//#include<stdio.h>
//void Swap(int num1,int num2) {//形参（函数调用完就会销毁）
//	int swap = 0;
//	swap = num1;
//	num1 = num2;
//	num2 = swap;
//}
//int main() {
//	int number_1 = 100;
//	int number_2 = 200;
//	printf("交换前: number_1=%d number_2=%d\n", number_1,number_2);
//	Swap(number_1, number_2);//实参（实际参数）
//	printf("交换后: number_1=%d number_2=%d\n",number_1,number_2);
//	return 0;
//}
//打印结果并没有达到预期效果  我调用Swap函数又重新创建了空间，并没有在原来的地址改变  改变形参并不能改变实参
// 形参只是实参的一份临时拷贝
//传址：
//#include<stdio.h>
//void Swap(int* num1, int* num2) {
//	int swap = 0;
//	swap = *num1;
//	*num1 = *num2;
//	*num2 = swap;
//}
//int main()
//{
//	int number_1 = 100;
//	int number_2 = 200;
//	printf("交换前: number_1=%d number_2=%d\n", number_1, number_2);
//	Swap(&number_1, &number_2);
//	printf("交换后: number_1=%d number_2=%d\n", number_1, number_2);
//	return 0;
//}
//打印结果达到了预期效果   

//函数的嵌套调用（就是一环套一环套娃似的）
//#include<stdio.h>
//void TEST() {
//	printf("哈哈\n");
//}
//void test() {
//	TEST();
//}
//int main()
//{
//	test();
//	return 0;
//}

//函数的链式访问（一个函数作为另一个函数的参数）
//#include<stdio.h>
//#include<string.h>
//int main() {
//	printf("%d\n", strlen("abc"));
//	printf("%d", printf("%d", printf("%d", 1314)));//  printf函数返回的是打印在屏幕字符的个数
//	return 0;
//}

//函数递归（自己调用自己）
//一个整型值（无符号）按顺序打印;  举例：1234   打印： 1 2 3 4 
//#include<stdio.h>
//void Print(int number) {
//	if (number > 9) {//存在限制条件，当不满足时就不会继续递归
//		Print(number / 10);
//	}
//	printf("%d ", number % 10);
//	//越来越接近限制条件
//}
//int main() {
//	int number = 0;
//	scanf("%d", &number);
//	Print(number);
//	return 0;
//}
//每次递归都会开创空间，当递归很深时，很容易栈溢出（就相当于每次干活都增加一些难度，总有一次会因为太难而完不成）

//写一个函数不能创建临时变量,求字符串的长度（先模拟实现一下strlen）
//#include<stdio.h>
//int MY_strlen(char* group) {
//	/*int count = 0;
//	while (*group != '\0') {
//		group++;
//		count++;
//	}
//	return count;*/
//	if (*group != '\0') {
//		return 1 + MY_strlen(group +1);
//	}
//	else {
//		return 0;
//	}
//}
//int main()
//{
//	char group[] = "abcdefg";
//	printf("%d\n", MY_strlen(group));//数组传的是数组首元素地址
//}

//求n的阶乘
//#include<stdio.h>
//int Multiplication(int number) {
//	if (number < 2) {
//		return 1;
//	}
//	else {
//		return Multiplication(number - 1) * number;
//	}
//}
//int main()
//{
//	int number = 0;
//	scanf("%d", &number);
//	printf("%d\n", Multiplication(number));
//	return 0;
//}
//求第n个斐波那契数也就很简单了
//#include<stdio.h>
//int count = 0;
//int Number(int number) {
//	if (number == 3) {//number等于3看出现了多少次
//		count++;
//	}
//	if (number <= 2) {
//		return 1;
//	}
//	else {
//		return Number(number - 1) + Number(number - 2);
//	}
//}
//
//int main()
//{
//	int number = 0;
//	scanf("%d", &number);
//	printf("%d\n", Number(number));
//	printf("count = %d\n", count);//number = 21;count就4181次，效率太低了,重复大量计算
//	return 0;
//}
//循环方式求第n个斐波那契数
//#include<stdio.h>
//int Number(int number) {
//	int number_1 = 1;
//	int number_2 = 1;
//	int number_3 = 1;
//	while (number > 2) {
//		number_3 = number_1 + number_2;
//		number_1 = number_2;
//		number_2 = number_3;
//		number--;
//	}
//	return number_3;
//}
//int main() {
//	int number = 0;
//	scanf("%d", &number);
//	printf("%d\n", Number(number));
//	return 0;
//}

 //零碎的光：数组
//一维，二维数组的存放
//#include<stdio.h>
//int main() {
//	//int number[10] = { 0 };
//	//int frequency = 0;
//	//for (frequency = 0; frequency < 10; frequency++) {
//	//	printf("number[%d]地址=%p\n", frequency, &number[frequency]);
//	//}
//	//int number[2][3] = { 0,2,3,4 };//不完全初始化 后面补0（\0）
//	int Number[2][3] = { {4,5},{1,2,3} };//也可以这样定义二维数组
//	int frequency = 0;
//	int Frequency = 0;
//	for (frequency = 0; frequency < 2; frequency++) {
//		for (Frequency = 0; Frequency < 3; Frequency++) {
//			printf("Number[%d][%d]地址为%p\n", frequency, Frequency, &Number[frequency][Frequency]);
//		}
//	}
//	return 0;
//}

/*
   数组名就是数组首元素地址
   但有两个例外（是整个数组地址）   1.sizeof(数组名)    2.&数组名
*/
//#include<stdio.h>
//int main() {
//	int group[10] = { 0 };
//	printf("%d\n", sizeof(group));//  4*10=40
//	printf("%p\n", &group);
//	printf("%p\n", group);
//	printf("%p\n", &group + 1);
//	printf("%p\n", group + 1);
//	return 0;
//}

//将0123456789升序（冒泡排序）
#include<stdio.h>
void Swap(int group[], int size) {
	int frequency = 0;
	for (frequency = 0; frequency < size - 1; frequency++) {
		int Frequency = 0;
		for (Frequency = 0; Frequency < size - 1 - frequency; Frequency++) {
			if (group[Frequency] > group[Frequency + 1]) {
				int swap = group[Frequency];
				group[Frequency] = group[Frequency + 1];
				group[Frequency + 1] = swap;
			}
		}
	}
}
int main()
{    
	int group[] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(group) / sizeof(group[0]);
	Swap(group, size);
	int i = 0;
	for (i = 0; i < 10; i++) {
		printf("%d ", group[i]);
	}
	return 0;
}