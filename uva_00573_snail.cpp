#include <iostream>

using namespace std;

void solution(int H, int U, int D, int F);

int main(int argc, char const *argv[])
{
    int H(0), U(0), D(0), F(0);

    while (cin >> H && cin >> U && cin >> D && cin >> F && H != 0)
        solution(H, U, D, F);

    return 0;
}

void solution(int H, int U, int D, int F)
{
    double current_H(0), decrease_U((double)U * F / 100), current_U(U);
    int day(0);
    
    while (current_H >= 0)
    {
        day++;

        // actualize situation
        current_H += current_U;
        if (current_H > H)
        {
            cout << "success on day " << day << endl;
            return;
        }
        current_H -= D;

        // actualize constants
        current_U -= decrease_U;
        if (current_U < 0)
            current_U = 0;
    }

    cout << "failure on day " << day << endl;
}
