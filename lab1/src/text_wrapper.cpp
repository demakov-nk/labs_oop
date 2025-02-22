#include "text_wrapper.hpp"

#include <iostream>

using namespace std;

/* PUBLIC */
TextWrapper::TextWrapper(const MyString input, const int line_width):
                        input(input), input_len(strlen(input)), line_width(line_width)
{
    lines_init(); 
}

TextWrapper::~TextWrapper()
{
    input.~MyString();
    if (lines)
    {
        for (int i = 0; i < lines_count; i++) lines[i].~MyString();
        delete [] lines;
    }
}

void TextWrapper::print_wrapped() const
{
    print_top();
    print_text();
    print_bottom();
    print_cat();
}

/* PRIVATE */
void TextWrapper::enhance_arr(MyString*& arr, int old_size, const int new_size)
{
    /* Увеличивает массив строк */

    if (old_size <= 0 || new_size <= old_size) return;

    MyString* arr_copy = new MyString[new_size];
    for (int i = 0; i < old_size; i++)
    {
        strcpy(arr_copy[i], arr[i]);
        arr[i].~MyString();
    }
    if (arr) delete [] arr;
    arr = arr_copy;
}

int TextWrapper::get_word_len(const int current_index) const
{
    if (current_index < 0 || current_index >= input_len) return -1;

    /* Находим индекс начала слова */
    int start = current_index;
    while (start != 0 && input.get(start - 1) != ' ') start--;
    /* Находим индекс конца слова (он равен end-1) */
    int end = current_index;
    while (input.get(end) != ' ' && input.get(end) != '\0') end++;

    return end - start;
}

bool TextWrapper::is_new_word(const int current_index) const
{
    /* Проверка, является ли символ началом слова */

    if (current_index < 0 || current_index >= input_len) return false;

    return current_index == 0 || input.get(current_index - 1) == ' ';
}

bool TextWrapper::is_fit(const int current_index, const int current_line_len) const
{
    /* Проверка, помещается ли слово в текущую строку */

    if (current_index < 0 || current_index >= input_len) return false;

    int word_len = get_word_len(current_index);
    return current_line_len + word_len <= line_width;
}

void TextWrapper::normalize(const int current_index)
{
    /* Все оставшееся место в строке заполняется пробелами */
    for (int i = current_index + 1; i < line_width; i++) lines[lines_count - 1].set(i, ' ');
}

void TextWrapper::lines_init()
{
    /* Инициализация массива строк */
    
    lines_count = 1;
    lines = new MyString[lines_count];
    int current_line_len = 0;
    for (int i = 0; i < input_len; i++)
    {
        char ch = input.get(i);
        
        // Если встретили новое слово, которое не помещается в текущую строку,
        // то переносим его на следующую.
        if (is_new_word(i) && get_word_len(i) <= line_width && !is_fit(i, current_line_len))
        {
            normalize(current_line_len - 1);
            enhance_arr(lines, lines_count, lines_count + 1);
            lines_count++;
            current_line_len = 0;
        }

        // Дошли до конца строки - переходим на новую
        if (current_line_len == line_width)
        {
            enhance_arr(lines, lines_count, lines_count + 1);
            lines_count++;
            current_line_len = 0;
        }

        lines[lines_count - 1].set(current_line_len, ch);
        current_line_len++;
    }
    normalize(current_line_len - 1);
}

void TextWrapper::print_top() const
{
    for (int i = 0; i < line_width + 4; i++)
    {
        if (i == 0 || i == line_width + 3)
        {
            cout << '+';
        }
        else
        {
            cout << '-';
        }
    }
    cout << endl;
}

void TextWrapper::print_text() const
{
    for (int i = 0; i < lines_count; i++)
    {
        cout << "| ";
        lines[i].print();
        cout << " |\n";
    }
}

void TextWrapper::print_bottom() const
{
    for (int i = 0; i < line_width + 4; i++)
    {
        if (i == 0 || i == line_width + 3)
        {
            cout << '+';
        }
        else if (i > 2 && i < 8)
        {
            cout << ' ';
        }
        else
        {
            cout << '-';
        }
    }
    cout << endl;
}

void TextWrapper::print_cat() const
{
    cout << "   \\   /\n"
              << "    \\ /\n"
              << "     V\n"
              << "       /\\_/\\  (\n"
              << "      ( ^.^ ) _)\n"
              << "        \\\"/  (\n"
              << "      ( | | )\n"
              << "     (__d b__)\n"    << endl;
}
