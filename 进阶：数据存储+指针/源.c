#define _CRT_SECURE_NO_WARNINGS
//数据在内存的存储
//整形： char也归纳为了整形类型了  因为char字符对应的是ASCII值（相对应的具体数字）
//#include<stdio.h>
//int main()//调试打开内存哦
//{
//	int number = -10;
//	/* 负数 原码10000000 00000000 00000000 00001010
//	      反码：10000000 11111111 11111111 11110101
//	       补码 11111111 11111111 11111111 11110111
//		   为啥负数用补码存储呢？ 这样可以数据统一处理（CPU只有加法）
//	       原码 -> 补码 （按位取反+1）
//		   100000000 00000000 00000000 00001000按位取反
//		   100000000 00000000 00000000 00001001加一又回去了
//	      16进制    ff         ff    ff       f 6
//		   大小端：低地址放低位，高地址放高位 ->小端存储 ; 低地址放高位，高地址放低位 -> 大端存储
//	*/
//	return 0;
//}
//写一个代码，判断当前编译器是大端还是小端
//#include<stdio.h>
//int main()
//{
//	int number = 1;
//	char* point = (char*)&number;
//	if (*point == 1) {
//		printf("小端\n");
//	}
//	else {
//		printf("大端\n");
//	}
//	return 0;
//}
//牛刀小试
//1.这个式子打印的结果是啥
//#include<stdio.h>
//int main() {
//	char number1 = -1;
//	// 10000000 00000000 00000000 00000001原码
//	// 11111111 11111111 11111111 11111111补码
//	// 截断 11111111
//	// %d方式打印  11111111 11111111 11111111 11111111补码 -> 10000000 00000000 00000000 00000001原码
//	signed number2 = -1;
//	// -1
//	unsigned char number3 = -1;
//	// 11111111 unsigned无符号%d形式打印 00000000 00000000 00000000 11111111 
//	printf("%d %d %d\n", number1, number2, number3);//  -1  -1  255
//	return 0;
//}
/*
     补充一点 char到底是signed char还是unsigned char ？C语言是没有规定的；但int啊，short啊是signed int（short）

     char 00000000(0)……01111111(127) ->10000000(11111111 11111111 11111111 10000000十进制-128)（-128）->100000001(原码11111111)（-127)……11111111(原码10000001)（-1）
     char类型的范围 -128 到 127
     无符号的char 00000000（0）->00000001(1)->01111111(127)->10000000(128)无符号位->10000001(129)->11111111(255)
*/
//2.这个式子打印的结果是啥
//#include<stdio.h>
//int main() {
//    char number = -128;
//    // 10000000 %u无符号打印 11111111 11111111 11111111 10000000
//    /*
//       10000000 00000000 00000000 10000000 原码
//       11111111 11111111 11111111 011111111  反码
//       11111111 11111111 11111111 10000000 补码
//    */
//    printf("%u\n", number);//一个很大的数
//    return 0;
//}
//3.这个式子打印的结果是啥
//#include<stdio.h>
//int main() {
//    char number = 128;
//    //00000000 00000000 00000000 10000000
//    //10000000 %u无符号打印整形 11111111 11111111 11111111 10000000
//    printf("%u\n", number);//很大的数
//    return 0;
//}
// 4.这个式子打印的结果是啥
//#include<stdio.h>
//int main() {
//    unsigned int number = 0;//无符号整形没有负数啊
//    for (number = 9; number >= 0; number--) {//条件恒成立嘛
//        printf("%u\n", number);
//    }
//    return 0;
//}
//5.这个式子打印的结果是啥
//#include<stdio.h>
//#include<string.h>
//int main() {
//    char array[1000];
//    int number;
//    for (number = 0; number < 1000; number++) {
//        array[number] = -1 - number;
//   // -1 -2……-128 127 126……0
//    }
//    printf("%d\n", strlen(array));//strlen遇到\0结束 255
//    return 0;
//}
//6.这个式子打印的结果是啥
//#include<stdio.h>
//unsigned char number = 0;
//int main() {
//    for (number = 0; number <= 255; number++) {//死循环
//        printf("你还是太年轻\n");
//    }
//    return 0;
//}
//浮点类型在内存中的存储
/*
       浮点数表示方法：第一种直接写出来 3.1415926 ； 第二种用科学计数法表示  1E10（1.0*10^10）

       根据国际标准IEEE（电器和电子工程协会）754规定,任意一个二进制浮点数表示形式为 （-1)^s * M * 2^E  ；（-1)^s为符号位 s为0则为正数，s为1则为负数 ；M为有效数 1<=M<2 ；2^E表示指数位
       
       举个例子来说 十进制5.0写成二进制   （-1)^0 * 1.01 * 2^2   ；  5.5   （-1)^1 * 1.011 * 2^2 

       float   32个bit位   0（符号位）00000000（8bit指数位） 00000000 00000000 0000000（23bit有效值位）
       double  8字节64bit位   1bit为符号位  11bit为指数位  52bit为有效值位

       IEEE754对有效数M和指数E有一些特别规定
       M的取值范围 1<=M<2 ,它可以写成1.xxxx,其中xxxx为小数部分，在计算机保存M时，默认这个第一位总是1，因此可以被舍弃，只保留小数，等读取时再把1加上去，这样节省了一位有效数字，float可以保存24位有效数字了
       E为一个无符号整数，这意味着如果E为8位，取值范围为（0-255）（11位 0-2047）；但是科学计数法E可以为负数的，所以IEEE754规定，存E的时候需要加一个中间数，8位E+127(11位+1023) ；例如2^10 ,E=10,10+127=137 即10001001
       
       指数E从内存中取出还有三种情况
       E为不全0或不全1的 
       E为全0   E为8位时+127 ；11位+1023 还E为0 说明这是一个很小的数，这时浮点数的指数E等于1-127（1-1023）即为真实值，有效数字M不在加上1，这样做表示正负0，以及很小的数字
       E为全1   正（负）无穷大 取决于符号位
*/
//#include<stdio.h>
//int main() {
//    float Number = 9.0;
//   // 0 10000010 00100000 00000000 0000000
//   //   4    1    1   0    0 0 0 0
//    int number = 9;
//    float* pFloat = (float*)&number;
//    printf("number的值=%d\n", number);//无可置疑 9
//    printf("*pFloat的值=%f\n", *pFloat);// 0 00000000 00000000 00000000 0001001   
//    *pFloat = 9.0;
//    printf("number的值=%d\n", number);// 0 10000010 00100000 00000000 0000000 很大的数字
//    printf("*pFloat的值=%f\n", *pFloat);// 毋庸置疑9.0
//    return 0;
//}

