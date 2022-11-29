#include<stdio.h>
#include<stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct node {
    int val;
    int index;
};

void quicksort(struct node* nodes, int left_index, int right_index){
	int i = left_index;
	int j = right_index;
	struct node mid_node = nodes[left_index];
	struct node temp_node;
	
	if(i >= j)
		return;
	
	while(i != j){
		while(nodes[j].val > mid_node.val && i < j)
			j--;
		while(nodes[i].val <= mid_node.val && i < j)
			i++;
		if(i < j){
			temp_node = nodes[i];
			nodes[i] = nodes[j];
			nodes[j] = temp_node;	
		}
		
	}
	
	temp_node = nodes[j];
	nodes[j] = nodes[left_index];
	nodes[left_index] = temp_node;	
	
	
	quicksort(nodes, left_index, j-1);
	quicksort(nodes, j+1, right_index);
	
} 

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i = 0;
	int begin_index = 0;
	int end_index = numsSize - 1;
	int* result = NULL;
	
	struct node* nodes = (struct node*)malloc(numsSize * sizeof(struct node));
	for(i = 0; i < numsSize ; i++){
		nodes[i].index = i;
		nodes[i].val = nums[i];
	}
	quicksort(nodes, begin_index, end_index);

	while(begin_index < end_index){
		if(nodes[begin_index].val + nodes[end_index].val == target){
			result = (int*)malloc(2 * sizeof(int));
			result[0] = nodes[begin_index].index;
			result[1] = nodes[end_index].index;
			free(nodes);
			return result;
		}
		else if(nodes[begin_index].val + nodes[end_index].val < target){
			begin_index++;
		}
		else{
			end_index--;
		}
	}
	
	free(nodes);
	return result;
}

int main(){
	int num[5] = {-1,-2,-3,-4,-5};
	int i;
	twoSum(num, 5, -8, &i);
}
