#include<iostream>
#include<vector>
using namespace std;

/*
����һ�� n ���ڵ�� ����ͼ ���ڵ���Ϊ 0 �� n - 1 ������ÿ���ڵ� ���� ��һ�����ߡ�
ͼ��һ����СΪ n �±�� 0 ��ʼ������ edges ��ʾ���ڵ� i ���ڵ� edges[i] ֮����һ������ߡ�����ڵ� i û�г��ߣ���ô edges[i] == -1 ��
���㷵��ͼ�е� � �������û���κλ����뷵�� -1 ��
һ����ָ���������յ��� ͬһ�� �ڵ��·����
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
����һ���±�� 0 ��ʼ���ַ��� s ���Լ�һ���±�� 0 ��ʼ���������� spaces ��
���� spaces ����ԭ�ַ�������Ҫ��ӿո���±ꡣÿ���ո�Ӧ�ò��뵽�������������ַ�ֵ ֮ǰ ��
���磬s = "EnjoyYourCoffee" �� spaces = [5, 9] ����ô������Ҫ�� 'Y' �� 'C' ֮ǰ��ӿո��������ַ��ֱ�λ���±� 5 ���±� 9 ����ˣ����յõ� "Enjoy Your Coffee" ��
������ӿո񣬲������޸ĺ���ַ�����
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
����һ���ַ���s��һ���ַ�letter
������s�е���letter�ַ���ռ�İٷֱ�
����ȡ������ӽ��İٷֱȡ�
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

