#include<stdio.h>
#include<stdlib.h>

 struct ListNode {
 	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	
	struct ListNode *current_l1, *current_l2, *root_result, *NewNode;
	int cin = 0;
	current_l1 = l1;
	current_l2 = l2;
	struct ListNode* current_result = (struct ListNode*)malloc(sizeof(struct ListNode));
	root_result = current_result;
	
	while(current_l1 != NULL && current_l2 != NULL){
		NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		NewNode->val = (current_l1->val + current_l2->val + cin) % 10;
		NewNode->next = NULL;
		current_result->next = NewNode;
		current_result = current_result->next;
		if((current_l1->val + current_l2->val + cin) > 9)
			cin = 1;
		else 
			cin = 0;
		current_l1 = current_l1->next;
		current_l2 = current_l2->next;
	}

	while(current_l1 != NULL){
		NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		NewNode->val = (current_l1->val + cin) % 10;
		NewNode->next = NULL;
		current_result->next = NewNode;
		current_result = current_result->next;
		if((current_l1->val + cin) > 9)
			cin = 1;
		else 
			cin = 0;
		current_l1 = current_l1->next;
	}
	
	while(current_l2 != NULL){
		NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		NewNode->val = (current_l2->val + cin) % 10;
		NewNode->next = NULL;
		current_result->next = NewNode;
		current_result = current_result->next;
		if((current_l2->val + cin) > 9)
			cin = 1;
		else 
			cin = 0;
		current_l2 = current_l2->next;
	}
	
	if(cin == 1){
        NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		NewNode->val = 1;
		NewNode->next = NULL;
		current_result->next = NewNode;
    }
    
    current_result = root_result->next;
	free(root_result);
    return(current_result);
}

main(){
	struct ListNode* root_l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* root_l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *current, *NewNode, *result;
	current = root_l1;
	current->val = 9;
	current->next = NULL;
	
	current = root_l2;
	current->val = 9;
	current->next = NULL;
	
	result = addTwoNumbers(root_l1, root_l2);
}












