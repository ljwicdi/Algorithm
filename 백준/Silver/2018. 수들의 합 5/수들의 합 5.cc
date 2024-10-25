#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int N, start = 1, end = 1, answer = 1, sum = 1;
    // N값, start값, end값, answer값, sum값
	
	cin >> N;

	while (N != end)
	{
		if (sum == N)
		{
			answer++;
			end++;
			sum += end;
		}// sum과 N의 값이 같으면 sum+=end 와 end++ 를 해준다.
		else if (sum > N)
		{
			sum -= start;
			start++;
		}// sum의 값이 N의 값보다 크면 sum에서 start를 빼주고 start++를 해준다.
		else
		{
			end++;
			sum += end;
		} 
	}

	cout << answer;

	return 0;
}