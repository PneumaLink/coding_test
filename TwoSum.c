#include <stdio.h>
#include <stdlib.h>

//	https://leetcode.com/problems/two-sum/submissions/

int	*twoSum(int* nums, int numsSize, int target, int* returnSize){
	int	*result;

	result = (int*)malloc(sizeof(int) * 2);
	for(int first = 0 ; first < numsSize - 1 ; first++){
		for(int second = first + 1 ; second < numsSize ; second++){
			if (nums[first] + nums[second] == target){
				result[0] = first;
				result[1] = second;
			}
		}
	}
	return (result);
}

int	main(void){
	int	nums[] = {1,2,3,4,5,6,7,8,9};
	int	numsSize = 9;
	int	target = 11;
	int	*result;

	result = twoSum(nums, numsSize, target, result);
	printf("%d %d\n", result[0], result[1]);
	free(result);
	return (0);
}
