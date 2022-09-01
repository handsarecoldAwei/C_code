#define _CRT_SECURE_NO_WARNINGS
////来深入一下长度不受限制的字符串函数
//1. strlen字符串长度函数  
//#include<stdio.h>
//#include<string.h>
//int main() {
//	if (strlen("abc") - strlen("abcdef") > 0) {
//		printf(">\n");//返回值是无符号类型   size_t(unsigned int)     所以打印结果是>
//	}
//	else {
//		printf("<\n");
//	}
//	return 0;
//}

//  模拟实现strlen函数
//#include<stdio.h>
//int my_strlen(const char* array) {//计算变量的长度 不修改 const
//	assert(array != NULL);//让代码更加健康
//	int count = 0;//计数器实现strlen
//	while (*array != '\0') {
//		count++;
//		array++;
//	}
//	return count;
//}
//int main() {
//	char array[] = "abc";
//	int much = my_strlen(array);
//	printf("%d\n", much);
//	return 0;
//}

//2.  strcpy拷贝函数    string字符串   copy拷贝
//#include<stdio.h>
// #include<string.h>
//int main() {
//	char array[20] = "###################";
//	//strcpy(array, "hello");//这么写没毛病  但有点小别扭
//	char array_one[] = "hello";
//	strcpy(array, array_one);
//	printf("%s\n", array);//调试你会发现  '\0'  也拷贝进去了
//	return 0;
//}

//3.  strcat字符串追加  追加时先找到目标文件的  '\0'  再把源数据追加进去
//#include<stdio.h>
//#include<string.h>
//int main() {
//	char array1[30] = "hello \0#########";
//	char array2[] = "world";
//	strcat(array1, array2);
//	printf("%s\n", array1);//调试你会发现  '\0'  也追加进去了  并且在 \0 后面追加的
//	return 0;
//}

//模拟实现  strcat
//#include<stdio.h>
//#include<assert.h>
//char* my_strcat(char* array, const char* array1) {//追加又不修改  更加健康
//	char* start = array;//追加函数完成后会返回目标文件起始地址
//	assert(array && array1);//断言一下 预防空指针
//	//1.找到目标的  '\0'
//	while (*array) {
//		array++;
//	}
//	//2.追加字符串，包含  '\0'
//	while (*array++ = *array1++) {
//		;
//	}
//	return start;
//}
//int main() {
//	char array[20] = "hello";
//	char array1[] = "world";
//	printf("%s\n", my_strcat(array, array1));
//	return 0;
//}

//4. 模拟实现字符串比较函数  strcmp
//#include<stdio.h>
//#include<assert.h>
//int my_strcmp(const char* array1,const char* array2) {//  strcmp函数返回大于或小于 或等于的数字
//	assert(array1 && array2);//健康
//	while (*array1 == *array2) {
//		if (*array1 == '\0') {
//			return 0;
//		}
//		array1++;
//		array2++;
//	}
//	if (*array1 > *array2) {
//		return 1;
//	}
//	else {
//		return -1;
//	}
//}
//int main() {
//	char* array1 = "abcde";
//	char* array2 = "able";
//	int number = my_strcmp(array1, array2);
//	if (number > 0) {
//		printf("array1 > array2\n");
//	}
//	else if (number < 0) {
//		printf("array1 < array2\n");
//	}
//	else {
//		printf("array1 = array2\n");
//	}
//	return 0;
//}


//长度受限制的字符串函数  相对较于安全  可控
//1. strncpy拷贝函数
//#include<stdio.h>
//  #include<string.h>
//int main() {
//	char array1[20] = "abcdef";
//	char array2[] = "ghk";
//	strncpy(array1, array2, 5);//不够五个  将\0拷贝过去
//	printf("%s\n", array1);
//	return 0;
//}
//2.strncat 追加函数
//#include<stdio.h>
// #include<string.h>
//int main() {
//	char array1[30] = "hello \0##############";
//	char array2[] = "world";
//	strncat(array1, array2, 8);//   /0也追加过去
//	printf("%s\n", array1);
//	return 0;
//
//}

//3.strncmp  你想比较几个字符就比较几个字符


//模拟实现strstr函数  在array1中查找是否有array2数组
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//char* my_strstr(const char* array1, const char* array2) {//只找到不修改
//	assert(array1 && array2);
//	const char* point1 = NULL;
//	const char* point2 = NULL;
//	char* start = array1;
//	if (*array2 == '\0') {
//		return array1;
//	}
//	while (*start) {
//		point1 = start;
//		point2 = array2;
//		while (*point1 && *point2 && (*point1 == *point2)) {
//			point1++;
//			point2++;
//		}
//		if (*point2 == '\0') {
//			return start;
//		}
//		start++;
//	}
//	return NULL;
//}
//int main() {
//	char array1[] = "abcdefabcdef";
//	char array2[] = "cdef";
//	char* point = my_strstr(array1, array2);
//	if (point == NULL) {
//		printf("没找到\n");
//	}
//	else {
//		printf("找到了：%s\n", point);
//	}
//	return 0;
//}


