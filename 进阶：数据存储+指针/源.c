#define _CRT_SECURE_NO_WARNINGS
//�������ڴ�Ĵ洢
//���Σ� charҲ����Ϊ������������  ��Ϊchar�ַ���Ӧ����ASCIIֵ�����Ӧ�ľ������֣�
//#include<stdio.h>
//int main()//���Դ��ڴ�Ŷ
//{
//	int number = -10;
//	/* ���� ԭ��10000000 00000000 00000000 00001010
//	      ���룺10000000 11111111 11111111 11110101
//	       ���� 11111111 11111111 11111111 11110111
//		   Ϊɶ�����ò���洢�أ� ������������ͳһ����CPUֻ�мӷ���
//	       ԭ�� -> ���� ����λȡ��+1��
//		   100000000 00000000 00000000 00001000��λȡ��
//		   100000000 00000000 00000000 00001001��һ�ֻ�ȥ��
//	      16����    ff         ff    ff       f 6
//		   ��С�ˣ��͵�ַ�ŵ�λ���ߵ�ַ�Ÿ�λ ->С�˴洢 ; �͵�ַ�Ÿ�λ���ߵ�ַ�ŵ�λ -> ��˴洢
//	*/
//	return 0;
//}
//дһ�����룬�жϵ�ǰ�������Ǵ�˻���С��
//#include<stdio.h>
//int main()
//{
//	int number = 1;
//	char* point = (char*)&number;
//	if (*point == 1) {
//		printf("С��\n");
//	}
//	else {
//		printf("���\n");
//	}
//	return 0;
//}
//ţ��С��
//1.���ʽ�Ӵ�ӡ�Ľ����ɶ
//#include<stdio.h>
//int main() {
//	char number1 = -1;
//	// 10000000 00000000 00000000 00000001ԭ��
//	// 11111111 11111111 11111111 11111111����
//	// �ض� 11111111
//	// %d��ʽ��ӡ  11111111 11111111 11111111 11111111���� -> 10000000 00000000 00000000 00000001ԭ��
//	signed number2 = -1;
//	// -1
//	unsigned char number3 = -1;
//	// 11111111 unsigned�޷���%d��ʽ��ӡ 00000000 00000000 00000000 11111111 
//	printf("%d %d %d\n", number1, number2, number3);//  -1  -1  255
//	return 0;
//}
/*
     ����һ�� char������signed char����unsigned char ��C������û�й涨�ģ���int����short����signed int��short��

     char 00000000(0)����01111111(127) ->10000000(11111111 11111111 11111111 10000000ʮ����-128)��-128��->100000001(ԭ��11111111)��-127)����11111111(ԭ��10000001)��-1��
     char���͵ķ�Χ -128 �� 127
     �޷��ŵ�char 00000000��0��->00000001(1)->01111111(127)->10000000(128)�޷���λ->10000001(129)->11111111(255)
*/
//2.���ʽ�Ӵ�ӡ�Ľ����ɶ
//#include<stdio.h>
//int main() {
//    char number = -128;
//    // 10000000 %u�޷��Ŵ�ӡ 11111111 11111111 11111111 10000000
//    /*
//       10000000 00000000 00000000 10000000 ԭ��
//       11111111 11111111 11111111 011111111  ����
//       11111111 11111111 11111111 10000000 ����
//    */
//    printf("%u\n", number);//һ���ܴ����
//    return 0;
//}
//3.���ʽ�Ӵ�ӡ�Ľ����ɶ
//#include<stdio.h>
//int main() {
//    char number = 128;
//    //00000000 00000000 00000000 10000000
//    //10000000 %u�޷��Ŵ�ӡ���� 11111111 11111111 11111111 10000000
//    printf("%u\n", number);//�ܴ����
//    return 0;
//}
// 4.���ʽ�Ӵ�ӡ�Ľ����ɶ
//#include<stdio.h>
//int main() {
//    unsigned int number = 0;//�޷�������û�и�����
//    for (number = 9; number >= 0; number--) {//�����������
//        printf("%u\n", number);
//    }
//    return 0;
//}
//5.���ʽ�Ӵ�ӡ�Ľ����ɶ
//#include<stdio.h>
//#include<string.h>
//int main() {
//    char array[1000];
//    int number;
//    for (number = 0; number < 1000; number++) {
//        array[number] = -1 - number;
//   // -1 -2����-128 127 126����0
//    }
//    printf("%d\n", strlen(array));//strlen����\0���� 255
//    return 0;
//}
//6.���ʽ�Ӵ�ӡ�Ľ����ɶ
//#include<stdio.h>
//unsigned char number = 0;
//int main() {
//    for (number = 0; number <= 255; number++) {//��ѭ��
//        printf("�㻹��̫����\n");
//    }
//    return 0;
//}
//�����������ڴ��еĴ洢
/*
       ��������ʾ��������һ��ֱ��д���� 3.1415926 �� �ڶ����ÿ�ѧ��������ʾ  1E10��1.0*10^10��

       ���ݹ��ʱ�׼IEEE�������͵��ӹ���Э�ᣩ754�涨,����һ�������Ƹ�������ʾ��ʽΪ ��-1)^s * M * 2^E  ����-1)^sΪ����λ sΪ0��Ϊ������sΪ1��Ϊ���� ��MΪ��Ч�� 1<=M<2 ��2^E��ʾָ��λ
       
       �ٸ�������˵ ʮ����5.0д�ɶ�����   ��-1)^0 * 1.01 * 2^2   ��  5.5   ��-1)^1 * 1.011 * 2^2 

       float   32��bitλ   0������λ��00000000��8bitָ��λ�� 00000000 00000000 0000000��23bit��Чֵλ��
       double  8�ֽ�64bitλ   1bitΪ����λ  11bitΪָ��λ  52bitΪ��Чֵλ

       IEEE754����Ч��M��ָ��E��һЩ�ر�涨
       M��ȡֵ��Χ 1<=M<2 ,������д��1.xxxx,����xxxxΪС�����֣��ڼ��������Mʱ��Ĭ�������һλ����1����˿��Ա�������ֻ����С�����ȶ�ȡʱ�ٰ�1����ȥ��������ʡ��һλ��Ч���֣�float���Ա���24λ��Ч������
       EΪһ���޷�������������ζ�����EΪ8λ��ȡֵ��ΧΪ��0-255����11λ 0-2047�������ǿ�ѧ������E����Ϊ�����ģ�����IEEE754�涨����E��ʱ����Ҫ��һ���м�����8λE+127(11λ+1023) ������2^10 ,E=10,10+127=137 ��10001001
       
       ָ��E���ڴ���ȡ�������������
       EΪ��ȫ0��ȫ1�� 
       EΪȫ0   EΪ8λʱ+127 ��11λ+1023 ��EΪ0 ˵������һ����С��������ʱ��������ָ��E����1-127��1-1023����Ϊ��ʵֵ����Ч����M���ڼ���1����������ʾ����0���Լ���С������
       EΪȫ1   ������������� ȡ���ڷ���λ
*/
//#include<stdio.h>
//int main() {
//    float Number = 9.0;
//   // 0 10000010 00100000 00000000 0000000
//   //   4    1    1   0    0 0 0 0
//    int number = 9;
//    float* pFloat = (float*)&number;
//    printf("number��ֵ=%d\n", number);//�޿����� 9
//    printf("*pFloat��ֵ=%f\n", *pFloat);// 0 00000000 00000000 00000000 0001001   
//    *pFloat = 9.0;
//    printf("number��ֵ=%d\n", number);// 0 10000010 00100000 00000000 0000000 �ܴ������
//    printf("*pFloat��ֵ=%f\n", *pFloat);// ��ӹ����9.0
//    return 0;
//}

