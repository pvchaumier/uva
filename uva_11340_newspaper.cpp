#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, K, M, value;
    char character;
    double res;
    map <char, int> m;
    string text;

    cin >> N;
    while (N--)
    {
        m.clear();
        res = 0;

        cin >> K;
        while (K--)
        {
            cin >> character >> value;
            m[character] = value;
        }

        cin >> M;
        cin.ignore();
        while (M--)
        {
            getline(cin, text);
            for (auto c: text)
            {
                if (m.count(c))
                    res += m[c];
            }
        }
        cout << fixed << setprecision(2) << res/100 << "$" << endl;
    }

    return 0;
}