//strtok字符串切割函数  找到标记会用\0结尾，返回一个指向这个标记的指针
//#include<stdio.h>
//#include<string.h>
//int main() {
//	char array[] = "110120@qq.com";
//	char* point = "@.";
//
//	char alternatives[20] = { 0 };
//	strcpy(alternatives, array);//strtok函数会改变被操作字符串，所以使用它切分的字符串一般都是临时拷贝的内容并可以修改
//	char* point1 = NULL;
//
//	//point = strtok(alternatives, point);
//	//printf("第一次切割 %s\n", point);
//
//	//point = strtok(NULL, point);//strtok函数第一个函数为NULL，则在标记处保存的位置开始，找下一个标记
//	//printf("第二次切割 %s\n", point);
//
//	//point = strtok(NULL, point);
//	//printf("第三次切割 %s\n", point);//如果字符串不存在更多标记，返回NULL指针
//
//	for (point1 = strtok(alternatives, point); point1 != NULL; point1 = strtok(NULL, point)) {
//		printf("%s\n", point1);
//	}
//
//	return 0;
//}

//使用库函数的时候，调用失败都会有错误码  errno
//strerror  错误码转换为错误信息
//#include<stdio.h>
//#include<string.h>//strerror头文件
//#include<errno.h> //errno头文件  全局错误码
//#include<stdio.h> //perror头文件
//
//int main() {
//
//	//printf("%s\n", strerror(0));      // No error
//	//printf("%s\n", strerror(1));     //Operation not permitted
//	//printf("%s\n", strerror(2));     //No such file or directory
//	//printf("%s\n", strerror(3));     //No such process
//	//printf("%s\n", strerror(4));     //Interrupted function call
//	//printf("%s\n", strerror(5));	 //Input / output error
//
//	FILE* point = fopen("test.txt", "r");//打开文件 读的形式打开  打开失败会返回NULL指针
//	if (point == NULL) {
//		/*printf("%s\n", strerror(errno));*/
//		perror("fopen");//   错误码转化为错误信息，打印错误信息  一步到位
//		return 1;//调用失败就不用往下走了 程序结束
//	}
//	fclose(point);//关闭文件
//	point = NULL;
//	return 0;
//}


//讲一下字符分类函数
//#include<stdio.h>
//#include<ctype.h> //isdigit头文件  
//int main() {
//	char judge = '#';
//	int number = isdigit(judge);//isdigit 如果是数字字符0-9返回非零值  不是返回0
//	printf("%d\n", number);
//	return 0;
//}

//字符转换函数
//#include<stdio.h>
//#include<ctype.h>//isupper大写字母字符分类函数头文件
//int main() {
//	char array[20] = { 0 };
//	scanf("%s", array);
//	int frequency = 0;
//	while (array[frequency] != '\0') {
//		if (isupper(array[frequency])) {
//			array[frequency] = tolower(array[frequency]);//tolower将大写转换为小写
//		}
//		printf("%c ", array[frequency]);
//		frequency++;
//	}
//	return 0;
//}

//内存函数
//内存拷贝  memcpy  拷贝不重叠的内存  VS中重不重叠都可以拷贝   memory记忆在程序中为内存  cpy（copy）复制，拷贝
//         memmove函数可以处理重叠内存
//#include<stdio.h>
//#include<string.h>//memcpy头文件
//#include<assert.h>
//void* my_memcpy(void* target, const void* source, size_t number) {// 我不知道内存拷贝的类型  用void*   ； size_t无符号整数
//	void* start = target;
//	assert(target && source);
//	while (number--) {
//		*(char*)target = *(char*)source;
//		target = (char*)target + 1;
//		source = (char*)source + 1;
//	}
//	return start;
//} 
//void* my_memmove(void* target, const void* source, size_t number) {
//	void* start = target;
//	assert(target && source);
//	if (target < source) {//前->后
//		while (number--) {
//			*(char*)target = *(char*)source;
//			target = (char*)target + 1;
//			source = (char*)source + 1;
//		}
//	}
//	else {//后->前
//		while (number--) {
//			*((char*)target + number) = *((char*)source + number);
//		}
//	}
//	return start;
//}
//int main() {
//	/*int array1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int array2[10] = { 0 };
//	memcpy(array2, array1, 20);*/
//
//	//模拟实现
//	int array1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int array2[10] = { 0 };
//	//my_memcpy(array2, array1, 20);
//	//my_memcpy(array1+2, array1, 20);//自己写的不能拷贝重叠的内存
//
//	//memmove(array1 + 2, array1, 20);
//	//模拟实现memmove
//	my_memmove(array1 + 2, array1, 20);
//	return 0;
//}

//memcmp 内存比较   memset内存设置
//#include<stdio.h>
//#include<string.h>//内存函数头文件
//int main() {
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[] = { 1, 1, 4 };
//	int judge = memcmp(array1, array2, 8);//  和strcmp字符串比较类似
//	printf("%d\n", judge);
//	int array3[10] = { 0 };
//	memset(array3, 1, 20);//以字节为单位进行内存设置
//	return 0;
//}


