#define _CRT_SECURE_NO_WARNINGS
////������һ�³��Ȳ������Ƶ��ַ�������
//1. strlen�ַ������Ⱥ���  
//#include<stdio.h>
//#include<string.h>
//int main() {
//	if (strlen("abc") - strlen("abcdef") > 0) {
//		printf(">\n");//����ֵ���޷�������   size_t(unsigned int)     ���Դ�ӡ�����>
//	}
//	else {
//		printf("<\n");
//	}
//	return 0;
//}

//  ģ��ʵ��strlen����
//#include<stdio.h>
//int my_strlen(const char* array) {//��������ĳ��� ���޸� const
//	assert(array != NULL);//�ô�����ӽ���
//	int count = 0;//������ʵ��strlen
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

//2.  strcpy��������    string�ַ���   copy����
//#include<stdio.h>
// #include<string.h>
//int main() {
//	char array[20] = "###################";
//	//strcpy(array, "hello");//��ôдûë��  ���е�С��Ť
//	char array_one[] = "hello";
//	strcpy(array, array_one);
//	printf("%s\n", array);//������ᷢ��  '\0'  Ҳ������ȥ��
//	return 0;
//}

//3.  strcat�ַ���׷��  ׷��ʱ���ҵ�Ŀ���ļ���  '\0'  �ٰ�Դ����׷�ӽ�ȥ
//#include<stdio.h>
//#include<string.h>
//int main() {
//	char array1[30] = "hello \0#########";
//	char array2[] = "world";
//	strcat(array1, array2);
//	printf("%s\n", array1);//������ᷢ��  '\0'  Ҳ׷�ӽ�ȥ��  ������ \0 ����׷�ӵ�
//	return 0;
//}

//ģ��ʵ��  strcat
//#include<stdio.h>
//#include<assert.h>
//char* my_strcat(char* array, const char* array1) {//׷���ֲ��޸�  ���ӽ���
//	char* start = array;//׷�Ӻ�����ɺ�᷵��Ŀ���ļ���ʼ��ַ
//	assert(array && array1);//����һ�� Ԥ����ָ��
//	//1.�ҵ�Ŀ���  '\0'
//	while (*array) {
//		array++;
//	}
//	//2.׷���ַ���������  '\0'
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

//4. ģ��ʵ���ַ����ȽϺ���  strcmp
//#include<stdio.h>
//#include<assert.h>
//int my_strcmp(const char* array1,const char* array2) {//  strcmp�������ش��ڻ�С�� ����ڵ�����
//	assert(array1 && array2);//����
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


//���������Ƶ��ַ�������  ��Խ��ڰ�ȫ  �ɿ�
//1. strncpy��������
//#include<stdio.h>
//  #include<string.h>
//int main() {
//	char array1[20] = "abcdef";
//	char array2[] = "ghk";
//	strncpy(array1, array2, 5);//�������  ��\0������ȥ
//	printf("%s\n", array1);
//	return 0;
//}
//2.strncat ׷�Ӻ���
//#include<stdio.h>
// #include<string.h>
//int main() {
//	char array1[30] = "hello \0##############";
//	char array2[] = "world";
//	strncat(array1, array2, 8);//   /0Ҳ׷�ӹ�ȥ
//	printf("%s\n", array1);
//	return 0;
//
//}

//3.strncmp  ����Ƚϼ����ַ��ͱȽϼ����ַ�


//ģ��ʵ��strstr����  ��array1�в����Ƿ���array2����
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//char* my_strstr(const char* array1, const char* array2) {//ֻ�ҵ����޸�
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
//		printf("û�ҵ�\n");
//	}
//	else {
//		printf("�ҵ��ˣ�%s\n", point);
//	}
//	return 0;
//}


//strtok�ַ����и��  �ҵ���ǻ���\0��β������һ��ָ�������ǵ�ָ��
//#include<stdio.h>
//#include<string.h>
//int main() {
//	char array[] = "110120@qq.com";
//	char* point = "@.";
//
//	char alternatives[20] = { 0 };
//	strcpy(alternatives, array);//strtok������ı䱻�����ַ���������ʹ�����зֵ��ַ���һ�㶼����ʱ���������ݲ������޸�
//	char* point1 = NULL;
//
//	//point = strtok(alternatives, point);
//	//printf("��һ���и� %s\n", point);
//
//	//point = strtok(NULL, point);//strtok������һ������ΪNULL�����ڱ�Ǵ������λ�ÿ�ʼ������һ�����
//	//printf("�ڶ����и� %s\n", point);
//
//	//point = strtok(NULL, point);
//	//printf("�������и� %s\n", point);//����ַ��������ڸ����ǣ�����NULLָ��
//
//	for (point1 = strtok(alternatives, point); point1 != NULL; point1 = strtok(NULL, point)) {
//		printf("%s\n", point1);
//	}
//
//	return 0;
//}

