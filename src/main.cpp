
#include <iostream>
#include "ArithmeticExpressions.h"
//#include "StackOnTheList.h"

using namespace std;

int main()
{
    //// --- int: базовые операции ---
    //Stack<int> s(3);
    //s.Push(10);
    //s.Push(20);
    //s.Push(30);
    //s.Push(40);                            // проигнорируется — стек полон
    //cout << "s = " << s << "\n";           // [10 20 30]
    //cout << "size = " << s.size() << "\n"; // 3

    //s.Pop();
    //cout << "after pop: " << s << "\n";    // [10 20]

    //// --- заполнение через Push ---
    //Stack<int> s2(3);
    //s2.Push(1);
    //s2.Push(2);
    //s2.Push(3);
    //cout << "s2 = " << s2 << "\n";         // [1 2 3]

    //// --- копирование ---
    //Stack<int> s3 = s2;
    //s3.Push(99);                           // sz=3, top=2 → полон, проигнорируется
    //cout << "s2 = " << s2 << "\n";         // [1 2 3]
    //cout << "s3 = " << s3 << "\n";         // [1 2 3]

    //// --- string ---
    //Stack<string> ss(2);
    //ss.Push("hello");
    //ss.Push("world");
    //cout << "ss = " << ss << "\n";         // [hello world]

    //// --- clear ---
    //s2.clear();
    //cout << "s2 after clear = " << s2
    //    << ", IsEmpty=" << s2.IsEmpty() << "\n";

    

    // ####################################################################


    string infix;

    cout << "Enter an arithmetic expression with variables: ";
    getline(cin, infix);

    ArithmeticExpression example(infix);

    cout << "Common notation: " << example.GetInfix() << endl;
    cout << "Reverse Polish notation: " << example.GetPostfix() << endl << endl;

    vector<char> vars = example.GetOperands();

    map<char, double> values;
    cout << "Enter the variable values:" << endl;
    for (char v : vars)
    {
        double val;
        cout << v << " = ";
        cin >> val;
        values[v] = val;
        cout << endl;
    }

    double result = example.Calculate(values);
    cout << "Result: " << result << endl;

    return 0;
}