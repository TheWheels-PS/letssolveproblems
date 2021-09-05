#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int width, height, answer = 0;

    cin >> height >> width;

    // 입력받은 폭의 크기만큼 벡터 컨테이너 생성
    vector<int> v(width);

    // 블록의 높이를 입력 받기
    for (int i = 0; i < width; i++)
        cin >> v[i];

    /* 
    이 문제를 해결하기 위한 방법. 해설을 통해서 알게 되었음.
    임의의 한 블록의 위치를 기준점으로 삼아 왼쪽에서의 가장 높은 블럭의 개수, 오른쪽에서 가장 높은 블럭의 개수를
    left, right에 저장

    둘 중에 작은 것에 기준점 블럭의 개수를 뺀 값이 해당 위치에 고이는 빗물의 양이다.
    */

    //    왼쪽의 최댓값과 오른쪽의 최댓값 저장을 위해 변수 생성
    int left, right;

    // 양 쪽 끝을 제외하고 안 쪽의 블록만 검사하는 범위
    for (int i = 1; i < width - 1; i++)
    {
        // 기준점이 바뀔 때마다 left & right를 0으로 초기화
        left = 0, right = 0;

        // max함수를 사용해 왼쪽에서의 최댓값을 저장
        for (int j = 0; j < i; ++j)
            left = max(left, v[j]);

        // max함수를 사용해 오른쪽에서의 최댓값을 저장
        for (int j = i + 1; j < width; ++j)
            right = max(right, v[j]);

        // 둘 중에 작은 값에서 기준점이 되는 위치의 블록의 개수를 뺀값을 모두 더한 값이 답
        answer += max(0, min(left, right) - v[i]);
    }

    cout << answer << endl;

    return 0;
}