#ifndef STRING_HPP_
#define STRING_HPP_

#include "array.hpp"
#include "stack.hpp"
#include "queue.hpp"


namespace my
{

void strcat(char * dst, char * src);

char * decimal_char(double d, int limit = 6);

char * ntoc(int n, int limit = 6);//정수를 문자열로 변환
char * ntoc(double d, int limit = 6);
// char * ntoc(float f, int limit = 6);//실수를 문자열로 변환
// char * ntoc(char c, int limit = 6);


namespace string
{

using namespace Array;


struct String
{
    my::Array::array<char> _arr;
    size_t length = 0;

    String operator=(char c){
        
        return *this;
    }
    String operator=(char * ch){
        
        return *this;
    }
    String operator=(String & str){
        
        return *this;
    }
    String operator+(char c){

        return *this;
    }
    String operator+(char * ch){
        
        return *this;
    }
    String operator+(String & str){

        return *this;
    }
    String operator+=(char c){

        return *this;
    }
    String operator+=(char * ch){

        return *this;
    }
    String operator+=(String & str){

        return *this;
    }
};




} // namespace string




} // namespace my









    

#endif//STRING_HPP_