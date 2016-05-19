#include <iostream>
#include <string>
#include <queue>
#include <vector>

#define pii pair<int, pair<int, int> >

using namespace std;

int main(int argc, char const *argv[])
{
    string regis("");
    int Q(0), P(0), K(0);
    pii tmp;
    priority_queue< pii, vector<pii>, greater<pii> > pq;

    while (cin >> regis)
    {
        if (regis == "#")
        {
            cin >> K;
            while (K--)
            {
                tmp = pq.top();
                cout << tmp.second.first << endl;
                tmp.first += tmp.second.second;
                pq.pop();
                pq.push(tmp);
            }
        }
        else
        {
            cin >> Q >> P;
            pq.push(make_pair(P, make_pair(Q, P)));
        }
    }

    return 0;
}