//讲一下进阶指针
//1.字符指针
//#include<stdio.h>
//int main() {
//    /*  字符指针的一般使用
//    char happy = 'A';
//    char* point = &happy;
//    *point = 'a';
//    printf("%c\n", *point);*/
//    char *word = "HelloWord";//字符串常量不能改
//    char array[] = "HelloWord";//字符串在数组存放可以改
//    array[0] = 'A';
//    printf("%c\n", *word);//本质是把这个字符串 "HelloWord" 首字符存在了word中
//
//    printf("%s\n", word);
//    printf("%s\n", array);
//
//    return 0;
//}
//小试牛刀一下
//#include<stdio.h>
//int main() {
//    char array1[] = "HelloWorld";
//    char array2[] = "HelloWorld";
//    const char *array3 = "HelloWorld";//字符串常量(加上const 是不是代码更健壮了一点呢？？)
//    const char *array4 = "HelloWorld";
//    if (array1 == array2) {
//        printf("1相等\n");
//    }
//    else {
//        printf("1不相等\n");//数组内容相同，但是需要开辟不同的空间来存放数组的，所以不相等
//    }if (array3 == array4) {
//        printf("2相等\n");//字符串常量，又是指针指向，他们指向同一个位置
//    }
//    else {
//        printf("2不相等\n");
//    }
//    return 0;
//}

//指针数组  存放指针的数组
//#include<stdio.h>
//int main() {
//    //一种尴尬的写法
//    int number1 = 10;
//    int number2 = 20;
//    int number3 = 30;
//    int* array[] = {&number1,&number2 ,&number3};
//    int frequency = 0;
//    for (frequency = 0; frequency < 3; frequency++) {
//        printf("%d ", *(array[frequency]));
//    }
//    printf("\n");
//    //搞起来
//    int array1[] = { 1, 2, 3, 4, 5 };
//    int array2[] = { 6, 7, 8, 9, 10 };
//    int array3[] = { 11, 12, 13, 14, 15 };
//    int* array4[] = { array1,array2,array3 };
//    int frequency1 = 0;
//    int frequency2 = 0;
//    for (frequency1 = 0; frequency1 < 3; frequency1++) {
//        for (frequency2 = 0; frequency2 < 5; frequency2++) {
//            //printf("%d ", *(array4[frequency1] + frequency2));//第一种写法
//            printf("%d ", array4[frequency1][frequency2]);//第二种写法
//        }
//        printf("\n");
//    }
//    return 0;
//}

