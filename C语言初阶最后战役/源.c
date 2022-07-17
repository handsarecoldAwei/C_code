#define _CRT_SECURE_NO_WARNINGS

//细节讲一下操作符
//1.算术操作符
//#include<stdio.h>
//int main() {
//	//float number = 6 / 5;//  结果是1；系统自动认为整数相除
//	//float number = 6.0 / 5.0;//  结果正确 但从“double”到“float”截断;C语言中，如果不指定数据类型，那么小数默认为是double类型
//	float number = 6.0f / 5.0f;
//	printf("%f\n", number);
//	return 0;
//}


//2.移位操作符（右移操作符有两种说法；第一种算术右移，右边丢弃，左边补符号位；第二种逻辑右移，右边丢弃，左边补零）
//#include<stdio.h>
//int main() {
//	int number1 = -1;
//	int number2 = number1 >> 1;//负数是以补码的形式存在的；算术右移结果是-1；逻辑右移则会是一个很大的数
//	printf("%d\n", number2);//本编译器是算术右移逻辑来处理的
//	return 0;
//}
//这移位操作符有什么用呢？ ---不要创建第三个变量 实现 3 和 5的交换
//#include<stdio.h>//第一种方法
//int main() {
//	int number1 = 3;
//	int number2 = 5;
//	printf("number1 = %d number2 = %d\n", number1, number2);
//	 number1 = number1 + number2;
//	 number2 = number1 - number2;
//	 number1 = number1 - number2;
//	printf("number1 = %d number2 = %d\n", number1, number2);
//	return 0;
//}
//这样如果超过 int 类型所在范围，就会导致交换错误

//#include<stdio.h>
//int main() {
//	int number1 = 3;
//	int number2 = 5;
//	printf("number1 = %d number2 = %d\n", number1, number2);
//	 number1 = number1 ^ number2;//   a ^ a = 0; 0 ^ 5 = 5;
//	 number2 = number1 ^ number2;
//	 number1 = number1 ^ number2;
//	printf("number1 = %d number2 = %d\n", number1, number2);
//	return 0;
//}

//判断一个数字的二进制有多少个1
// 第一种写法
//#include<stdio.h>
//int main() {
//	int number = 0;
//	scanf("%d", &number);
//	int frequency = 0;
//	int count = 0;
//	for (frequency = 0; frequency < 32; frequency++) {
//		if ((number >> frequency) & 1 == 1) {
//			count++;
//		}
//	}
//	printf("%d二进制中1的个数 = %d\n", number, count);
//	return 0;
//}
//第二种写法

//int Number(unsigned int number) {//第一种写法
//    int count = 0;
//    
//   while (number) {
//        if (number % 2 == 1) {
//            count++;
//        }
//        number /= 2;
//    }
//
//    
//    return count;
//}
//#include<stdio.h>
//int Number(int number){
//    int count = 0;
//    while (number) {
//        number = number & (number - 1);
//        count++;
//    }
//    /*
//        5  00000101     4  00000100   00000100  
//        4  00000100     3  00000011   00000000
//    */
//    return count;
//}
//int main() {
//    int number = 5;
//    
//    int amount = Number(number);
//    
//    printf("%d\n", amount);
//}
//打印整形二进制的奇数位和偶数位
//#include<stdio.h>
//int main() {
//    int number = 0;
//    scanf("%d", &number);
//    int frequency = 0;
//    //打印偶数位
//    for (frequency = 31; frequency >= 1; frequency -= 2) {
//        printf("%d ", (number >> frequency) & 1);
//    }
//    printf("\n");
//    //打印奇数位
//    for (frequency = 30; frequency >= 0; frequency -= 2) {
//        printf("%d ", (number >> frequency) & 1);
//    }
//    return 0;
//}

