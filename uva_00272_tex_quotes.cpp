#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    char c;
    bool isFirst(true);
    
    while(scanf("%c", &c) != EOF)
    {
        if (c == '"')
        {
            isFirst ? printf("``"): printf("''");
            isFirst = !isFirst;
        }
        else
        {
            printf("%c", c);
        }
    }

    return 0;
}