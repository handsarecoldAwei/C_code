#define _CRT_SECURE_NO_WARNINGS

//ϸ�ڽ�һ�²�����
//1.����������
//#include<stdio.h>
//int main() {
//	//float number = 6 / 5;//  �����1��ϵͳ�Զ���Ϊ�������
//	//float number = 6.0 / 5.0;//  �����ȷ ���ӡ�double������float���ض�;C�����У������ָ���������ͣ���ôС��Ĭ��Ϊ��double����
//	float number = 6.0f / 5.0f;
//	printf("%f\n", number);
//	return 0;
//}


//2.��λ�����������Ʋ�����������˵������һ���������ƣ��ұ߶�������߲�����λ���ڶ����߼����ƣ��ұ߶�������߲��㣩
//#include<stdio.h>
//int main() {
//	int number1 = -1;
//	int number2 = number1 >> 1;//�������Բ������ʽ���ڵģ��������ƽ����-1���߼����������һ���ܴ����
//	printf("%d\n", number2);//�������������������߼��������
//	return 0;
//}
//����λ��������ʲô���أ� ---��Ҫ�������������� ʵ�� 3 �� 5�Ľ���
//#include<stdio.h>//��һ�ַ���
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
//����������� int �������ڷ�Χ���ͻᵼ�½�������

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

//�ж�һ�����ֵĶ������ж��ٸ�1
// ��һ��д��
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
//	printf("%d��������1�ĸ��� = %d\n", number, count);
//	return 0;
//}
//�ڶ���д��

//int Number(unsigned int number) {//��һ��д��
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
//��ӡ���ζ����Ƶ�����λ��ż��λ
//#include<stdio.h>
//int main() {
//    int number = 0;
//    scanf("%d", &number);
//    int frequency = 0;
//    //��ӡż��λ
//    for (frequency = 31; frequency >= 1; frequency -= 2) {
//        printf("%d ", (number >> frequency) & 1);
//    }
//    printf("\n");
//    //��ӡ����λ
//    for (frequency = 30; frequency >= 0; frequency -= 2) {
//        printf("%d ", (number >> frequency) & 1);
//    }
//    return 0;
//}

//3.��ֵ������
//#include<stdio.h>
//int main() {
//	int number1 = 100;
//	int number2 = 200;
//	int number3 = 300;
//	number1 = number2 = number3 + 100;//�ǿ�������������ֵ�ģ������˵ĸо�---�ܲ����
//	printf("%d  %d  %d\n", number1, number2, number3);

//	return 0;
//}

// 4. sizeof��Ŀ������
//#include<stdio.h>
//int main() {
//	int arr[10] = { 0 };//   []�±����ò�������˫Ŀ��������  һ��������arr  һ����10
//	printf("1-->%d\n", sizeof(arr));
//	printf("2-->%d\n", sizeof(int[10]));//40   
//	short number1 = 10;
//	int number2 = 100;
//	//  sizeof()�ڲ��ǲ����������
//	printf("3-->%d\n", sizeof(number1 = number2 + 100));
//	printf("4-->%d\n", number1);
//	printf("%d\n", sizeof(&number1));//��ַ��Сȡ����32��64����ϵͳ   4 / 8
//	return 0;
//}

// 5.  һ�� = Ϊ��ֵ������ == Ϊ�ж��Ƿ���ȣ������ַ��������� ==

//6.  &&�߼���    Сϸ��
//#include<stdio.h>
//int main()
//{
//	int number1 = 0, number2 = 0, number3 = 10,number4 = 20;
//	number1 = number2++ && number3++ && ++number4;//һ������Ϊ��ʣ�µĲ�������
//	printf("%d\n%d\n%d\n", number2, number3,number4);// 1    10    20
//	return 0;
//}


/*
   ����������
           ���ʽ������������CPU�н��е�  ����������CPU֮ǰ���������γ��ȶ��ᷢ����������   ��һ��������������
*/
//#include<stdio.h>
//int main() {
//    char number1 = 3;
//    // 3�Ķ����Ʊ� 00000000 00000000 00000000 00000011
//    //  ��ŵ�char������ �����ض�  00000011
//    char number2 = 127;
//    // 127�Ķ����Ʊ� 00000000 00000000 00000000 01111111
//    //  ��ŵ�char������ �����ض�  01111111
//
//    char number3 = number1 + number2;
//    //  00000000 00000000 00000000 00000011
//    //  00000000 00000000 00000000 01111111
//// ��ӣ�00000000 00000000 00000000 10000010
//    
//    printf("%d\n", number3);
//    //  int���ʹ�ӡ����
//    //number3�ض�   10000010   ���λ����λ������1������0��
//    //  11111111 11111111 11111111 10000010(�����Բ�����ʽ����)
//    //  11111111 11111111 11111111 10000001 ����
//    //  00000000 00000000 00000000 011111110ԭ��
//    // -126
//
//    return 0;
//
//}