//��һ�½���ָ��
//1.�ַ�ָ��
//#include<stdio.h>
//int main() {
//    /*  �ַ�ָ���һ��ʹ��
//    char happy = 'A';
//    char* point = &happy;
//    *point = 'a';
//    printf("%c\n", *point);*/
//    char *word = "HelloWord";//�ַ����������ܸ�
//    char array[] = "HelloWord";//�ַ����������ſ��Ը�
//    array[0] = 'A';
//    printf("%c\n", *word);//�����ǰ�����ַ��� "HelloWord" ���ַ�������word��
//
//    printf("%s\n", word);
//    printf("%s\n", array);
//
//    return 0;
//}
//С��ţ��һ��
//#include<stdio.h>
//int main() {
//    char array1[] = "HelloWorld";
//    char array2[] = "HelloWorld";
//    const char *array3 = "HelloWorld";//�ַ�������(����const �ǲ��Ǵ������׳��һ���أ���)
//    const char *array4 = "HelloWorld";
//    if (array1 == array2) {
//        printf("1���\n");
//    }
//    else {
//        printf("1�����\n");//����������ͬ��������Ҫ���ٲ�ͬ�Ŀռ����������ģ����Բ����
//    }if (array3 == array4) {
//        printf("2���\n");//�ַ�������������ָ��ָ������ָ��ͬһ��λ��
//    }
//    else {
//        printf("2�����\n");
//    }
//    return 0;
//}

