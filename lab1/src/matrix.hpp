class Matrix
{
private:
    int lines, cols;
    double** matrix;

    bool is_compatible(const Matrix* m1, const Matrix* m2);
    void del_matrix_if_exists();

public:
    Matrix(int n);
    Matrix(int m, int n, double fill_value=0);
    Matrix(const Matrix& source);
    ~Matrix();

    double get(int i, int j) const;
    void set(int i, int j, double value);
    int get_height() const;
    int get_width() const;
    void negate();
    void add_in_place(Matrix& other);
    Matrix multiply(Matrix &other);

    const Matrix& operator = (const Matrix& source);
};