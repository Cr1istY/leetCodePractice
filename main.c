#include<stdio.h>
#include<stdlib.h>

/*简单排序*/
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


/*day1: 两数求和*/
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


/*2: 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。*/
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
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。
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
	//排序
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
给你一个下标从 0 开始、长度为 n 的二进制字符串 s ，你可以对其执行两种操作：

选中一个下标 i 并且反转从下标 0 到下标 i（包括下标 0 和下标 i ）的所有字符，成本为 i + 1 。
选中一个下标 i 并且反转从下标 i 到下标 n - 1（包括下标 i 和下标 n - 1 ）的所有字符，成本为 n - i 。
返回使字符串内所有字符 相等 需要的 最小成本 。

反转 字符意味着：如果原来的值是 '0' ，则反转后值变为 '1' ，反之亦然。
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