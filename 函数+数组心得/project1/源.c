
//   ������꼶�ĵܵ���һ�����ĺ���ѧ�ܷ�
//#include<stdio.h>
//int main()
//{
	//int chinese = 0;
	//int math = 0;
	//scanf_s("%d %d", &chinese, &math);
//	int sum = chinese + math;
//	printf("sum = %d\n", sum);
//	return 0;
//}
//�����Ҫ��ȫ����һ��������ѧ���ܷ��أ��ظ��Ĵ����������������low��  ����õ��˺���

//#include<stdio.h>
//int ADD(int chinese, int math) //int �������ͣ�ADD�������֣�����������1����������2��
//{
//	return chinese + math;//return��������ֵ����     
//}
////�ͱ����ʲô ��ʲô  �⣨����ʳ��Խ�������  ��й�����;�������
//int main()
//{
//	int chinese = 0;
//	int math = 0;
//	scanf_s("%d %d", &chinese, &math);
//	int sum =ADD(chinese, math);
//	printf("sum =  %d\n", sum);
//	return 0;
//}

/*----------------------------------------------------------------
 
    ǰ�潲��һά���飬�������ΪX�᣻ ��ά�����ؾ���X-Y�ᣨƽ������ϵ��
*/
#include<stdio.h>
int main()
{
	int group[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };//һά����
	int group_two[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };//��ά����  �൱����������
	//����һ��һά����  
	printf("%d\n", group[0]);
	printf("%d\n", group[1]);
	printf("%d\n", group[2]);
	//���ʶ�ά����
	printf("%d\n", group_two[2][0]);//����[][]��Ҫд���±�

	//��һά����������±��Ǵ�0��ʼ�ģ�����õ�1�����Ƿ���group[0],o�����±꣬�Դ�����
	return 0;
}