//结构体深刨
//1.只有关键字 没有名字 这种被称为匿名结构体类型
//struct person
//{
//	char name[20];
//	int age;
//	double height;
//	struct//匿名结构体类型
//	{
//		char phone[12];
//		char address[20];
//	};
//};
//#include<stdio.h>
//int main() {
//	struct person one = { "one",18,180.00,{"110120","中国大陆"} };
//	printf("%s\n", one.address);
//	return 0;
//}//结构体对象 one 可以通过 one.address 直接访问匿名结构体成员变量 phone，代码相对比较简洁
//  //反之则必须通过 jim.结构体名字.phone 来访问结构体成员变量

//2.结构体自引用  不是包含同类型的变量，而是包含同类型的指针

//数据结构：数据在内存中存储的结构 ； 线性数据结构有一种是顺序表 就是 1，2，3，4…… 一个挨一个存放；第二个是链表，没有相邻，而是你在这个位置，我在那个位置，每个数据前半段是存放数据的数据域，后半段是指针域（你可以找到我，我也可以找到你）
//struct person
//{
//	char name[20];
//	int age;
//	struct person* next;//如果用 struct person next，这不是死递归嘛
//	//          指针变量大小是可算得，  struct person* next可以找到和自己同类型的结构
//}


//3.结构体类型对齐
//#include<stdio.h>
//struct student1
//{
//	char one;//第一个成员在结构体变量偏移量为0的地址处，其他成员变量要对齐到对齐数（编译器默认对齐数与该成员大小的较小值，VS是8）的整数倍处
//	int two;
//	char three;
//};//结构体总大小为最大对齐数的整数倍  如果嵌套了结构体，则找结构体最大对齐数就可以了
//struct student2
//{
//	char one;
//	char three;
//	int two;
//};
//int main() {
//	struct student1 one = { 0 };
//	struct student2 two = { 0 };
//	printf("%d\n", sizeof(one));//12
//	printf("%d\n", sizeof(two));//8   student1和2的成员一摸一样，但所占总空间还是有些区别的 让占用空间小的尽量集中在一起
//	return 0;
//}
/*
   为什么存在内存对齐？
   1.平台原因：不是所有的硬件可以访问任意地址的数据；某些硬件只能只能获取特定的数据，否则硬件会出现异常
   2.性能原因：访问未对齐需要两次访问，访问对齐需要一次就可以了
   总的来说：结构体对齐就是用空间来换取时间的做法
*/

//修改默认对齐数  和 offsetof(计算变量在首地址的偏移)宏  模拟实现offsetof
//#include<stdio.h>
//#include <stddef.h>//offsetof头文件
////#pragma pack(2)//修改默认对齐数为8
//struct student1
//{
//	char one;
//	int two;
//	char three;
//};
////#pragma pack()//修改回来
//
//#define OFFSETOF(struct_name,member_name)     (int*)&(((struct_name*)0)->member_name)
//
//int main() {
//	//printf("%d\n", sizeof(struct student1));//8
//	//printf("%d\n", offsetof/*小写给人误以为是函数*/(struct student1, one));
//	//printf("%d\n", offsetof(struct student1, two));
//	//printf("%d\n", offsetof(struct student1, three));
//
//    printf("%d\n", OFFSETOF(struct student1, one));
//    printf("%d\n", OFFSETOF(struct student1, two));
//    printf("%d\n", OFFSETOF(struct student1, three));
//
//	return 0;
//}

/*4.位段 
    1.成员：int   ；  unsigned int  ；signed  int； char 
    2.位段成员名后边有一个冒号和数字
    3.位段的空间是按照4个字节（int）或者1个字节（char）来开辟的

    4.位段不跨平台的：第一int位段当作有符号还是无符号不确定
                     第二位段最大数目不确定（16位机器最大16，32位机器32）
                     第三位段的成员从左向右分配还是从右向左分配尚未定义
                     第四：当一个结构有两个位段，第二个位段比较大，无法容纳第一个位段剩余位时，是舍弃还是利用不确定
    

*/
//#include<stdio.h>
//struct word
//{
//    int a : 2;//成员a占2个bit位
//    int b : 5;//成员b占5个bit位
//    int c : 30;//成员c占30个bit位
//};
//int main() {
//    printf("%d\n", sizeof(struct word));
//    return 0;
//}
//位段可以更好的节省空间，但有跨平台的问题

/*  枚举的优点：
             1.增加代码的可读性和维护性
             2.有类型检查，更为严谨
             3.便于调试
             4.使用方便，一次可定义多个变量

*/
//enum Color
//{
//    RED,
//    GREEN,
//    BLUE,
//
//};
//#include<stdio.h>
//int main() {
//    enum Color one = BLUE;
//    printf("%d\n", RED);
//    printf("%d\n", GREEN);
//    printf("%d\n", sizeof(one));
//    return 0;
//}


