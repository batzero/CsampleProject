#include <stdio.h>
#include<stdlib.h>

typedef struct {

	char name[20];
	int age;
	double height;
}element;

typedef struct ListNode {

	element data;
	struct ListNode *link;
}ListNode;


ListNode* insert_first(ListNode *head, int value)
{

	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}


ListNode* insert_last(ListNode *head, element value)
{

	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = value;
	node->link = NULL;
	if (head == NULL) {
		head = node;
		return head;
	}
	else {
		ListNode *p;
		for (p = head; p->link != NULL; p = p->link);
		p->link = node;
		return head;
	}
}
ListNode *alternate(ListNode *list1, ListNode *list2)
{

	ListNode *list3 = NULL;
	ListNode *p1, *p2, *p3 = NULL;
	if (list1 == NULL)return list1;
	else {
		p1 = list1;
		p2 = list2;
		while ((p1 != NULL) || (p2 != NULL)) {
			if (p1 != NULL) {
				list3 = insert_last(list3, p1->data);
				p1 = p1->link;
			}
			if (p2 != NULL) {
				list3 = insert_last(list3, p2->data);
				p2 = p2->link;
			}
		}
		return list3;
	}
}
int main(void)
{
	
	ListNode *head1 = NULL;
	head1 = insert_first(head1, 3);
	head1 = insert_first(head1, 2);
	head1 = insert_first(head1, 1);
	print_list(head1);

	ListNode *head2 = NULL;
	head2 = insert_first(head2, 5);
	head2 = insert_first(head2, 4);
	head2 = insert_first(head2, 0);
	print_list(head2);

	ListNode*head3 = NULL;
	head3 = alternate(head1, head2);
	print_list(head3);
	return 0;
}
