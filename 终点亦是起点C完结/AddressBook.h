#pragma once

#include<stdio.h>
#include<stdlib.h>//动态用到的头文件
#include<string.h>

#define MAX_NAME 20
#define MAX_GENDER 10
#define MAX_TELEPHONE 12
#define MAX_ADDRESS 30
#define MAX 1000

//动态版本
#define CAPACITY 3
#define SIZE 2

//联系人定义
typedef struct person
{
	char name[MAX_NAME];
	char gender[MAX_GENDER];
	int age;
	char telephone[MAX_TELEPHONE];
	char address[MAX_ADDRESS];
}person;

//静态通讯录定义
//typedef struct AddressBook
//{
//	person app[MAX];//存放人的信息
//	int size;//记录当前通讯录有效信息个数
//}AddressBook;

//动态通讯录定义
typedef struct AddressBook
{
	person* app;//存放人的信息
	int size;//记录当前通讯录有效信息个数
	int capacity;//记录当前通讯录的最大容量
}AddressBook;


//初始化通讯录
void InitializationAddressBook(AddressBook* point);

//增
void AddPerson(AddressBook* point);

//打印
void PrintfPerson(const AddressBook* point);//打印不修改 代码更健康

//删
void DelPerson(AddressBook* point);

//查
void SearchPerson(AddressBook* point);

//改
void ReviesPerson(AddressBook* point);

//动态释放空间
void FreePerson(AddressBook* point);

//保存通讯录信息
void SavePerson(AddressBook* point);

//加载文件
void LoadAddressBook(AddressBook* point);

//增容函数
void CapacityIncrease(AddressBook* point);