//ʹ�ÿ⺯����ʱ�򣬵���ʧ�ܶ����д�����  errno
//strerror  ������ת��Ϊ������Ϣ
//#include<stdio.h>
//#include<string.h>//strerrorͷ�ļ�
//#include<errno.h> //errnoͷ�ļ�  ȫ�ִ�����
//#include<stdio.h> //perrorͷ�ļ�
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
//	FILE* point = fopen("test.txt", "r");//���ļ� ������ʽ��  ��ʧ�ܻ᷵��NULLָ��
//	if (point == NULL) {
//		/*printf("%s\n", strerror(errno));*/
//		perror("fopen");//   ������ת��Ϊ������Ϣ����ӡ������Ϣ  һ����λ
//		return 1;//����ʧ�ܾͲ����������� �������
//	}
//	fclose(point);//�ر��ļ�
//	point = NULL;
//	return 0;
//}


//��һ���ַ����ຯ��
//#include<stdio.h>
//#include<ctype.h> //isdigitͷ�ļ�  
//int main() {
//	char judge = '#';
//	int number = isdigit(judge);//isdigit ����������ַ�0-9���ط���ֵ  ���Ƿ���0
//	printf("%d\n", number);
//	return 0;
//}

//�ַ�ת������
//#include<stdio.h>
//#include<ctype.h>//isupper��д��ĸ�ַ����ຯ��ͷ�ļ�
//int main() {
//	char array[20] = { 0 };
//	scanf("%s", array);
//	int frequency = 0;
//	while (array[frequency] != '\0') {
//		if (isupper(array[frequency])) {
//			array[frequency] = tolower(array[frequency]);//tolower����дת��ΪСд
//		}
//		printf("%c ", array[frequency]);
//		frequency++;
//	}
//	return 0;
//}

//�ڴ溯��
//�ڴ濽��  memcpy  �������ص����ڴ�  VS���ز��ص������Կ���   memory�����ڳ�����Ϊ�ڴ�  cpy��copy�����ƣ�����
//         memmove�������Դ����ص��ڴ�
//#include<stdio.h>
//#include<string.h>//memcpyͷ�ļ�
//#include<assert.h>
//void* my_memcpy(void* target, const void* source, size_t number) {// �Ҳ�֪���ڴ濽��������  ��void*   �� size_t�޷�������
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
//	if (target < source) {//ǰ->��
//		while (number--) {
//			*(char*)target = *(char*)source;
//			target = (char*)target + 1;
//			source = (char*)source + 1;
//		}
//	}
//	else {//��->ǰ
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
//	//ģ��ʵ��
//	int array1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int array2[10] = { 0 };
//	//my_memcpy(array2, array1, 20);
//	//my_memcpy(array1+2, array1, 20);//�Լ�д�Ĳ��ܿ����ص����ڴ�
//
//	//memmove(array1 + 2, array1, 20);
//	//ģ��ʵ��memmove
//	my_memmove(array1 + 2, array1, 20);
//	return 0;
//}

//memcmp �ڴ�Ƚ�   memset�ڴ�����
//#include<stdio.h>
//#include<string.h>//�ڴ溯��ͷ�ļ�
//int main() {
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[] = { 1, 1, 4 };
//	int judge = memcmp(array1, array2, 8);//  ��strcmp�ַ����Ƚ�����
//	printf("%d\n", judge);
//	int array3[10] = { 0 };
//	memset(array3, 1, 20);//���ֽ�Ϊ��λ�����ڴ�����
//	return 0;
//}


//�ṹ������
//1.ֻ�йؼ��� û������ ���ֱ���Ϊ�����ṹ������
//struct person
//{
//	char name[20];
//	int age;
//	double height;
//	struct//�����ṹ������
//	{
//		char phone[12];
//		char address[20];
//	};
//};
//#include<stdio.h>
//int main() {
//	struct person one = { "one",18,180.00,{"110120","�й���½"} };
//	printf("%s\n", one.address);
//	return 0;
//}//�ṹ����� one ����ͨ�� one.address ֱ�ӷ��������ṹ���Ա���� phone��������ԱȽϼ��
//  //��֮�����ͨ�� jim.�ṹ������.phone �����ʽṹ���Ա����

//2.�ṹ��������  ���ǰ���ͬ���͵ı��������ǰ���ͬ���͵�ָ��

//���ݽṹ���������ڴ��д洢�Ľṹ �� �������ݽṹ��һ����˳��� ���� 1��2��3��4���� һ����һ����ţ��ڶ���������û�����ڣ������������λ�ã������Ǹ�λ�ã�ÿ������ǰ����Ǵ�����ݵ������򣬺�����ָ����������ҵ��ң���Ҳ�����ҵ��㣩
//struct person
//{
//	char name[20];
//	int age;
//	struct person* next;//����� struct person next���ⲻ�����ݹ���
//	//          ָ�������С�ǿ���ã�  struct person* next�����ҵ����Լ�ͬ���͵Ľṹ
//}


//3.�ṹ�����Ͷ���
//#include<stdio.h>
//struct student1
//{
//	char one;//��һ����Ա�ڽṹ�����ƫ����Ϊ0�ĵ�ַ����������Ա����Ҫ���뵽��������������Ĭ�϶�������ó�Ա��С�Ľ�Сֵ��VS��8������������
//	int two;
//	char three;
//};//�ṹ���ܴ�СΪ����������������  ���Ƕ���˽ṹ�壬���ҽṹ�����������Ϳ�����
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
//	printf("%d\n", sizeof(two));//8   student1��2�ĳ�Աһ��һ��������ռ�ܿռ仹����Щ����� ��ռ�ÿռ�С�ľ���������һ��
//	return 0;
//}
/*
   Ϊʲô�����ڴ���룿
   1.ƽ̨ԭ�򣺲������е�Ӳ�����Է��������ַ�����ݣ�ĳЩӲ��ֻ��ֻ�ܻ�ȡ�ض������ݣ�����Ӳ��������쳣
   2.����ԭ�򣺷���δ������Ҫ���η��ʣ����ʶ�����Ҫһ�ξͿ�����
   �ܵ���˵���ṹ���������ÿռ�����ȡʱ�������
*/

//�޸�Ĭ�϶�����  �� offsetof(����������׵�ַ��ƫ��)��  ģ��ʵ��offsetof
//#include<stdio.h>
//#include <stddef.h>//offsetofͷ�ļ�
////#pragma pack(2)//�޸�Ĭ�϶�����Ϊ8
//struct student1
//{
//	char one;
//	int two;
//	char three;
//};
////#pragma pack()//�޸Ļ���
//
//#define OFFSETOF(struct_name,member_name)     (int*)&(((struct_name*)0)->member_name)
//
//int main() {
//	//printf("%d\n", sizeof(struct student1));//8
//	//printf("%d\n", offsetof/*Сд��������Ϊ�Ǻ���*/(struct student1, one));
//	//printf("%d\n", offsetof(struct student1, two));
//	//printf("%d\n", offsetof(struct student1, three));
//
//    printf("%d\n", OFFSETOF(struct student1, one));
//    printf("%d\n", OFFSETOF(struct student1, two));
//    printf("%d\n", OFFSETOF(struct student1, three));
//
//	return 0;
//}

/*4.λ�� 
    1.��Ա��int   ��  unsigned int  ��signed  int�� char 
    2.λ�γ�Ա�������һ��ð�ź�����
    3.λ�εĿռ��ǰ���4���ֽڣ�int������1���ֽڣ�char�������ٵ�

    4.λ�β���ƽ̨�ģ���һintλ�ε����з��Ż����޷��Ų�ȷ��
                     �ڶ�λ�������Ŀ��ȷ����16λ�������16��32λ����32��
                     ����λ�εĳ�Ա�������ҷ��仹�Ǵ������������δ����
                     ���ģ���һ���ṹ������λ�Σ��ڶ���λ�αȽϴ��޷����ɵ�һ��λ��ʣ��λʱ���������������ò�ȷ��
    

*/
//#include<stdio.h>
//struct word
//{
//    int a : 2;//��Աaռ2��bitλ
//    int b : 5;//��Աbռ5��bitλ
//    int c : 30;//��Աcռ30��bitλ
//};
//int main() {
//    printf("%d\n", sizeof(struct word));
//    return 0;
//}
//λ�ο��Ը��õĽ�ʡ�ռ䣬���п�ƽ̨������

