#include <iostream>
#include <set>

#define ull unsigned long long

using namespace std;

void solution(int n);

int main(int argc, char const *argv[])
{
    int n;

    while (cin >> n && n != 0)
        solution(n);

    return 0;
}

void solution(int n)
{
    multiset<int> ms;
    ull k(0), tmp(0), res(0);

    while (n--)
    {
        cin >> k;
        while (k--)
        {
            cin >> tmp;
            ms.insert(tmp);
        }

        res += *(--ms.end()) - *ms.begin();
        ms.erase(ms.cbegin());
        ms.erase(--ms.end());
    }

    cout << res << endl;
}