//联合体（共用体）  特征是 公用同一块空间
//union body
//{
//    char one;
//    int two;
//}u;
//#include<stdio.h>
//int BigSmall() {
//    u.two = 1;
//    return u.one;
//}
//int main() {
//    //union body test;
//    //printf("%d\n", sizeof(test));//打印结果是4
//
//    //printf("%p\n", &test);
//    //printf("%p\n", &(test.one));
//    //printf("%p\n", &(test.two));//地址一样
//
//    int number = BigSmall();
//    if (number == 1) {
//        printf("小端存储\n");
//    }
//    else {
//        printf("大端存储\n");
//    }
//    return 0;
//}
//联合体大小计算  联合体的大小至少为最大成员的大小 ， 当最大成员大小不是最大对齐数的倍数时，要对齐到最大对齐数的倍数


/*
    写一个通讯录  1.可以存放1000个人信息（名字+性别+年龄+电话+地址） 2.增删查改
    AddressBook.h 函数声明    
    AddressBook.c 函数定义
    源.c 通讯录模板
*/
//通讯录--静态版本
//#include"AddressBook.h"
////通讯录--动态版本  1.通讯录初始化后，能存放三个人信息  放满后可以增加两个人信息
//void menu()
//{
//    printf("############ 1.ADD  #############\n");
//    printf("############ 2.DEL  #############\n");
//    printf("############3.SEARCH#############\n");
//    printf("############4.REVIES#############\n");
//    printf("############5.PRINTF#############\n");
//    printf("############ 0.QUIT #############\n");
//}
//enum Options
//{
//    QUIT,
//    ADD,
//    DEL,
//    SEARCH,
//    REVIES,
//    PRINTF
//};
//int main()
//{
//    int input = 0;
//    AddressBook  ab;//创建通讯录
//    InitializationAddressBook(&ab);//初始化通讯录
//    do {
//        menu();
//        printf("请选择:->\n");
//        scanf("%d", &input);
//        switch (input)
//        {
//        case ADD:
//            //增加人的信息
//            AddPerson(&ab);
//            break;
//        case DEL:
//            //删除
//            DelPerson(&ab);
//            break;
//        case SEARCH:
//            //查找
//            SearchPerson(&ab);
//            break;
//        case REVIES:
//            //修改
//            ReviesPerson(&ab);
//            break;
//        case PRINTF:
//            //打印
//            PrintfPerson(&ab);
//            break;
//        case QUIT:
//            SavePerson(&ab);//保存信息
//            FreePerson(&ab);//动态释放空间
//            printf("退出通讯录\n");
//            break;
//        default:
//            printf("选择错误，请重新选择\n");
//            break;
//        }
//    } while (input);
//    return 0;
//}


//-------------动态内存分配（比固态更灵活，动态内存开辟在堆区）

//malloc
//#include<stdio.h>
//#include<stdlib.h>//malloc(开辟空间值未被初始化) ,calloc（值被初始化）和realloc（动态内存空间调整）头文件
//int main() {
//    //int array[10] = { 0 };//栈区开辟的10个整形空间
//    //int* point = (int*)malloc(10 * sizeof(int));//动态内存开辟  因为malloc返回类型是void*所以强制类型转换
//    //int* point1 = (int*)realloc(NULL, 40);//这个类似与malloc，直接开辟四十个字节
//    int* point = (int*)calloc(10, sizeof(int));
//
//    if (point == NULL) {//开辟失败返回空指针  所以malloc的返回值要做检查
//         //常见的动态内存错误：1.对NULL指针解引用操作
//        perror("main");
//        return 0;
//    }
//
//    //使用
//    int frequency = 0;
//    for (frequency = 0; frequency < 10; frequency++) { //常见的动态内存错误：2.对动态内存空间的越界访问
//        printf("%d \n", point[frequency]);
//        *(point + frequency) = frequency;
//        printf("%d ", point[frequency]);
//        
//    }
//
//    //调整空间  再加点
//    int* start = realloc(point, 10 * sizeof(int));//realloc返回值为调整之后的内存地址（后面有足够的空间直接追加，原来数据不发生变化；如果没有足够的空间，则找一个可以装下的，返回一个新的内存地址）
//    if (start != NULL) {//调整失败返回空指针
//        point = start;
//    }
//  
//    //回收
//    free(point);//malloc和free成对出现  free如果参数是NULL，则函数什么事情都不做
//     //常见的动态内存错误：3.free释放非动态开辟空间或只是放一部分（动态开辟的的指针往后走，释放指针之后的动态空间）；对同一块动态开辟的空间多次释放或忘记释放（内存泄漏）
//     //动态开辟的空间，两种回收方式（1.主动释放2.程序结束）
//    point = NULL;//手动置为空指针
//    return 0;
//}

//温馨提示：静态库又叫数据段   常量放在代码段

//柔性数组（C99 结构体最后一个成员是未知大小的数组） 柔性数组前面必须至少有一个成员
//#include<stdio.h>
//#include<stdlib.h>
//struct test
//{
//    int number;
//    //int array[];//大小是未知
//    int array[0];//也可以写成这样
//    
//};
//int main()
//{
//    //printf("%d\n", sizeof(struct test));// 结果是4  sizeof不计算柔性数组的内存
//
//    struct test* point = (struct test*)malloc(sizeof(struct test) + 10 * sizeof(int));
//    point->number = 10;
//    int frequency = 0;
//    for (frequency = 0; frequency < 10; frequency++) {
//        point->array[frequency] = frequency;
//    }
//    struct test* point1 = (struct test*)realloc(point,sizeof(struct test) + 20 * sizeof(int));
//    if (point1 != NULL) {
//        point = point1;
//    }
//    free(point);
//    point = NULL;
//    return 0;
//}
    

