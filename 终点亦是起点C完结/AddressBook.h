#pragma once

#include<stdio.h>
#include<stdlib.h>//��̬�õ���ͷ�ļ�
#include<string.h>

#define MAX_NAME 20
#define MAX_GENDER 10
#define MAX_TELEPHONE 12
#define MAX_ADDRESS 30
#define MAX 1000

//��̬�汾
#define CAPACITY 3
#define SIZE 2

//��ϵ�˶���
typedef struct person
{
	char name[MAX_NAME];
	char gender[MAX_GENDER];
	int age;
	char telephone[MAX_TELEPHONE];
	char address[MAX_ADDRESS];
}person;

//��̬ͨѶ¼����
//typedef struct AddressBook
//{
//	person app[MAX];//����˵���Ϣ
//	int size;//��¼��ǰͨѶ¼��Ч��Ϣ����
//}AddressBook;

//��̬ͨѶ¼����
typedef struct AddressBook
{
	person* app;//����˵���Ϣ
	int size;//��¼��ǰͨѶ¼��Ч��Ϣ����
	int capacity;//��¼��ǰͨѶ¼���������
}AddressBook;


//��ʼ��ͨѶ¼
void InitializationAddressBook(AddressBook* point);

//��
void AddPerson(AddressBook* point);

//��ӡ
void PrintfPerson(const AddressBook* point);//��ӡ���޸� ���������

//ɾ
void DelPerson(AddressBook* point);

//��
void SearchPerson(AddressBook* point);

//��
void ReviesPerson(AddressBook* point);

//��̬�ͷſռ�
void FreePerson(AddressBook* point);

//����ͨѶ¼��Ϣ
void SavePerson(AddressBook* point);

//�����ļ�
void LoadAddressBook(AddressBook* point);

//���ݺ���
void CapacityIncrease(AddressBook* point);