//3.赋值操作符
//#include<stdio.h>
//int main() {
//	int number1 = 100;
//	int number2 = 200;
//	int number3 = 300;
//	number1 = number2 = number3 + 100;//是可以这样连续赋值的，但给人的感觉---很差！！！
//	printf("%d  %d  %d\n", number1, number2, number3);

//	return 0;
//}

// 4. sizeof单目操作符
//#include<stdio.h>
//int main() {
//	int arr[10] = { 0 };//   []下标引用操作符（双目操作符）  一个操作数arr  一个是10
//	printf("1-->%d\n", sizeof(arr));
//	printf("2-->%d\n", sizeof(int[10]));//40   
//	short number1 = 10;
//	int number2 = 100;
//	//  sizeof()内部是不参与运算的
//	printf("3-->%d\n", sizeof(number1 = number2 + 100));
//	printf("4-->%d\n", number1);
//	printf("%d\n", sizeof(&number1));//地址大小取决于32或64操作系统   4 / 8
//	return 0;
//}

// 5.  一个 = 为赋值；二个 == 为判断是否相等；两个字符串不能用 ==

//6.  &&逻辑与    小细节
//#include<stdio.h>
//int main()
//{
//	int number1 = 0, number2 = 0, number3 = 10,number4 = 20;
//	number1 = number2++ && number3++ && ++number4;//一个条件为假剩下的不用算了
//	printf("%d\n%d\n%d\n", number2, number3,number4);// 1    10    20
//	return 0;
//}


/*
   整型提升：
           表达式的整型运算在CPU中进行的  所以在送往CPU之前，不够整形长度都会发生整型提升   进一步获得了这个精度
*/
//#include<stdio.h>
//int main() {
//    char number1 = 3;
//    // 3的二进制表达： 00000000 00000000 00000000 00000011
//    //  存放到char类型中 发生截断  00000011
//    char number2 = 127;
//    // 127的二进制表达： 00000000 00000000 00000000 01111111
//    //  存放到char类型中 发生截断  01111111
//
//    char number3 = number1 + number2;
//    //  00000000 00000000 00000000 00000011
//    //  00000000 00000000 00000000 01111111
//// 相加：00000000 00000000 00000000 10000010
//    
//    printf("%d\n", number3);
//    //  int类型打印出来
//    //number3截断   10000010   最高位符号位（负补1；正补0）
//    //  11111111 11111111 11111111 10000010(负数以补码形式存在)
//    //  11111111 11111111 11111111 10000001 补码
//    //  00000000 00000000 00000000 011111110原码
//    // -126
//
//    return 0;
//
//}

//证明整型提升的存在
//#include<stdio.h>
//int main() {
//    char number = 1;
//    printf("%u\n", sizeof(number)); //  %u无符号整形
//    printf("%u\n", sizeof(+number)); // 4  发生了整型提升 
//    printf("%u\n", sizeof(-number));
//    printf("%u\n", sizeof(!number));// gcc是4
//    return 0;
//}
//相对应就有算术转换（int 和double ，long等类型的运算）

/*
      操作符属性：
                1.操作符是有优先级的   （）有括号肯定写算括号里面的数
                2.操作符是有结合性的  （） N/A 没有结合性   ；   5 + 3 加号 L -> R 先计算左边再计算右边  ； 强制类型转换，sizeof等  R->L
                3.是否控制求值顺序     if(3 && 巴拉巴拉一堆式子)  其实左边为真，右边就不用计算；三目操作符  真计算表达式2的式子，假就计算表达式3的式子
*/

//  表达式优先级   number1 * number2 + number3 * number4 + number5 * number6 请问先计算乘法然后想加还是计算两个乘法相加再计算另一个乘法呢？？？
//        number + --number 这个都知道先算--再算加号 但问题是用减减之后相加呢？还是相加用之前的值呢？？
//    所以在写代码的时候，不要做猪队友，也不要让系统做选择题