//牛刀小试
//1.打印X型图案
//#include<stdio.h>
//int main()
//{
//    int number = 0;
//    while (scanf("%d", &number) != EOF) {
//        int frequency1 = 0;
//        for (frequency1 = 0; frequency1 < number; frequency1++) {
//            int frequency2 = 0;
//            for (frequency2 = 0; frequency2 < number; frequency2++) {
//                if (frequency1 == frequency2) {
//                    printf("*");
//                }
//                else if (frequency1 + frequency2 == number - 1) {
//                    printf("*");
//                }
//                else {
//                    printf(" ");
//                }
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//2.获取月份天数
//#include<stdio.h>
//int main()
//{
//    int year = 0;
//    int month = 0;
//    int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31 };
//    while (scanf("%d %d", &year, &month) != EOF) {
//        int day = days[month];
//        if (month == 2) {
//            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
//                day ++;
//            }
//        }
//        printf("%d\n", day);
//    }
//    return 0;
//}

//3.五科成绩去掉最高和最低求每科平均值
//#include<stdio.h>
//int main()
//{
//    int sum = 0;
//    int score = 0;
//    int frequency = 0;
//    int max = 0;
//    int min = 100;
//    for (frequency = 0; frequency < 7; frequency++) {
//        scanf("%d", &score);
//        sum += score;
//        if (score > max) {
//            max = score;
//        }
//        if (score < min) {
//            min = score;
//        }
//    }
//    printf("%2f\n", (sum - min - max) / 5.0);
//    return 0;
//}

//4.一个升序数列，插入一个数，仍是升序
//#include<stdio.h>
//int main()
//{
//    int array[51] = { 0 };
//    int number = 0;
//    //输入数据
//    scanf("%d", &number);
//    int frequency = 0;
//    for (frequency = 0; frequency < number; frequency++) {
//        scanf("%d", &array[frequency]);
//    }
//    //输入要插入的数据
//    int insert_number = 0;
//    scanf("%d", &insert_number);
//    for (frequency = number - 1; frequency >= 0; frequency--) {
//        if (array[frequency] > insert_number) {
//            array[frequency + 1] = array[frequency];
//        }
//        else {
//            array[frequency + 1] = insert_number;
//            break;
//        }
//    }
//    if (frequency < 0) {
//        array[0] = insert_number;
//    }
//    //输出
//    for (frequency = 0; frequency < number + 1; frequency++) {
//        printf("%d ", array[frequency]);
//    }
//    return 0;
//}

//5.将一个数的二进制位的奇数和偶数位的交换
//#include<stdio.h>
//int main()
//{
//    int number = 10;
//    int middle = ((number & 0xaaaaaaaa) >> 1) + ((number & 0x55555555) << 1);
//    printf("%d\n", middle);
//    return 0;
//}

