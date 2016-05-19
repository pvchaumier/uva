#include <iostream>
#include <vector>
#include <cmath>

#define vi vector<int>
#define ull unsigned long long

using namespace std;

void solution();

int main(int argc, char const *argv[])
{
    int C; cin >> C;

    while (C--)
        solution();

    return 0;
}

void solution()
{
    vi polynom;
    int tmp(0), d(0), k(0), i(0);
    ull res(0), n(0);

    cin >> i;
    i++;
    while (i--)
    {
        cin >> tmp;
        polynom.push_back(tmp);
    }
    cin >> d;
    cin >> k;
    n = (ull)ceil((-1.0 + sqrt(1.0 + 8.0 * k / d)) / 2.0);

    for (int i = 0; i < polynom.size(); ++i)
    {
        res += (ull)pow(n, i) * polynom[i];
    }
    cout << res << endl;
}