//ָ������  ���ָ�������
//#include<stdio.h>
//int main() {
//    //һ�����ε�д��
//    int number1 = 10;
//    int number2 = 20;
//    int number3 = 30;
//    int* array[] = {&number1,&number2 ,&number3};
//    int frequency = 0;
//    for (frequency = 0; frequency < 3; frequency++) {
//        printf("%d ", *(array[frequency]));
//    }
//    printf("\n");
//    //������
//    int array1[] = { 1, 2, 3, 4, 5 };
//    int array2[] = { 6, 7, 8, 9, 10 };
//    int array3[] = { 11, 12, 13, 14, 15 };
//    int* array4[] = { array1,array2,array3 };
//    int frequency1 = 0;
//    int frequency2 = 0;
//    for (frequency1 = 0; frequency1 < 3; frequency1++) {
//        for (frequency2 = 0; frequency2 < 5; frequency2++) {
//            //printf("%d ", *(array4[frequency1] + frequency2));//��һ��д��
//            printf("%d ", array4[frequency1][frequency2]);//�ڶ���д��
//        }
//        printf("\n");
//    }
//    return 0;
//}

//����ָ�루��һ��ָ�룩��ָ�������ָ�룩  �� ����ָ�루ָ�����Σ����ַ�ָ�루ָ���ַ���
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
//    //int(*point2)[10] = &array;//ȡ����������ĵ�ַ��������ָ�룬�ַ�ָ��ȡ��ַһ����
//    //printf("%p\n", point1);
//    //printf("%p\n", point1 + 1);// +1��һ��int����
//    //printf("%p\n", point2);
//    //printf("%p\n", point2+1);// +1 ���������飨&array���ǰ�ȡ�ģ�
//
//    //����ָ���ʹ��
//    int* point3 = array;
//    int(*point4)[10] = &array;//������point3�Ϳ��Խ�����⣬��Ҫ�����иߴ��ϵı�ʾ��ɱ������ţ�������鷳
//    //����ָ�룬��ָ��ָ��һ�����飬����10��Ԫ�أ�ÿ��Ԫ��int����
//    //    int(*point5[10])[5]  print5�Ǵ������ָ������飬�������ܹ����10������ָ�룬ÿ������ָ���ܹ�ָ��һ������
//
//    int frequency = 0;
//    /*for (frequency = 0; frequency < 10; frequency++) {
//        printf("%d ", *(point3 + frequency));     //��һ�ַ���
//    }*/
//    //for (frequency = 0; frequency < 10; frequency++) {
//    //    printf("%d ", *((*point4)+frequency));//��������е�ܱ�Ť
//    //}
//    //����չʾ��������֮��
//    int array_two[3][5] = { {1, 2, 3, 4, 5},{6, 7, 8, 9, 10},{11, 12, 13, 14, 15} };
//    MyPrintf(array_two, 3,5);
//    return 0;
//}