/*  
    文件：将数据放在电脑硬盘上，做到数据持久化
     磁盘上的文件是文件；在程序设计中有两种（1.程序文件（源程序文件.c）（目标文件.obj）(可执行程序.exe)2.数据文件：程序运行时读写的数据）
     文件名：c:\code(<-文件路径)\test（<-文件主干名）.txt（文件后缀）
     一般来说通过FILE的指针来维护FILE结构的变量（文件信息区），定义pf是一个指向FILE类型数据的指针变量，通过文件信息区中的信息来访问该文件
     文件读写之前应先打开文件（fopen），使用结束后应关闭文件（fclose）

*/
//#include<stdio.h>
//struct student
//{
//    int age;
//    char name[20];
//};
//int main()
//{
//    char array[20] = { 0 };
//    struct student one = { 18,"aoteman" };
//    struct student two = { 0 };
//
//    //打开文件
//    //FILE* pf = fopen("D:\\ShiWeiGeng\\新建文件夹 (11)\\VsCode\\Project1\\test.txt", "r");//绝对路径
//    FILE* pf = fopen("test.txt", "r");//相对路径
//    if (pf == NULL) {
//        perror("fopen");
//        return 1;
//    }
//
//    //写文件  -------------------------
//    
//    //流（水流）：高度抽象的概念；屏幕，硬盘，U盘，光盘，软盘每个都有自己的读写规则，所以为了降低门槛，用流来进行读写
//    //其实C语言程序，只要运行，就默认打开了3个流   stdin（标准输入流->键盘),stdout(标准输出流->屏幕),stderr(标准错误流->屏幕)
//    
//    //1.字符输出函数	fputc	所有输出流
//    /*fputc('h', pf);
//    fputc('e', pf);
//    fputc('l', pf);
//    fputc('l', pf);
//    fputc('o', pf);*/
//
//    /*fputc('h', stdout);//从屏幕上写入
//    fputc('e', stdout);
//    fputc('l', stdout);
//    fputc('l', stdout);
//    fputc('o', stdout);*/
//
//    //2.文本行输出函数	fputs	所有输出流
//    /*fputs("abcdefg\n", pf);
//    fputs("hijklmn\n", pf);*/
//
//    //3.格式化输出函数	fprintf	所有输出流
//    /*fprintf(pf, "%d %s", one.age, one.name);*/
//    //fprintf写成printf -> fprintf(stdout, "%d %s", one.age, one.name)   参数不同功能不同
//
//    //4.二进制输出	fwrite	文件
//    //fwrite(&one, sizeof(struct student), 1, pf);//字符串用二进制写进去和文本写进去一样
//
//    //读文件---------------------------
//
//    //1.字符输入函数	fgetc	所有输入流  //文件结束或遇到错误会返回EOF
//    /*int number=fgetc(pf);
//    printf("%c\n", number);
//    number = fgetc(pf);
//    printf("%c\n", number);
//    number = fgetc(pf);
//    printf("%c\n", number);*/
//
//    /*int number = fgetc(stdin);//从键盘上读取
//    printf("%c\n", number);
//    number = fgetc(stdin);
//    printf("%c\n", number);
//    number = fgetc(stdin);
//    printf("%c\n", number);*/
//
//    //2.文本行输入函数	fgets	所有输入流
//    //fgets(array, 4, pf);//读取3个，另外一个放\0
//    //printf("%s\n", array);
//    //fgets(array, 4, pf);
//    //printf("%s\n", array);
//
//    //3.格式化输入函数	fscanf	所有输入流
//    /*fscanf(pf, "%d %s", &(two.age), two.name);
//    //fscanf写成scanf-> fscanf(stdin, "%d %s", &(two.age), two.name);
//    printf("%d %s\n", two.age, two.name);*/
//
//    //4.二进制输入	fread	文件
//    /*fread(&two, sizeof(struct student), 1, pf);
//    printf("%d %s\n", two.age, two.name);*/
//
//    //文件的随机读写--------------------------------------------
//    
//    //  1.  fseek根据文件指针的位置和偏移来定位文件指针
//    //  2.ftell返回文件指针起始位置的偏移量
//
//    fseek(pf, 2, SEEK_CUR);//  SEEK_CUR  当前位置   ； SEEK_END  最后位置  ； SEEK_SET  最前位置
//    int number = fgetc(pf);
//    printf("%c\n", number);
//    int number1 = ftell(pf);
//    printf("%c\n", number);
//
//    fseek(pf, -2, SEEK_END);
//    number = fgetc(pf);
//    printf("%c\n", number);
//    number1 = ftell(pf);
//    printf("%c\n", number);
//
//    fseek(pf, 2, SEEK_SET);
//    number = fgetc(pf);
//    printf("%c\n", number);
//    number1 = ftell(pf);
//    printf("%c\n", number);
//
//    //  3.rewind文件指针的位置返回到起始位置
//
//    rewind(pf);
//    number = fgetc(pf);
//    printf("%c\n", number);
//
//
//    //关闭文件-------------------------------
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}//      内存程序   (输入/读取）<----------------------------->（输出/写入）  文件（硬盘）


//sprintf  和sscanf
//struct student
//{
//    char name[20];
//    int age;
//    char gender[10];
//};
//#include<stdio.h>
//int main()
//{
//    struct student one = { "aoteman",18,"weizhi" };
//    struct student middle1 = { 0 };
//    char middle2[100] = { 0 };
//
//    //把一个格式化的数据转化为字符串
//    sprintf(middle2, "%s %d %s", one.name, one.age, one.gender);
//    printf("%s\n", middle2);
//
//    //从middle2中还原一个结构体数据
//    sscanf(middle2, "%s %d %s", middle1.name, &(middle1.age), middle1.gender);
//    printf("%s %d %s\n", middle1.name, middle1.age, middle1.gender);
//    return 0;
//        
//}

