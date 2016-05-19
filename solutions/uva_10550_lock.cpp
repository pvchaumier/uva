#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a(0), b(0), c(0), d(0), res;
    while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF)
    {
        res = 360 * 3;
        if (!(a == b && b == c && c == d  && d == 0))
        {
            res += ((a - b + 40) % 40) * 9;
            res += ((c - b + 40) % 40) * 9;
            res += ((c - d + 40) % 40) * 9;
            cout << res << endl;
        }
    }

    return 0;
}