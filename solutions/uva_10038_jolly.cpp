#include <iostream>
#include <vector>

using namespace std;

void solution(int N);

int main(int argc, char const *argv[])
{
    int N;

    while(cin >> N)
        solution(N);

    return 0;
}

void solution(int N)
{
    vector<int> v(N, 0);
    int current(0), old(0);
    bool res = true;
    int i(N);

    cin >> old;
    i--;

    while(i--)
    {
        cin >> current;
        if (abs(old - current) < N)
            v[abs(old - current)]++;
        old = current;
    }
    i = 0;
    while (res && ++i < N)
    {
        if (v[i] != 1)
            res = false;
        if (!res){ break;}
    }

    if (res)
        cout << "Jolly" << endl;
    else
        cout << "Not jolly" << endl;
}
