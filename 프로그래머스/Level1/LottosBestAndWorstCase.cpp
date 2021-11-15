#include <iostream>
#include <vector>

using namespace std;

/*
[문제]
로또 번호중에 '0'은 확인할 수 없는 번호
lottos와 win_nums를 비교하여 몇개까지 맞출수 있는지 최선의 경우와 최악의 경우의 순위를 구하여라.

1등 : 6개 번호 모두 일치
2등 : 5개 번호 일치
3등 : 4개 번호 일치
4등 : 3개 번호 일치
5등 : 2개 번호 일치
6(낙첨) : 그 외
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

		// 이미 확정된 숫자는 앞으로 보내어 연산 횟수를 줄인다.
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

	// 최고순위, 최저 순위 순서대로 반환
	// 최선의 경우는 correctCount + 알 수 없는 숫자의 개수
	// 최악의 경우는 correctCOunt
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