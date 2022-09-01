#define _CRT_SECURE_NO_WARNINGS
#include"AddressBook.h"

//静态初始化
//void InitializationAddressBook(AddressBook* point) {
//	point->size = 0;
//	memset(point->app, 0, sizeof(point->app));
//}

//动态初始化
void InitializationAddressBook(AddressBook* point) {
	point->app = (person*)malloc(CAPACITY * sizeof(person));
	if (point->app == NULL) {
		perror("InitializationAddressBook");
		return;
	}
	point->size = 0;
	point->capacity = CAPACITY;

	//加载文件
	LoadAddressBook(point);
}

//动态释放
void FreePerson(AddressBook* point) {
	free(point->app);
	point->app = NULL;
	point->size = 0;
	point->capacity = 0;
}

//静态增
//void AddPerson(AddressBook* point) {
//	if (point->size == MAX) {
//		printf("通讯录已满，无法添加\n");
//		return;
//	}
//	//增加
//	printf("请输入名字：->");
//	scanf("%s", point->app[point->size].name);
//	printf("请输入性别：->");
//	scanf("%s", point->app[point->size].gender);
//	printf("请输入年龄：->");
//	scanf("%d", &(point->app[point->size].age));//年龄需要取地址
//	printf("请输入电话：->");
//	scanf("%s", point->app[point->size].telephone);
//	printf("请输入地址：->");
//	scanf("%s", point->app[point->size].address);
//
//	point->size++;
//	printf("增加成功\n");
//}
 

//增容函数
void CapacityIncrease(AddressBook* point) {
	if (point->size == point->capacity) {
		person* point1 = (person*)realloc(point->app, (point->capacity + SIZE) * sizeof(person));
		if (point1 != NULL) {
			point->app = point1;
			point->capacity += SIZE;
			printf("增容成功\n");
		}
		else {
			perror("AddPerson");
			printf("添加联系人失败\n");
			return;
		}
	}
}

//动态增
void AddPerson(AddressBook* point) {
	//增容
	CapacityIncrease(point);
	
	//增加
	printf("请输入名字：->");
	scanf("%s", point->app[point->size].name);
	printf("请输入性别：->");
	scanf("%s", point->app[point->size].gender);
	printf("请输入年龄：->");
	scanf("%d", &(point->app[point->size].age));//年龄需要取地址
	printf("请输入电话：->");
	scanf("%s", point->app[point->size].telephone);
	printf("请输入地址：->");
	scanf("%s", point->app[point->size].address);

	point->size++;
	printf("增加成功\n");
}



//打印
void PrintfPerson(AddressBook* point) {
	//标题打印
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "性别", "年龄", "电话", "地址");
	//打印数据
	int frequency = 0;
	for (frequency = 0; frequency < point->size; frequency++) {
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n", 
		    point->app[frequency].name,
			point->app[frequency].gender,
			point->app[frequency].age,
			point->app[frequency].telephone,
			point->app[frequency].address);
	}
}


static int FindName(AddressBook* point, char name[]) {//修饰函数  只在本文件用即可，外部找不到
	int frequency = 0;
	for (frequency = 0; frequency < point->size; frequency++) {
		if (strcmp(point->app[frequency].name, name) == 0) {
			return frequency;
		}
	}
	return -1;
}



//删除
void DelPerson(AddressBook* point) {
	if (point->size == 0) {
		printf("通讯录为空，无需删除\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("请输入删除人的名字:->");
	scanf("%s", name);
	//有没有删除人的信息
	int who = FindName(point, name);
	if (who == -1) {
		printf("删除人不存在\n");
		return;
	}
	//删除
	int frequency = 0;
	for (frequency = 0; frequency < point->size - 1; frequency++) {
		point->app[frequency] = point->app[frequency + 1];
	}
	point->size--;
	printf("删除成功\n");
}


//查找
void SearchPerson(AddressBook* point) {
	char name[MAX_NAME] = { 0 };
	printf("请输入查找人的名字:->");
	scanf("%s", name);
	//有没有查找人的信息
	int who = FindName(point, name);
	if (who == -1) {
		printf("查找人不存在\n");
		return;
	}
	else {
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "性别", "年龄", "电话", "地址");
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n",
			point->app[who].name,
			point->app[who].gender,
			point->app[who].age,
			point->app[who].telephone,
			point->app[who].address);
	}
}

//改
void ReviesPerson(AddressBook* point) {
	char name[MAX_NAME] = { 0 };
	printf("请输入修改人的名字:->");
	scanf("%s", name);
	//有没有修改人的信息
	int who = FindName(point, name);
	if (who == -1) {
		printf("修改人不存在\n");
		return;
	}
	else {
		printf("请输入名字：->");
		scanf("%s", point->app[who].name);
		printf("请输入性别：->");
		scanf("%s", point->app[who].gender);
		printf("请输入年龄：->");
		scanf("%s", &(point->app[who].age));//年龄需要取地址
		printf("请输入电话：->");
		scanf("%s", point->app[who].telephone);
		printf("请输入地址：->");
		scanf("%s", point->app[who].address);
		printf("修改成功\n");
	}
}

void SavePerson(AddressBook* point)
{
	//打开文件
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL) {
		perror(SavePerson);
		return;
	}
	//写
	int frequency = 0;
	for (frequency = 0; frequency < point->size; frequency++) {
		fwrite(point->app + frequency, sizeof(person), 1, pf);
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
}

//加载文件
void LoadAddressBook(AddressBook* point) {

	//打开文件
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		perror(LoadAddressBook);
		return;
	}

	//读文件
	person middle = { 0 };
	while (fread(&middle, sizeof(person), 1, pf)) {
		CapacityIncrease(point);//是否考虑增容
		point->app[point->size] = middle;
		point->size++;
	}

	//关闭文件
	fclose(pf);
	pf = NULL;

}