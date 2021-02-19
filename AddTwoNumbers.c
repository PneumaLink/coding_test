/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *newNode(int data){
	struct ListNode	*new;

	if (!(new = (struct ListNode*)malloc(sizeof(struct ListNode))))
		return (NULL);
	new->next = NULL;
	new->val = data;
	return(new);
}

struct ListNode	*addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	struct ListNode	*result;
	struct ListNode *cp;
	int				carry;

	if (!(result = (struct ListNode*)malloc(sizeof(struct ListNode))))
		return (NULL);
	result->next = NULL;
	result->val = 0;
	cp = result;
	carry = 0;
	while (1){
		carry = (l1->val + l2->val) / 10;
		cp->val = (l1->val + l2->val) % 10;
		l1 = l1->next;
		l2 = l2->next;
		if (!l1 && !l2)
			break ;
		//	carry처리를 다시 생각합시다/
	}
	return (result);
}
