#define _CRT_SECURE_NO_WARNINGS

////��һ�����Լ��(շת�����)  24  18���� �� ���Լ���������18
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
//	printf("���Լ��Ϊ��%d", number_2);
//	return 0;
//}

////��100-200ֱ�ӵ����������� 1 �����������⣬���ܱ��κ���������������
//#include<stdio.h>
//#include<math.h>//sqrt��ƽ������ͷ�ļ�
//int main()
//{
//	int number = 0;
//	int count = 0;
//	//for (number = 100; number <= 200; number++) {
//	for (number = 101; number <= 200; number += 2) {//�Ż�  ż���϶���������
//		int number_1 = 0;
//		int flag = 1;
//		//for (number_1 = 2; number_1 < number; number_1++) {
//		for (number_1 = 2; number_1 <= sqrt(number); number_1++) {
//			//  2 -> number-1�Ƿ��п��Ա�����
//			if (number % number_1 == 0) {
//				flag = 0;
//				break;
//			}
//		}
//		//if (number == number_1) {   // ��һ��д��
//		if (flag == 1) {//�ڶ���д��
//			printf("%d  ", number);//����
//			count++;
//		}
//	}
//	printf("����������%d\n", count);
//	return 0;
//}

// goto����ʹ��   ģ��ʵ��һ�����Զ��ػ�����
//#include<stdio.h>
//#include<stdlib.h>//systemͷ�ļ�
//#include<string.h>//strcmpͷ�ļ�
//int main()
//{
	//char input[20] = { 0 };
	//system("shutdown -s -t 60");//systemִ��ϵͳ����   shutdown�ر�  -s(site)����   -t��time��ʱ��  60(60��)
//again :
	//printf("���ĵ��Խ�60��󱻹���ǿ�ƹػ����������ʱ���Ƿ����Ź⣿\n");
	//scanf("%s", input);
	//if (strcmp(input, "�����Ź�") == 0) {  // strcmp�Ƚ������ַ����Ƿ����
	//	system("shutdown -a");// shutdown -aȡ��
	//}
//	else {
//		goto again;
//	}
//	return 0;
//}
//goto����������������Ƕ��ѭ����breakֻ�ܽ�����ǰѭ����goto����������⣬ѭ��Ҳ���Խ��
//#include<stdio.h>
//#include<stdlib.h>//systemͷ�ļ�
//#include<string.h>//strcmpͷ�ļ�
//int main() {
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");//systemִ��ϵͳ����   shutdown�ر�  -s(site)����   -t��time��ʱ��  60(60��)
//	while (1) {
//		printf("���ĵ��Խ�60��󱻹���ǿ�ƹػ����������ʱ���Ƿ����Ź⣿\n");
//		scanf("%s", input);
//		if (strcmp(input, "�����Ź�") == 0) {  // strcmp�Ƚ������ַ����Ƿ����
//			system("shutdown -a");// shutdown -aȡ��
//			break;
//		}
//	}
//	return 0;
//}
//goto���ֻ���ں����ڲ�ʹ�ã����ܿ纯��


/*
   ����ͽ�һ�º���

   ������Ϊ��1.�⺯����C�����Լ����ĺ�����  2.�Զ��庯��
*/
//#include<stdio.h>
//#include<string.h>//�⺯��  strcpyͷ�ļ�
//int main() {
//	char number[20] = { 0 };
//	char number_1[] = "1314521";
//	strcpy(number, number_1);//strcpy�ַ�������
//	printf("%s\n", number);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>//memsetͷ�ļ�
//int main()
//{
//	char greeting[] = "Hello World";
//	memset(greeting, 'O', 6);//memset�ڴ����ú���
//	printf("%s\n", greeting);
//	return 0;
//}

