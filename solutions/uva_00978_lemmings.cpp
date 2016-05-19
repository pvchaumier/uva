#include <iostream>
#include <queue>

using namespace std;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void solution(int B, int SG, int SB);

int main(int argc, char const *argv[])
{
    int N(0), B(0), SG(0), SB(0);

    cin >> N;
    while (N--)
    {
        cin >> B >> SG >> SB;
        solution(B, SG, SB);
        if (N != 0)
            cout << endl;
    }

    return 0;
}

void solution(int B, int SG, int SB)
{
    priority_queue<int> g, b, g_tmp, b_tmp;
    int tmp, g_l, b_l;
    int size(0);

    for (int i = 0; i < SG; ++i)
    {
        cin >> tmp;
        g.push(tmp);
    }
    for (int i = 0; i < SB; ++i)
    {
        cin >> tmp;
        b.push(tmp);
    }

    // 
    // Play battles
    // 
    while (!g.empty() && !b.empty())
    {
        size = min(B, min(g.size(), b.size()));
        for (int i = 0; i < size; ++i)
        {
            g_l = g.top();
            b_l = b.top();
            g.pop();
            b.pop();

            if (g_l > b_l)
                g_tmp.push(g_l - b_l);
            if (b_l > g_l)
                b_tmp.push(b_l - g_l);
        }
        while (!g_tmp.empty())
        {
            g.push(g_tmp.top());
            g_tmp.pop();
        }
        while (!b_tmp.empty())
        {
            b.push(b_tmp.top());
            b_tmp.pop();
        }
    }

    //
    // Print result
    //
    if (g.empty() && b.empty())
        cout << "green and blue died" << endl;
    else if (g.empty())
    {
        cout << "blue wins" << endl;
        while (!b.empty())
        {
            cout << b.top() << endl;
            b.pop();
        }
    }
    else
    {
        cout << "green wins" << endl;
        while (!g.empty())
        {
            cout << g.top() << endl;
            g.pop();
        }
    }
}
