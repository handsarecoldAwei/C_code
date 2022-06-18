/*
    最后的战役

    讲完这局，基本C笼统的回顾了一遍

    关键字（也叫保留字，看见P就是停车场，看见关键字，就是某中带有标志的符号）

    关键字不能自己创造 C提供的  也不能做变量名    
*/

//auto 声明自动变量
//#include<stdio.h>
//int main()
//{
//    {
//       auto int number = 100;//局部变量
//       //auto 声明自动变量(每个局部变量都是auto修饰的，自动创建自动销毁就是自动变量，auto可省略不写)
//       int number2 = 120;
//       //auto 省略掉了
//    }
//    return 0;
//}

//continue结束当前循环，开始下一轮循环
//#include<stdio.h>
//int main()
//{
//    int frequency = 1;
//    for (frequency = 1; frequency <= 50; frequency++) {
//        if (frequency == 25) {
//            continue;//当条件满足（25），结束当前循环，开始下一轮循环,所以打印不了25
//        }
//        printf("打印次数：%d\n", frequency);
//    }
//    return 0;
//}


//extern	声明变量或函数是在其它文件或本文件的其他位置定义
//#include<stdio.h>
//extern number_one;
//int main()
//{
//    printf("%d\n", number_one);
//    return 0;
//}
//extern（声明外部符号的） 你也理解为用strlen函数，要调用头文件那样理解  

//go to语句 无条件跳转语句   我举的例子不是很好，代码死循环，重在理解
//#include<stdio.h>
//int main()
//{
//    printf("1不要去缅甸\n");
//    GG://传送位置，一定要加：（冒号）
//    printf("2不要去缅甸\n");
//    printf("3不要去缅甸\n");
//    goto  GG;//   goto就是传送门  传送到哪里？ 传送到GG的地方
//    printf("1不要去缅甸\n");//永远不会执行
//    return 0;
//}


//register  声明寄存器变量
//#include<stdio.h>
//int main()
//{
//    register int number = 100;//建议把这个值放在寄存器（至于放不放还要看编译器，只是建议）
//    return 0;
//}
/*
   寄存器？？？

   首先思考一个问题，数据可以存放到哪里呢？  网盘（百度网盘啊啥的）      硬盘（C盘，D盘等）     内存    高级缓存   寄存器  你发现没有从左到右速度越快，空间越小   
   为了提高电脑速度，计算机会把大量频繁使用的数据放在寄存器里  当你寄存器里找不到 找高级缓存  层层向下 这样速度就提升了很多

*/

//static 声明静态变量   3个作用；  1.修饰局部变量  2.修饰全局变量 3.修饰函数

//#include<stdio.h>
//void Test() {
//    static int number = 0;//static修饰后，局部变量并没有消亡，而是延长了生命周期   保留了上一次number++的执行结果
//    number++;
//    printf("%d\n", number);
//
//}
//int main()
//{
//    int frequency = 0;
//    
//    while (frequency < 10) {
//        Test();
//        frequency++;
//    }
//    
//    return 0;
//}
//static改变了局部变量的生命周期，本质上是改变了数据的存储类型
//数据的存储类型有  栈区（存放局部变量和函数参数，你可以理解为存放临时的） 堆区（动态内存分配，你可以理解为存在一直放生变化的） 静态区（存放static修饰的东西和静态变量，你可以理解为存放长时间不变的）
//static修饰全局变量 和函数时，只能在本文件内使用被static修饰的东西，extern来了都不行

//define 用以给数据类型取别名
//#include<stdio.h>
//#define MAX 10000 //定义MAX值为1000(定义符号)
//#define ADD(X, Y) X+Y//define定义宏
//int main()
//{
//    printf("%d\n", ADD(5, 6));//打印结果为11
//    printf("%d\n", 5 * ADD(5, 6)); //相当于   5*5+6=31
//    return 0;
//}

//typedef用以给数据类型取别名(就是换个名)
//#include<stdio.h>
//typedef double decimal;//用decimal来表示double类型
//int main()
//{
//    double number = 3.14;
//    decimal number2 = 3.1415;
//    printf("%lf\n", number2);
//    return 0;
//}

//union共用体类型 ; volatile	说明变量在程序执行中可被隐含地改变   这俩先不讲
//谢谢大家的一路陪伴，笼统的概括了一下C