//数组指针（是一种指针）（指向数组的指针）  ； 整型指针（指向整形）；字符指针（指向字符）
//#include<stdio.h>
//void MyPrintf(int(*point)[5], int row1, int row2) {
//    int frequency1 = 0;
//    int frequency2 = 0;
//    for (frequency1 = 0; frequency1 < row1; frequency1++) {
//        for (frequency2 = 0; frequency2 < row2; frequency2++) {
//            printf("%d ", *(* (point + frequency1) + frequency2));
//        }
//        printf("\n");
//    }
//}
//int main() {
//    int array[10] = { 1, 2, 3, 4, 5 ,6, 7, 8, 9, 10};
//    //int* point1 = array;
//    //int(*point2)[10] = &array;//取出的是数组的地址（和整型指针，字符指针取地址一样）
//    //printf("%p\n", point1);
//    //printf("%p\n", point1 + 1);// +1跳一个int类型
//    //printf("%p\n", point2);
//    //printf("%p\n", point2+1);// +1 跳整个数组（&array不是白取的）
//
//    //数组指针的使用
//    int* point3 = array;
//    int(*point4)[10] = &array;//用上面point3就可以解决问题，非要搞这中高大上的表示，杀鸡焉用牛刀，还麻烦
//    //数组指针，该指针指向一个数组，数组10个元素，每个元素int类型
//    //    int(*point5[10])[5]  print5是存放数组指针的数组，该数组能够存放10个数组指针，每个数组指针能够指向一个数组
//
//    int frequency = 0;
//    /*for (frequency = 0; frequency < 10; frequency++) {
//        printf("%d ", *(point3 + frequency));     //第一种方法
//    }*/
//    //for (frequency = 0; frequency < 10; frequency++) {
//    //    printf("%d ", *((*point4)+frequency));//这种情况有点很别扭
//    //}
//    //来，展示他的用武之地
//    int array_two[3][5] = { {1, 2, 3, 4, 5},{6, 7, 8, 9, 10},{11, 12, 13, 14, 15} };
//    MyPrintf(array_two, 3,5);
//    return 0;
//}

//一维数组传参和二维数组传参
//#include<stdio.h>
//void test1(int **array1) {//传过来指针数组，那我用二级指针接受（二级指针指向一级指针）
//}
//void test2(int* array2) {}//一维数组用一级指针接受是可以的
//void test2(int* array2[5]) {}//二维数组用指针数组接受？？要用数组指针
////void test2(int **array2){}//二维数组用二级指针接受？合理嘛？
//
//int main() {
//    int* array1[20] = { 0 };
//    int array2[3][5] = { 0 };
//    test1(array1);
//    test2(array2);
//    return 0;
//}

//朝花夕拾
//1.打印结果是啥
//#include<stdio.h>
//int number;// 全局变量未初始化默认是0
//int main() {
//    number--;//  -1
//    if (number > sizeof(number)) {//  sizeof出来的结果肯定是整数，变量大小不可能为负数； 一个负数和无符号整数相比，转化为无符号整数，将会是一个很大的数
//        printf(">\n");
//    }
//   
//    else {
//        printf("<\n");
//    }
//    printf("%u", number);
//    return 0;
//}
//2. a+aa+aaa+aaaa+aaaaa 的前五项之和
//#include<stdio.h>
//int main() {
//    int number1 = 0;
//    int number2 = 0;
//    scanf("%d %d", &number1, &number2);
//    int frequency = 0;
//    int sum = 0;
//    int number3 = 0;//先算一项的值 
//    for (frequency = 0; frequency < number2; frequency++) {//第number2项
//        number3 = number3 * 10 + number1;
//        sum += number3;
//    }
//    printf("%d\n", sum);
//    return 0;
//}

 //3.打印一个范围水仙花数  水仙花数是一个n位数，各个数字的n次方之和等于该数本身
//#include<stdio.h>
//#include<math.h>//pow数字开方函数的头文件
//int main() {
//    int number = 0;
//    for (number = 0; number <= 10000; number++) {//   0-10000直接的数
//        //判断number是几位数
//        int much = 1;
//        int brother = number;
//        while (brother / 10) {
//            much++;
//            brother /= 10;
//        }
//        //计算number每一位n次方之和
//        brother = number;
//        int sum = 0;
//        while (brother) {
//            sum += pow(brother % 10, much);// pow(数字，次方)，计算一个数字次方函数
//            brother /= 10;
//        }
//        //3.判断
//        if (sum == number) {
//            printf("%d\n", number);
//        }
//    }
//    return 0;
//}

//二级指针也是指针，只不过比一级指针更大？？？不对的；第一指针在32位操作系统4字节（64位操作系统8字节）；第二呢你说的是比较两个地址大呢？还是比较的是所占空间呢？