//һά���鴫�κͶ�ά���鴫��
//#include<stdio.h>
//void test1(int **array1) {//������ָ�����飬�����ö���ָ����ܣ�����ָ��ָ��һ��ָ�룩
//}
//void test2(int* array2) {}//һά������һ��ָ������ǿ��Ե�
//void test2(int* array2[5]) {}//��ά������ָ��������ܣ���Ҫ������ָ��
////void test2(int **array2){}//��ά�����ö���ָ����ܣ������
//
//int main() {
//    int* array1[20] = { 0 };
//    int array2[3][5] = { 0 };
//    test1(array1);
//    test2(array2);
//    return 0;
//}

//����Ϧʰ
//1.��ӡ�����ɶ
//#include<stdio.h>
//int number;// ȫ�ֱ���δ��ʼ��Ĭ����0
//int main() {
//    number--;//  -1
//    if (number > sizeof(number)) {//  sizeof�����Ľ���϶���������������С������Ϊ������ һ���������޷���������ȣ�ת��Ϊ�޷���������������һ���ܴ����
//        printf(">\n");
//    }
//   
//    else {
//        printf("<\n");
//    }
//    printf("%u", number);
//    return 0;
//}
//2. a+aa+aaa+aaaa+aaaaa ��ǰ����֮��
//#include<stdio.h>
//int main() {
//    int number1 = 0;
//    int number2 = 0;
//    scanf("%d %d", &number1, &number2);
//    int frequency = 0;
//    int sum = 0;
//    int number3 = 0;//����һ���ֵ 
//    for (frequency = 0; frequency < number2; frequency++) {//��number2��
//        number3 = number3 * 10 + number1;
//        sum += number3;
//    }
//    printf("%d\n", sum);
//    return 0;
//}

 //3.��ӡһ����Χˮ�ɻ���  ˮ�ɻ�����һ��nλ�����������ֵ�n�η�֮�͵��ڸ�������
//#include<stdio.h>
//#include<math.h>//pow���ֿ���������ͷ�ļ�
//int main() {
//    int number = 0;
//    for (number = 0; number <= 10000; number++) {//   0-10000ֱ�ӵ���
//        //�ж�number�Ǽ�λ��
//        int much = 1;
//        int brother = number;
//        while (brother / 10) {
//            much++;
//            brother /= 10;
//        }
//        //����numberÿһλn�η�֮��
//        brother = number;
//        int sum = 0;
//        while (brother) {
//            sum += pow(brother % 10, much);// pow(���֣��η�)������һ�����ִη�����
//            brother /= 10;
//        }
//        //3.�ж�
//        if (sum == number) {
//            printf("%d\n", number);
//        }
//    }
//    return 0;
//}

//����ָ��Ҳ��ָ�룬ֻ������һ��ָ����󣿣������Եģ���һָ����32λ����ϵͳ4�ֽڣ�64λ����ϵͳ8�ֽڣ����ڶ�����˵���ǱȽ�������ַ���أ����ǱȽϵ�����ռ�ռ��أ�

//4.��ʽ��ӡ���飬������n��printfÿ������ɷ�����
//#include<stdio.h>
//int main() {
//    int row = 0;
//    scanf("%d", &row);
//    //��
//    int frequency = 0;
//    for (frequency = 0; frequency < row; frequency++) {
//        //��ӡһ��  �ո�
//        int frequency_two = 0;
//        for (frequency_two = 0; frequency_two < row - 1 - frequency; frequency_two++) {
//            printf(" ");
//        }
//        ////��ӡ1��3��5��7����*
//        for (frequency_two = 0; frequency_two < 2*frequency+1; frequency_two++) {
//            printf("*");
//        }
//        printf("\n");
//    }
//    //��
//    for (frequency = 0; frequency < row - 1; frequency++) {
//        //��ӡһ��  �ո�
//        int frequency_two = 0;
//        for (frequency_two = 0; frequency_two <= frequency; frequency_two++) {
//            printf(" ");
//        }
//        ////��ӡ7��5,3,1����*
//        for (frequency_two = 0; frequency_two < 2 * (row - 1 -frequency)-1; frequency_two++) {
//            printf("*");
//        }
//        printf("\n");
//    }
//    return 0;
//}

