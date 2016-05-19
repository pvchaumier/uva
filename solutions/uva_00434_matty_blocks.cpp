#include <iostream>
#include <vector>

using namespace std;

void solution(int K);

int main(int argc, char const *argv[])
{
    int cases, K;
    cin >> cases;

    while (cases--)
    {
        cin >> K;
        solution(K);
    }

    return 0;
}

void solution(int K)
{
    vector<int> front(K), right(K);
    vector<bool> front_selected(K, false), right_selected(K, false);
    int i(0), value(0), mini(0), maxi(0);

    i = K;
    while (i--)
    {
        cin >> value;
        front[K-i-1] = value;
    }
    i = K;
    while (i--)
    {
        cin >> value;
        right[K-i-1] = value;
    }

    for (int i = 0; i < K; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            maxi += min(front[i], right[j]);
            if (!front_selected[i] && !right_selected[j] && (front[i] == right[j]))
            {
                front_selected[i] = true;
                right_selected[j] = true;
                mini += front[i];
            }
        }
    }

    for (int i = 0; i < K; ++i)
    {
        if (!front_selected[i])
            mini += front[i];
        if (!right_selected[i])
            mini += right[i];
    }

    cout << "Matty needs at least " << mini << " blocks, and can add at most " << maxi - mini << " extra blocks." << endl;
}
