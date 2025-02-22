#include "rect_test_funcs.h"

#include <iostream>

using namespace std;

int main()
{
    Rect r1(2, 8, 5, -1);

    r1.inflate(5); sides_test("Test 1.1:", &r1, -3, 13, 10, -6);
    r1.inflate(0); sides_test("Test 1.2:", &r1, -3, 13, 10, -6);
    r1.inflate(-4); sides_test("Test 1.3:", &r1, -3, 13, 10, -6);
    r1.inflate(2.9); sides_test("Test 1.4:", &r1, -5, 15, 12, -8);

    r1.inflate(3, 2); sides_test("Test 2.1:", &r1, -8, 18, 14, -10);
    r1.inflate(0, 2); sides_test("Test 2.2:", &r1, -8, 18, 16, -12);
    r1.inflate(3, 0); sides_test("Test 2.3:", &r1, -11, 21, 16, -12);
    r1.inflate(-3, 2); sides_test("Test 2.4:", &r1, -11, 21, 16, -12);
    r1.inflate(3, -2); sides_test("Test 2.5:", &r1, -11, 21, 16, -12);
    r1.inflate(-3, -2); sides_test("Test 2.6:", &r1, -11, 21, 16, -12);
    r1.inflate(3.3, 2.2); sides_test("Test 2.7:", &r1, -14, 24, 18, -14);

    r1.inflate(1, 2, 3, 4); sides_test("Test 3.1:", &r1, -15, 26, 21, -18);
    r1.inflate(0, 2, 3, 4); sides_test("Test 3.2:", &r1, -15, 28, 24, -22);
    r1.inflate(1, 0, 3, 4); sides_test("Test 3.3:", &r1, -16, 28, 27, -26);
    r1.inflate(1, 2, 0, 4); sides_test("Test 3.4:", &r1, -17, 30, 27, -30);
    r1.inflate(1, 2, 3, 0); sides_test("Test 3.5:", &r1, -18, 32, 30, -30);
    r1.inflate(0, 0, 3, 4); sides_test("Test 3.6:", &r1, -18, 32, 33, -34);
    r1.inflate(0, 2, 0, 4); sides_test("Test 3.7:", &r1, -18, 34, 33, -38);
    r1.inflate(0, 2, 3, 0); sides_test("Test 3.8:", &r1, -18, 36, 36, -38);
    r1.inflate(0, 0, 0, 4); sides_test("Test 3.9:", &r1, -18, 36, 36, -42);
    r1.inflate(0, 0, 3, 0); sides_test("Test 3.10:", &r1, -18, 36, 39, -42);
    r1.inflate(0, 0, 0, 0); sides_test("Test 3.11:", &r1, -18, 36, 39, -42);
    r1.inflate(-1, 2, 3, 4); sides_test("Test 3.12:", &r1, -18, 36, 39, -42);
    r1.inflate(1, -2, 3, 4); sides_test("Test 3.13:", &r1, -18, 36, 39, -42);
    r1.inflate(1, 2, -3, 4); sides_test("Test 3.14:", &r1, -18, 36, 39, -42);
    r1.inflate(1, 2, 3, -4); sides_test("Test 3.15:", &r1, -18, 36, 39, -42);
    r1.inflate(-1, -2, 3, 4); sides_test("Test 3.16:", &r1, -18, 36, 39, -42);
    r1.inflate(-1, 2, -3, 4); sides_test("Test 3.17:", &r1, -18, 36, 39, -42);
    r1.inflate(-1, 2, 3, -4); sides_test("Test 3.18:", &r1, -18, 36, 39, -42);
    r1.inflate(-1, -2, -3, 4); sides_test("Test 3.19:", &r1, -18, 36, 39, -42);
    r1.inflate(-1, -2, 3, -4); sides_test("Test 3.20:", &r1, -18, 36, 39, -42);
    r1.inflate(-1, -2, -3, -4); sides_test("Test 3.21:", &r1, -18, 36, 39, -42);
    r1.inflate(1.1, 2.2, 3.3, 4.4); sides_test("Test 3.22:", &r1, -19, 38, 42, -46);

    r1.move(4, 5); sides_test("Test 4.1:", &r1, -15, 42, 47, -41);
    r1.move(0, 5); sides_test("Test 4.2:", &r1, -15, 42, 52, -36);
    r1.move(4, 0); sides_test("Test 4.3:", &r1, -11, 46, 52, -36);
    r1.move(0, 0); sides_test("Test 4.4:", &r1, -11, 46, 52, -36);
    r1.move(-4, 5); sides_test("Test 4.5:", &r1, -15, 42, 57, -31);
    r1.move(4, -5); sides_test("Test 4.6:", &r1, -11, 46, 52, -36);
    r1.move(-4, -5); sides_test("Test 4.7:", &r1, -15, 42, 47, -41);
    r1.move(4.4, 5.5); sides_test("Test 4.8:", &r1, -11, 46, 52, -36);

    cout << "\nAll `rect_operations` tests passed successfully.\n";
    return 0;
}