//4.花式打印方块，不再用n个printf每行来完成方块啦
//#include<stdio.h>
//int main() {
//    int row = 0;
//    scanf("%d", &row);
//    //上
//    int frequency = 0;
//    for (frequency = 0; frequency < row; frequency++) {
//        //打印一行  空格
//        int frequency_two = 0;
//        for (frequency_two = 0; frequency_two < row - 1 - frequency; frequency_two++) {
//            printf(" ");
//        }
//        ////打印1（3，5，7个）*
//        for (frequency_two = 0; frequency_two < 2*frequency+1; frequency_two++) {
//            printf("*");
//        }
//        printf("\n");
//    }
//    //下
//    for (frequency = 0; frequency < row - 1; frequency++) {
//        //打印一行  空格
//        int frequency_two = 0;
//        for (frequency_two = 0; frequency_two <= frequency; frequency_two++) {
//            printf(" ");
//        }
//        ////打印7（5,3,1个）*
//        for (frequency_two = 0; frequency_two < 2 * (row - 1 -frequency)-1; frequency_two++) {
//            printf("*");
//        }
//        printf("\n");
//    }
//    return 0;
//}

//5.一瓶汽水1元，2个空瓶可换一瓶汽水，给你20元，能买多少汽水
//#include<stdio.h>
//int main() {
//    int money = 0;
//    scanf("%d", &money);
//    int pop = money;
//    int swap = money;
//    while (swap > 1) {
//        pop += swap / 2;//喝多少汽水
//        swap = swap / 2 + swap % 2;//兑换多少汽水
//    }
//    printf("%d", pop);
//    return 0;
//}

//6.调整数组  使奇数全部位于偶数前面
//#include<stdio.h>
//void Swap(int arr[], int size) {
//    int left = 0;
//    int right = size - 1;
//    while (left < right) {
//        while ((left < right) && (arr[left] % 2 == 1)) {
//          left++;//发现奇数从后找偶数
//        }
//        while ((left < right) && (arr[right] % 2 == 0)) {
//            right--;//发现偶数从前找奇数
//        }
//        if (left < right && left < right) {
//            int swap = arr[left];
//            arr[left] = arr[right];
//            arr[right] = swap;
//        }
//    }
//}
//int main(){
//    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//    Swap(arr, size);
//    int frequency = 0;
//    for (frequency = 0; frequency < size; frequency++) {
//        printf("%d ", arr[frequency]);
//    }
//    return 0;
//}

//7.计算打印结果
//#include<stdio.h>
//int main() {
//    unsigned char/* 0 - 255 */ one = 100;
//    //00000000 00000000 00000000 01100100  int类型100发生截断
//    //01100100
//    unsigned char two = 200;
//    //00000000 00000000 00000000 11001000 int类型200发生截断
//    //11001000
//    unsigned char three;
//    three = one + two;
//    //00000000 00000000 00000000 01100100 + 00000000 00000000 00000000 11001000 相加存放在char中（发生截断）
//    //00101100
//    printf("%d %d \n", one + two/*相加直接放在int中*/, three/*在整型提升*/);
//    return 0;
//}

/* 8. 打印杨辉三角   换一种形式看待杨辉三角
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/
//#include<stdio.h>
//int main() {
//    int array[10][10] = { 0 };
//    int number1 = 0;
//    int number2 = 0;
//    for (number1 = 0; number1 < 10; number1++) {
//        for (number2 = 0; number2 < 10; number2++) {
//            if (number2 == 0) {
//                array[number1][number2] = 1;
//            }
//            if (number1 == number2) {
//                array[number1][number2] = 1;
//            }
//            if (number1 > 1 && number2 > 0) {
//                array[number1][number2] = array[number1 - 1][number2 - 1] + array[number1 - 1][number2];
//            }
//        }
//    }
//    for (number1 = 0; number1 < 10; number1++) {
//        for (number2 = 0; number2 <=number1; number2++) {
//            printf("%d ", array[number1][number2]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

/* 9. 代码（智力题）找犯人   3个人说了真话，一个人说了假话
 A：不是我
 B：是C
 C：是D
 D：C放屁
*/
//#include<stdio.h>
//int main() {
//    char why = 0;
//    for (why = 'A'; why <= 'D'; why++) {
//        if ((why != 'A') + (why == 'C') + (why == 'D') + (why != 'D')==3) {
//            printf("%c是嫌疑犯\n", why);
//        }
//    }
//    return 0;
//}

