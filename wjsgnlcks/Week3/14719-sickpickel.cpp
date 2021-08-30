// 빗물
// 쉽게 푸는 법
#include <bits/stdc++.h>
#define Max 501

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[Max][Max];
	int h, w, input;

	cin >> h >> w;
	for (int i = 0; i < w; i++)
	{
		cin >> input;
		while (input--)
			arr[input][i] = 1;
	}

	int ans = 0;
	for (int i = 0; i < h; i++)
	{
		int flag = 0, count = 0;
		for (int j = 0; j < w; j++)
		{
			if (arr[i][j])
				flag = 1;
			if (!flag)
				continue;

			if (arr[i][j])
			{
				ans += count;
				count = 0;
			}
			else
				count++;
		}
	}

	cout << ans << "\n";
	return 0;
}