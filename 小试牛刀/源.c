#define _CRT_SECURE_NO_WARNINGS

//求1/1-1/2+1/3....+1/99-1/100的和
// 第一种写法
//#include<stdio.h>
//int main() {
//	int frequency = 0;
//	double sum = 0.0;
//	for (frequency = 1; frequency <= 100; frequency++) {
//		if (frequency % 2 == 0) {
//			sum -= 1.0 / frequency;
//		}else{
//			sum += 1.0 / frequency;
//		}
//
//	}
//	printf("总和为=%lf\n", sum);
//	return 0;
//}
//第二种写法
//#include<stdio.h>
//int main() {
//	int frequency = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (frequency = 1; frequency <= 100; frequency++) {
//		sum += flag*1.0 / frequency;
//		flag = -flag;
//	}
//	printf("%lf", sum);
//	return 0;
//}

//求十个整数最大值
//#include<stdio.h>
//int main() {
//	int group[10] = { -1,5, 3, 2, 1, 4, 6, 8, 9, -3 };
//	int max = group[0];
//	int frequency = 0;
//	for (frequency = 1; frequency < 10; frequency++) {
//		if (group[frequency] > max) {
//			max = group[frequency];
//		}
//	}
//	printf("最大值=%d\n", max);
//	return 0;
//}

//乘法口诀表
//#include<stdio.h>
//int main()
//{
//	int number_1 = 1;
//	int number_2 = 1;
//	for (number_1 = 1; number_1 <= 9; number_1++) {
//		for (number_2 = 1; number_2 <= 9; number_2++) {
//			printf("%d*%d=%-2d ", number_1, number_2, number_1 * number_2);//  %2d表示输入2位整型数，不够两位右对齐； -2d左对齐
//		//  %5.2f则表示宽度为5的浮点数，整数位3为，小数位2位，不够5则右对齐    %5s则表示位5个字符的字符串
//		}
//		printf("\n");
//	}
//	return 0;
//}

//字符串逆序（非递归实现）
//#include<stdio.h>
// #include<string.h>
//void Swap(char* group) {
//	int left = 0;
//	int right = strlen(group) - 1;
///*
//    strlen模拟实现
//int my_strlen(char*group){
//       int count = 0;
//	   while(*group != '/0'){
//	   count++;
//	   group++;
//	   }
//	   return count;
//}	*/
//	while (left < right) {
//		char swap = group[left];//   *(group + left)
//		group[left] = group[right];//  *(gorup + left) = *(group + right);
//		group[right] = swap;
//		left++;
//		right--;
//	}
//}
//int main() {
//	char group[] = "helloworld";
//	Swap(group);
//	printf("%s\n", group);
//	return 0;
//}
//递归实现
//#include<stdio.h>
//#include<string.h>
//void Swap(char* group) {
//	char first_number = *group;//第一步
//	int right = strlen(group) - 1;
//	*group = *(group + right);//第二步
//	*(group + right) = '\0';//第三步
//	if (strlen(group + 1) >= 2) {
//		Swap(group + 1);
//	}
//	*(group + right) = first_number;
//}
//int main() {
//	char group[] = "helloworlld";
//	Swap(group);
//	printf("%s\n", group);
//	return 0;
//}