/* 10.五名运动员比赛，每个人都说对了一半，求他们的名次
A:B第二，我第三
B:我第二，E第四
C:我第一，D第二
D:C最后，我第三
E:我第四，A第一
*/
//#include<stdio.h>
//int main() {
//    int A, B, C, D, E = 0;
//    for (A = 1; A <= 5; A++) {
//        for (B = 1; B <= 5; B++) {
//            for (C = 1; C <= 5; C++) {
//                for (D = 1; D <= 5; D++) {
//                    for (E = 1; E <= 5; E++) {
//                        if(
//                            ((B==2)+(A==3)==1) &&
//                            ((B == 2) + (E == 4) == 1) &&
//                            ((C == 1) + (D == 2) == 1) &&
//                            ((C == 5) + (D == 3) == 1) &&
//                            ((E == 4) + (A == 1) == 1)
//                            )if (A * B * C * D * E == 120) {
//                            printf("比赛名次 A=%d  B=%d  C=%d  D=%d  E=%d\n", A, B, C, D, E);
//                        }
//                    }
//                }
//            }
//        }
//    }
//    return 0;
//}
/*11.智力题 有一根香，（没有计时器）燃烧完一根1个小时，给你两根香，请确认一个15分钟的时间段
      
      把一根香两头点燃（30分钟）和另外一根香一头点燃（烧掉一半）；等两头点燃的香燃烧完，把另外一根香的一头点燃

 12.智力题 一个人住30楼，下雨天和电梯有人的时候坐电梯30层回家；其他时间到15楼，请问怎么回事？

    官方答案：这人侏儒症，个子矮；有人和拿雨伞可以点到30楼层

 13.智力题 36匹马，6个跑道，不给计时器，确定前三名

    第一步：36匹马分成6组，每组先比一次，取每组的前三名（6次）

    第二步：将每个组的前三名留下，剩余淘汰；再将每个组的第一名进行比赛，选出这个比赛的前三名小组（因为第一第二第三肯定在他们之中产生的），剩余淘汰（1次）

    第三步：最终留下的马：a1,a2,a3(第一名小组)
                        b1,b2,b3(第二名小组)
                        c1,c2,c3(第三名小组)
     a1,肯定是第一
     第二不可能是c1(还没b1跑的好呢)，b2,a3;在a2,b1中有一个第二
     第三可能是c1,b1,b2,a2,a3(这次5匹马开始跑，取前两名)（1次）

     总共次数8次（6+1+1）
*/

// 一级指针接受->（一级指针传参）; （变量的地址&）

//二级指针接受 ->（二级指针传参）；（一级指针的地址）；（存放一级指针的数组）

//函数指针（指向函数的指针，存放函数地址的指针）
//#include<stdio.h>
//int Add(int number1, int number2) {
//    return number1 + number2;
//}
//int main() {
//    int(*point/*因为优先级所以（）括起来，（）里面可以看出是个指针*/)(int, /*函数参数*/int) = &Add;//&取函数地址  ； *point就是函数指针变量
//    //printf("%p\n", &Add);
//    //printf("%p\n", Add);//两个打印结果是一样的，和数组有点像
//    int number1 = (*point)(100, 200);//  *point解引用是函数地址  
//    int number2 = Add(100, 200);
//    int number3 = (point)(100, 200);// &Add和Add打印地址的结果是一样的，point是指向Add的， point==Add
//    //   *(point)(100,200)这样是不行的，point会先跟（100，200）结合，解引用一个数字合适嘛？？
//    int number4 = (*****point)(100, 200);// 既然一个*去掉结果一样，n个星号试试
//    printf("number1=%d\n", number1);//300
//    printf("number2=%d\n", number2);
//    printf("number3=%d\n", number3);
//    printf("number4=%d\n", number4);
//    return 0;
//}