/*  ö�ٵ��ŵ㣺
             1.���Ӵ���Ŀɶ��Ժ�ά����
             2.�����ͼ�飬��Ϊ�Ͻ�
             3.���ڵ���
             4.ʹ�÷��㣬һ�οɶ���������

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


//�����壨�����壩  ������ ����ͬһ��ռ�
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
//    //printf("%d\n", sizeof(test));//��ӡ�����4
//
//    //printf("%p\n", &test);
//    //printf("%p\n", &(test.one));
//    //printf("%p\n", &(test.two));//��ַһ��
//
//    int number = BigSmall();
//    if (number == 1) {
//        printf("С�˴洢\n");
//    }
//    else {
//        printf("��˴洢\n");
//    }
//    return 0;
//}
//�������С����  ������Ĵ�С����Ϊ����Ա�Ĵ�С �� ������Ա��С�������������ı���ʱ��Ҫ���뵽���������ı���


/*
    дһ��ͨѶ¼  1.���Դ��1000������Ϣ������+�Ա�+����+�绰+��ַ�� 2.��ɾ���
    AddressBook.h ��������    
    AddressBook.c ��������
    Դ.c ͨѶ¼ģ��
*/
//ͨѶ¼--��̬�汾
//#include"AddressBook.h"
////ͨѶ¼--��̬�汾  1.ͨѶ¼��ʼ�����ܴ����������Ϣ  ���������������������Ϣ
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
//    AddressBook  ab;//����ͨѶ¼
//    InitializationAddressBook(&ab);//��ʼ��ͨѶ¼
//    do {
//        menu();
//        printf("��ѡ��:->\n");
//        scanf("%d", &input);
//        switch (input)
//        {
//        case ADD:
//            //�����˵���Ϣ
//            AddPerson(&ab);
//            break;
//        case DEL:
//            //ɾ��
//            DelPerson(&ab);
//            break;
//        case SEARCH:
//            //����
//            SearchPerson(&ab);
//            break;
//        case REVIES:
//            //�޸�
//            ReviesPerson(&ab);
//            break;
//        case PRINTF:
//            //��ӡ
//            PrintfPerson(&ab);
//            break;
//        case QUIT:
//            SavePerson(&ab);//������Ϣ
//            FreePerson(&ab);//��̬�ͷſռ�
//            printf("�˳�ͨѶ¼\n");
//            break;
//        default:
//            printf("ѡ�����������ѡ��\n");
//            break;
//        }
//    } while (input);
//    return 0;
//}


//-------------��̬�ڴ���䣨�ȹ�̬������̬�ڴ濪���ڶ�����

//malloc
//#include<stdio.h>
//#include<stdlib.h>//malloc(���ٿռ�ֵδ����ʼ��) ,calloc��ֵ����ʼ������realloc����̬�ڴ�ռ������ͷ�ļ�
//int main() {
//    //int array[10] = { 0 };//ջ�����ٵ�10�����οռ�
//    //int* point = (int*)malloc(10 * sizeof(int));//��̬�ڴ濪��  ��Ϊmalloc����������void*����ǿ������ת��
//    //int* point1 = (int*)realloc(NULL, 40);//���������malloc��ֱ�ӿ�����ʮ���ֽ�
//    int* point = (int*)calloc(10, sizeof(int));
//
//    if (point == NULL) {//����ʧ�ܷ��ؿ�ָ��  ����malloc�ķ���ֵҪ�����
//         //�����Ķ�̬�ڴ����1.��NULLָ������ò���
//        perror("main");
//        return 0;
//    }
//
//    //ʹ��
//    int frequency = 0;
//    for (frequency = 0; frequency < 10; frequency++) { //�����Ķ�̬�ڴ����2.�Զ�̬�ڴ�ռ��Խ�����
//        printf("%d \n", point[frequency]);
//        *(point + frequency) = frequency;
//        printf("%d ", point[frequency]);
//        
//    }
//
//    //�����ռ�  �ټӵ�
//    int* start = realloc(point, 10 * sizeof(int));//realloc����ֵΪ����֮����ڴ��ַ���������㹻�Ŀռ�ֱ��׷�ӣ�ԭ�����ݲ������仯�����û���㹻�Ŀռ䣬����һ������װ�µģ�����һ���µ��ڴ��ַ��
//    if (start != NULL) {//����ʧ�ܷ��ؿ�ָ��
//        point = start;
//    }
//  
//    //����
//    free(point);//malloc��free�ɶԳ���  free���������NULL������ʲô���鶼����
//     //�����Ķ�̬�ڴ����3.free�ͷŷǶ�̬���ٿռ��ֻ�Ƿ�һ���֣���̬���ٵĵ�ָ�������ߣ��ͷ�ָ��֮��Ķ�̬�ռ䣩����ͬһ�鶯̬���ٵĿռ����ͷŻ������ͷţ��ڴ�й©��
//     //��̬���ٵĿռ䣬���ֻ��շ�ʽ��1.�����ͷ�2.���������
//    point = NULL;//�ֶ���Ϊ��ָ��
//    return 0;
//}

