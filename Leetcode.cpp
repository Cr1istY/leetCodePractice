#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

/*
给你一个 n 个节点的 有向图 ，节点编号为 0 到 n - 1 ，其中每个节点 至多 有一条出边。
图用一个大小为 n 下标从 0 开始的数组 edges 表示，节点 i 到节点 edges[i] 之间有一条有向边。如果节点 i 没有出边，那么 edges[i] == -1 。
请你返回图中的 最长 环，如果没有任何环，请返回 -1 。
一个环指的是起点和终点是 同一个 节点的路径。
*/

class {
public:
	int longestPath(vector<int>& edges) {
        int n = edges.size();
        vector<int> time(n, 0);
        int res = -1;
        for (int i = 0, clock = 1; i < n; i++) {
            if (time[i]) continue;
            for (int x = i, start_time = clock; x >= 0; x = edges[x]) {
                if (time[x]) {
                    if (time[x] >= start_time) {
                        res = max(res, clock - time[x]);
                    }
                    break;
                }
                time[x] = clock++;
            }
        }
        return res;
	}
};


/*
给你一个下标从 0 开始的字符串 s ，以及一个下标从 0 开始的整数数组 spaces 。
数组 spaces 描述原字符串中需要添加空格的下标。每个空格都应该插入到给定索引处的字符值 之前 。
例如，s = "EnjoyYourCoffee" 且 spaces = [5, 9] ，那么我们需要在 'Y' 和 'C' 之前添加空格，这两个字符分别位于下标 5 和下标 9 。因此，最终得到 "Enjoy Your Coffee" 。
请你添加空格，并返回修改后的字符串。
*/

class Solution {
public:
	string addSpaces(string s, vector<int>& spaces) {
		int n = s.size();
		for (int i = 0; i < spaces.size(); i++) {
			s.insert(spaces[i] + i, " ");
		}
		return s;
	}
/*
给你一个字符串s和一个字符letter
返回在s中等于letter字符所占的百分比
向下取整到最接近的百分比。
*/
    int percentageLetters(string s, char letter)
    {
        int n = s.size();
        int a = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == letter)
            {
                a++;
            }
        }
		return n == 0 ? 0 : a * 100 / n;
    }
/*
给你一个下标从 0 开始的二维整数数组 questions ，其中 questions[i] = [pointsi, brainpoweri] 。
这个数组表示一场考试里的一系列题目，你需要 按顺序 （也就是从问题 0 开始依次解决），针对每个问题选择 解决 或者 跳过 操作
解决问题 i 将让你 获得  pointsi 的分数
但是你将 无法 解决接下来的 brainpoweri 个问题（即只能跳过接下来的 brainpoweri 个问题）
如果你跳过问题 i ，你可以对下一个问题决定使用哪种操作。
*/
    long long mostPoints(vector<vector<int>>& questions) {
        long long num = 0;
        long long temp = 0;
        int i = 0;
        int j = 0;
        do {
            i = j;
            j++;
            while (i < questions.size())
            {
                num += questions[i][0];
                if (i += questions[i][1] + 1 > questions.size())
                {
                    int m = i;
                    int n = i;
                    m += questions[m][1] + 1;
                    n += questions[n][1] + 2;
                    if (questions[m][0] > questions[n][0])
                    {
                        i += questions[i][1] + 1;
                    }
                    else {
                        i += questions[i][1] + 2;
                    }
                    num += questions[i][0];
                }
                else {
                    i += questions[i][1] + 1;
                }
            }
			if (num > temp)
			{
				temp = num;
			}
            num = 0;

		} while (j < questions.size());
		return temp;
    }
/*
给你一个下标从 0 开始的整数数组 nums 。
请你从所有满足 i < j < k 的下标三元组 (i, j, k) 中，找出并返回下标三元组的最大值
如果所有满足条件的三元组的值都是负数，则返回 0 
*/
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0, imax = 0, dmax = 0;
        for (int k = 0; k < n; k++) {
            res = max(res, dmax * nums[k]);
            dmax = max(dmax, imax - nums[k]);
            imax = max(imax, static_cast<long long>(nums[k]));
        }
        return res;
    }


/*
给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer 
，子集中每一元素对 (answer[i], answer[j]) 都应当满足：
answer[i] % answer[j] == 0 ，或
answer[j] % answer[i] == 0
如果存在多个有效解子集，返回其中任何一个均可。*/


	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<int> dp(n, 1), pre(n, -1);
		int maxSize = 0, maxIndex = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					pre[i] = j;
				}
			}
			if (dp[i] > maxSize) {
				maxSize = dp[i];
				maxIndex = i;
			}
		}
		vector<int> result;
		while (maxIndex != -1) {
			result.push_back(nums[maxIndex]);
			maxIndex = pre[maxIndex];
		}
		reverse(result.begin(), result.end());
		return result;
	}
    /*
    416. 分割等和子集
    */
    bool canPartition(vector<int>& nums) {
        int i = 0;
        for (unsigned int i : nums)
        {
            int n = nums.size();
            if (n < 2) {
                return false;
            }
            int sum = accumulate(nums.begin(), nums.end(), 0);
            int maxNum = *max_element(nums.begin(), nums.end());
            if (sum & 1) {
                return false;
            }
            int target = sum / 2;
            if (maxNum > target) {
                return false;
            }
            vector<vector<int>> dp(n, vector<int>(target + 1, 0));
            for (int i = 0; i < n; i++) {
                dp[i][0] = true;
            }
            dp[0][nums[0]] = true;
            for (int i = 1; i < n; i++) {
                int num = nums[i];
                for (int j = 1; j <= target; j++) {
                    if (j >= num) {
                        dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                    }
                    else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            return dp[n - 1][target];
        }

    }
};

int main(void) {
	Solution s;
    vector<int> nums = {12, 6, 1, 2, 7};
	cout << s.maximumTripletValue(nums) << endl;
	cin.get();
	return 0;
}