/*
  解读两段有趣的代码

    （*（void (*）()）0）() ;   
    1. void (*）()函数指针，参数无参;  
     2. void (*）()0 把0强制类型转化成地址；
      3. 在对0进行解引用操作，找到函数地址；
       4. （*（void (*）()）0）()进行调用


    void(*point(int,void(*)(int)))(int)
     1.  point(int,void(*))  point先和（）结合，成函数 ，一个参数是int，另一个是函数指针
       2. void(*)(int)  函数名有了，参数有了，剩下就是返回类型了（函数指针）
       这个代码写成  void(*)(int) point(int,void(*)(int)) 但语法不允许这样写
       用 typedef void(*)(int) swap 这样写报错不允许
       swap point(int,swap);
       
*/
//函数指针的应用   实现计算器 + - * /
//#include<stdio.h>
//void menu() {
//    printf("*******1.Add***************\n");
//    printf("*******2.Sub***************\n");
//    printf("*******3.Mul***************\n");
//    printf("*******4.Div***************\n");
//    printf("*******0.Escape***************\n");
//}
//int Add(int number1, int number2) {
//    return number1 + number2;
//}
//int Sub(int number1, int number2) {
//    return number1 - number2;
//}
//int Mul(int number1, int number2) {
//    return number1 * number2;
//}
//int Div(int number1, int number2) {
//    return number1 / number2;
//}
//int main() {
//    //int (*point1)(int, int) = Add;//函数指针
//    //int (*point2)(int, int) = Sub;//函数指针
//   // int (*point3[4])(int, int) = {Add,Sub,Mul,Div};//函数指针数组
//    
//   // scanf("%d", &input);
//    int input = 0;
//    do {
//        menu();
//        int number1 = 0;
//        int number2 = 0;
//        int result = 0;
//        
//        scanf("%d", &input);
//        switch (input) {
//        case 1:
//            scanf("%d %d", &number1, &number2);
//            result = Add(number1, number2);
//            printf("%d\n", result);
//            break;
//        case 2:
//            scanf("%d %d", &number1, &number2);
//            result = Sub(number1, number2);
//            printf("%d\n", result); 
//            break;
//        case 3:
//            scanf("%d %d", &number1, &number2);
//            result = Mul(number1, number2);
//            printf("%d\n", result); 
//            break;
//        case 4:
//            scanf("%d %d", &number1, &number2);
//            result = Div(number1, number2);
//            printf("%d\n", result); 
//            break;
//        case 0:
//            printf("退出程序\n");
//            break;
//        default:
//            printf("选择错误，请重新选择\n");
//             break;
//        }
//    } while (input);
//    return 0;
//} 
/*    这样写代码，你不感觉很冗余嘛？
          scanf("%d %d", &number1, &number2);
            result = Sub(number1, number2);
            printf("%d\n", result); 写了四遍   
            改善一下：既然调用函数的参数，返回类型都是一样的，那还不如来个函数指针数组一笔带过呢
*/
//int main() {
//  
//    int input = 0;
//    do {
//        menu();
//        int(*point[5])(int, int) = { NULL,Add,Sub,Mul,Div };//数组下标是从零开始的
//        int number1 = 0;
//        int number2 = 0;
//        int result = 0;
//        scanf("%d", &input);
//        
//        if (input >= 1 && input <= 4) {
//            scanf("%d %d", &number1, &number2);
//            result = (*point[input])(number1, number2);
//            printf("%d\n", result);
//        }
//        else if (input == 0) {
//            printf("退出程序\n");
//            break;
//        }
//        else {
//            printf("输入错误，请重新选择\n");
//        }
//
//    } while (input);
//    return 0;
//}
/*    
        int (*point1)(int,int);//函数指针
        int (*point2[3])(int,int);//函数指针数组
        int (*(*point3)[3])(int,int)=&point2;//函数指针数组的地址

        回调函数：一个函数作为参数传给另外一个函数，当被调用这个函数时，就叫做回调函数
*/
//int MyFunction(int(*point)(int, int)) {
//    int number1 = 0;
//    int number2 = 0;
//    scanf("%d %d", &number1, &number2);
//    return point(number1, number2);
//}
//int main() {
//    
//    int input = 0;
//    do {
//        menu();
//        
//        int result = 0;
//        
//        scanf("%d", &input);
//        switch (input) {
//        case 1:
//           
//            result = MyFunction(Add);
//            printf("%d\n", result);
//            break;
//        case 2:
//            
//            result = MyFunction(Sub);
//            printf("%d\n", result); 
//            break;
//        case 3:
//           
//            result = MyFunction(Mul);
//            printf("%d\n", result); 
//            break;
//        case 4:
//            
//            result = MyFunction(Div);
//            printf("%d\n", result); 
//            break;
//        case 0:
//            printf("退出程序\n");
//            break;
//        default:
//            printf("选择错误，请重新选择\n");
//             break;
//        }
//    } while (input);
//    return 0;
//} 

//冒泡排序
//#include<stdio.h>
//void MySort(int array[], int size) {//只能排序整形数据
//    int frequency1 = 0;
//    for (frequency1 = 0; frequency1 < size - 1; frequency1++) {//冒泡排序躺数
//        int frequency2 = 0;
//        for (frequency2 = 0; frequency2 < size - 1 - frequency1; frequency2++) {//一趟冒泡排序
//            if (array[frequency2] > array[frequency2 + 1]) {//整形数据的交换  如果要实现字符串结构体数据交换 这部分内容需要改变的
//                int swap = array[frequency2];
//                array[frequency2] = array[frequency2 + 1];
//                array[frequency2 + 1] = swap;
//            }
//        }
//    }
//}
//void MyPrintf(int array[], int size) {
//    int frequency = 0;
//    for (frequency = 0; frequency < 10; frequency++) {
//        printf("%d ", array[frequency]);
//    }
//    printf("\n");
//}
//int main() {
//    int array[10] = { 9, 8, 7 , 6, 5, 4 , 3, 2, 1, 0 };
//    int size = sizeof(array) / sizeof(array[0]);
//    MySort(array, size);
//    MyPrintf(array, size);
//    return 0;
//}
/*在C中有一个  qsort函数 整形字符串结构体数据都可以排序

     void qsort (void* base, //待排序对象的第一个数据地址  我也不知道第一个元素是什么类型所以用的是 void*
                 size_t num, //排序元素个数
                 size_t size, //排序的一个元素大小  单位是字节
                 int (*compar)(const void*,const void*)); //比较两个元素的函数   (const void*第一个元素的地址,const void*第二个元素的地址)

 */
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
////void MyPrintf(int array[], int size) {
////    int frequency = 0;
////    for (frequency = 0; frequency < 10; frequency++) {
////        printf("%d ", array[frequency]);
////    }
////    printf("\n");
////}
//struct student {
//    int age;
//    char name[20];
//};
////int compare1(const void*point1, const void*point2) {
////    return *(int*)point1 - *(int*)point2;
////}
//
////int compare2(const void* point1, const void* point2) {
////    return strcmp(((struct student*)point1)->name,((struct student*)point2)->name);
////}
//int compare2(const void* point1, const void* point2) {
//    return ((struct student*)point1)->age - ((struct student*)point2)->age;
//}
//int main() {
//    //int array[10] = { 9, 8, 7 , 6, 5, 4 , 3, 2, 1, 0 };
//    //int size = sizeof(array) / sizeof(array[0]);
//    //qsort(array, size, sizeof(array[0]), compare1);
//    //MyPrintf(array, size);
//    struct student one[3] = {{18,"Awei"},{99,"xchangmian"},{77,"bniulang"}};
//    int size_struct = sizeof(one) / sizeof(one[0]);
//    qsort(one, size_struct, sizeof(one[0]), compare2);
//    return 0;
//}