//��ܰ��ʾ����̬���ֽ����ݶ�   �������ڴ����

//�������飨C99 �ṹ�����һ����Ա��δ֪��С�����飩 ��������ǰ�����������һ����Ա
//#include<stdio.h>
//#include<stdlib.h>
//struct test
//{
//    int number;
//    //int array[];//��С��δ֪
//    int array[0];//Ҳ����д������
//    
//};
//int main()
//{
//    //printf("%d\n", sizeof(struct test));// �����4  sizeof����������������ڴ�
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
    

//ţ��С��
//1.��ӡX��ͼ��
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

//2.��ȡ�·�����
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

//3.��Ƴɼ�ȥ����ߺ������ÿ��ƽ��ֵ
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

//4.һ���������У�����һ��������������
//#include<stdio.h>
//int main()
//{
//    int array[51] = { 0 };
//    int number = 0;
//    //��������
//    scanf("%d", &number);
//    int frequency = 0;
//    for (frequency = 0; frequency < number; frequency++) {
//        scanf("%d", &array[frequency]);
//    }
//    //����Ҫ���������
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
//    //���
//    for (frequency = 0; frequency < number + 1; frequency++) {
//        printf("%d ", array[frequency]);
//    }
//    return 0;
//}

//5.��һ�����Ķ�����λ��������ż��λ�Ľ���
//#include<stdio.h>
//int main()
//{
//    int number = 10;
//    int middle = ((number & 0xaaaaaaaa) >> 1) + ((number & 0x55555555) << 1);
//    printf("%d\n", middle);
//    return 0;
//}

/*  
    �ļ��������ݷ��ڵ���Ӳ���ϣ��������ݳ־û�
     �����ϵ��ļ����ļ����ڳ�������������֣�1.�����ļ���Դ�����ļ�.c����Ŀ���ļ�.obj��(��ִ�г���.exe)2.�����ļ�����������ʱ��д�����ݣ�
     �ļ�����c:\code(<-�ļ�·��)\test��<-�ļ���������.txt���ļ���׺��
     һ����˵ͨ��FILE��ָ����ά��FILE�ṹ�ı������ļ���Ϣ����������pf��һ��ָ��FILE�������ݵ�ָ�������ͨ���ļ���Ϣ���е���Ϣ�����ʸ��ļ�
     �ļ���д֮ǰӦ�ȴ��ļ���fopen����ʹ�ý�����Ӧ�ر��ļ���fclose��

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
//    //���ļ�
//    //FILE* pf = fopen("D:\\ShiWeiGeng\\�½��ļ��� (11)\\VsCode\\Project1\\test.txt", "r");//����·��
//    FILE* pf = fopen("test.txt", "r");//���·��
//    if (pf == NULL) {
//        perror("fopen");
//        return 1;
//    }
//
//    //д�ļ�  -------------------------
//    
//    //����ˮ�������߶ȳ���ĸ����Ļ��Ӳ�̣�U�̣����̣�����ÿ�������Լ��Ķ�д��������Ϊ�˽����ż������������ж�д
//    //��ʵC���Գ���ֻҪ���У���Ĭ�ϴ���3����   stdin����׼������->����),stdout(��׼�����->��Ļ),stderr(��׼������->��Ļ)
//    
//    //1.�ַ��������	fputc	���������
//    /*fputc('h', pf);
//    fputc('e', pf);
//    fputc('l', pf);
//    fputc('l', pf);
//    fputc('o', pf);*/
//
//    /*fputc('h', stdout);//����Ļ��д��
//    fputc('e', stdout);
//    fputc('l', stdout);
//    fputc('l', stdout);
//    fputc('o', stdout);*/
//
//    //2.�ı����������	fputs	���������
//    /*fputs("abcdefg\n", pf);
//    fputs("hijklmn\n", pf);*/
//
//    //3.��ʽ���������	fprintf	���������
//    /*fprintf(pf, "%d %s", one.age, one.name);*/
//    //fprintfд��printf -> fprintf(stdout, "%d %s", one.age, one.name)   ������ͬ���ܲ�ͬ
//
//    //4.���������	fwrite	�ļ�
//    //fwrite(&one, sizeof(struct student), 1, pf);//�ַ����ö�����д��ȥ���ı�д��ȥһ��
//
//    //���ļ�---------------------------
//
//    //1.�ַ����뺯��	fgetc	����������  //�ļ���������������᷵��EOF
//    /*int number=fgetc(pf);
//    printf("%c\n", number);
//    number = fgetc(pf);
//    printf("%c\n", number);
//    number = fgetc(pf);
//    printf("%c\n", number);*/
//
//    /*int number = fgetc(stdin);//�Ӽ����϶�ȡ
//    printf("%c\n", number);
//    number = fgetc(stdin);
//    printf("%c\n", number);
//    number = fgetc(stdin);
//    printf("%c\n", number);*/
//
//    //2.�ı������뺯��	fgets	����������
//    //fgets(array, 4, pf);//��ȡ3��������һ����\0
//    //printf("%s\n", array);
//    //fgets(array, 4, pf);
//    //printf("%s\n", array);
//
//    //3.��ʽ�����뺯��	fscanf	����������
//    /*fscanf(pf, "%d %s", &(two.age), two.name);
//    //fscanfд��scanf-> fscanf(stdin, "%d %s", &(two.age), two.name);
//    printf("%d %s\n", two.age, two.name);*/
//
//    //4.����������	fread	�ļ�
//    /*fread(&two, sizeof(struct student), 1, pf);
//    printf("%d %s\n", two.age, two.name);*/
//
//    //�ļ��������д--------------------------------------------
//    
//    //  1.  fseek�����ļ�ָ���λ�ú�ƫ������λ�ļ�ָ��
//    //  2.ftell�����ļ�ָ����ʼλ�õ�ƫ����
//
//    fseek(pf, 2, SEEK_CUR);//  SEEK_CUR  ��ǰλ��   �� SEEK_END  ���λ��  �� SEEK_SET  ��ǰλ��
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
//    //  3.rewind�ļ�ָ���λ�÷��ص���ʼλ��
//
//    rewind(pf);
//    number = fgetc(pf);
//    printf("%c\n", number);
//
//
//    //�ر��ļ�-------------------------------
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}//      �ڴ����   (����/��ȡ��<----------------------------->�����/д�룩  �ļ���Ӳ�̣�


//sprintf  ��sscanf
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
//    //��һ����ʽ��������ת��Ϊ�ַ���
//    sprintf(middle2, "%s %d %s", one.name, one.age, one.gender);
//    printf("%s\n", middle2);
//
//    //��middle2�л�ԭһ���ṹ������
//    sscanf(middle2, "%s %d %s", middle1.name, &(middle1.age), middle1.gender);
//    printf("%s %d %s\n", middle1.name, middle1.age, middle1.gender);
//    return 0;
//        
//}

/*  �ļ����֪ʶ
1. һ�麯���Ա�
    scanf      ��Ա�׼����ĸ�ʽ���������  stdin
    fscanf     ��������������ĸ�ʽ���������  stdin/�ļ�
    sscanf     ��һ���ַ����ж�ȡһ����ʽ������

    printf     ��Ա�׼����ĸ�ʽ���������  stdout
    fprintf    ��������������ĸ�ʽ���������  stdout/�ļ�
    sprintf    ��һ����ʽ�������ݣ�ת��Ϊ�ַ���


 2. ���������ڴ����Զ�������ʽ�洢������ת���������棬���Ƕ������ļ�����ֵ�ȿ��Զ����ƴ洢Ҳ����ASCII��ʽ�洢��
   �����ASCII��ʽ�洢���ļ������ı��ļ����ַ���

   ����10000�������  ASCII��ʽ�洢����Ҫ����ֽڣ�ÿ���ַ�һ���ֽڣ�������������ʽ�������ֻҪ�ĸ��ֽ�

 3.�ļ�������  ���������������ȷŵ��ļ������� װ�����һ��ŵ�����  �����Ч��


 4.�ļ���ȡ�����ж�  feof�����ļ���ȡ�У�������feof��������ֱֵ���ж��ļ��Ƿ�����������ж϶�ȡ�ļ��������������ļ���β������

   fgetc�����ڶ�ȡ������ʱ�򣬻᷵��EOF  �� ������ȡ�����󣬷��ص��Ƕ�ȡ���ַ�����ASCIIֵ

   fgets�����ڶ�ȡ������ʱ�򣬻᷵�ؿ�ָ�� �� ������ȡ�����󣬷����ַ����ռ����ʼ��ַ

   fread�����ڶ�ȡ�����󣬷��ص���ʵ�ʶ�ȡ�ĸ�����������ֶ�ȡ�ĸ���С��ָ����Ԫ�ظ�������������һ��

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
//        //������ļ����󣬾Ͱ��ϸ��ļ��ر�
//        fclose(pf_read);
//        pf_read = NULL;
//        return 1;
//    }
//
//    //�ļ��򿪳ɹ� ��д�ļ�
//    int middle = 0;
//    while ((middle = fgetc(pf_read)) != EOF) {
//        //��ȡ�ɹ�  д�ļ�
//        fputc(middle, pf_write);
//    }
//    
//    if (feof(pf_read)) {//�������������������ļ���βָʾ��������£������ط���ֵ�����򣬽�������
//        printf("�ļ���������\n");
//    }
//    else if (ferror(pf_read)) {//�����������������Ĵ���ָʾ��������£������ط���ֵ��   ���򣬽������㡣
//        printf("�ļ���ȡʧ�ܽ���\n");
//    }
//
//    //�ر��ļ�
//    fclose(pf_read);
//    pf_read = NULL;
//    fclose(pf_write);
//    pf_write = NULL;
//
//    return 0;
//}

//atoi ��ģ��ʵ��atoi(�ַ���ת��Ϊ����)
//#include<stdio.h>
////#include<stdlib.h>//atoiͷ�ļ�
//#include<assert.h>
//#include<ctype.h>//  isspace  isdigitͷ�ļ�
//#include<limits.h>//INT_MAX  INT_MINͷ�ļ�
//
//enum is_legitimate
//{
//    NOOK,//0  �Ƿ�
//    OK//1     �Ϸ�
//};
//
//enum is_legitimate number;//��¼my_atoi����ֵ�Ƿ�Ϸ�
//
//int my_atoi(const char* point) {
//
//    int flag = 1;
//
//    //1.���Ŀ�ָ��
//    /*assert(point != NULL);*/
//    if (point == NULL) {
//        return 0;
//    }
//
//    //2.���ַ���
//    if (*point == '\0') {
//        return 0;
//    }
//
//    //3.�����հ��ַ�
//    while (isspace(*point)) {
//        point++;
//    }
//
//    //4.����������
//    if (*point == '+') {
//        flag = 1;
//        point++;
//    }
//    else if(*point=='-') {
//        flag = -1;
//        point++;
//    }
//
//    //5.���������ַ�
//    long long number1 = 0;
//    while (isdigit(*point)) {
//        number1 = number1 * 10 + flag*(*point - '0');
//        if (number1 > INT_MAX || number1 < INT_MIN) {//Ԥ��������Χ
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
//        //�������ַ�
//        return 0;
//    }
//
//}
//int main()
//{
//    const char* point = "  120";
//    int middle = my_atoi(point);
//    if (number == OK) {
//        printf("������ת����%d\n", middle);
//    }
//    else {
//        printf("�Ƿ�ת��\n");
//    }
//    
//    return 0;
//}