//  朝花夕拾
//#include<stdio.h>
//#include<string.h>
//int main() {
//    char group[] = "Hello World";
//    printf("%d  %d\n", sizeof(group), strlen(group));//  sizeof计算变量空间的大小（包括\0） 打印结果12 ； strlen计算长度\0结束   打印结果11
//    return 0;
//}

// 圆滑一下指针类型的意义
// 1.指针类型决定了：指针解引用的权限有多大
//#include<stdio.h>
//int main() {
//    int number = 0x11223344;
//    //int* point = &number; // 将这个地址改为 00 00 00 00 它访问的是int类型整个地址
//    char* point = &number;  //  将地址改为  00 33 22 11  它访问的是char类型一个字节地址
//    *point = 0;
//    return 0;
//}

//2.指针类型还决定了走一步能走多远
//#include<stdio.h>
//int main() {
//    int group[10] = { 0 };
//    int* point1 = group;
//    char* point2 = group;
//    printf("%p\n", point1);
//    printf("%p\n", point2);
//    printf("%p\n", point1 + 1);//走一步是一个int的长度
//    printf("%p\n", point2 + 1);//走一步是一个char的长度
//    return 0;
//}
//所以在写代码过程中，具体问题具体分析（看你的需求选择指针类型）

// 野指针成因

//1.未初始化     int * point;（在你不确定指向什么位置时，你要指向空指针)（初始化！！！）

//2.越界访问  比如访问数组问题（小心访问越界！！！）
//(尤其是数组，C规定指针可以指向最后一个数组元素尾巴位置，但不能指向数组第一个元素向前的位置)（可以指向尾巴，可以指向头，但不能指向头外面）

//3.指针指向的空间释放，没有指向空指针（释放的空间记得及时指向空指针）
//#include<stdio.h>//错误代码示范
//int* test() {
//    int number_test = 100;//局部变量  出大括号消亡 空间释放
//    return &number_test;//但把地址传过去了
//}
//int main() {
//    int* number = test();
//    *number = 200;
//    return 0;
//}

// 预防空指针呢可以提前检查
//#include<stdio.h>
//int main() {
//    int number = 100;
//    int* point = &number;
//    if (point != NULL) {
//        *point = 200;
//        printf("不是空指针，请放心食用\n");
//    }
//    printf("%d\n", number);
//    return 0;
//}

//下面讲一下指针的运算
//1. 指针 + 整数（取决于指针的类型，访问一步能有多长）

//2. 指针 - 指针（得到的是两个指针之间元素的个数）
//#include<stdio.h>
//int main() {
//    int array[10] = { 0 };
//    printf("%d\n", &array[9] - &array[1]);//打印结果是8
//    return 0;
//}
//计算字符的长度
//#include<stdio.h>
//int my_strlen(char* HowMuch) {
//    char* first = HowMuch;
//    while (*HowMuch != '\0') {
//        HowMuch++;
//    }
//    return HowMuch - first;
//}
//int main() {
//    int length=my_strlen("HelloWorld");
//    printf("%d\n", length);
//    return 0;
//}

//打印数组元素方式
//#include<stdio.h>//理解原理 玩花一点 谢谢
//int main() {
//    int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    int* point = array;//数组名就是首元素地址
//
//    //  array[2] <==> 2 [array] 你要明白 []是双目操作符，两边是操作数
//
//    printf("%d\n", array[2]);
//    printf("%d\n", 2[array]);
//
//    //*(array+2) <==> *(point + 2) <==> point[2] <==>2[point]
//
//    printf("%d\n", *(array + 2));
//    printf("%d\n", point[2]);
//
//    return 0;
//}

//二级指针
//#include<stdio.h>
//int main() {
//    int number = 100;
//    int* point1 = &number;// point1是指针变量 一级指针
//
//    int** point2 = &point1;//  *point2 = point1   point1类型是 int*
//    printf("%d\n", **point2);
//    return 0;
//}

