#define _CRT_SECURE_NO_WARNINGS

//��1/1-1/2+1/3....+1/99-1/100�ĺ�
// ��һ��д��
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
//	printf("�ܺ�Ϊ=%lf\n", sum);
//	return 0;
//}
//�ڶ���д��
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

//��ʮ���������ֵ
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
//	printf("���ֵ=%d\n", max);
//	return 0;
//}

//�˷��ھ���
//#include<stdio.h>
//int main()
//{
//	int number_1 = 1;
//	int number_2 = 1;
//	for (number_1 = 1; number_1 <= 9; number_1++) {
//		for (number_2 = 1; number_2 <= 9; number_2++) {
//			printf("%d*%d=%-2d ", number_1, number_2, number_1 * number_2);//  %2d��ʾ����2λ��������������λ�Ҷ��룻 -2d�����
//		//  %5.2f���ʾ���Ϊ5�ĸ�����������λ3Ϊ��С��λ2λ������5���Ҷ���    %5s���ʾλ5���ַ����ַ���
//		}
//		printf("\n");
//	}
//	return 0;
//}

//�ַ������򣨷ǵݹ�ʵ�֣�
//#include<stdio.h>
// #include<string.h>
//void Swap(char* group) {
//	int left = 0;
//	int right = strlen(group) - 1;
///*
//    strlenģ��ʵ��
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
//�ݹ�ʵ��
//#include<stdio.h>
//#include<string.h>
//void Swap(char* group) {
//	char first_number = *group;//��һ��
//	int right = strlen(group) - 1;
//	*group = *(group + right);//�ڶ���
//	*(group + right) = '\0';//������
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


/*------------ - ������ʵ��(�������Ż�)-------------------------------------- -
    Դ.c    ��Ϸ�߼���ʵ��
    game.c  ��Ϸ��غ�����ʵ��
    game.h  ��Ϸ��صĺ�������������������ͷ�ļ��İ���
*/
//#include"game.h"
//void menu() {
//    printf("##########################\n");
//    printf("#####1. ������ ############\n");
//    printf("#####0. �˳���Ϸ ##########\n");
//    printf("##########################\n");
//}
//void game() {
//    char ChessBoard[ROW1][ROW2];//�洢����  ��ά����
//    InitialiseChessBoard(ChessBoard, ROW1, ROW2);//��ʼ������
//    PrintfChessBoard(ChessBoard, ROW1, ROW2);//��ӡ����
//    char win = 0;//��Ϸ��״̬
//    while (1) {
//        //�������
//        gamer(ChessBoard, ROW1, ROW2);
//        PrintfChessBoard(ChessBoard, ROW1, ROW2);
//        //�ж�����Ƿ�Ӯ��ʤ��
//        win = IsWin(ChessBoard, ROW1, ROW2);
//        if (win != 'C') {
//            break;
//        }
//        //��������
//        Compter(ChessBoard, ROW1, ROW2);
//        PrintfChessBoard(ChessBoard, ROW1, ROW2);
//        //�жϵ����Ƿ�Ӯ��ʤ��
//        win = IsWin(ChessBoard, ROW1, ROW2);
//        if (win != 'C') {
//            break;
//        }
//    }
//    if (win == 'V') {
//        printf("���Ӯ��\n");
//    }
//    else if (win == 'X') {
//        printf("����Ӯ��\n");
//    }
//    else{
//        printf("����൱����ʵNB\n");
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
//        printf("��ѡ��->\n");
//        scanf("%d", &input);
//        switch (input) {
//        case 1:
//            printf("��ʼ��Ϸ\n");
//            game();
//            break;
//        case 0 :
//            printf("�˳���Ϸ\n");
//            break;
//        default :
//            printf("ѡ�����������ѡ��\n");
//            break;
//        }
//
//    } while (input);
//    return 0;
//}


//----------ɨ�ף��������Ż���------------------------
/*
   Դ.c��Ϸ�߼���ʵ�ֺͲ���
   game.c��Ϸ������ʵ��
   game.h��Ϸ�����������Ͱ���
*/
//#include "game.h"
//void menu() {
//    printf("##########################\n");
//    printf("#####1. ɨ����Ϸ ##########\n");
//    printf("#####0. �˳���Ϸ ##########\n");
//    printf("##########################\n");
//}
//void game() {
//    char Minefield[ROWS1][ROWS2] = {0};///�׵���Ϣ
//    char Show[ROWS1][ROWS2] = {0};//�Ų��׵���Ϣ
//    InitialiseChessBoard(Minefield, ROWS1, ROWS2,'0');//��ʼ������
//    InitialiseChessBoard(Show, ROWS1, ROWS2, '*');
//
//    //PrintfChessBoard(Minefield, ROW1, ROW2);
//    //��ӡ����
//    PrintfChessBoard(Show, ROW1, ROW2);
//
//    Set(Minefield, ROW1, ROW2);//������
//    PrintfChessBoard(Minefield, ROW1, ROW2);
//
//    FindWin(Minefield, Show, ROW1, ROW2);//�Ų���
//}
//
//int main()
//{
//    int input = 0;
//    srand((unsigned int)time(NULL));
//    do {
//        menu();
//        printf("��ѡ��->\n");
//        scanf("%d", &input);
//        switch (input) {
//        case 1:
//            printf("��ʼ��Ϸ\n");
//            game();
//            break;
//        case 0 :
//            printf("�˳���Ϸ\n");
//            break;
//        default :
//            printf("ѡ�����������ѡ��\n");
//            break;
//        }
//
//    } while (input);
//    return 0;
//}

//��ŵ������
//#include<stdio.h>
//void hanoi(int salver, char A, char B, char C) {
//    if (salver == 1) {
//        printf("%d������:%c--->%c\n", salver, A, C);
//    }
//    else {
//        hanoi(salver - 1, A, C,B);//����һ����salver-1�ŵ�B
//        printf("%d������:%c--->%c\n", salver,A,C);//�������
//        hanoi(salver - 1, B,A,C);//����������λ��B��alver-1�ƶ���C
//    }
//}
//int main() {
//    int salver = 0;
//    printf("���������Ӹ�����");
//    scanf("%d", &salver);
//    hanoi(salver,'A','B','C');
//    return 0;
//
//}

////������̨������
//һ������һ�ο�����1��̨�ף�Ҳ����һ����2��̨�ף���һ��������һ��n��̨���ж������㷨����һһ�г��ҹ��ɣ�
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
    printf("�ܹ�������%d\n", ways);
    return 0;
}

