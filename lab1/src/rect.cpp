#include "rect.hpp"

#include <iostream>

using namespace std;

/* PRIVATE */

// void Rect::normalize()
// {
//     if (left > right)
//     {
//         int x = left;
//         left = right;
//         right = x;
//     }
//     if (top < bottom)
//     {
//         int y = top;
//         top = bottom;
//         bottom = y;
//     }
// }
void Rect::normalize(int* left, int* right, int* top, int* bottom)
{
    if (*left > *right)
    {
        int x = *left;
        *left = *right;
        *right = x;
    }
    if (*top < *bottom)
    {
        int y = *top;
        *top = *bottom;
        *bottom = y;
    }
}

/* PUBLIC */

Rect::Rect(int l, int r, int t, int b)
{
    // cout << "Конструктор класса Rect для объекта " << this << endl;

    // left = l;
    // right = r;
    // top = t;
    // bottom = b;
    // normalize();
    normalize(&l, &r, &t, &b);
    ptx = l;
    pty = b;
    width = r - l;
    height = t - b;
}

Rect::Rect()
{
    // cout << "Конструктор по умолчанию класса Rect для объекта " << this << endl;

    // left = right = top = bottom = 0;
    ptx = pty = 0;
    width = height = 0;
}

Rect::Rect(const Rect& source)
{
    // cout << "Конструктор копирования класса Rect для объекта " << this << endl;

    // left = source.get_left();
    // right = source.get_right();
    // top = source.get_top();
    // bottom = source.get_bottom();
    ptx = source.get_left();
    pty = source.get_bottom();
    width = source.get_width();
    height = source.get_height();
}

Rect::~Rect()
{
    // cout << "Деструктор класса Rect для объекта " << this << endl;
}


int Rect::get_left() const { /*return left;*/ return ptx; }
int Rect::get_right() const { /*return right;*/ return ptx + width; }
int Rect::get_top() const { /*return top;*/ return pty + height; }
int Rect::get_bottom() const { /*return bottom;*/ return pty; }

void Rect::set_all(int left, int right, int top, int bottom)
{
    // this->left = left;
    // this->right = right;
    // this->top = top;
    // this->bottom = bottom;
    // normalize();
    normalize(&left, &right, &top, &bottom);
    ptx = left;
    pty = bottom;
    width = right - left;
    height = top - bottom;
}

void Rect::inflate(int amount)
{
    if (amount < 0) return;

    // left -= amount;
    // right += amount;
    // top += amount;
    // bottom -= amount;
    ptx -= amount;
    pty -= amount;
    width += 2*amount;
    height += 2*amount;
}

void Rect::inflate(int dw, int dh)
{
    if (dw < 0 || dh < 0) return;

    // left -= dw;
    // right += dw;
    // top += dh;
    // bottom -= dh;
    ptx -= dw;
    pty -= dh;
    width += 2*dw;
    height += 2*dh;
}

void Rect::inflate(int d_left, int d_right, int d_top, int d_bottom)
{
    if (d_left < 0 || d_right < 0 || d_top < 0 || d_bottom < 0) return;
    
    // left -= d_left;
    // right += d_right;
    // top += d_top;
    // bottom -= d_bottom;
    ptx -= d_left;
    pty -= d_bottom;
    width += d_left + d_right;
    height += d_top + d_bottom;
}

void Rect::move(int dx, int dy)
{
    // left += dx;
    // right += dx;
    // top += dy;
    // bottom += dy;
    ptx += dx;
    pty += dy;
}

int Rect::get_width() const
{
    // return right - left;
    return width;
}

int Rect::get_height() const
{
    // return top - bottom;
    return height;
}

int Rect::get_square() const
{
    return get_width() * get_height();
}

void Rect::set_width(int width)
{
    if (width < 1) return;

    // right = left + width;
    this->width = width;
}

void Rect::set_height(int height)
{
    if (height < 1) return;

    // top = bottom + height;
    this->height = height;
}

/* Внешние функции */

Rect bounding_rect(const Rect r1, const Rect r2)
{
    int min_left   = (r1.get_left() < r2.get_left())     ? r1.get_left()   : r2.get_left();
    int max_right  = (r1.get_right() > r2.get_right())   ? r1.get_right()  : r2.get_right();
    int max_top    = (r1.get_top() > r2.get_top())       ? r1.get_top()    : r2.get_top();
    int min_bottom = (r1.get_bottom() < r2.get_bottom()) ? r1.get_bottom() : r2.get_bottom();

    Rect bounding;
    bounding.set_all(min_left, max_right, max_top, min_bottom);
    return bounding;
}

void print_rect(const Rect& r)
{
    printf("{A(%d, %d), ", r.get_left(), r.get_bottom());
    printf("B(%d, %d), ", r.get_left(), r.get_top());
    printf("C(%d, %d), ", r.get_right(), r.get_top());
    printf("D(%d, %d)}\n", r.get_right(), r.get_bottom());
}