//֤�����������Ĵ���
//#include<stdio.h>
//int main() {
//    char number = 1;
//    printf("%u\n", sizeof(number)); //  %u�޷�������
//    printf("%u\n", sizeof(+number)); // 4  �������������� 
//    printf("%u\n", sizeof(-number));
//    printf("%u\n", sizeof(!number));// gcc��4
//    return 0;
//}
//���Ӧ��������ת����int ��double ��long�����͵����㣩

/*
      ���������ԣ�
                1.�������������ȼ���   ���������ſ϶�д�������������
                2.���������н���Ե�  ���� N/A û�н����   ��   5 + 3 �Ӻ� L -> R �ȼ�������ټ����ұ�  �� ǿ������ת����sizeof��  R->L
                3.�Ƿ������ֵ˳��     if(3 && ��������һ��ʽ��)  ��ʵ���Ϊ�棬�ұ߾Ͳ��ü��㣻��Ŀ������  �������ʽ2��ʽ�ӣ��پͼ�����ʽ3��ʽ��
*/

//  ���ʽ���ȼ�   number1 * number2 + number3 * number4 + number5 * number6 �����ȼ���˷�Ȼ����ӻ��Ǽ��������˷�����ټ�����һ���˷��أ�����
//        number + --number �����֪������--����Ӻ� ���������ü���֮������أ����������֮ǰ��ֵ�أ���
//    ������д�����ʱ�򣬲�Ҫ������ѣ�Ҳ��Ҫ��ϵͳ��ѡ����

//  ����Ϧʰ
//#include<stdio.h>
//#include<string.h>
//int main() {
//    char group[] = "Hello World";
//    printf("%d  %d\n", sizeof(group), strlen(group));//  sizeof��������ռ�Ĵ�С������\0�� ��ӡ���12 �� strlen���㳤��\0����   ��ӡ���11
//    return 0;
//}

// Բ��һ��ָ�����͵�����
// 1.ָ�����;����ˣ�ָ������õ�Ȩ���ж��
//#include<stdio.h>
//int main() {
//    int number = 0x11223344;
//    //int* point = &number; // �������ַ��Ϊ 00 00 00 00 �����ʵ���int����������ַ
//    char* point = &number;  //  ����ַ��Ϊ  00 33 22 11  �����ʵ���char����һ���ֽڵ�ַ
//    *point = 0;
//    return 0;
//}

//2.ָ�����ͻ���������һ�����߶�Զ
//#include<stdio.h>
//int main() {
//    int group[10] = { 0 };
//    int* point1 = group;
//    char* point2 = group;
//    printf("%p\n", point1);
//    printf("%p\n", point2);
//    printf("%p\n", point1 + 1);//��һ����һ��int�ĳ���
//    printf("%p\n", point2 + 1);//��һ����һ��char�ĳ���
//    return 0;
//}
//������д��������У��������������������������ѡ��ָ�����ͣ�

// Ұָ�����

//1.δ��ʼ��     int * point;�����㲻ȷ��ָ��ʲôλ��ʱ����Ҫָ���ָ��)����ʼ����������

//2.Խ�����  ��������������⣨С�ķ���Խ�磡������
//(���������飬C�涨ָ�����ָ�����һ������Ԫ��β��λ�ã�������ָ�������һ��Ԫ����ǰ��λ��)������ָ��β�ͣ�����ָ��ͷ��������ָ��ͷ���棩

//3.ָ��ָ��Ŀռ��ͷţ�û��ָ���ָ�루�ͷŵĿռ�ǵü�ʱָ���ָ�룩
//#include<stdio.h>//�������ʾ��
//int* test() {
//    int number_test = 100;//�ֲ�����  ������������ �ռ��ͷ�
//    return &number_test;//���ѵ�ַ����ȥ��
//}
//int main() {
//    int* number = test();
//    *number = 200;
//    return 0;
//}

// Ԥ����ָ���ؿ�����ǰ���
//#include<stdio.h>
//int main() {
//    int number = 100;
//    int* point = &number;
//    if (point != NULL) {
//        *point = 200;
//        printf("���ǿ�ָ�룬�����ʳ��\n");
//    }
//    printf("%d\n", number);
//    return 0;
//}

//���潲һ��ָ�������
//1. ָ�� + ������ȡ����ָ������ͣ�����һ�����ж೤��

