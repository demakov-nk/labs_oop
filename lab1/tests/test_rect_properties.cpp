#include "rect_test_funcs.h"

#include <iostream>

using namespace std;

int main()
{
    Rect r1(2, 8, 5, -1);
    w_h_s_test("Test 1:", &r1, 6, 6, 36);

    r1.set_width(5); w_h_s_test("Test 2:", &r1, 5, 6, 30);
    r1.set_width(0); w_h_s_test("Test 3:", &r1, 5, 6, 30);
    r1.set_width(-5); w_h_s_test("Test 4:", &r1, 5, 6, 30);
    r1.set_width(2.5); w_h_s_test("Test 5:", &r1, 2, 6, 12);

    r1.set_height(10); w_h_s_test("Test 6:", &r1, 2, 10, 20);
    r1.set_height(0); w_h_s_test("Test 7:", &r1, 2, 10, 20);
    r1.set_height(-10); w_h_s_test("Test 8:", &r1, 2, 10, 20);
    r1.set_height(5.4); w_h_s_test("Test 9:", &r1, 2, 5, 10);

    cout << "\nAll `rect_properties` tests passed successfully.\n";
    return 0;
}
