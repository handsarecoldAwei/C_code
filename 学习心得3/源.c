/*

   ��ֽ�һ��

   ����������˼�壬���Ա仯����
   ���������仯����

   ��дһ��������ֽ�ϣ�Ҫռֽ������ɣ�����ô����һ�������أ�

*/

#include<stdio.h>
 
#define MAX 1000 // #defineԤ����ָ��  MAX���������  1000��ֵ

enum Week
{

	Monday = 1,//��ʼ������
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday,
   
	//enum���൱��һ���Ȳ����У��������ʼ����������Monday = 0; Tuesday = 1�Դ�����
};

int main()
{
	int number = 100; //��100���ֵ����int���������ͣ�number������������
	char word = "Hello";//��Hello����ַ�������char���ַ��ͣ�word������������
	double fraction = 88.6;

	  //Ϊʲô˵number word fraction �Ǳ������أ�

	number = number - 5;
	printf("%d\n", number);

	//��ӡint������%d�� char���ַ���%s�����ַ�%c����double��%lf����float��%f���ȵ�
	// 
//--------------------------------------------------------------

	int a = 50;
	char w = "haha";
	double f = 1.1;

	//�е�����������һ����������ʵ���ǲ��淶�ģ���������룬һ����Ŀ��ǧ�����д��룬����int a ��ɶ����һ����զ˵���ţ� ����֪�⣡

	//�»���������    ֲ���ս��ʬ�е�����  sun_flower ��������ֱ�Ӽ�һ���»���

	//�շ�������      sunFlower �ڶ�����������ĸ��д

//------------------------------------------------------------------

//��һ�³���  ��һ�����泣��

	char laugh = "haha";//�ַ�������

	char number_1 = 65; //�ַ�����

	printf("%c\n", number_1);   //��ӡ������A��ASCII�������Ƕ�֪������������Ƕ��������ԣ�������������̵���ĸ�ͷ��ŵĵ��أ�ASCII����Ӧ����

// �ڶ���  const��Ӣ����˼���� - �ؼ��֣����εĳ���

	const int number_one = 50; //  ��ʾ���������������ڽ��б仯�����������Ǳ����������й�����������
	//number_one = number_one - 50;

//  ������  define��Ӣ����˼���壩����ı�ʶ������  

	int number_two = MAX;
	printf("%d\n", number_two);//��ӡ���1000

//  ������ ö�ٳ������������кܶ����һһ�оٵĳ��������ڼ���

	enum Week number_zero = Thursday;
	printf("%d\n", number_zero);

//----------------------------------------------------------

	//��ѧ�еļӼ��˳���C��զд��   ������������
	int math_number = 0;
	int Math_number = 0;
	scanf_s("%d %d", &math_number, &Math_number);//scanf_s��VS�������ṩ�ģ�����C�涨�ģ�������scanf����ִ���Ϊ���������������ܹ�ȥ������ʹ��scanf
	int add = math_number + Math_number;//���� + - * / %��ȡ��) ��ʵ��һ����
	printf("%d\n", add);


	int days = 8 / 3;

	printf("%d|n", days);//���2
	

	return 0;
}

