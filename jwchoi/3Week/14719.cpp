/* 
풀이 큰 틀
내 자신을 기준으로 왼쪽에서 큰 거와 오른쪽에서 큰 거를 구한다
그 중 작은 것과 내 자신의 값을 빼면 빗물의 양이 나온다
*/

#include <iostream>

using namespace std;

#define SIZE 501

int ary[SIZE];

int Solution(int w, int ary[])
{
}

int main(void)
{
    int h, w;
    cin >> h >> w;

    for (int i = 0; i < w; ++i)
    {
        cin >> ary[i];
    }

    cout << Solution(w, ary) << endl;

    return 0;
}