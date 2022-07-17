#define _CRT_SECURE_NO_WARNINGS
//#include "game.h"
//
//void InitialiseChessBoard(char ChessBoard[ROW1][ROW2],int row1,int row2) {
//	int frequency_1 = 0;
//	int frequency_2 = 0;
//	for (frequency_1 = 0; frequency_1 < row1; frequency_1++) {
//		for (frequency_2 = 0; frequency_2 < row2; frequency_2++) {
//			ChessBoard[frequency_1][frequency_2] =' ';
//		}
//	}
//}
//
//
//void PrintfChessBoard(char ChessBoard[ROW1][ROW2], int row1, int row2) {
//	int frequency_1 = 0;
//	
//	for (frequency_1 = 0; frequency_1 < row1; frequency_1++) {
//		int frequency_2 = 0;
//		for (frequency_2 = 0; frequency_2 < row2; frequency_2++) {
//			printf(" %c ", ChessBoard[frequency_1][frequency_2]);
//			if (frequency_2 < row2 - 1) {
//				printf("|");
//			}
//		}
//		printf("\n");
//		if (frequency_1 < row1 - 1) {
//			int frequency_3 = 0;
//			for (frequency_3 = 0; frequency_3 < row2; frequency_3++) {
//				printf("---");
//				if (frequency_3 < row2 - 1) {
//					printf("|");
//				}
//			}
//			printf("\n");
//		}
//	}
//}
//
//void gamer(char ChessBoard[ROW1][ROW2], int row1, int row2) {
//	int number1 = 0;
//	int number2 = 0;
//	printf("������ж�->\n");
//	while (1) {
//		scanf("%d %d", &number1, &number2);
//		if (number1 >= 1 && number1 <= row1 && number2 >= 1 && number2 <= row2) {
//			if (ChessBoard[number1 - 1][number2 - 1] == ' ') {
//				ChessBoard[number1 - 1][number2 - 1] = 'V';
//				break;
//			}
//			else {
//				printf("���걻ռ�ã�����������\n");
//			}
//		}
//		else {
//			printf("����Ƿ�������������\n");
//		}
//	}
//}
//
//void Compter(char ChessBoard[ROW1][ROW2], int row1, int row2) {
//	printf("�����ж�->\n");
//	while (1){
//		
//		int number1 = rand() % row1;
//		int number2 = rand() % row2;
//		if (ChessBoard[number1][number2] == ' ') {
//			ChessBoard[number1][number2] = 'X';
//			break;
//		}
//	}
//}
//
//
//int IsFull(char ChessBoard[ROW1][ROW2], int row1, int row2) {
//	int frequency = 0;
//	int frequency1 = 0;
//	for (frequency = 0; frequency < row1; frequency++) {
//		for (frequency1 = 0; frequency1 < row2; frequency1++) {
//			if (ChessBoard[frequency][frequency1] == ' ') {
//				return 0;
//			}
//		}
//	}
//	return 1;
//}
//
//char IsWin(char ChessBoard[ROW1][ROW2], int row1, int row2) {
//	int frequency = 0;
//	for (frequency = 0; frequency < row1; frequency++) {//�ж�3��
//		if (ChessBoard[frequency][0] == ChessBoard[frequency][1] && ChessBoard[frequency][0] == ChessBoard[frequency][2] && ChessBoard[frequency][0] != ' ') {
//			return ChessBoard[frequency][0];
//		}
//	}
//	for (frequency = 0; frequency < row1; frequency++) {//�ж�3��
//		if (ChessBoard[0][frequency] == ChessBoard[1][frequency] && ChessBoard[1][frequency] == ChessBoard[2][frequency] && ChessBoard[1][frequency] != ' ') {
//			return ChessBoard[0][frequency];
//		}
//	}
//	//�ж϶Խ���
//	if (ChessBoard[0][0] == ChessBoard[1][1] && ChessBoard[0][0] == ChessBoard[2][2] && ChessBoard[1][1] != ' ') {
//		return ChessBoard[0][0];
//	}
//	if (ChessBoard[0][2] == ChessBoard[1][1] && ChessBoard[0][2] == ChessBoard[2][0] && ChessBoard[1][1] != ' ') {
//		return ChessBoard[0][2];
//	}
//	//�ж�ƽ��
//	int same = IsFull(ChessBoard, row1, row2);
//	if (same == 1) {
//		return '=';
//	}
//	else {//����
//		return 'C';
//	}
//}

