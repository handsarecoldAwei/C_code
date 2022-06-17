/*
    讲一下指针
     将相当于一个源文件你创建一个快捷方式，右键快捷方式-->打开文件所在位置；然后你再移动源文件，你会发现，不管你源文件咋移动，但快捷方式打开文件所占位置就可以找到
     这就相当于指针，你的Wegame打开lol其实也是一种指针
*/
//#include<stdio.h>
//int main()
//{
//    int number = 100;
//    int* point = &number;//int*（整形指针），因为数是int类型；快捷方式右击属性的目标存放的是地址，所以&number（number的地址）；point是指针变量
//    printf("%p\n", &number);//%p是打印地址
//    printf("%d\n", *point);//*p是解引用，你可以理解为双击快捷方式（打开快捷方式）
//    *point = 200;
//    printf("%d\n", *point);//相当于打开快捷方式修改（打开word文档修改啊啥的）
//
//    //一个指针占多大空间呢？
//    printf("%d\n", sizeof(char*));
//    printf("%d\n", sizeof(short*));
//    printf("%d\n", sizeof(int*));
//    printf("%d\n", sizeof(long*));
//    printf("%d\n", sizeof(long long*));
//    printf("%d\n", sizeof(float*));
//    printf("%d\n", sizeof(double*));
//    //指针大小是相同的    指针是来存放地址的  地址多大空间，指针就多大空间（身份证上的身份证号，那块地就可以输下，我管你胖子瘦子高子矮子）
//    
//    //我这是64位的，所以指针大小是8字节；32位的就是4
//    return 0;
//}

/*
    讲一下刚才printf("%p\n", &number);的地址编号是怎么来的

    首先呢电脑有32（x86）位操作系统和64(x64)位操作系统 
    以32位操作系统举例子  32就是32根地址线，通电后有正电和负电 电信号转化为数字信息0和1
    这也就是计算机语言是二进制语言的由来
    0和1总共组成2^32有序数列（内存单元）
    然后2^32  /  8 = ？？？字节啥的再除1024等等你可以算算
    如果以一个比特位为一个地址，一个char就要占8个地址，这是不是有点太浪费了
    所以C就规定一个内存单元是一字节，然后分配地址

*/

/*-----------------------------------------
  为了描述一个复杂对象，所以就有了结构体
  你不可能人用int，char等来描述吧，他是不是集优秀帅气才智为一体啊，哈哈

*/
#include<stdio.h>
struct people {
    char name[20];
    int EQ;
    int IQ;
    double height;
};
int main()
{
    struct people one = { "张三", 85, 90, 165.51 };//第一个人创建和信息（结构体出现和初始化）
    printf("1.%s %d %d %lf\n", one.name, one.EQ, one.IQ, one.height);//第一人.相应信息（结构体成员变量）
    struct people* point = &one;//结构体指针
    printf("2.%s %d %d %lf\n", (*point).name, (*point).EQ, (*point).IQ, (*point).height);
    printf("3.%s %d %d %lf\n", point->name, point->EQ, point->IQ, point->height);//point（快捷方式）->name（源程序）
    return 0;
}