#include "my_string.hpp"

class TextWrapper
{
private:
    const MyString input;
    const int input_len;
    const int line_width;

    MyString* lines;
    int lines_count;

public:
    TextWrapper(const MyString input, const int line_width);
    ~TextWrapper();
    void print_wrapped() const;

private:
    void enhance_arr(MyString*& arr, int old_size, const int new_size);
    int get_word_len(const int current_index) const;
    bool is_new_word(const int current_index) const;
    bool is_fit(const int current_index, const int current_line_len) const;
    void normalize(const int current_index);
    
    void lines_init();

    void print_top() const;
    void print_text() const;
    void print_bottom() const;
    void print_cat() const;
};
