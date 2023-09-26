#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//ѧ���ṹ��
typedef struct student
{
	long long int number;//ѧ��
	char name[10];//����
	char grade[20];//�༶
	int math;//��ѧ
	int chinese;//����
	int english;//Ӣ��
	struct student* next;//ָ����һ���ڵ��ָ��
}student;
//����ķ�װ ������
typedef struct List
{
	student * front;//ͷָ��
	student* tail;//βָ�� �������
}List;
List* createList()//����
{
	List* list = calloc(1, sizeof(List));
	if (list == NULL)
	{
		return NULL;
	}
	return list; 
}
student* createStudent()
{
	
	student* newNode = calloc(1, sizeof(student));
	if (!newNode)
	{
		return NULL;
	}
	return newNode;
}
//���ļ��ж�ȡ���ݲ�����һ��������
List* createlistfromfile(const char* filename)//�ļ���
{
	//����ͷ�ڵ� calloc ���Զ���ʼ��������ڴ�
	student* headNode = createStudent();
	//���ͷ�ڵ�����ɹ����򴴽�����
	List* list = createList();
	list->front = headNode;//ͷ�ڵ�
	list->tail = headNode;//β�ڵ�

	
	FILE* fp = fopen(filename, "r");//rΪ�ɶ�,��ȡ
	//�����Ա��
	if (fp == NULL)
	{
		perror("open file failed");
		return list;
	}
	//ȥ����ͷ
	char arr[1024] = { 0 };
	fgets(arr,1024,fp);

	//��ȡ�ļ� fscanf д
	while (!feof(fp))//�ж��Ƿ����
	{
		student* newNode = createStudent();
		int ret = fscanf(fp, "%lld %s %s %d %d %d\n", &newNode->number, &newNode->name, &newNode->grade, &newNode->math, &newNode->chinese, &newNode->english);
		if (ret == EOF)
		{
			break;
		}
		//�ѵ�ǰ�ڵ��������
			list->tail->next = newNode;
			list->tail = newNode;
	}
	fclose(fp);
	return list;
}
//�鿴����ѧ����Ϣ
void printAll(List* list)
{
	//��ȡ��һ���ڵ��ָ��
	student* curNode = list->front->next;
	//printf()//��ͷ
	while (curNode != NULL)
	{
		printf("%lld   %s    %s   %d   %d   %d\n", curNode->number, curNode->name, curNode->grade, curNode->math, curNode->chinese, curNode->english);
		curNode = curNode->next;//�ƶ�curNode
	}
}
//�鿴ѧ����Ϣ
//��ѧ�Ų���
void searchNumber(List* list,long long int number)
{
	student* curNode = list->front->next;
	while (curNode != NULL)
	{
		if (number == curNode->number)
		{
			printf("%lld   %s    %s   %d   %d   %d\n", curNode->number, curNode->name, curNode->grade, curNode->math, curNode->chinese, curNode->english);
			break;
		}
		curNode = curNode->next;
	}
}
//����������
void searchname(List* list, const char* name)
{
	student* curNode = list->front->next;
	while (curNode != NULL)
	{
		if (strcmp(name, curNode->name) == 0)
		{
			printf("%lld   %s    %s   %d   %d   %d\n", curNode->number, curNode->name, curNode->grade, curNode->math, curNode->chinese, curNode->english);

		}
		curNode = curNode->next;
	}
}
//ɾ��
void removeStudent(List* list, long long int number)
{
	student* prevNode = list->front;
	while (prevNode->next != NULL)
	{
		//�ҵ���
		if (prevNode->next->number)
		{
			break;
		}
		prevNode = prevNode->next;
	}
	if (prevNode && prevNode->next != NULL)
	{
		//�ȱ���Ҫɾ���Ľڵ�
		student* delNode = prevNode->next;

		prevNode->next = delNode->next;
		free(delNode);
		if (prevNode->next == list->tail)
		{
			list->tail = prevNode;
		}
	}
}
void menu()
{
	printf("***********ѧ������ϵͳ**************\n");
	printf("***********1.�鿴����ѧ���ɼ�********\n");
	printf("***********2.���ѧ��****************\n");
	printf("***********3.ɾ��ѧ��****************\n"); 
	printf("***********4.����ѧ��****************\n");

}

int main()
{
	List* list = createlistfromfile();
	int op = 0;
	while (true)
	{
		menu();
		printf("input");
		scanf("%d", &op);
		switch (op)
		{
			case 1:
				printAll(list);//�鿴����ѧ��
				break;
			case 2:
				break;
			case 3:
			{
				long long int number = 0;
				printf("������ɾ��ѧ��ѧ��");
				scanf("%d", number);
				removeStudent(list, number);
			}	
				break;
			case 4:
			{
				printf("******��������********");
				printf("****1����ѧ�Ų���*****");
				printf("****1������������*****");
				printf("input:");
				scanf("%d", &op);
				if (op == 1)
				{
					long long int number = -1;
					printf("play number");
					scanf("%lld", &number);
					searchNumber(list, number);
				}
				else
				{
					char name[10] = { 0 };
					printf("play name");
					getchar();
					gets_s(name,10);
					searchname(list,name);
				}
			}
				break;
			default:
				break;
		}
		//����ͣ
		system("pause");
		//������
		system("cls");
	}
	return 0;
}