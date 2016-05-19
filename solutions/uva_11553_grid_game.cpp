#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void solution()
{
    int n(0); cin >> n;
    vvi M(n, vi(n));
    int res(10000), current(0);

    vi columns(n);
    for (int i = 0; i < n; ++i)
        columns[i] = i;

    // Parse input
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> M[i][j];
        }
    }

    // Loop on all possible games
    do
    {
        current = 0;
        for (int i = 0; i < n; ++i)
            current += M[i][columns[i]];
        res = min(current, res);
    }
    while (next_permutation(columns.begin(), columns.end()));

    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    int t(0);
    cin >> t;
    while (t--)
        solution();

    return 0;
}
