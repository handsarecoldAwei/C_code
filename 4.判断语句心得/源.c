/*��һ���ж���䣬������Ҳ����������Ѷ������ϵͳ��

    1.��һ��  if������� else if�����ߣ�   else������

  ��һ������  �����ú�ѧϰ��������һ��1,У���ø��õ�offer�����������۷壻�������ǲ���Ҫ�̳м�ҵ��������2�������ҵ����ʧҵ���ؼҿ��Ŀ���

*/

//#include<stdio.h>
//int main()
//{
//	int volunteer = 0;//����
//	scanf_s("%d", &volunteer);//΢����Ϊscanf�Ӹ�_s(safety)�����ǰ�ȫ��
//	if (volunteer == 1)//��C��һ��=Ϊ��ֵ��a==b������ʾa�Ƿ����b    if(����)
//	{
//		printf("offer���֣������۷�ָ�տɴ�\n");
//	}
//	else if (volunteer == 2) {//else if(����)
//		printf("�����п󣬲�����˼\n");
//	}
//	else {
//		printf("������Ķ��أ�����������\n");
//	}
//	return 0;
//}//if������else if������ else����һ��Ҫ��{}�����൱�ڣ�������ʵ�����{}������������û��ֻ�ܹ�����һ��

//ifҲ����Ƕ��ʹ��   ���������ȳ���Ȼ��ɼ�����90�ֲſ��Դ���Ϸ�����򣬸Ͻ��ؼ�ѧϰȥ����Ȼ��ҳ����Ź��ӿ�ʼ�ӻ���
//#include<stdio.h>
//int main()
//{
//	int age = 0;
//	int score = 0;
//	scanf_s("%d %d", &age, &score);
//	if (age >= 18) {
//		if (score >= 90) {
//			printf("�Ϻ��Ϻ��ٶ��ٶȣ����ӷ���\n");
//		}
//		else {
//			printf("��Ǹ���ɼ��е�Сƫ��ú�ѧϰ");
//		}
//	}
//	else {
//		printf("��Ǹ����δ����\n");
//
//	}
//	return 0;
//}


/*----------------------------

   2.switch���   �����ӣ���һ��ѡ���⣬ѡ����������һ��
*/
#include<stdio.h>
int main() {
    int lol = 0;
    scanf_s("%d", &lol);
    switch (lol) {//���switch���൱��һ��ѡ������Ŀ
    case 1://case����ѡ��
        printf("�ڻ�����\n");
        break;//break���Ǵ��ƣ���ѡ���˾Ͳ�Ҫ�����������
    case 2:
        printf("����һ��\n");
        break;
    case 3:
        printf("��Ȼ����");
        break;
    default:
        printf("�����ɶ����\n");
            break;
    }
    return 0;

}