//-------------------------ɨ��-----------------------------------
//#include "game.h"
//
//void InitialiseChessBoard(char group[ROWS1][ROWS2], int rows1, int rows2, char set) {
//	int frequency1 = 0;
//	int frequency2 = 0;
//	for (frequency1 = 0; frequency1 < ROWS1; frequency1++) {
//		for (frequency2 = 0; frequency2 < ROWS2; frequency2++) {
//			group[frequency1][frequency2] = set;
//		}
//	}
//}
//
//void PrintfChessBoard(char group[ROWS1][ROWS2], int row1, int row2) {
//	int frequency1 = 1;
//	int frequency2 = 1;
//	printf("-----------ɨ����Ϸ-------------\n");
//	for (frequency1 = 0; frequency1 <= ROW2; frequency1++) {//��ӡ�������
//		printf("%d ", frequency1);
//	}
//	printf("\n");//����
//	for (frequency1 = 1; frequency1 <= ROW1; frequency1++) {
//		printf("%d ", frequency1);//��ӡ�������
//		for (frequency2 = 1; frequency2 <= ROW2; frequency2++) {
//			printf("%c ", group[frequency1][frequency2]);
//		}
//		printf("\n");
//	}
//	printf("-----------ɨ����Ϸ-------------\n");
//}
//
//void Set(char Minefield[ROWS1][ROWS2], int row1, int row2) {
//	int count = YourMinefield;
//	while (count) {
//		int number1 = rand() % row1 + 1;
//		int number2 = rand() % row2 + 1;
//		if (Minefield[number1][number2] == '0') {
//			Minefield[number1][number2] = '1';
//			count--;
//		}
//	}
//}
//
//
//static int MinefieldNumber(char Minefield[ROWS1][ROWS2], int number1, int number2) {//�������ֻ��Ϊ��ʵ��Find����
//	return Minefield[number1 - 1][number2] +
//		Minefield[number1 - 1][number2 - 1] +
//		Minefield[number1][number2 - 1] +
//		Minefield[number1 + 1][number2 - 1] +
//		Minefield[number1 + 1][number2] +
//		Minefield[number1 + 1][number2 + 1] +
//		Minefield[number1][number2 + 1] +
//		Minefield[number1 - 1][number2 + 1] - 8 * '0';
//	/* ѭ����ʽȥд     for��number3 = -1;number3<=1;number3++��{
//							for��number4 = -1;number4<=1;number4++��{
//							��ӡMinefield[number1+number3][number2+number4];
//							}
//					   }
//	*/
//}
//
//void FindWin(char Minefield[ROWS1][ROWS2], char Show[ROWS1][ROWS2], int row1, int row2) {
//	int number1 = 0;
//	int number2 = 0;
//	int win = 0;
//	while (win < row1 * row2 - YourMinefield) {
//		printf("�������Ų��׵�����>");
//		scanf("%d%d", &number1, &number2);
//		if (number1 >= 1 && number1 <= row1 && number2 >= 1 && number2 <= row2) {//�ж�����Ϸ���
//			if (Minefield[number1][number2] == '1') {
//				printf("��Ǹ��������������\n");
//				PrintfChessBoard(Minefield, ROW1, ROW2);
//				break;
//			}
//			else {
//				int count = MinefieldNumber(Minefield, number1, number2);
//				Show[number1][number2] = count + '0';
//				PrintfChessBoard(Minefield, ROW1, ROW2);//��ʾ�Ų����Ϣ
//				win++;
//			}
//		}
//		else {
//			printf("���겻�Ϸ�,����������\n");
//		}
//	}
//	if (win == row1 * row2 - YourMinefield) {
//		printf("��ϲ�㣬ɨ���ϰ������׳ɹ�\n");
//		PrintfChessBoard(Minefield, ROW1, ROW2);
//	}
//}


