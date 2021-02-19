#include <stdlib.h>
#include <stdio.h>

struct ListNode {
      int val;
      struct ListNode *next;
 };
 
struct ListNode *newNode(int data){
	struct ListNode	*new;

	new = (struct ListNode*)malloc(sizeof(struct ListNode));
	new->next = NULL;
	new->val = data;
	return(new);
}

void			remainsList(struct ListNode *body, struct ListNode *tail, int carry){
	int	sum;

	while(tail){
		sum = carry + tail->val;
		carry = sum / 10;
		body->next = newNode(sum % 10);
		body = body->next;
		tail = tail->next;
	}
	if (carry > 0)
		body->next = newNode(carry);
}

struct ListNode	*addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	struct ListNode	*result;
	struct ListNode *cp;
	int				carry;
	int				sum;

	result = (struct ListNode*)malloc(sizeof(struct ListNode));
	result->next = NULL;
	result->val = 0;
	cp = result;
	carry = 0;
	while (1){
		sum = carry + l1->val + l2->val;
		carry = sum / 10;
		cp->val = sum % 10;
		l1 = l1->next;
		l2 = l2->next;
		if (l1 == NULL || l2 == NULL)
			break ;
		cp->next = newNode(0);
		cp = cp->next;
	}
	if (l1)
		remainsList(cp, l1, carry);
	else if(l2)
		remainsList(cp, l2, carry);
	else if (carry > 0)
		cp->next = newNode(carry);
	return (result);
}

//===============================================================================================

void	listFree(struct ListNode *list){
	struct ListNode	*point;

	while(list){
		point = list;
		list = list->next;
		free(point);
	}
}

struct ListNode	*makeList(int nums[], int len){
	struct ListNode	*result;
	struct ListNode *cp;

	if(len <= 0)
		return NULL;
	result = newNode(nums[--len]);
	cp = result;
	while(len-- > 0){
		cp->next = newNode(nums[len]);
		cp = cp->next;
	}
	return (result);
}

void			printList(struct ListNode *list){
	while(list){
		printf("-%d-", list->val);
		list = list->next;
	}
	printf("\n");
}

int	main(void){
	struct ListNode	*l1;                                                                   
	struct ListNode	*l2;
	struct ListNode	*result;
	int	num1[] = {4, 3, 2, 1};
	int	num2[] = {9, 9, 9, 9, 8, 7, 6, 5};

	l1 = makeList(num1, 4);
	l2 = makeList(num2, 8);
	printList(l1);
	printList(l2);
	result = addTwoNumbers(l1, l2);
	printList(result);
	listFree(l1);
	listFree(l2);
	listFree(result);
	return (0);
}
