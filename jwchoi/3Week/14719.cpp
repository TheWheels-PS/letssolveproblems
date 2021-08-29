// 해설보고 이해
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int dp[31] = {0};

    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 2] * 3; // 2x3 도형을 가장 오른쪽에 두는 경우, 2x3 도형이 3개이기 때문에 *3을 해준다
        for (int j = 4; j <= i; j += 2)
        {
            dp[i] += dp[i - j] * 2; // n=4부터는 새로운 도형이 추가된다. 하지만 n이 4,6,8,10...일때 도형의 모양이 모두 다르기 때문에 각각 dp[i]에 더해준다.
        }
    }

    cout << dp[n];
    return 0;
}