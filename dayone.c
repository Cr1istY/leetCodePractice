

/*
����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸣������㲻��ʹ��������ͬ��Ԫ�ء�

����԰�����˳�򷵻ش𰸡�

1. ��������ֱ�ӱ������飬�ҵ��������ĺ͵���Ŀ��ֵ�������±�
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