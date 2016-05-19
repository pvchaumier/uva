#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solution(string line);

int main(int argc, char const *argv[])
{
    string line;

    while (getline(cin, line) && line != "#")
    {
        solution(line);
    }

    return 0;
}

void solution(string line)
{
    string next_permut(line), sorted(line);
    next_permutation(next_permut.begin(), next_permut.end());
    sort(sorted.begin(), sorted.end());

    if (next_permut == sorted)
        cout << "No Successor" << endl;
    else
        cout << next_permut << endl;
}