/*     
      整型数组-- - 存放整形int     字符数组----存放char
      .............指针数组也就是存放指针呗
 */

//结构体  一个结构体也可以作为另一个结构体成员
//#include<stdio.h>
//struct student {//结构体类型 相当于int number的 int
//    char name[20];
//    int age;
//}stu1 ={"迪迦奥特曼",18};//stu1全局变量
//int main() {
//    //struct student c这是局部变量
//    printf("%s  %d\n", stu1.name, stu1.age);
//    return 0;
//}

//结构体传参
//#include<stdio.h>
//struct student {
//    char name[20];
//    int age;
//};
//void print1(struct student stu1) {//传值调用 传过来有多大我就创建多大来接受，浪费了空间； 传值太多还需要一点时间，浪费了时间；但改变原参改变不了形参，相对安全一点
//    printf("%s %d\n", stu1.name, stu1.age);
//}
//void print2(struct student* stu1) {
//    printf("%s %d\n", stu1 -> name, stu1 -> age);//传址调用 只用重新创建一个4/8字节（具体看32位还是64位操作系统）来接受地址，效率高，灵活一点
//}
//int main() {
//    struct student stu1 = { "阿伟已经死了", 18 };
//    print1(stu1);
//    print2(&stu1);
//    return 0;
//}
//首选传址调用
/*
   函数传参需要压栈的；函数调用需要在(数据结构上的栈)栈上开辟空间，先进后出，后进先出
   如果直接给函数传值调用，那结构体举例，结构体越大，系统开销就比较大，导致性能下降
   所以首选传址 后考虑传值
*/

/*      调试 完善一下

    1. Debug（调试版本 可以进行调试 所占的空间会比较大一些）和Release（发行版本 无法调试 相对应空间所占小一点）版本

     因为Release版本往往是进行了各种优化，你在Debug中运行的，不一定能在Release运行同样的效果

    2.语法错误 编译器都过不了 ； 其实调试是解决运行时的错误（逻辑错误） 
*/

//3.调试---条件断点  //这个代码运行结果是什么呢？？
//#include<stdio.h>
//int main()
//{
//    int frequency = 0;
//    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//    //先不管式子对错 试想一下如果这循环1万次呢，这样一遍一遍来调试，多low啊，用条件断点开始调试
//    for (frequency = 0; frequency <= 10; frequency++) {
//        array[frequency] = 0;
//        printf("hehe\n");
//    }
//    return 0;
//}
//这个在VS2022版中的运行结果是  越界访问发生错误 其实还有一种情况是 死循环 为什么会这么说呢？
// frequency 和 array是局部变量，都会在栈区开辟空间，栈区内存的使用习惯是 先用高地址再用低地址，而数组会随着下标的增长地址是从低到高变化的，一旦越界访问，访问到frequency被重新赋值为0，开始新一轮的循坏，最终程序奔溃卡死

//良好代码的养成
//模拟实现字符串拷贝函数strcpy
//#include<stdio.h>
//#include<assert.h>//断言所需要的头文件
//char* MyStrcpy(char *array1,const char*array2) {//预防array2被修改可以加const修饰
//    //如果传参给我来了个空指针，我解引用不就出现错误了嘛？
//
//    assert(array2 != NULL);//断言  如果为空指针则给出警告
//    assert(array1 != NULL);
//   char* first = array1;
//    while (*array1++ = *array2++) {//
//        ;//HelloWorld的拷贝
//    }
//    //while (*array2++ = *array1++) {//如果不小心写成了这样的   没有报警高！虽然没有达到预期竟然运行成功了
//    //    ;
//    //}
// 
//  return first;// strcpy返回的是目标首元素地址
//}
//int main()
//{
//    char array1[20] = "#########";
//    char array2[] = "HelloWorld";
//    printf("%s\n", MyStrcpy(array1,array2));//链式访问
//    return 0;
//}
//注释玩成花
//#include<stdio.h>
//int main() {
//    /*你好啊*/int/*没想到吧嘿嘿*/ number/*哈哈哈*/ = 100;//嗯...
//    printf("%d\n", number);
//    return 0;
//}
//解释一下 C语言是没有输入输出函数的 每次用printf还要引用库函数（头文件）

