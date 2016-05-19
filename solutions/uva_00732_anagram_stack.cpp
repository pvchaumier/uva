#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void solution(string in, string out, string stack, string current_out, 
              string operations, int push, int pop);

int main(int argc, char const *argv[])
{
    string in(""), out(""), tmp("");

    while (cin >> in && cin >> out)
    {

        cout << "[" << endl;
        if (in.size() == out.size())
            solution(in, out, "", "", "", 0, 0);
        cout << "]" << endl;
    }

    return 0;
}

void solution(string in, string out, string stack, string current_out, 
              string operations, int push, int pop)
{
    bool verbose = false;
    if (verbose)
    {
        cout << "\n############### Status ###################" << endl;
        cout << "    in, out     - "    << in << ", " << out   << endl;
        cout << "    stack       - "    <<     stack           << endl;
        cout << "    current_out - "    <<     current_out     << endl;
        cout << "    operations  - "    <<     operations      << endl;
        cout << "    push, pop   - "    << push << ", " << pop << endl;
    }


    if (current_out != out.substr(0, current_out.size()))
    {
        return;
    }

    if (current_out == out)
    {
        operations.erase(operations.end()-1);
        cout << operations << endl;
        return;
    }


    // push and go on
    if (push < in.size())
    {
        solution(in, out, stack + in[push], current_out, 
                 operations + "i ", push + 1, pop);
    }
    
    // pop and go on
    if (stack.size() > 0)
    {
        operations += "o ";
        current_out += stack[stack.size() - 1];
        stack.erase(stack.end()-1);
        pop++;
        solution(in, out, stack, current_out, operations, push, pop);
    }
}
