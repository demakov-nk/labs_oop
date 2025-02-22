#include "matrix.hpp"

#include <iostream>
#include <cassert>

using namespace std;

/* PRIVATE */

bool Matrix::is_compatible(const Matrix* m1, const Matrix* m2)
{
    return m1->cols == m2->lines;
}

void Matrix::del_matrix_if_exists()
{
    if (matrix)
    {
        for (int i = 0; i < lines; i++) delete [] matrix[i];
        delete [] matrix;
    }
}

/* PUBLIC */

Matrix::Matrix(int n)
{
    assert(n > 0);
    lines = n;
    cols = n;
    matrix = new double*[lines];
    for (int i = 0; i < lines; i++)
    {
        matrix[i] = new double[cols];
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = 1;
        }
    }
}

Matrix::Matrix(int m, int n, double fill_value)
{
    assert(m > 0 && n > 0);
    lines = m;
    cols = n;
    matrix = new double*[lines];
    for (int i = 0; i < lines; i++)
    {
        matrix[i] = new double[cols];
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = fill_value;
        }
    }
}

Matrix::Matrix(const Matrix& source)
{
    lines = source.get_height();
    cols = source.get_width();

    matrix = new double*[lines];
    for (int i = 0; i < lines; i++)
    {
        matrix[i] = new double[cols];
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = source.get(i, j);
        }
    }
}

Matrix::~Matrix() { del_matrix_if_exists(); }

double Matrix::get(int i, int j) const
{
    assert(i >= 0 && i < lines && j >= 0 && j < cols);

    return matrix[i][j];
}

void Matrix::set(int i, int j, double value)
{
    if (i < 0 || i >= lines || j < 0 || j >= cols) return;

    matrix[i][j] = value;
}

int Matrix::get_height() const
{
    return lines;
}

int Matrix::get_width() const
{
    return cols;
}

void Matrix::negate()
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = -matrix[i][j];
        }
    }
}

void Matrix::add_in_place(Matrix& other)
{
    if (!is_compatible(this, &other)) throw "Матрицы несовместимы.";

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] += other.get(i, j);
        }
    }
}

Matrix Matrix::multiply(Matrix& other)
{
    if (!is_compatible(this, &other)) throw "Матрицы несовместимы.";

    Matrix res(cols, other.get_width());
    for (int i = 0; i < res.get_height(); i++)
    {
        for (int j = 0; j < res.get_width(); j++)
        {
            double sum = 0;
            for (int x = 0; x < cols; x++)
            {
                sum += matrix[i][x] * other.get(x, j);
            }
            res.set(i, j, sum);
        }
    }

    return res;
}

const Matrix& Matrix::operator = (const Matrix& source)
{
    if (&source == this) return *this;

    lines = source.get_height();
    cols = source.get_width();

    del_matrix_if_exists();
    matrix = new double*[lines];
    for (int i = 0; i < lines; i++)
    {
        matrix[i] = new double[cols];
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = source.get(i, j);
        }
    }

    return *this;
}