//实现sqort
//#include<stdio.h>
//int compare_int(const void* point1, const void* point2) {
//    return *(int*)point1 - *(int*)point2;
//}
//void Swap(char* word1, char* word2, int width) {
//    int frequency = 0;
//    for (frequency = 0; frequency < width; frequency++) {
//        char swap = *word1;
//        *word1 = *word2;
//        *word2 = swap;
//        word1++;
//        word2++;
//    }
//
//}
//void MyQsort(void* base,
//    int size, 
//    int width, 
//    int (*compar)(const void*point1, const void*point2))//比较两个元素的函数
//{
//    
//    int frequency1 = 0;
//    for (frequency1 = 0; frequency1 < size - 1; frequency1++) {//冒泡排序躺数
//        int frequency2 = 0;
//        for (frequency2 = 0; frequency2 < size - 1 - frequency1; frequency2++) {//一趟冒泡排序
//            if (compar((char*)base+frequency2*width, (char*)base + (frequency2+1) * width)>0) {//前面只能整形数据的交换  如果要实现字符串结构体数据交换 这部分内容需要改变的
//                Swap((char*)base + frequency2 * width, (char*)base + (frequency2 + 1) * width,width);//交换
//            }
//        }
//    }
//}
//
//void MyPrintf(int array[], int size) {
//    int frequency = 0;
//    for (frequency = 0; frequency < 10; frequency++) {
//        printf("%d ", array[frequency]);
//    }
//    printf("\n");
//}
//
//int main() {
//    int array[10] = { 9, 8, 7 , 6, 5, 4 , 3, 2, 1, 0 };
//    int size = sizeof(array) / sizeof(array[0]);
//    MyQsort(array, size,sizeof(array[0]),compare_int);
//    MyPrintf(array, size);
//    return 0;
//}

//关于void*指针
//#include<stdio.h>
//int main() {
//    char A = 'a';
//    int A = 97;
//    void* point = &A;//无具体类型指针指向char
//    point = &A;//我不指向char了  我指向int类型  这样是可以的
//    //   *point 和  point++   这样不行  我一次访问几个字节？？？  err
//    return 0;
//}


//------------牛刀小试
//  1打印结果是啥
//#include<stdio.h>
//int main() {
//    //char array[] = { 'a','b','c' };
//    //printf("%d\n", sizeof(*array));//  'a' char类型一个字节  打印出来1
//    //strlen（里面放的是地址）
//    int array[2][4] = { 0 };
//    printf("%d\n", sizeof(array[0]));// 第一行大小   16  二维数组可以看成 array[2]为数组名  [3]是数组元素的个数
//    printf("%d\n", sizeof(array[0]+1));//第一行第二个地址  4/8
//    printf("%d\n", sizeof(array+1));  //array第一行地址   4/8
//    printf("%d\n", sizeof(*(array + 1)));  // 第二行地址解引用第二行大小  16
//    printf("%d\n", sizeof(array[3]));//第四行数组名  不存在，sizeof括号里面也不进行运算 16
//    
//    return 0;
//}