//2. ָ�� - ָ�루�õ���������ָ��֮��Ԫ�صĸ�����
//#include<stdio.h>
//int main() {
//    int array[10] = { 0 };
//    printf("%d\n", &array[9] - &array[1]);//��ӡ�����8
//    return 0;
//}
//�����ַ��ĳ���
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

//��ӡ����Ԫ�ط�ʽ
//#include<stdio.h>//���ԭ�� �滨һ�� лл
//int main() {
//    int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    int* point = array;//������������Ԫ�ص�ַ
//
//    //  array[2] <==> 2 [array] ��Ҫ���� []��˫Ŀ�������������ǲ�����
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

//����ָ��
//#include<stdio.h>
//int main() {
//    int number = 100;
//    int* point1 = &number;// point1��ָ����� һ��ָ��
//
//    int** point2 = &point1;//  *point2 = point1   point1������ int*
//    printf("%d\n", **point2);
//    return 0;
//}

/*     
      ��������-- - �������int     �ַ�����----���char
      .............ָ������Ҳ���Ǵ��ָ����
 */

//�ṹ��  һ���ṹ��Ҳ������Ϊ��һ���ṹ���Ա
//#include<stdio.h>
//struct student {//�ṹ������ �൱��int number�� int
//    char name[20];
//    int age;
//}stu1 ={"���Ȱ�����",18};//stu1ȫ�ֱ���
//int main() {
//    //struct student c���Ǿֲ�����
//    printf("%s  %d\n", stu1.name, stu1.age);
//    return 0;
//}

//�ṹ�崫��
//#include<stdio.h>
//struct student {
//    char name[20];
//    int age;
//};
//void print1(struct student stu1) {//��ֵ���� �������ж���Ҿʹ�����������ܣ��˷��˿ռ䣻 ��ֵ̫�໹��Ҫһ��ʱ�䣬�˷���ʱ�䣻���ı�ԭ�θı䲻���βΣ���԰�ȫһ��
//    printf("%s %d\n", stu1.name, stu1.age);
//}
//void print2(struct student* stu1) {
//    printf("%s %d\n", stu1 -> name, stu1 -> age);//��ַ���� ֻ�����´���һ��4/8�ֽڣ����忴32λ����64λ����ϵͳ�������ܵ�ַ��Ч�ʸߣ����һ��
//}
//int main() {
//    struct student stu1 = { "��ΰ�Ѿ�����", 18 };
//    print1(stu1);
//    print2(&stu1);
//    return 0;
//}
//��ѡ��ַ����
/*
   ����������Ҫѹջ�ģ�����������Ҫ��(���ݽṹ�ϵ�ջ)ջ�Ͽ��ٿռ䣬�Ƚ����������ȳ�
   ���ֱ�Ӹ�������ֵ���ã��ǽṹ��������ṹ��Խ��ϵͳ�����ͱȽϴ󣬵��������½�
   ������ѡ��ַ ���Ǵ�ֵ
*/

/*      ���� ����һ��

    1. Debug�����԰汾 ���Խ��е��� ��ռ�Ŀռ��Ƚϴ�һЩ����Release�����а汾 �޷����� ���Ӧ�ռ���ռСһ�㣩�汾

     ��ΪRelease�汾�����ǽ����˸����Ż�������Debug�����еģ���һ������Release����ͬ����Ч��

    2.�﷨���� �������������� �� ��ʵ�����ǽ������ʱ�Ĵ����߼����� 
*/

//3.����---�����ϵ�  //����������н����ʲô�أ���
//#include<stdio.h>
//int main()
//{
//    int frequency = 0;
//    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//    //�Ȳ���ʽ�ӶԴ� ����һ�������ѭ��1����أ�����һ��һ�������ԣ���low�����������ϵ㿪ʼ����
//    for (frequency = 0; frequency <= 10; frequency++) {
//        array[frequency] = 0;
//        printf("hehe\n");
//    }
//    return 0;
//}
//�����VS2022���е����н����  Խ����ʷ������� ��ʵ����һ������� ��ѭ�� Ϊʲô����ô˵�أ�
// frequency �� array�Ǿֲ�������������ջ�����ٿռ䣬ջ���ڴ��ʹ��ϰ���� ���øߵ�ַ���õ͵�ַ��������������±��������ַ�Ǵӵ͵��߱仯�ģ�һ��Խ����ʣ����ʵ�frequency�����¸�ֵΪ0����ʼ��һ�ֵ�ѭ�������ճ���������

//���ô��������
//ģ��ʵ���ַ�����������strcpy
//#include<stdio.h>
//#include<assert.h>//��������Ҫ��ͷ�ļ�
//char* MyStrcpy(char *array1,const char*array2) {//Ԥ��array2���޸Ŀ��Լ�const����
//    //������θ������˸���ָ�룬�ҽ����ò��ͳ��ִ������
//
//    assert(array2 != NULL);//����  ���Ϊ��ָ�����������
//    assert(array1 != NULL);
//   char* first = array1;
//    while (*array1++ = *array2++) {//
//        ;//HelloWorld�Ŀ���
//    }
//    //while (*array2++ = *array1++) {//�����С��д����������   û�б����ߣ���Ȼû�дﵽԤ�ھ�Ȼ���гɹ���
//    //    ;
//    //}
// 
//  return first;// strcpy���ص���Ŀ����Ԫ�ص�ַ
//}
//int main()
//{
//    char array1[20] = "#########";
//    char array2[] = "HelloWorld";
//    printf("%s\n", MyStrcpy(array1,array2));//��ʽ����
//    return 0;
//}
//ע����ɻ�
//#include<stdio.h>
//int main() {
//    /*��ð�*/int/*û�뵽�ɺٺ�*/ number/*������*/ = 100;//��...
//    printf("%d\n", number);
//    return 0;
//}
//����һ�� C������û��������������� ÿ����printf��Ҫ���ÿ⺯����ͷ�ļ���

//  const����ָ��
//#include<stdio.h>
//int main() {
//    const int number = 100;
//    int days = 30;
//    //number = 200;  const���εı����ǲ��ܸĵ�
//    //int* point = &number;
//    //*point = 200;////���ҵ���ַ�޸ķ�ʽ��Ȼ����number��ֵ
//    
//    //const int* point = &number;
//    //*point = 200;   //const  ����*point ��ָ��������ǲ����Ըĵ� �������ᱨ��
//   // point = &days; //����ָ����Ըı�
//
//    int* const point = &number;
//    //point = &number;  //  const ����pointʱ��ָ���ܸı䣬�����ݿ���
//    *point = 50;
//
//    printf("%d\n", *point);
//    return;
//}
/*
    ����˵���� Ů����point(ָ��)��������1�Ǿ��¹�ϵ��ָ����1��Ǯ��˵����̲裬
    ��1˵��ûǮ������������  �����  const  ����*point ��ָ��������ǲ����Ըĵ�
    Ů��˵���Ǯ�������һ������ұ����̸����ȥ�ˣ���1���ˣ�˵�Ҹ����򣬵�ǰ�������ǲ�Ҫ�뿪��  �����const ����pointʱ��ָ���ܸı䣬�����ݿ���
    ���������1�ܻ����Ȳ�������Ҳ�����㰮�ϱ��� �����  const int * const point ��
    �����һ��ָ�� ������ָ������Է�����const ���������һ�� ������  const int * const * const point
*/
 //С��ţ��
//1.��ӡnumber�Ľ��
//#include<stdio.h>
//int number = 1;//ȫ�ֱ���
//void test() {
//    int number = 100;//�ֲ�����
//    number -= 50;//�ֲ�����
//}
//int main() {
//    test();
//    printf("%d\n", number);//  1
//    return 0;
//}

//2.������������С������
//����1  ���Ч�ʵ�һ��
//#include<stdio.h>
//int main() {
//    int NumberOne = 0;
//    int NumberTwo = 0;
//    scanf("%d %d", &NumberOne, &NumberTwo);
//    int min = NumberOne > NumberTwo ? NumberOne : NumberTwo;//��С��������СҲ����������һ����
//    while(1){
//        if (min % NumberOne == 0 && min % NumberTwo == 0) {
//            printf("%d\n", min);
//            break;
//        }
//        min++;
//    }
//}
//����2
//#include<stdio.h>
//int main() {
//    int NumberOne = 0;
//    int NumberTwo = 0;
//    scanf("%d %d", &NumberOne, &NumberTwo);
//    int frequency = 1;
//    for (frequency = 1;; frequency++) {//��д�ж�������Ϊ��
//        if (frequency * NumberOne % NumberTwo == 0) {
//            printf("%d\n", frequency * NumberOne);
//            break;
//        }
//    }
//    return 0;
//}

//3.��һ�仰���� ���� I like China.  ->  China. like I
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
    //scanf("%s", array);// scanf�����ո�ͻ�ֹͣ ���Բ�����scanf
    gets(array);//get(�ַ�����ַ���Ĵ洢)
    //��ת��  1.���ַ�����ת
    int length = strlen(array);
    Swap(array, array + length - 1);//  �������±�  �������±�
    //2.ÿ����������
    char* start = array;
    while (*start) {
        char* end = start;
        while (*end != ' ' && *end !='\0') {
            end++;
        }
        // 3.����һ������
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

















