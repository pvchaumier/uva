#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(string in);

int main(int argc, char const *argv[])
{
    string in("");
    int case_nb(0);

    while (cin >> in && in != "end")
    {
        case_nb++;
        cout << "Case " << case_nb << ": ";
        solution(in);
    }

    return 0;
}

void solution(string in)
{
    int max(in[in.size()-1]), res(1);
    vector<int> v(1);
    v[0] = in[0];

    for (int i = 1; i < in.size(); ++i)
    {
        int add_to = -1;
        for (int j = 0; j < v.size(); ++j)
        {
            if (v[j] >= in[i])
            {
                if (add_to == -1 || v[add_to] > v[j])
                    add_to = j;
            }
        }

        if (add_to == -1)
            v.push_back(in[i]);
        else
            v[add_to] = in[i];
    }

    cout << v.size() << endl;
}
