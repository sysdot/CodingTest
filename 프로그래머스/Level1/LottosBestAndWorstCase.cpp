#include <iostream>
#include <vector>

using namespace std;

/*
[����]
�ζ� ��ȣ�߿� '0'�� Ȯ���� �� ���� ��ȣ
lottos�� win_nums�� ���Ͽ� ����� ����� �ִ��� �ּ��� ���� �־��� ����� ������ ���Ͽ���.

1�� : 6�� ��ȣ ��� ��ġ
2�� : 5�� ��ȣ ��ġ
3�� : 4�� ��ȣ ��ġ
4�� : 3�� ��ȣ ��ġ
5�� : 2�� ��ȣ ��ġ
6(��÷) : �� ��
*/

int GetRank(int _correctCount)
{
	switch (_correctCount)
	{
	case 2:
		return 5;
	case 3:
		return 4;
	case 4:
		return 3;
	case 5:
		return 2;
	case 6:
		return 1;
	default:
		return 6;
	}
}

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
	vector<int> answer;
	answer.reserve(2);
	
	int correctCount = 0;
	int missingNumCount = 0;

	for (int i = 0; i < lottos.size(); ++i)
	{
		if (lottos[i] == 0)
		{
			missingNumCount++;
			continue;
		}

		// �̹� Ȯ���� ���ڴ� ������ ������ ���� Ƚ���� ���δ�.
		for (int j = correctCount; j < win_nums.size(); ++j)
		{
			if (lottos[i] == win_nums[j])
			{
				int temp = win_nums[correctCount];
				win_nums[correctCount] = win_nums[j];
				win_nums[j] = temp;
				
				correctCount++;
			}
		}
	}

	// �ְ����, ���� ���� ������� ��ȯ
	// �ּ��� ���� correctCount + �� �� ���� ������ ����
	// �־��� ���� correctCOunt
	answer.push_back(GetRank(correctCount + missingNumCount));
	answer.push_back(GetRank(correctCount));

	return answer;
}

int main()
{
	vector<int> lottos, win_nums;
	lottos.reserve(6);
	win_nums.reserve(6);

	lottos.push_back(44);
	lottos.push_back(1);
	lottos.push_back(0);
	lottos.push_back(0);
	lottos.push_back(31);
	lottos.push_back(25);

	win_nums.push_back(31);
	win_nums.push_back(10);
	win_nums.push_back(45);
	win_nums.push_back(1);
	win_nums.push_back(6);
	win_nums.push_back(19);

	vector<int> result = solution(lottos, win_nums);
	for (vector<int>::iterator iter = result.begin(); iter != result.end(); ++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}