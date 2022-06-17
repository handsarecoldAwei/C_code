
//   你给三年级的弟弟算一下语文和数学总分
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
//如果你要给全班算一下语文数学的总分呢？重复的代码罗列起来，这多low啊  这就用到了函数

//#include<stdio.h>
//int ADD(int chinese, int math) //int 函数类型；ADD函数名字；（函数参数1，函数参数2）
//{
//	return chinese + math;//return函数返回值类型     
//}
////就比如吃什么 拉什么  肉（酸性食物）吃进肚子里  排泄出来就具有酸性
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
 
    前面讲到一维数组，可以理解为X轴； 二维数组呢就是X-Y轴（平面坐标系）
*/
#include<stdio.h>
int main()
{
	int group[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };//一维数组
	int group_two[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };//二维数组  相当于三行三列
	//访问一下一维数组  
	printf("%d\n", group[0]);
	printf("%d\n", group[1]);
	printf("%d\n", group[2]);
	//访问二维数组
	printf("%d\n", group_two[2][0]);//访问[][]都要写上下标

	//拿一维数组举例，下标是从0开始的，你想得到1，就是访问group[0],o处的下标，以此类推
	return 0;
}