//�Զ��庯��
//��ֵ��
//#include<stdio.h>
//void Swap(int num1,int num2) {//�βΣ�����������ͻ����٣�
//	int swap = 0;
//	swap = num1;
//	num1 = num2;
//	num2 = swap;
//}
//int main() {
//	int number_1 = 100;
//	int number_2 = 200;
//	printf("����ǰ: number_1=%d number_2=%d\n", number_1,number_2);
//	Swap(number_1, number_2);//ʵ�Σ�ʵ�ʲ�����
//	printf("������: number_1=%d number_2=%d\n",number_1,number_2);
//	return 0;
//}
//��ӡ�����û�дﵽԤ��Ч��  �ҵ���Swap���������´����˿ռ䣬��û����ԭ���ĵ�ַ�ı�  �ı��ββ����ܸı�ʵ��
// �β�ֻ��ʵ�ε�һ����ʱ����
//��ַ��
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
//	printf("����ǰ: number_1=%d number_2=%d\n", number_1, number_2);
//	Swap(&number_1, &number_2);
//	printf("������: number_1=%d number_2=%d\n", number_1, number_2);
//	return 0;
//}
//��ӡ����ﵽ��Ԥ��Ч��   

//������Ƕ�׵��ã�����һ����һ�������Ƶģ�
//#include<stdio.h>
//void TEST() {
//	printf("����\n");
//}
//void test() {
//	TEST();
//}
//int main()
//{
//	test();
//	return 0;
//}

//��������ʽ���ʣ�һ��������Ϊ��һ�������Ĳ�����
//#include<stdio.h>
//#include<string.h>
//int main() {
//	printf("%d\n", strlen("abc"));
//	printf("%d", printf("%d", printf("%d", 1314)));//  printf�������ص��Ǵ�ӡ����Ļ�ַ��ĸ���
//	return 0;
//}

//�����ݹ飨�Լ������Լ���
//һ������ֵ���޷��ţ���˳���ӡ;  ������1234   ��ӡ�� 1 2 3 4 
//#include<stdio.h>
//void Print(int number) {
//	if (number > 9) {//����������������������ʱ�Ͳ�������ݹ�
//		Print(number / 10);
//	}
//	printf("%d ", number % 10);
//	//Խ��Խ�ӽ���������
//}
//int main() {
//	int number = 0;
//	scanf("%d", &number);
//	Print(number);
//	return 0;
//}
//ÿ�εݹ鶼�Ὺ���ռ䣬���ݹ����ʱ��������ջ��������൱��ÿ�θɻ����һЩ�Ѷȣ�����һ�λ���Ϊ̫�Ѷ��겻�ɣ�

//дһ���������ܴ�����ʱ����,���ַ����ĳ��ȣ���ģ��ʵ��һ��strlen��
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
//	printf("%d\n", MY_strlen(group));//���鴫����������Ԫ�ص�ַ
//}

//��n�Ľ׳�
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
//���n��쳲�������Ҳ�ͺܼ���
//#include<stdio.h>
//int count = 0;
//int Number(int number) {
//	if (number == 3) {//number����3�������˶��ٴ�
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
//	printf("count = %d\n", count);//number = 21;count��4181�Σ�Ч��̫����,�ظ���������
//	return 0;
//}
//ѭ����ʽ���n��쳲�������
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

 //����Ĺ⣺����
//һά����ά����Ĵ��
//#include<stdio.h>
//int main() {
//	//int number[10] = { 0 };
//	//int frequency = 0;
//	//for (frequency = 0; frequency < 10; frequency++) {
//	//	printf("number[%d]��ַ=%p\n", frequency, &number[frequency]);
//	//}
//	//int number[2][3] = { 0,2,3,4 };//����ȫ��ʼ�� ���油0��\0��
//	int Number[2][3] = { {4,5},{1,2,3} };//Ҳ�������������ά����
//	int frequency = 0;
//	int Frequency = 0;
//	for (frequency = 0; frequency < 2; frequency++) {
//		for (Frequency = 0; Frequency < 3; Frequency++) {
//			printf("Number[%d][%d]��ַΪ%p\n", frequency, Frequency, &Number[frequency][Frequency]);
//		}
//	}
//	return 0;
//}

/*
   ����������������Ԫ�ص�ַ
   �����������⣨�����������ַ��   1.sizeof(������)    2.&������
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

//��0123456789����ð������
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