//�ҳ�����ֻ����һ�ε�����
//#include<stdio.h>
//void Find(int array[], int size, int* number1, int* number2)
//{
//
//    //1.�������������
//    int frequency = 0;
//    int middle = 0;
//    for (frequency = 0; frequency < size; frequency++) {
//        middle ^= array[frequency];
//    }
//
//    //2.����middle����һλΪ1
//    int find = 0;
//    for (frequency < 0; frequency < 32; frequency++)
//    {
//        if (((middle >> frequency) & 1) == 1) {
//            find = frequency;
//            break;
//        }
//    }
//
//    //3.��findλΪ1�ķ���һ���飬Ϊ0�ķ���һ����
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

/*--------------------------Ԥ�������ľ�ǿ��--------------------------------

    1.   .c�ļ���.exe�ļ���һ��.c�ļ�ͨ��������ת��Ϊ.obj�ļ���Ȼ��ͨ�������������ӿ⣬Ҳ����˵�ɾ�̬�⣩��Ū�ɿ�ִ�г���ͨ�����л�������ȡ���н��

    2.     ���뻷��
           
           ��������ΪԤ��������ͻ�������ɷ�
           Ԥ����Ԥ���룩����һ���ͷ�ļ��İ�����
                  �ڶ�#define����ĺ�ͷ��ŵ��滻��
                  ����ע��ɾ����
                  ��Щ�����ı�����
           ���룺��C���Դ���ת��Ϊ�����루1.�﷨����
                                         2.�������
                                         3.�������
                                         4.���Ż��ܣ�
           ��ࣺ��������ת�����˶�����ָ�����ָ� �����˷��ű�

           ���������Ѷ��Ŀ���ͷ�ļ��������ӣ�1.�ϲ��α�
                                            2.���ű�ĺϲ����ض�λ��
            
            ���л���1.������������ڴ��У�һ���ɲ���ϵͳ����ɡ��ڶ��������У��������������ֹ���ɻ�ͨ����ִ�д������
                    2.����ִ�п�ʼ��main������ʼ
                    3.ϵͳ�����ڴ�ռ�
                    4.��ֹ����������main��ֹ��������ֹ��
*/

