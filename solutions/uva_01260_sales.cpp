#include <iostream>
#include <vector>

#define vi vector<int>

using namespace std;

void solution()
{
    int n(0), i(0), res(0);
    cin >> n;
    vi months(n);

    // get all the months
    i = n;
    while (i--)
    {
        cin >> months[n-i-1];
    }

    // calculate the result
    for (int i = 1; i < months.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (months[i] >= months[j])
                res++;
        }
    }

    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    int T(0); cin >> T;

    while (T--)
        solution();

    return 0;
}
