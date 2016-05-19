#include <iostream>

using namespace std;

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main(void)
{
    int n, i, a, b, c, min, med, max;

    cin >> n;
    i = n;

    while (i--)
    {
        cin >> a >> b >> c;

        min = MIN(a, MIN(b, c));
        max = MAX(a, MAX(b, c));

        if (a == min)
            med = (b == max) ? c : b;
        else if (a == max)
            med = (b == min) ? c : b;
        else
            med = a;

        cout << "Case " << n - i << ": " << med << endl;

    }

    return 0;
}
