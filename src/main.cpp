#include "mylib.hpp"
#include "array.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "string.hpp"



void print(char * data){
    write(STDOUT_FILENO,data,my::strlen(data));
}

void print(char data){
    write(STDOUT_FILENO,&data,1);
}

void print(const my::Array::array<char> & str){
    print(str._inner._data);
}


int main() {
    
    double d = 123.456;


    my::Array::array<char> str;
    str._inner.set(my::decimal_char(d));
    print(str);
    print('\n');

    return 0;
}