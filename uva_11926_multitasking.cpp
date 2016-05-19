#include <iostream>
#include <bitset>
#include <string>

#define SIZE 1000001

using namespace std;

void solution(int n, int m);
int main(int argc, char const *argv[])
{
    int n, m;

    while (cin >> n && cin >> m && !(n == 0 && m == 0))
        solution(n, m);

    return 0;
}

void solution(int n, int m)
{
    int start(0), end(0), period(0);
    bitset<SIZE> tasks;
    bool res(true);

    for (int i = 0; i < n; ++i)
    {
        cin >> start >> end;
        if (res)
        {
            for (int j = start; j < end; ++j)
            {
                if (tasks[j])
                    res = false;
                else
                    tasks.set(j);
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> start >> end >> period;
        if (res)
        {
            int j = 0;
            while (j * period + start < SIZE)
            {
                for (int k = j * period + start; k < j * period + end; ++k)
                {
                    if (k >= SIZE)
                        break;
                    else
                    {
                        if (tasks[k])
                            res = false;
                        else
                            tasks.set(k);
                    }
                }
                j++;
            }
        }
    }

    cout << (res ? "NO ": "") << "CONFLICT" << endl;
}
