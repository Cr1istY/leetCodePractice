

/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。

1. 暴力法：直接遍历数组，找到两个数的和等于目标值，返回下标
*/

int* twoSum(int* nums, int numsSize, int target) {
	int i, j;
	int result[2];
	int* answer = malloc(2 * sizeof(int));
	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				result[0] = i;
				result[1] = j;
				break;
			}
		}
	}

	return answer;
}