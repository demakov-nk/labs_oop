class Barrel
{
    int vol; // текущий объем жидкости в мл
    double percent; // % спирта

public:
    Barrel(int vol, double percent = 0);

    int get_vol() const;
    double get_percent() const;

    void reduce(int volume);

    void pour_from(Barrel& src, const int volume);
};