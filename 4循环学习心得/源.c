/*
   讲一下循环   现实生活中有些事必须一直做（吃饭啊）总有一天，你会看到坚持的意义

   先要说一点，给定条件中非零非空为真，零和空为假   不知道你是否英语Zero（零）有无意义，空洞的意思

   1.while循环  拿淘金热举例(黄金矿可以挖1000，第500次已经预测到是铁矿，扔掉不要)
*/
//#include<stdio.h>
//#define Frequency 1000//#define定义的标识符常量
//int main()
//{
//	int rush = 1;//第一次开始挖
//	while (rush <= Frequency) {//while（这里写条件，条件为真执行，假跳过）
//		if (rush == 500) {
//			printf("铁矿扔掉不要！\n");
//			rush ++;//就相当于rush = rush + 1
//			break;//如果加break呢？  //直接跳出循环（注意不是判断语句）
//			
//		}
//		printf("rush = %d哇塞！金矿\n", rush);
//		rush++;
//	}
//	printf("该死的资本主义家，我要休息，停止压榨！！\n");
//	return 0;
//	
//}


/*
     do while循环（先干再判断）     while循环是先判断条件，在进行下一步；

	              举例： 挖矿1000次
*/
#include<stdio.h>
#define Frequency 1000
int main() {
	int rush = 1;
	
	do {
		rush++;
		printf("rush = %d\n", rush);
		
	} while (rush <= Frequency);
	printf("山上的笋都被你挖完了\n");
	return 0;
}

/*--------------------------------------

  2.for循环   挖矿1000次

 */

//#include<stdio.h>
//#define Frequency 1000
//int main()
//{
//	int rush = 1;
//	for (rush = 1; rush <= Frequency; rush++) {//相比于while，直接都写在for（）里了
//		printf("rush = %d\n", rush);
//	}
//	printf("山上的笋都被你挖完了\n");
//	return 0;
//}

/*
    除了上述的循环  还有一种循环，死循环


	死循环有没有用呢？ 

	答案是有用的！在某些特定的场合的确要用到死循环（一直执行）很简单一个例子，正常情况下你不可能打着打着LOL给你退出了吧？玩微信玩着玩着给你退掉了吧？

*/