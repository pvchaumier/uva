#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

void print_res(map<string, int> proportion, int total);

int main(int argc, char const *argv[])
{
    int nb_cases(0), total(0);
    string line;
    map<string, int> proportion;

    cin >> nb_cases;
    cin.ignore();
    getline(cin, line);

    while (getline(cin, line))
    {
        if (line == "")
        {
            print_res(proportion, total);
            cout << endl;
            proportion.clear();
            total = 0;
        }
        else
        {
            total++;
            if (proportion.find(line) != proportion.end())
                proportion[line]++;
            else
                proportion[line] = 1;
        }
    }

    print_res(proportion, total);
    if (line == "")
    proportion.clear();
    total = 0;

    return 0;
}

void print_res(map<string, int> proportion, int total)
{
    for (auto x: proportion)
    {
        double prop = (double) x.second / total;
        prop *= 100;
        cout << x.first << " "
             << fixed << setprecision(4) << prop << endl;
    }
}
