#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, a, b;

    cin >> n;
    
    while (n--)
    {
        cin >> a >> b;
        (a > b) ? printf(">\n") : (a == b) ? printf("=\n") : printf("<\n");
    }

    return 0;
}