#include<stdio.h>
#include<stdlib.h>

/*������*/
void ez_sort(int* nums, int numsSize) {
	int i, j;
	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[i] > nums[j]) {
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
}


/*day1: �������*/
/*
	int nums[4] = {2, 7, 11, 15};
	int target = 9;
	int* answer = malloc(2 * sizeof(int));

	unsigned int j = sizeof(nums) / sizeof(nums[0]);

	answer = twoSum(&nums, j, target);

	putchar('[');
	for (int i = 0; i < 2; i++) {
		printf("%d%s", answer[i], (i == 0 ? ", " : "]\n"));
	}
	free(answer);
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


/*2: �������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�

���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����

����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��*/
struct ListNode {
	int val;
	struct ListNode* next;
	
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* head = NULL, * tail = NULL;
    int carry = 0;
    while (l1 || l2) {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;
        if (!head) {
            head = tail = malloc(sizeof(struct ListNode));
            tail->val = sum % 10;
            tail->next = NULL;
        }
        else {
            tail->next = malloc(sizeof(struct ListNode));
            tail->next->val = sum % 10;
            tail = tail->next;
            tail->next = NULL;
        }
        carry = sum / 10;
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    if (carry > 0) {
        tail->next = malloc(sizeof(struct ListNode));
        tail->next->val = carry;
        tail->next->next = NULL;
    }
    return head;
}


/*
* 4.
����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ���������������������� ��λ�� ��

�㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log (m+n)) ��
*/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int i, j;
	int* nums = malloc((nums1Size + nums2Size) * sizeof(int));
	for (i = 0; i < nums1Size; i++) {
		nums[i] = nums1[i];
	}
	for (j = 0; j < nums2Size; j++) {
		nums[i + j] = nums2[j];
	}
	//����
	for (i = 0; i < nums1Size + nums2Size; i++) {
		for (j = i + 1; j < nums1Size + nums2Size; j++) {
			if (nums[i] > nums[j]) {
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
	if ((nums1Size + nums2Size) % 2 == 0) {
		return (nums[(nums1Size + nums2Size) / 2] + nums[(nums1Size + nums2Size) / 2 - 1]) / 2.0;
	}
	else {
		return nums[(nums1Size + nums2Size) / 2];
	}
}

/*
����һ���±�� 0 ��ʼ������Ϊ n �Ķ������ַ��� s ������Զ���ִ�����ֲ�����

ѡ��һ���±� i ���ҷ�ת���±� 0 ���±� i�������±� 0 ���±� i ���������ַ����ɱ�Ϊ i + 1 ��
ѡ��һ���±� i ���ҷ�ת���±� i ���±� n - 1�������±� i ���±� n - 1 ���������ַ����ɱ�Ϊ n - i ��
����ʹ�ַ����������ַ� ��� ��Ҫ�� ��С�ɱ� ��

��ת �ַ���ζ�ţ����ԭ����ֵ�� '0' ����ת��ֵ��Ϊ '1' ����֮��Ȼ��
*/

long long minimumCost(char* s) {

}

/*


*/





//int main() {
//	int s[10] = {1, 5, 7, 9, 45, 78, 64, 44, 564, 10};
//	ez_sort(s, 10);
//	int i;
//	for (i = 0; i < 10; i++) {
//		printf("%d ", s[i]);
//	}
//
//	return 0;
//}