/*  文件相关知识
1. 一组函数对比
    scanf      针对标准输入的格式化输入语句  stdin
    fscanf     针对所有输入流的格式化输入语句  stdin/文件
    sscanf     从一个字符串中读取一个格式化数据

    printf     针对标准输出的格式化输入语句  stdout
    fprintf    针对所有输入流的格式化输入语句  stdout/文件
    sprintf    把一个格式化的数据，转换为字符串


 2. 数据在在内存中以二进制形式存储，不加转换输出到外存，就是二进制文件（数值既可以二进制存储也可以ASCII形式存储）
   外存以ASCII形式存储的文件就是文本文件（字符）

   比如10000这个数字  ASCII形式存储，需要五个字节（每个字符一个字节）；而二进制形式输出，则只要四个字节

 3.文件缓冲区  想磁盘中输出数据先放到文件缓冲区 装满后才一起放到磁盘  提高了效率


 4.文件读取结束判定  feof（在文件读取中，不能用feof函数返回值直接判断文件是否结束，而是判断读取文件结束还是遇到文件结尾结束）

   fgetc函数在读取结束的时候，会返回EOF  ； 正常读取结束后，返回的是读取到字符串的ASCII值

   fgets函数在读取结束的时候，会返回空指针 ； 正常读取结束后，返回字符串空间的起始地址

   fread函数在读取结束后，返回的是实际读取的个数；如果发现读取的个数小于指定的元素个数，这就是最后一次

*/
//#include<stdio.h>
//int main()
//{
//    FILE* pf_read = fopen("test.txt", "r");
//    if (pf_read == NULL) {
//        return 1;
//    }
//    FILE* pf_write = fopen("my_test.txt", "w");
//    if (pf_write == NULL) {
//        //打开这个文件错误，就把上个文件关闭
//        fclose(pf_read);
//        pf_read = NULL;
//        return 1;
//    }
//
//    //文件打开成功 读写文件
//    int middle = 0;
//    while ((middle = fgetc(pf_read)) != EOF) {
//        //读取成功  写文件
//        fputc(middle, pf_write);
//    }
//    
//    if (feof(pf_read)) {//在设置了与流关联的文件结尾指示符的情况下，将返回非零值。否则，将返回零
//        printf("文件正常结束\n");
//    }
//    else if (ferror(pf_read)) {//在设置了与流关联的错误指示器的情况下，将返回非零值。   否则，将返回零。
//        printf("文件读取失败结束\n");
//    }
//
//    //关闭文件
//    fclose(pf_read);
//    pf_read = NULL;
//    fclose(pf_write);
//    pf_write = NULL;
//
//    return 0;
//}

//atoi 和模拟实现atoi(字符串转化为整数)
//#include<stdio.h>
////#include<stdlib.h>//atoi头文件
//#include<assert.h>
//#include<ctype.h>//  isspace  isdigit头文件
//#include<limits.h>//INT_MAX  INT_MIN头文件
//
//enum is_legitimate
//{
//    NOOK,//0  非法
//    OK//1     合法
//};
//
//enum is_legitimate number;//记录my_atoi返回值是否合法
//
//int my_atoi(const char* point) {
//
//    int flag = 1;
//
//    //1.传的空指针
//    /*assert(point != NULL);*/
//    if (point == NULL) {
//        return 0;
//    }
//
//    //2.空字符串
//    if (*point == '\0') {
//        return 0;
//    }
//
//    //3.遇到空白字符
//    while (isspace(*point)) {
//        point++;
//    }
//
//    //4.正负号问题
//    if (*point == '+') {
//        flag = 1;
//        point++;
//    }
//    else if(*point=='-') {
//        flag = -1;
//        point++;
//    }
//
//    //5.处理数字字符
//    long long number1 = 0;
//    while (isdigit(*point)) {
//        number1 = number1 * 10 + flag*(*point - '0');
//        if (number1 > INT_MAX || number1 < INT_MIN) {//预防超出范围
//            return 0;
//        }
//        point++;
//    }
//
//    if (*point == '\0') {
//        number = OK;
//        return (int)number1;
//    }
//    else {
//        //非数字字符
//        return 0;
//    }
//
//}
//int main()
//{
//    const char* point = "  120";
//    int middle = my_atoi(point);
//    if (number == OK) {
//        printf("正常的转换：%d\n", middle);
//    }
//    else {
//        printf("非法转换\n");
//    }
//    
//    return 0;
//}

//找出数组只出现一次的数字
//#include<stdio.h>
//void Find(int array[], int size, int* number1, int* number2)
//{
//
//    //1.把所有数据异或
//    int frequency = 0;
//    int middle = 0;
//    for (frequency = 0; frequency < size; frequency++) {
//        middle ^= array[frequency];
//    }
//
//    //2.计算middle的哪一位为1
//    int find = 0;
//    for (frequency < 0; frequency < 32; frequency++)
//    {
//        if (((middle >> frequency) & 1) == 1) {
//            find = frequency;
//            break;
//        }
//    }
//
//    //3.在find位为1的放在一个组，为0的放在一个组
//    int one = 0;
//    int two = 0;
//    for (frequency = 0; frequency < size; frequency++) {
//        if (((array[frequency] >> find) & 1) == 1) {
//            one ^= array[frequency];
//        }
//        else {
//            two ^= array[frequency];
//        }
//    }
//    *number1 = one;
//    *number2 = two;
//}
//int main()
//{
//    int array[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4 };
//    int size = sizeof(array) / sizeof(array[0]);
//    int number1 = 0;
//    int number2 = 0;
//    Find(array, size, &number1, &number2);
//    printf("%d %d\n", number1, number2);
//    return 0;
//}

/*--------------------------预处理（最后的倔强）--------------------------------

    1.   .c文件到.exe文件（一个.c文件通过编译器转换为.obj文件，然后通过链接器（链接库，也可以说成静态库））弄成可执行程序，通过运行环境，获取运行结果

    2.     翻译环境
           
           编译器分为预处理，编译和汇编三个成分
           预处理（预编译）：第一完成头文件的包含；
                  第二#define定义的宏和符号的替换；
                  第三注释删除；
                  这些都是文本操作
           编译：把C语言代码转换为汇编代码（1.语法分析
                                         2.词义分析
                                         3.语义分析
                                         4.符号汇总）
           汇编：将汇编代码转换成了二进制指令（机器指令） 生成了符号表

           链接器：把多个目标的头文件进行链接（1.合并段表
                                            2.符号表的合并和重定位）
            
            运行坏境1.程序必须载入内存中，一般由操作系统来完成。在独立坏境中，程序的载入必须手工完成或通过可执行代码完成
                    2.程序执行开始从main函数开始
                    3.系统分配内存空间
                    4.终止程序（正常从main终止或意外终止）
*/

