#include "string.hpp"



namespace my
{

void strcat(char * dst, char * src){
    size_t dst_len = my::strlen(dst);
    size_t src_len = my::strlen(src);
    char * temp = new char[dst_len + src_len];
    size_t idx = 0;
    for (size_t i = 0; i < dst_len; i++, idx++){
        temp[idx] = dst[i];
    }
    for (size_t i = 0; i < src_len; i++, idx++){
        temp[idx] = src[i];
    }
    delete[] dst;
    dst = new char[my::strlen(temp)];
    my::memcpy(dst,temp,my::strlen(temp));

}

void strcat(char * dst, char * src){
    size_t dst_len = my::strlen(dst);
    size_t src_len = my::strlen(src);
    char * temp = new char[dst_len + src_len];
    size_t idx = 0;
    for (size_t i = 0; i < dst_len; i++, idx++){
        temp[idx] = dst[i];
    }
    for (size_t i = 0; i < src_len; i++, idx++){
        temp[idx] = src[i];
    }
    delete[] dst;
    dst = new char[my::strlen(temp)];
    my::memcpy(dst,temp,my::strlen(temp));

}


char * ntoc(int n, int limit){//정수를 문자열로 변환
    my::Stack::stack<char> stack;
    bool flag = false;
    stack.push('\0');
    if(n < 0){
        n *= -1;
        flag = true;
    }
    do{
        stack.push((n%10)+'0');
        n/=10;
    }while(n);
    if(flag){
        stack.push('-');
    }
    char * result = new char[stack.size];
    stack.arr_pop(result);
    return result;
}

char * decimal_char(double d, int limit){
    my::Queue::queue<char> q;
    q.push('.');
    d -= int(d);
    if(d<0){
        d *= -1;
    }
    d*=10;
    while(limit--){
        q.push(int(d)+'0');
        d *= 10;
    }
    char * result = new char[q.size];
    q.arr_pop(result);
    return result;
}

char * ntoc(double d, int limit){
    char * temp = my::ntoc(int(d));
    my::Queue::queue<char> q;
    if(d < 0){
        d *= -1;
    }
    bool flag = false;//소수가 -0.1234면 맨 앞에 - 붙이기 위해
    if(!int(d)){
        flag = true;
    }
    d -= int(d);
    q.push('.');
    double tolerence = 0.1;
    while(limit--){
        d *= 10;
        q.push(int(d)+'0');
    }
    size_t idx = 0;
    char * result;
    if (flag){
        result = new char[my::strlen(temp)+q.size+1];
        result[0] = '-';
        my::memcpy(result+1,temp,my::strlen(temp));
        q.arr_pop(result+1+my::strlen(temp));
    }else {
        result = new char[my::strlen(temp)+q.size];
        my::memcpy(result,temp,my::strlen(temp));
        q.arr_pop(result+my::strlen(temp));
    }
    return result;
}
// char * ntoc(float f, int limit);//실수를 문자열로 변환
// char * ntoc(char c, int limit);



} // namespace my