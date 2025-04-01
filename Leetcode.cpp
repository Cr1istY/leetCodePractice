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
/*
����һ���±�� 0 ��ʼ�Ķ�ά�������� questions ������ questions[i] = [pointsi, brainpoweri] ��
��������ʾһ���������һϵ����Ŀ������Ҫ ��˳�� ��Ҳ���Ǵ����� 0 ��ʼ���ν���������ÿ������ѡ�� ��� ���� ���� ����
������� i ������ ���  pointsi �ķ���
�����㽫 �޷� ����������� brainpoweri �����⣨��ֻ�������������� brainpoweri �����⣩
������������� i ������Զ���һ���������ʹ�����ֲ�����
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
};

int main(void) {
	Solution s;
    vector<vector<int>> questions = { {21, 5}, {92, 3}, {74, 2}, {39, 4}, {58, 2}, {5, 5}, {49, 4}, {65, 3} };
	cout << s.mostPoints(questions) << endl;
	cin.get();
	return 0;
}