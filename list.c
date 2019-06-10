#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>



typedef int element;

typedef struct ListNode {

	element data;
	struct ListNode *link;

}ListNode;

void error(char *message)
{

	fprintf(stderr, "%s\n", message);
	exit(1);
}


ListNode* insert_first(ListNode *head, int value)
{

	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
//노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode *head, ListNode *pre, element value)
{

	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode *head)
{

	ListNode *removed;
	if (head == NULL)return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;

}

void print_list(ListNode *head)
{
	for (ListNode *p = head;p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

int get_sum(ListNode *head)
{

	int sum = 0;
	for (ListNode *p = head; p != NULL; p = p->link)
		sum += p->data;
	return sum;
}

int search(ListNode *head, int value)
{
	int count = 0;
	for (ListNode *p = head; p != NULL; p = p->link) {
		if (p->data == value)count++;
	}
	return count;
}

int main(void) {
	ListNode *head = NULL;
	int count, data, value;

	printf("노드의 개수;");
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		printf("노드 #%d 데이터:", i);
		scanf("%d", &data);
		head = insert_first(head, data);
	}
	printf("탐색할 값을 입력하시오:");
	scanf("%d", &value);
	printf("%d는 연결 리스트에서 %d번 나타납니다.", value, search(head, value));
	return 0;
}