// 2 旋转字符    实现一个函数  可以旋转number个字符 
//#include<stdio.h>
//#include<string.h>
////void StartRotate(char* array, int rotate_number) {//第一种方法  暴力转换
////    int frequency = 0;
////    int length = strlen(array);
////    for (frequency = 0; frequency < rotate_number; frequency++) {
////        char swap = *array;//第一步
////        int frequency_two = 0;
////        for (frequency_two = 0; frequency_two < length-1; frequency_two++) {
////            *(array + frequency_two) = *(array + frequency_two + 1);//第二步
////        }
////        *(array + length - 1) = swap;//第三步
////    }
////}
//#include<assert.h>
//void Swap(char*left,char*right) {//实现交换
//    assert(left);
//    assert(right);
//    while (left < right) {
//        char swap = *left;
//        *left = *right;
//        *right = swap;
//        left++;
//        right--;
//    }
//}
//void StartRotate(char* array, int rotate_number) {//第二种方法  三步旋转法
//    assert(array);
//    int length = strlen(array);
//    Swap(array, array + rotate_number - 1);//左
//    Swap(array + rotate_number, array + length - 1);//右
//    Swap(array, array + length - 1);//整体交换
//}
//int main() {
//    char array[20] = "ILikeBeijing";
//    int rotate_number = 5;
//    StartRotate(array, rotate_number);
//    printf("%s\n", array);
//    return 0;
//}

//3.判断是否是旋转字符
//第一种方法  穷举法
//#include<stdio.h>
//#include<string.h>
//int IsRotateNumber(char* array_one, char* array_two) {
//    int frequency = 0;
//        int length = strlen(array_one);
//        for (frequency = 0; frequency < length; frequency++) {
//            char swap = *array_one;
//            int frequency_two = 0;
//            for (frequency_two = 0; frequency_two < length-1; frequency_two++) {
//                *(array_one + frequency_two) = *(array_one + frequency_two + 1);
//            }
//            *(array_one + length - 1) = swap;
//            if (strcmp(array_one, array_two) == 0) {
//                return 1;
//            }
//        }
//        return 0;
//}
//int main() {
//    char array_one[] = "ABCDE";
//    char array_two[] = "BCDEA";
//    int result = IsRotateNumber(array_one, array_two);
//    if (result == 1) {
//        printf("Yes!!!\n");
//    }
//    else {
//        printf("No!!!\n");
//    }
//    return 0;
//}

//第二种方法    ABCDEABCDE   追加字符串找旋转字符   BCDEA
////先学一下追加函数
/*#include<stdio.h>
#include<string.h>*///追加函数头文件
//int main() {
//    char array[20] = "Hello";
//    strcat(array, "World");//  追加字符串函数（追加对象；追加内容，但不能追加本身）
//    printf("%s\n", array);
//    strncat(array, array, 5);//   (追加对象；追加内容;追加对象的个数)
//    printf("%s\n", array);
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int IsRotateNumber(char* array_one, char* array_two) {
//    if (strlen(array_one) != strlen(array_two)) {
//        return 0;
//    }
//    //1.先追加
//    int length = strlen(array_one);
//    strncat(array_one, array_one, length);
//    //2.判断是否为旋转函数
//    char* return_type = strstr(array_one, array_two);//  strstr判断是否为旋转函数 是返回地址，不是则返回空指针
//    return return_type != NULL;
//}
//int main() {
//    char array_one[20] = "ABCDE";
//    char array_two[] = "BCDEA";
//    int result = IsRotateNumber(array_one, array_two);
//    if (result == 1) {
//        printf("Yes!!!\n");
//    }
//    else {
//        printf("No!!!\n");
//    }
//    return 0;
//}

/*
    杨氏矩阵  有一个数组矩阵，每行从左到右递增，从上到下递增

    请写一个程序在矩阵中找一个数字是否存在

    要求：时间复杂小于O(N)  就是如果有N个元素，简单粗暴的手法找N次    O(1)是找这个数字用固定数次（常数）就找到了

*/
#include<stdio.h>
int find_number(int array[3][3], int* row, int* col, int number) {
    int coordinate1 = 0;
    int coordinate2 = *col - 1;
    while (coordinate1 < *row && coordinate2 >= 0) {
        if (array[coordinate1][coordinate2] < number) {
            coordinate1++;
        }
        else if (array[coordinate1][coordinate2] > number) {
            coordinate2--;
        }
        else {
            *row = coordinate1;
            *col = coordinate2;
            return 1;//找到了
        }
    }
    return 2;//找不到
}
int main() {
    int array[3][3] = { 1, 2, 3,4,5,6,7,8,9 };
    int row = 3;
    int col = 3;
    int number = 7;//矩阵找7
    int is = find_number(array,&row,&col,number);
    if (is == 1) {
        printf("找到了\n下标是%d %d\n", row, col);
    }
    else {
        printf("找不到\n");
    }
    return 0;
}
/*小wink： 
          1. C++.cpp文件原来是.cplusplus 的缩写
          2.当使用free释放掉一个指针内容后，指针变量的值要手动置为NULL（虚空先知）
          3.不同游戏状态调用不同函数，回调函数作用之一
          4.数组地址交给数组指针，一般指针拿捏不住
*/