//  const修饰指针
//#include<stdio.h>
//int main() {
//    const int number = 100;
//    int days = 30;
//    //number = 200;  const修饰的变量是不能改的
//    //int* point = &number;
//    //*point = 200;////用找到地址修改方式竟然改了number的值
//    
//    //const int* point = &number;
//    //*point = 200;   //const  修饰*point 被指向的内容是不可以改的 编译器会报错
//   // point = &days; //但是指向可以改变
//
//    int* const point = &number;
//    //point = &number;  //  const 修饰point时，指向不能改变，但内容可以
//    *point = 50;
//
//    printf("%d\n", *point);
//    return;
//}
/*
    简单来说就是 女生是point(指针)，它和男1是眷侣关系，指着男1的钱包说想喝奶茶，
    男1说我没钱，不会给你买的  这就是  const  修饰*point 被指向的内容是不可以改的
    女孩说这点钱都不给我画，我找别的人谈恋爱去了，男1急了，说我给你买，但前提条件是不要离开我  这就是const 修饰point时，指向不能改变，但内容可以
    但是这个男1很坏，既不给你买，也不让你爱上别人 这就是  const int * const point 了
    这才是一级指针 ，二级指针则可以放三个const 你可以想象一下 哈哈哈  const int * const * const point
*/
 //小试牛刀
//1.打印number的结果
//#include<stdio.h>
//int number = 1;//全局变量
//void test() {
//    int number = 100;//局部变量
//    number -= 50;//局部优先
//}
//int main() {
//    test();
//    printf("%d\n", number);//  1
//    return 0;
//}

//2.求俩个数的最小公倍数
//方法1  相对效率低一点
//#include<stdio.h>
//int main() {
//    int NumberOne = 0;
//    int NumberTwo = 0;
//    scanf("%d %d", &NumberOne, &NumberTwo);
//    int min = NumberOne > NumberTwo ? NumberOne : NumberTwo;//最小公倍数最小也是俩数最大的一个数
//    while(1){
//        if (min % NumberOne == 0 && min % NumberTwo == 0) {
//            printf("%d\n", min);
//            break;
//        }
//        min++;
//    }
//}
//方法2
//#include<stdio.h>
//int main() {
//    int NumberOne = 0;
//    int NumberTwo = 0;
//    scanf("%d %d", &NumberOne, &NumberTwo);
//    int frequency = 1;
//    for (frequency = 1;; frequency++) {//不写判断条件恒为真
//        if (frequency * NumberOne % NumberTwo == 0) {
//            printf("%d\n", frequency * NumberOne);
//            break;
//        }
//    }
//    return 0;
//}

//3.将一句话倒置 比如 I like China.  ->  China. like I
#include<stdio.h>
#include<string.h>
void Swap(char* left, char* right) {
    while (left < right) {
        char middle = *left;
        *left = *right;
        *right = middle;
        left++;
        right--;
    }
}
int main() {
    char array[100] = { 0 };
    //scanf("%s", array);// scanf遇到空格就会停止 所以不能用scanf
    gets(array);//get(字符串地址在哪存储)
    //翻转法  1.将字符串反转
    int length = strlen(array);
    Swap(array, array + length - 1);//  数组左下标  数组右下标
    //2.每个单词逆序
    char* start = array;
    while (*start) {
        char* end = start;
        while (*end != ' ' && *end !='\0') {
            end++;
        }
        // 3.逆序一个单词
        Swap(start, end-1);

        if (*end == ' ') {
            start = end + 1;
        }
        else {
            start = end;
        }
    }
    printf("%s\n", array);
    return 0;
}

