//5.һƿ��ˮ1Ԫ��2����ƿ�ɻ�һƿ��ˮ������20Ԫ�����������ˮ
//#include<stdio.h>
//int main() {
//    int money = 0;
//    scanf("%d", &money);
//    int pop = money;
//    int swap = money;
//    while (swap > 1) {
//        pop += swap / 2;//�ȶ�����ˮ
//        swap = swap / 2 + swap % 2;//�һ�������ˮ
//    }
//    printf("%d", pop);
//    return 0;
//}

//6.��������  ʹ����ȫ��λ��ż��ǰ��
//#include<stdio.h>
//void Swap(int arr[], int size) {
//    int left = 0;
//    int right = size - 1;
//    while (left < right) {
//        while ((left < right) && (arr[left] % 2 == 1)) {
//          left++;//���������Ӻ���ż��
//        }
//        while ((left < right) && (arr[right] % 2 == 0)) {
//            right--;//����ż����ǰ������
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

//7.�����ӡ���
//#include<stdio.h>
//int main() {
//    unsigned char/* 0 - 255 */ one = 100;
//    //00000000 00000000 00000000 01100100  int����100�����ض�
//    //01100100
//    unsigned char two = 200;
//    //00000000 00000000 00000000 11001000 int����200�����ض�
//    //11001000
//    unsigned char three;
//    three = one + two;
//    //00000000 00000000 00000000 01100100 + 00000000 00000000 00000000 11001000 ��Ӵ����char�У������ضϣ�
//    //00101100
//    printf("%d %d \n", one + two/*���ֱ�ӷ���int��*/, three/*����������*/);
//    return 0;
//}

/* 8. ��ӡ�������   ��һ����ʽ�����������
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

/* 9. ���루�����⣩�ҷ���   3����˵���滰��һ����˵�˼ٻ�
 A��������
 B����C
 C����D
 D��C��ƨ
*/
//#include<stdio.h>
//int main() {
//    char why = 0;
//    for (why = 'A'; why <= 'D'; why++) {
//        if ((why != 'A') + (why == 'C') + (why == 'D') + (why != 'D')==3) {
//            printf("%c�����ɷ�\n", why);
//        }
//    }
//    return 0;
//}

/* 10.�����˶�Ա������ÿ���˶�˵����һ�룬�����ǵ�����
A:B�ڶ����ҵ���
B:�ҵڶ���E����
C:�ҵ�һ��D�ڶ�
D:C����ҵ���
E:�ҵ��ģ�A��һ
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
//                            printf("�������� A=%d  B=%d  C=%d  D=%d  E=%d\n", A, B, C, D, E);
//                        }
//                    }
//                }
//            }
//        }
//    }
//    return 0;
//}
/*11.������ ��һ���㣬��û�м�ʱ����ȼ����һ��1��Сʱ�����������㣬��ȷ��һ��15���ӵ�ʱ���
      
      ��һ������ͷ��ȼ��30���ӣ�������һ����һͷ��ȼ���յ�һ�룩������ͷ��ȼ����ȼ���꣬������һ�����һͷ��ȼ

 12.������ һ����ס30¥��������͵������˵�ʱ��������30��ؼң�����ʱ�䵽15¥��������ô���£�

    �ٷ��𰸣�����٪��֢�����Ӱ������˺�����ɡ���Ե㵽30¥��

 13.������ 36ƥ��6���ܵ���������ʱ����ȷ��ǰ����

    ��һ����36ƥ��ֳ�6�飬ÿ���ȱ�һ�Σ�ȡÿ���ǰ������6�Σ�

    �ڶ�������ÿ�����ǰ�������£�ʣ����̭���ٽ�ÿ����ĵ�һ�����б�����ѡ�����������ǰ����С�飨��Ϊ��һ�ڶ������϶�������֮�в����ģ���ʣ����̭��1�Σ�

    ���������������µ���a1,a2,a3(��һ��С��)
                        b1,b2,b3(�ڶ���С��)
                        c1,c2,c3(������С��)
     a1,�϶��ǵ�һ
     �ڶ���������c1(��ûb1�ܵĺ���)��b2,a3;��a2,b1����һ���ڶ�
     ����������c1,b1,b2,a2,a3(���5ƥ��ʼ�ܣ�ȡǰ����)��1�Σ�

     �ܹ�����8�Σ�6+1+1��
*/