/*------------ - 三子棋实现(还可以优化)-------------------------------------- -
    源.c    游戏逻辑的实现
    game.c  游戏相关函数的实现
    game.h  游戏相关的函数声明、符号声明、头文件的包含
*/
//#include"game.h"
//void menu() {
//    printf("##########################\n");
//    printf("#####1. 五子棋 ############\n");
//    printf("#####0. 退出游戏 ##########\n");
//    printf("##########################\n");
//}
//void game() {
//    char ChessBoard[ROW1][ROW2];//存储数据  二维数组
//    InitialiseChessBoard(ChessBoard, ROW1, ROW2);//初始化棋盘
//    PrintfChessBoard(ChessBoard, ROW1, ROW2);//打印棋盘
//    char win = 0;//游戏的状态
//    while (1) {
//        //玩家下棋
//        gamer(ChessBoard, ROW1, ROW2);
//        PrintfChessBoard(ChessBoard, ROW1, ROW2);
//        //判断玩家是否赢得胜利
//        win = IsWin(ChessBoard, ROW1, ROW2);
//        if (win != 'C') {
//            break;
//        }
//        //电脑下棋
//        Compter(ChessBoard, ROW1, ROW2);
//        PrintfChessBoard(ChessBoard, ROW1, ROW2);
//        //判断电脑是否赢得胜利
//        win = IsWin(ChessBoard, ROW1, ROW2);
//        if (win != 'C') {
//            break;
//        }
//    }
//    if (win == 'V') {
//        printf("玩家赢了\n");
//    }
//    else if (win == 'X') {
//        printf("电脑赢了\n");
//    }
//    else{
//        printf("旗鼓相当，属实NB\n");
//    }
//    
//    PrintfChessBoard(ChessBoard, ROW1, ROW2);
//}
//
//int main()
//{
//    int input = 0;
//    srand((unsigned int)time(NULL));
//    do {
//        menu();
//        printf("请选择->\n");
//        scanf("%d", &input);
//        switch (input) {
//        case 1:
//            printf("开始游戏\n");
//            game();
//            break;
//        case 0 :
//            printf("退出游戏\n");
//            break;
//        default :
//            printf("选择错误，请重新选择\n");
//            break;
//        }
//
//    } while (input);
//    return 0;
//}


//----------扫雷（还可以优化）------------------------
/*
   源.c游戏逻辑的实现和测试
   game.c游戏函数的实现
   game.h游戏函数的声明和包含
*/
//#include "game.h"
//void menu() {
//    printf("##########################\n");
//    printf("#####1. 扫雷游戏 ##########\n");
//    printf("#####0. 退出游戏 ##########\n");
//    printf("##########################\n");
//}
//void game() {
//    char Minefield[ROWS1][ROWS2] = {0};///雷的信息
//    char Show[ROWS1][ROWS2] = {0};//排查雷的信息
//    InitialiseChessBoard(Minefield, ROWS1, ROWS2,'0');//初始化棋盘
//    InitialiseChessBoard(Show, ROWS1, ROWS2, '*');
//
//    //PrintfChessBoard(Minefield, ROW1, ROW2);
//    //打印棋盘
//    PrintfChessBoard(Show, ROW1, ROW2);
//
//    Set(Minefield, ROW1, ROW2);//布置雷
//    PrintfChessBoard(Minefield, ROW1, ROW2);
//
//    FindWin(Minefield, Show, ROW1, ROW2);//排查雷
//}
//
//int main()
//{
//    int input = 0;
//    srand((unsigned int)time(NULL));
//    do {
//        menu();
//        printf("请选择->\n");
//        scanf("%d", &input);
//        switch (input) {
//        case 1:
//            printf("开始游戏\n");
//            game();
//            break;
//        case 0 :
//            printf("退出游戏\n");
//            break;
//        default :
//            printf("选择错误，请重新选择\n");
//            break;
//        }
//
//    } while (input);
//    return 0;
//}

//汉诺塔问题
//#include<stdio.h>
//void hanoi(int salver, char A, char B, char C) {
//    if (salver == 1) {
//        printf("%d个盘子:%c--->%c\n", salver, A, C);
//    }
//    else {
//        hanoi(salver - 1, A, C,B);//步骤一：将salver-1放到B
//        printf("%d个盘子:%c--->%c\n", salver,A,C);//步骤二：
//        hanoi(salver - 1, B,A,C);//步骤三：将位于B的alver-1移动到C
//    }
//}
//int main() {
//    int salver = 0;
//    printf("请输入盘子个数：");
//    scanf("%d", &salver);
//    hanoi(salver,'A','B','C');
//    return 0;
//
//}

////青蛙跳台阶问题
//一个青蛙一次可以跳1个台阶，也可以一次跳2个台阶，求一个青蛙上一个n级台阶有多少种算法？（一一列出找规律）
#include<stdio.h>
int frog(int number) {
    if (number < 3) {
        return number;
    }
    else {
        return frog(number - 1) + frog(number - 2);
    }
}
int main() {
    int number = 0;
    scanf("%d", &number);
    int ways = frog(number);
    printf("总共方法有%d\n", ways);
    return 0;
}

