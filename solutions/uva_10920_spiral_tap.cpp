#include <iostream>
#include <cmath>

using namespace std;

void solution(int SZ, int P);

int main(int argc, char const *argv[])
{
    int SZ, P;

    while (cin >> SZ && cin >> P && (SZ != 0 && P != 0))
    {
        solution(SZ, P);
    }

    return 0;
}

void solution(int SZ, int P)
{
    int i(SZ / 2), j(SZ / 2);
    int sqrtP((int)sqrt(P));
    int move_counter(P-1);
    int direction(0);
    int dist_to_move(1);
    int last_dist_moved(1);
    int pair(0);
    bool print(false);

    if (sqrtP % 2 == 0)
        sqrtP -= 1;

    i -= (sqrtP - 1) / 2;
    j += (sqrtP - 1) / 2;
    move_counter = P - pow(sqrtP, 2);
    last_dist_moved = sqrtP;

    if (print)
    {
        cout << "INITIAL SITUATION" << endl;
        cout << "    P            = " << P                        << endl;
        cout << "    SZ           = " << SZ                       << endl;
        cout << "    sqrt(P)      = " << (int) sqrt(P)            << endl;
        cout << "    sqrt(P)^2    = " << pow((int) sqrt(P), 2)    << endl;
        cout << "    i            = " << i                        << endl;
        cout << "    j            = " << j                        << endl;
        cout << "    move_counter = " << move_counter             << endl;
        cout << endl;
    }

    while (move_counter--)
    {
        if (print)
            cout << "i, j = " << i << ", " << j << endl;

        switch (direction)
        {
            case 0: i -= 1; break; // UP
            case 1: j -= 1; break; // LEFT
            case 2: i += 1; break; // DOWN
            case 3: j += 1; break; // RIGHT
        }

        dist_to_move--;
        if (dist_to_move == 0)
        {
            if (pair % 2)
                last_dist_moved++;
            pair++;
            dist_to_move = last_dist_moved;
            direction = (direction + 1) % 4;
        }
    }


    cout << "Line = " << SZ-i << ", column = " << j+1 << "." << endl;
}
