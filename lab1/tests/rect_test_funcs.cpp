#include "rect_test_funcs.h"

#include <iostream>
#include <cassert>

using namespace std;

void sides_test(const char* header_message, const Rect* rect,
                const int l, const int r, const int t, const int b)
{
    cout << header_message << endl;
    cout << "\tleft - "; assert(rect->get_left() == l); cout << "correct\n";
    cout << "\tright - "; assert(rect->get_right() == r); cout << "correct\n";
    cout << "\ttop - "; assert(rect->get_top() == t); cout << "correct\n";
    cout << "\tbottom - "; assert(rect->get_bottom() == b); cout << "correct\n";
    cout << "Test passed successfully.\n";
}

void w_h_s_test(const char* header_message, const Rect* rect,
                const int w, const int h, const int s)
{
    cout << header_message << endl;
    cout << "\twidth - "; assert(rect->get_width() == w); cout << "correct\n";
    cout << "\theight - "; assert(rect->get_height() == h); cout << "correct\n";
    cout << "\tsquare - "; assert(rect->get_square() == s); cout << "correct\n";
    cout << "Test passed successfully.\n";
}
