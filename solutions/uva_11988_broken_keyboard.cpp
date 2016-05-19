#include <iostream>
#include <string>
#include <list>

using namespace std;

void solution(string line);

int main(int argc, char const *argv[])
{
    string line("");

    while (getline(cin, line))
        solution(line);

    return 0;
}

void solution(string line)
{
    list<char> res;
    auto current = res.cbegin();

    for (int i = 0; i < line.size(); ++i)
    {
        if (line[i] == '[')
            current = res.cbegin();
        else if (line[i] == ']')
            current = res.cend();
        else
            res.insert(current, line[i]);
    }

    for (auto x: res)
        cout << x;
    cout << endl;
}
