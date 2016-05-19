#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

void solution(int n);

int main(int argc, char const *argv[])
{
    int n(0);

    while (cin >> n && n != 0)
        solution(n);

    return 0;
}

void solution(int n)
{
    vector<int> v(5);
    map<string, int> m;
    string tmp("");
    int course1(0), course2(0), course3(0), course4(0), course5(0);
    int max_popularity(0);
    int res(0);

    while (n--)
    {
        cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
        sort(v.begin(), v.end());
        tmp = to_string(v[0]) + to_string(v[1]) + to_string(v[2]) + 
              to_string(v[3]) + to_string(v[4]);
        if (m.find(tmp) != m.end())
            m[tmp]++;
        else
            m[tmp] = 1;
        max_popularity = max(max_popularity, m[tmp]);
    }

    for (auto x: m)
    {
        if (x.second == max_popularity)
            res += x.second;
    }

    cout << res << endl;
} 
 
