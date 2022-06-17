/*今讲一下判断语句，生活中也常遇到（腾讯防沉迷系统）

    1.第一种  if（如果） else if（或者）   else（否则）

  举一个例子  如果你好好学习，就输入一个1,校招拿个好的offer，走向人生巅峰；或者你是不是要继承家业，请输入2；否则毕业等于失业，回家开荒垦土

*/

//#include<stdio.h>
//int main()
//{
//	int volunteer = 0;//定义
//	scanf_s("%d", &volunteer);//微软认为scanf加个_s(safety)这样是安全的
//	if (volunteer == 1)//在C中一个=为赋值；a==b两个表示a是否等于b    if(条件)
//	{
//		printf("offer到手，人生巅峰指日可待\n");
//	}
//	else if (volunteer == 2) {//else if(条件)
//		printf("家里有矿，不好意思\n");
//	}
//	else {
//		printf("害，三亩田地，自力更生吧\n");
//	}
//	return 0;
//}//if（）；else if（）； else后面一定要加{}；就相当于，你拿这皇帝玉玺{}管三军六将；没拿只能管下面一行

//if也可以嵌套使用   比如你首先成年然后成绩超过90分才可以打游戏；否则，赶紧回家学习去，不然你家长拿着棍子开始挥霍了
//#include<stdio.h>
//int main()
//{
//	int age = 0;
//	int score = 0;
//	scanf_s("%d %d", &age, &score);
//	if (age >= 18) {
//		if (score >= 90) {
//			printf("上号上号速度速度，车队发车\n");
//		}
//		else {
//			printf("抱歉，成绩有点小偏差，好好学习");
//		}
//	}
//	else {
//		printf("抱歉您还未成年\n");
//
//	}
//	return 0;
//}


/*----------------------------

   2.switch语句   举例子：有一道选择题，选出正能量的一项
*/
#include<stdio.h>
int main() {
    int lol = 0;
    scanf_s("%d", &lol);
    switch (lol) {//你把switch就相当于一个选择题题目
    case 1://case就是选项
        printf("黑虎掏心\n");
        break;//break就是打破，你选完了就不要纠结这道题了
    case 2:
        printf("倒打一耙\n");
        break;
    case 3:
        printf("浩然正气");
        break;
    default:
        printf("你想干啥？？\n");
            break;
    }
    return 0;

}