// һ��ָ�����->��һ��ָ�봫�Σ�; �������ĵ�ַ&��

//����ָ����� ->������ָ�봫�Σ�����һ��ָ��ĵ�ַ���������һ��ָ������飩

//����ָ�루ָ������ָ�룬��ź�����ַ��ָ�룩
//#include<stdio.h>
//int Add(int number1, int number2) {
//    return number1 + number2;
//}
//int main() {
//    int(*point/*��Ϊ���ȼ����ԣ���������������������Կ����Ǹ�ָ��*/)(int, /*��������*/int) = &Add;//&ȡ������ַ  �� *point���Ǻ���ָ�����
//    //printf("%p\n", &Add);
//    //printf("%p\n", Add);//������ӡ�����һ���ģ��������е���
//    int number1 = (*point)(100, 200);//  *point�������Ǻ�����ַ  
//    int number2 = Add(100, 200);
//    int number3 = (point)(100, 200);// &Add��Add��ӡ��ַ�Ľ����һ���ģ�point��ָ��Add�ģ� point==Add
//    //   *(point)(100,200)�����ǲ��еģ�point���ȸ���100��200����ϣ�������һ�����ֺ������
//    int number4 = (*****point)(100, 200);// ��Ȼһ��*ȥ�����һ����n���Ǻ�����
//    printf("number1=%d\n", number1);//300
//    printf("number2=%d\n", number2);
//    printf("number3=%d\n", number3);
//    printf("number4=%d\n", number4);
//    return 0;
//}

