#include<iostream>
#include<vector>
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


};

