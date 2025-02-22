class Rect
{
    // int left, right, top, bottom;
    int ptx, pty, width, height;

    // void normalize();
    void normalize(int* left, int* right, int* top, int* bottom);

public:
    Rect(int l, int r, int t, int b);
    Rect();
    Rect(const Rect& source);
    ~Rect();

    /* Доступ к полям */
    int get_left() const;
    int get_right() const;
    int get_top() const;
    int get_bottom() const;
    /* Инициализация полей */
    void set_all(int left, int right, int top, int bottom);
    /* Сдвиги от центра */
    void inflate(int amount); // все стороны
    void inflate(int dw, int dh); // отдельно верх и низ, отдельно боковые стенки
    void inflate(int d_left, int d_right, int d_top, int d_bottom); // каждая сторона отдельно
    void move(int dx, int dy=0); // параллельный перенос
    /* Ширина, высота и площадь */
    int get_width() const;
    int get_height() const;
    int get_square() const;
    void set_width(int width);
    void set_height(int height);
};


Rect bounding_rect(const Rect r1, const Rect r2);
void print_rect(const Rect& r);
