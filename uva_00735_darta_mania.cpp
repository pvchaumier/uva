#include <iostream>

using namespace std;

void solution(int score)
{
    int c(0), p(0);

    for (int i = 0; i <= 60; ++i) {
    for (int j = 0; j <= 60; ++j) {
    for (int k = 0; k <= 60; ++k) {
        if ((i <= 20 || (i % 2 == 0 && i / 2 <= 20) || i % 3 == 0 || i == 50) &&
            (j <= 20 || (j % 2 == 0 && j / 2 <= 20) || j % 3 == 0 || j == 50) &&
            (k <= 20 || (k % 2 == 0 && k / 2 <= 20) || k % 3 == 0 || k == 50))
        {
            if (i + j + k == score)
            {
                p++;
                if (i >= j && j >= k)
                    c++;
            }

        }
    }
    }
    }


    if (p == 0)
    {
        cout << "THE SCORE OF " << score << " CANNOT BE MADE WITH THREE DARTS." << endl;
        return;
    }
    cout << "NUMBER OF COMBINATIONS THAT SCORES " << score
         << " IS " << c << "." << endl;

    cout << "NUMBER OF PERMUTATIONS THAT SCORES " << score
         << " IS " << p << "." << endl;
}

int main(int argc, char const *argv[])
{
    int score(0);
    while (cin >> score && score > 0)
    {
        solution(score);
        cout << "**********************************************************************" << endl;
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}