//1.Ԥ�������
//#include<stdio.h>
//int main()
//{
//    //printf("%s\n", __FILE__);//���б༭��Դ�ļ�
//    //printf("%d\n", __LINE__);//�ļ���ǰ�к�
//    //printf("%s\n", __DATE__);//�ļ������������
//    //printf("%s\n", __TIME__);//�ļ��������ʱ��
//    //printf("%s\n", __FUNCTION__);//�ļ�������ĺ�����
//    
//    //��ȷ�÷�--д�ռ�
//    FILE* pf = fopen("test.txt", "a+");//׷������
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

//2.#define�����ʶ��ɧ����   
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
//#undef NUMBER//�Ƴ��궨��
//    //printf("%d\n", NUMBER);//����
//    return 0;
//}

//3. #���滻������Ϊ�ַ�������##������������������һ��
//#include<stdio.h>
//#define PRINTF(accept) printf("this letter "#accept" value is%d\n",accept);
//#define LINK(one,two) one##two
//int main()
//{
//    //printf("1.helloworld\n");
//    //printf("2.hello""world\n");//1. �� 2.��ӡЧ����ͬ 
//
//    int number1 = 10;
//    ////��ӡ  this letter number1  value is  10
//    //PRINTF(number1);//  #accept ��ʾ"number1"
//
//    printf("%d\n", LINK(numbe, r1));
//    return 0;
//}


/*5.��ͺ������𣨺��еĵط��ͺ���������  C����Ҳû����������  ����ϰ�ߺ�ȫ����д��������Ҫȫ����д��

   //�ŵ㣺1.�򵥵������� �� ��Ⱥ����ڳ���Ĺ�ģ���ٶȸ�ʤһ��
           2.���������ǹ̶�����  ������Ĳ����������޹�

   //ȱ�㣺1.ÿ��ʹ�ú꣬һ���ֺ����ͻ���뵽�����У������˳���ĳ��ȣ�����������ֻ����һ���ط���ÿ�ε��û�����Ǹ��ط�ͬһ�ݴ���
           2.�겻�ܵ���
           3.�����������޹أ�Ҳ�᲻���Ͻ������ܻ��������ȼ�������
           4.�겻���Եݹ飨��ֻ���򵥵��ı��滻����ֻ�滻һ�Σ�������ֵݹ鶨�壬�ͻ��޷�����ȫ�滻�����º�������ʱԭ����������������  ����������

*/

//6.�������루����Ƕ�ף�  �����ʹ��룬ɾ�˿�ϧ����ɾ���£��������ǿ���ѡ���Ա���   
//#include<stdio.h>
//#define NUMBER 
//int main()
//{
//
////#if 1-2 //if  �������ʽ
////    printf("���������");
////#endif
//
//    //���NUMBER�����ˣ�����������
////#ifdef NUMBER
////    printf("���������\n");
////#endif
////
////#if defined NUMBER
////    printf("���������\n");
////#endif
//
//
//    //���NUMBERû���壬����������
//#ifndef NUMBER
//    printf("�������û����\n");
//#endif
//
//#if !defined NUMBER
//    printf("�������û����\n");
//#endif
//
//#if 1==2
//    printf("��һ��ִ��\n");//��һ��Ϊ��  �ڶ�����ʹΪ��Ҳ��ִ��
//#elif 2==3
//    printf("�ڶ���ִ��\n");
//#else
//    printf("������ִ��\n");
//#endif
//    return 0;
//}

//7.�ļ�����
/*    
      " " �� < >����ͷ�ļ��ı��������ǣ����Ҳ��Բ�ͬ  
      " " 1.�ȴ��Լ��������ڵ�Ŀ¼���� 2.���1�Ҳ��������ڿ⺯����ͷ�ļ�Ŀ¼����
      < > ֱ��ȥ�⺯��ͷ�ļ����ڵ�Ŀ¼�²���

      Ƕ���ļ�����   ͬһ��ͷ�ļ����ظ���ΰ�������ζ����뱻������ݣ��������ࣩ  ��η�ֹ�أ�
                    1. #pragma once
                    2. #ifndef __AddressBook_H__
                       #define __AddressBook_H__
                       #endif
*/
#include<stdio.h>//���ļ�������C���Կ����ṩ�ĺ���   <>
#ifndef __AddressBook_H__
#define __AddressBook_H__
#include"stdio.h"//�����ļ��������Զ���ĺ���ʹ��  ""  //����Ч���е����
int main()
{  
    printf("HelloWorld\n");
    return 0;
}
#endif

