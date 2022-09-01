#define _CRT_SECURE_NO_WARNINGS
#include"AddressBook.h"

//��̬��ʼ��
//void InitializationAddressBook(AddressBook* point) {
//	point->size = 0;
//	memset(point->app, 0, sizeof(point->app));
//}

//��̬��ʼ��
void InitializationAddressBook(AddressBook* point) {
	point->app = (person*)malloc(CAPACITY * sizeof(person));
	if (point->app == NULL) {
		perror("InitializationAddressBook");
		return;
	}
	point->size = 0;
	point->capacity = CAPACITY;

	//�����ļ�
	LoadAddressBook(point);
}

//��̬�ͷ�
void FreePerson(AddressBook* point) {
	free(point->app);
	point->app = NULL;
	point->size = 0;
	point->capacity = 0;
}

//��̬��
//void AddPerson(AddressBook* point) {
//	if (point->size == MAX) {
//		printf("ͨѶ¼�������޷����\n");
//		return;
//	}
//	//����
//	printf("���������֣�->");
//	scanf("%s", point->app[point->size].name);
//	printf("�������Ա�->");
//	scanf("%s", point->app[point->size].gender);
//	printf("���������䣺->");
//	scanf("%d", &(point->app[point->size].age));//������Ҫȡ��ַ
//	printf("������绰��->");
//	scanf("%s", point->app[point->size].telephone);
//	printf("�������ַ��->");
//	scanf("%s", point->app[point->size].address);
//
//	point->size++;
//	printf("���ӳɹ�\n");
//}
 

//���ݺ���
void CapacityIncrease(AddressBook* point) {
	if (point->size == point->capacity) {
		person* point1 = (person*)realloc(point->app, (point->capacity + SIZE) * sizeof(person));
		if (point1 != NULL) {
			point->app = point1;
			point->capacity += SIZE;
			printf("���ݳɹ�\n");
		}
		else {
			perror("AddPerson");
			printf("�����ϵ��ʧ��\n");
			return;
		}
	}
}

//��̬��
void AddPerson(AddressBook* point) {
	//����
	CapacityIncrease(point);
	
	//����
	printf("���������֣�->");
	scanf("%s", point->app[point->size].name);
	printf("�������Ա�->");
	scanf("%s", point->app[point->size].gender);
	printf("���������䣺->");
	scanf("%d", &(point->app[point->size].age));//������Ҫȡ��ַ
	printf("������绰��->");
	scanf("%s", point->app[point->size].telephone);
	printf("�������ַ��->");
	scanf("%s", point->app[point->size].address);

	point->size++;
	printf("���ӳɹ�\n");
}



//��ӡ
void PrintfPerson(AddressBook* point) {
	//�����ӡ
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	//��ӡ����
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


static int FindName(AddressBook* point, char name[]) {//���κ���  ֻ�ڱ��ļ��ü��ɣ��ⲿ�Ҳ���
	int frequency = 0;
	for (frequency = 0; frequency < point->size; frequency++) {
		if (strcmp(point->app[frequency].name, name) == 0) {
			return frequency;
		}
	}
	return -1;
}



//ɾ��
void DelPerson(AddressBook* point) {
	if (point->size == 0) {
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("������ɾ���˵�����:->");
	scanf("%s", name);
	//��û��ɾ���˵���Ϣ
	int who = FindName(point, name);
	if (who == -1) {
		printf("ɾ���˲�����\n");
		return;
	}
	//ɾ��
	int frequency = 0;
	for (frequency = 0; frequency < point->size - 1; frequency++) {
		point->app[frequency] = point->app[frequency + 1];
	}
	point->size--;
	printf("ɾ���ɹ�\n");
}


//����
void SearchPerson(AddressBook* point) {
	char name[MAX_NAME] = { 0 };
	printf("����������˵�����:->");
	scanf("%s", name);
	//��û�в����˵���Ϣ
	int who = FindName(point, name);
	if (who == -1) {
		printf("�����˲�����\n");
		return;
	}
	else {
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n",
			point->app[who].name,
			point->app[who].gender,
			point->app[who].age,
			point->app[who].telephone,
			point->app[who].address);
	}
}

//��
void ReviesPerson(AddressBook* point) {
	char name[MAX_NAME] = { 0 };
	printf("�������޸��˵�����:->");
	scanf("%s", name);
	//��û���޸��˵���Ϣ
	int who = FindName(point, name);
	if (who == -1) {
		printf("�޸��˲�����\n");
		return;
	}
	else {
		printf("���������֣�->");
		scanf("%s", point->app[who].name);
		printf("�������Ա�->");
		scanf("%s", point->app[who].gender);
		printf("���������䣺->");
		scanf("%s", &(point->app[who].age));//������Ҫȡ��ַ
		printf("������绰��->");
		scanf("%s", point->app[who].telephone);
		printf("�������ַ��->");
		scanf("%s", point->app[who].address);
		printf("�޸ĳɹ�\n");
	}
}

void SavePerson(AddressBook* point)
{
	//���ļ�
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL) {
		perror(SavePerson);
		return;
	}
	//д
	int frequency = 0;
	for (frequency = 0; frequency < point->size; frequency++) {
		fwrite(point->app + frequency, sizeof(person), 1, pf);
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

//�����ļ�
void LoadAddressBook(AddressBook* point) {

	//���ļ�
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		perror(LoadAddressBook);
		return;
	}

	//���ļ�
	person middle = { 0 };
	while (fread(&middle, sizeof(person), 1, pf)) {
		CapacityIncrease(point);//�Ƿ�������
		point->app[point->size] = middle;
		point->size++;
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;

}