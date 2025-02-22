#include "rect_test_funcs.h"

#include <iostream>

using namespace std;

int main()
{
    /* Similar/With itself */
    {
        Rect r1(0, 5, 5, 0);
        Rect res = bounding_rect(r1, r1);
        sides_test("Test 1.1:", &res, 0, 5, 5, 0);
    }

    /* Same side */
    {
        Rect r1(0, 5, 5, 0);
        Rect r2(5, 12, 5, 0);
        Rect res = bounding_rect(r1, r2);
        sides_test("Test 2.1:", &res, 0, 12, 5, 0);
    }

    /* Same corner */
    {
        Rect r1(0, 5, 5, 0);
        Rect r2(5, 12, 16, 5);
        Rect res = bounding_rect(r1, r2);
        sides_test("Test 3.1:", &res, 0, 12, 16, 0);
    }

    /* Intersections */
    {
        Rect r1(0, 5, 5, 0);
        Rect r2(2, 10, 8, 3);
        Rect r3(4, 6, 4, 2);
        Rect r4(3, 6, 9, -2);
        Rect res;

        res = bounding_rect(r1, r2); sides_test("Test 4.1:", &res, 0, 10, 8, 0);
        res = bounding_rect(r1, r3); sides_test("Test 4.2:", &res, 0, 6, 5, 0);
        res = bounding_rect(r1, r4); sides_test("Test 4.3:", &res, 0, 6, 9, -2);
        res = bounding_rect(r2, r3); sides_test("Test 4.4:", &res, 2, 10, 8, 2);
        res = bounding_rect(r2, r4); sides_test("Test 4.5:", &res, 2, 10, 9, -2);
        res = bounding_rect(r3, r4); sides_test("Test 4.6:", &res, 3, 6, 9, -2);
    }

    /* Non-intersection */
    {
        Rect r1(0, 5, 5, 0);
        Rect r2 (8, 11, -2, -7);
        Rect res = bounding_rect(r1, r2);
        sides_test("Test 5.1:", &res, 0, 11, 5, -7);
    }

    cout << "\nAll `bounding_rect` tests passed successfully.\n";
    return 0;
}

