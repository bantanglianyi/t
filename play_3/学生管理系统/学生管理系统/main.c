#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//学生结构体
typedef struct student
{
	long long int number;//学号
	char name[10];//姓名
	char grade[20];//班级
	int math;//数学
	int chinese;//语文
	int english;//英语
	struct student* next;//指向下一个节点得指针
}student;
//链表的封装 单链表
typedef struct List
{
	student * front;//头指针
	student* tail;//尾指针 方便插入
}List;
List* createList()//申请
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
//从文件中读取数据并生成一个链表返回
List* createlistfromfile(const char* filename)//文件名
{
	//创建头节点 calloc 会自动初始化申请的内存
	student* headNode = createStudent();
	//如果头节点申请成功，则创建链表
	List* list = createList();
	list->front = headNode;//头节点
	list->tail = headNode;//尾节点

	
	FILE* fp = fopen(filename, "r");//r为可读,读取
	//防御性编程
	if (fp == NULL)
	{
		perror("open file failed");
		return list;
	}
	//去掉表头
	char arr[1024] = { 0 };
	fgets(arr,1024,fp);

	//读取文件 fscanf 写
	while (!feof(fp))//判断是否读完
	{
		student* newNode = createStudent();
		int ret = fscanf(fp, "%lld %s %s %d %d %d\n", &newNode->number, &newNode->name, &newNode->grade, &newNode->math, &newNode->chinese, &newNode->english);
		if (ret == EOF)
		{
			break;
		}
		//把当前节点插入链表
			list->tail->next = newNode;
			list->tail = newNode;
	}
	fclose(fp);
	return list;
}
//查看所有学生信息
void printAll(List* list)
{
	//获取第一个节点的指针
	student* curNode = list->front->next;
	//printf()//表头
	while (curNode != NULL)
	{
		printf("%lld   %s    %s   %d   %d   %d\n", curNode->number, curNode->name, curNode->grade, curNode->math, curNode->chinese, curNode->english);
		curNode = curNode->next;//移动curNode
	}
}
//查看学生信息
//按学号查找
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
//按姓名查找
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
//删除
void removeStudent(List* list, long long int number)
{
	student* prevNode = list->front;
	while (prevNode->next != NULL)
	{
		//找到了
		if (prevNode->next->number)
		{
			break;
		}
		prevNode = prevNode->next;
	}
	if (prevNode && prevNode->next != NULL)
	{
		//先保存要删除的节点
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
	printf("***********学生管理系统**************\n");
	printf("***********1.查看所有学生成绩********\n");
	printf("***********2.添加学生****************\n");
	printf("***********3.删除学生****************\n"); 
	printf("***********4.查找学生****************\n");

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
				printAll(list);//查看所有学生
				break;
			case 2:
				break;
			case 3:
			{
				long long int number = 0;
				printf("请输入删除学生学号");
				scanf("%d", number);
				removeStudent(list, number);
			}	
				break;
			case 4:
			{
				printf("******查找类型********");
				printf("****1，按学号查找*****");
				printf("****1，按姓名查找*****");
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
		//先暂停
		system("pause");
		//再清屏
		system("cls");
	}
	return 0;
}