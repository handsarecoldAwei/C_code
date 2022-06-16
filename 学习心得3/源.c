/*

   这局讲一下

   变量：顾名思义，可以变化的量
   常量：不变化的量

   你写一个数字在纸上，要占纸的面积吧；那怎么创建一个变量呢？

*/

#include<stdio.h>
 
#define MAX 1000 // #define预处理指令  MAX定义的名字  1000数值

enum Week
{

	Monday = 1,//初始化命名
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday,
   
	//enum就相当于一个等差数列，如果不初始化命名，则Monday = 0; Tuesday = 1以此类推
};

int main()
{
	int number = 100; //将100这个值放在int（整数类型）number（变量名）中
	char word = "Hello";//将Hello这个字符串放在char（字符型）word（变量名）中
	double fraction = 88.6;

	  //为什么说number word fraction 是变量名呢？

	number = number - 5;
	printf("%d\n", number);

	//打印int类型用%d； char（字符串%s）（字符%c）；double（%lf）；float（%f）等等
	// 
//--------------------------------------------------------------

	int a = 50;
	char w = "haha";
	double f = 1.1;

	//有的人这样创建一个变量，其实这是不规范的；你可以试想，一个项目几千几万行代码，你这int a 是啥啊？一个词咋说来着？ 见文知意！

	//下划线命名法    植物大战僵尸中的阳光  sun_flower 两个单词直接加一个下划线

	//驼峰命名法      sunFlower 第二个单词首字母大写

//------------------------------------------------------------------

//讲一下常量  第一种字面常量

	char laugh = "haha";//字符串常量

	char number_1 = 65; //字符常量

	printf("%c\n", number_1);   //打印出来是A（ASCII）；我们都知道计算机语言是二进制语言，那怎样打出键盘的字母和符号的的呢？ASCII就相应而生

// 第二中  const（英文意思常量 - 关键字）修饰的常量

	const int number_one = 50; //  表示常变量，不可以在进行变化，但它本质是变量；就像中国人美国国籍
	//number_one = number_one - 50;

//  第三种  define（英文意思定义）定义的标识符常量  

	int number_two = MAX;
	printf("%d\n", number_two);//打印结果1000

//  第四种 枚举常量（生活中有很多可以一一列举的常量如星期几）

	enum Week number_zero = Thursday;
	printf("%d\n", number_zero);

//----------------------------------------------------------

	//数学中的加减乘除在C中咋写？   求两个整数和
	int math_number = 0;
	int Math_number = 0;
	scanf_s("%d %d", &math_number, &Math_number);//scanf_s是VS编译器提供的（不是C规定的），单纯scanf会出现错误，为了在其他编译器跑过去，建议使用scanf
	int add = math_number + Math_number;//其他 + - * / %（取余) 其实是一样的
	printf("%d\n", add);


	int days = 8 / 3;

	printf("%d|n", days);//结果2
	

	return 0;
}

