//_vakili_abdolrahimi
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int count(int S[], int m, int n)
{
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    if (m <= 0 && n >= 1)
        return 0;

    return count(S, m - 1, n) +
           count(S, m, n - S[m - 1]);
}

int main()
{
    int i, j, p;
    int arr[] = {1, 2, 5, 10, 50};
    int m = sizeof(arr) / sizeof(arr[0]);
    cout<<"Enter your money :\n";
    cin >> p;
    cout << count(arr, m, p);
    return 0;
}
