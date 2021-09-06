#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;

    int A[46], B[46];

    A[0] = 0;
    A[1] = 1;

    B[0] = 1;
    B[1] = 1;

    cin >> n;

    if (n >= 2)
    {
        for (int i = 2; i < n; ++i)
        {
            A[i] = A[i - 2] + A[i - 1];
            B[i] = B[i - 2] + B[i - 1];
        }
    }
    cout << A[n - 1] << " " << B[n - 1] << endl;

    return 0;
}