//1.预定义符号
//#include<stdio.h>
//int main()
//{
//    //printf("%s\n", __FILE__);//进行编辑的源文件
//    //printf("%d\n", __LINE__);//文件当前行号
//    //printf("%s\n", __DATE__);//文件被编译的日期
//    //printf("%s\n", __TIME__);//文件被编译的时间
//    //printf("%s\n", __FUNCTION__);//文件被编译的函数名
//    
//    //正确用法--写日记
//    FILE* pf = fopen("test.txt", "a+");//追加数据
//    if (pf == NULL) {
//        perror("fopen\n");
//        return 1;
//    }
//
//    int frequency = 0;
//    for (frequency = 0; frequency < 10; frequency++) {
//        fprintf(pf, "%d : %s %d %s %s \n", frequency, __FILE__, __LINE__, __DATE__, __TIME__);
//    }
//
//    fclose(pf);
//    pf = NULL;
//
//    return 0;
//}

//2.#define定义标识符骚操作   
//#include<stdio.h>
//#define CASE break;case
//#define NUMBER 100  
//int main()
//{
//    
//    int frequency = 0;
//    switch (scanf("%d", &frequency)) {
//    case1:
//        CASE 2 :
//            CASE 3 :
//            break;
//
//    }
//#undef NUMBER//移除宏定义
//    //printf("%d\n", NUMBER);//出错
//    return 0;
//}

//3. #（替换变量名为字符串）和##（将两个符号链接在一起）
//#include<stdio.h>
//#define PRINTF(accept) printf("this letter "#accept" value is%d\n",accept);
//#define LINK(one,two) one##two
//int main()
//{
//    //printf("1.helloworld\n");
//    //printf("2.hello""world\n");//1. 和 2.打印效果相同 
//
//    int number1 = 10;
//    ////打印  this letter number1  value is  10
//    //PRINTF(number1);//  #accept 表示"number1"
//
//    printf("%d\n", LINK(numbe, r1));
//    return 0;
//}


/*5.宏和函数区别（宏有的地方和函数和相似  C语言也没有区分两者  我们习惯宏全部大写，函数不要全部大写）

   //优点：1.简单的运算中 ； 宏比函数在程序的规模和速度更胜一筹
           2.函数参数是固定类型  ；而宏的参数和类型无关

   //缺点：1.每次使用宏，一部分宏代码就会插入到程序中，增加了程序的长度；而函数代码只出现一个地方，每次调用会调用那个地方同一份代码
           2.宏不能调试
           3.宏由于类型无关，也会不够严谨，可能还会有优先级的问题
           4.宏不可以递归（宏只做简单的文本替换，且只替换一次，如果出现递归定义，就会无法被完全替换，导致后续编译时原宏名被当作函数）  而函数可以

*/

//6.条件编译（可以嵌套）  调试型代码，删了可惜，不删碍事，所以我们可以选择性编译   
//#include<stdio.h>
//#define NUMBER 
//int main()
//{
//
////#if 1-2 //if  常量表达式
////    printf("有这个数字");
////#endif
//
//    //如果NUMBER定义了，下面参与编译
////#ifdef NUMBER
////    printf("有这个数字\n");
////#endif
////
////#if defined NUMBER
////    printf("有这个数字\n");
////#endif
//
//
//    //如果NUMBER没定义，下面参与编译
//#ifndef NUMBER
//    printf("这个数字没定义\n");
//#endif
//
//#if !defined NUMBER
//    printf("这个数字没定义\n");
//#endif
//
//#if 1==2
//    printf("第一个执行\n");//第一个为真  第二个即使为真也不执行
//#elif 2==3
//    printf("第二个执行\n");
//#else
//    printf("第三个执行\n");
//#endif
//    return 0;
//}

//7.文件包含
/*    
      " " 和 < >包含头文件的本质区别是：查找策略不同  
      " " 1.先从自己代码所在的目录查找 2.如果1找不到，则在库函数的头文件目录查找
      < > 直接去库函数头文件所在的目录下查找

      嵌套文件包含   同一个头文件被重复多次包含（意味这代码被拷贝多份，代码冗余）  如何防止呢？
                    1. #pragma once
                    2. #ifndef __AddressBook_H__
                       #define __AddressBook_H__
                       #endif
*/
#include<stdio.h>//库文件包含，C语言库中提供的函数   <>
#ifndef __AddressBook_H__
#define __AddressBook_H__
#include"stdio.h"//本地文件包含，自定义的函数使用  ""  //这样效率有点低了
int main()
{  
    printf("HelloWorld\n");
    return 0;
}
#endif

