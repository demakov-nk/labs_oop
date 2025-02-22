#include "rect_test_funcs.h"

#include <iostream>

using namespace std;

int main()
{
    Rect r1;
    Rect r2(2, 8, 5, -1);
    Rect r3(r2);

    
    sides_test("Testing r1 (default constructor):", &r1, 0, 0, 0, 0);
    sides_test("Testing r2 (constructor of 4 parameters):", &r2, 2, 8, 5, -1);
    sides_test("Testing r3 (copy constructor):", &r3, 2, 8, 5, -1);
    
    r3.set_all(1, 2, 3, 4);
    sides_test("Testing r3 (set_all method):", &r3, 1, 2, 4, 3);

    cout << "\nAll `rect_basic_methods` tests passed successfully.\n";
    return 0;
}