/*
  ���������Ȥ�Ĵ���

    ��*��void (*��()��0��() ;   
    1. void (*��()����ָ�룬�����޲�;  
     2. void (*��()0 ��0ǿ������ת���ɵ�ַ��
      3. �ڶ�0���н����ò������ҵ�������ַ��
       4. ��*��void (*��()��0��()���е���


    void(*point(int,void(*)(int)))(int)
     1.  point(int,void(*))  point�Ⱥͣ�����ϣ��ɺ��� ��һ��������int����һ���Ǻ���ָ��
       2. void(*)(int)  ���������ˣ��������ˣ�ʣ�¾��Ƿ��������ˣ�����ָ�룩
       �������д��  void(*)(int) point(int,void(*)(int)) ���﷨����������д
       �� typedef void(*)(int) swap ����д��������
       swap point(int,swap);
       
*/
//����ָ���Ӧ��   ʵ�ּ����� + - * /
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
//    //int (*point1)(int, int) = Add;//����ָ��
//    //int (*point2)(int, int) = Sub;//����ָ��
//   // int (*point3[4])(int, int) = {Add,Sub,Mul,Div};//����ָ������
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
//            printf("�˳�����\n");
//            break;
//        default:
//            printf("ѡ�����������ѡ��\n");
//             break;
//        }
//    } while (input);
//    return 0;
//} 
/*    ����д���룬�㲻�о��������
          scanf("%d %d", &number1, &number2);
            result = Sub(number1, number2);
            printf("%d\n", result); д���ı�   
            ����һ�£���Ȼ���ú����Ĳ������������Ͷ���һ���ģ��ǻ�������������ָ������һ�ʴ�����
*/
//int main() {
//  
//    int input = 0;
//    do {
//        menu();
//        int(*point[5])(int, int) = { NULL,Add,Sub,Mul,Div };//�����±��Ǵ��㿪ʼ��
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
//            printf("�˳�����\n");
//            break;
//        }
//        else {
//            printf("�������������ѡ��\n");
//        }
//
//    } while (input);
//    return 0;
//}
/*    
        int (*point1)(int,int);//����ָ��
        int (*point2[3])(int,int);//����ָ������
        int (*(*point3)[3])(int,int)=&point2;//����ָ������ĵ�ַ

        �ص�������һ��������Ϊ������������һ�����������������������ʱ���ͽ����ص�����
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
//            printf("�˳�����\n");
//            break;
//        default:
//            printf("ѡ�����������ѡ��\n");
//             break;
//        }
//    } while (input);
//    return 0;
//} 

//ð������
//#include<stdio.h>
//void MySort(int array[], int size) {//ֻ��������������
//    int frequency1 = 0;
//    for (frequency1 = 0; frequency1 < size - 1; frequency1++) {//ð����������
//        int frequency2 = 0;
//        for (frequency2 = 0; frequency2 < size - 1 - frequency1; frequency2++) {//һ��ð������
//            if (array[frequency2] > array[frequency2 + 1]) {//�������ݵĽ���  ���Ҫʵ���ַ����ṹ�����ݽ��� �ⲿ��������Ҫ�ı��
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
/*��C����һ��  qsort���� �����ַ����ṹ�����ݶ���������

     void qsort (void* base, //���������ĵ�һ�����ݵ�ַ  ��Ҳ��֪����һ��Ԫ����ʲô���������õ��� void*
                 size_t num, //����Ԫ�ظ���
                 size_t size, //�����һ��Ԫ�ش�С  ��λ���ֽ�
                 int (*compar)(const void*,const void*)); //�Ƚ�����Ԫ�صĺ���   (const void*��һ��Ԫ�صĵ�ַ,const void*�ڶ���Ԫ�صĵ�ַ)

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

//ʵ��sqort
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
//    int (*compar)(const void*point1, const void*point2))//�Ƚ�����Ԫ�صĺ���
//{
//    
//    int frequency1 = 0;
//    for (frequency1 = 0; frequency1 < size - 1; frequency1++) {//ð����������
//        int frequency2 = 0;
//        for (frequency2 = 0; frequency2 < size - 1 - frequency1; frequency2++) {//һ��ð������
//            if (compar((char*)base+frequency2*width, (char*)base + (frequency2+1) * width)>0) {//ǰ��ֻ���������ݵĽ���  ���Ҫʵ���ַ����ṹ�����ݽ��� �ⲿ��������Ҫ�ı��
//                Swap((char*)base + frequency2 * width, (char*)base + (frequency2 + 1) * width,width);//����
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

//����void*ָ��
//#include<stdio.h>
//int main() {
//    char A = 'a';
//    int A = 97;
//    void* point = &A;//�޾�������ָ��ָ��char
//    point = &A;//�Ҳ�ָ��char��  ��ָ��int����  �����ǿ��Ե�
//    //   *point ��  point++   ��������  ��һ�η��ʼ����ֽڣ�����  err
//    return 0;
//}


//------------ţ��С��
//  1��ӡ�����ɶ
//#include<stdio.h>
//int main() {
//    //char array[] = { 'a','b','c' };
//    //printf("%d\n", sizeof(*array));//  'a' char����һ���ֽ�  ��ӡ����1
//    //strlen������ŵ��ǵ�ַ��
//    int array[2][4] = { 0 };
//    printf("%d\n", sizeof(array[0]));// ��һ�д�С   16  ��ά������Կ��� array[2]Ϊ������  [3]������Ԫ�صĸ���
//    printf("%d\n", sizeof(array[0]+1));//��һ�еڶ�����ַ  4/8
//    printf("%d\n", sizeof(array+1));  //array��һ�е�ַ   4/8
//    printf("%d\n", sizeof(*(array + 1)));  // �ڶ��е�ַ�����õڶ��д�С  16
//    printf("%d\n", sizeof(array[3]));//������������  �����ڣ�sizeof��������Ҳ���������� 16
//    
//    return 0;
//}

// 2 ��ת�ַ�    ʵ��һ������  ������תnumber���ַ� 
//#include<stdio.h>
//#include<string.h>
////void StartRotate(char* array, int rotate_number) {//��һ�ַ���  ����ת��
////    int frequency = 0;
////    int length = strlen(array);
////    for (frequency = 0; frequency < rotate_number; frequency++) {
////        char swap = *array;//��һ��
////        int frequency_two = 0;
////        for (frequency_two = 0; frequency_two < length-1; frequency_two++) {
////            *(array + frequency_two) = *(array + frequency_two + 1);//�ڶ���
////        }
////        *(array + length - 1) = swap;//������
////    }
////}
//#include<assert.h>
//void Swap(char*left,char*right) {//ʵ�ֽ���
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
//void StartRotate(char* array, int rotate_number) {//�ڶ��ַ���  ������ת��
//    assert(array);
//    int length = strlen(array);
//    Swap(array, array + rotate_number - 1);//��
//    Swap(array + rotate_number, array + length - 1);//��
//    Swap(array, array + length - 1);//���彻��
//}
//int main() {
//    char array[20] = "ILikeBeijing";
//    int rotate_number = 5;
//    StartRotate(array, rotate_number);
//    printf("%s\n", array);
//    return 0;
//}

//3.�ж��Ƿ�����ת�ַ�
//��һ�ַ���  ��ٷ�
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

//�ڶ��ַ���    ABCDEABCDE   ׷���ַ�������ת�ַ�   BCDEA
////��ѧһ��׷�Ӻ���
/*#include<stdio.h>
#include<string.h>*///׷�Ӻ���ͷ�ļ�
//int main() {
//    char array[20] = "Hello";
//    strcat(array, "World");//  ׷���ַ���������׷�Ӷ���׷�����ݣ�������׷�ӱ���
//    printf("%s\n", array);
//    strncat(array, array, 5);//   (׷�Ӷ���׷������;׷�Ӷ���ĸ���)
//    printf("%s\n", array);
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int IsRotateNumber(char* array_one, char* array_two) {
//    if (strlen(array_one) != strlen(array_two)) {
//        return 0;
//    }
//    //1.��׷��
//    int length = strlen(array_one);
//    strncat(array_one, array_one, length);
//    //2.�ж��Ƿ�Ϊ��ת����
//    char* return_type = strstr(array_one, array_two);//  strstr�ж��Ƿ�Ϊ��ת���� �Ƿ��ص�ַ�������򷵻ؿ�ָ��
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
    ���Ͼ���  ��һ���������ÿ�д����ҵ��������ϵ��µ���

    ��дһ�������ھ�������һ�������Ƿ����

    Ҫ��ʱ�临��С��O(N)  ���������N��Ԫ�أ��򵥴ֱ����ַ���N��    O(1)������������ù̶����Σ����������ҵ���

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
            return 1;//�ҵ���
        }
    }
    return 2;//�Ҳ���
}
int main() {
    int array[3][3] = { 1, 2, 3,4,5,6,7,8,9 };
    int row = 3;
    int col = 3;
    int number = 7;//������7
    int is = find_number(array,&row,&col,number);
    if (is == 1) {
        printf("�ҵ���\n�±���%d %d\n", row, col);
    }
    else {
        printf("�Ҳ���\n");
    }
    return 0;
}
/*Сwink�� 
          1. C++.cpp�ļ�ԭ����.cplusplus ����д
          2.��ʹ��free�ͷŵ�һ��ָ�����ݺ�ָ�������ֵҪ�ֶ���ΪNULL�������֪��
          3.��ͬ��Ϸ״̬���ò�ͬ�������ص���������֮һ
          4.�����ַ��������ָ�룬һ��ָ������ס
*/










