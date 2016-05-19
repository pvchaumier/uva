#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    int value(0), size(0);

    while (cin >> value)
    {
        v.push_back(value);
        sort(v.begin(), v.end());
        size = v.size();
        if (v.size() % 2)
            cout << v[size/2] << endl;
        else
            cout << (v[size/2] + v[size/2-1]) / 2 << endl;
    }

    return 0;
}
