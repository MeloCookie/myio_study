#ifndef MYLIB_HPP_
#define MYLIB_HPP_

#include<unistd.h>


/*
destination = dest = dst -> 목적지
source = src -> 근원, 원천, 정보원
*/
namespace my
{
    
//공용
template<typename T>
size_t memcpy(T * dst, T * src, size_t size){
    size_t i = 0;
    for (i; i < size; i++){
        dst[i] = src[i];//*((T *)dst+i) = *((T *)src+i);
    }
    return i;
}

template<typename T>
void memcpy(T & dst, const T & src){
    dst = &src;
}



void C_memcpy(void * dst, void * src,  size_t size);

//배열 크기 구하는 법만 찾으면 사이즈 안주고 늘릴 수 있을까
template<typename T>
void memcat(T * dst, const T * src,size_t start, size_t size){
    for(size_t i = 0; i < size; i++){
        dst[start++] = src[i];
    }
}

template<typename T>
size_t countof(T * ptr_arr);// 배열 크기 사이즈 안쓰고 우째 구하지?


//문자열 관련




size_t strlen(const char * str);


//문자열에 dst와 똑같은 문자열이 들어있다면, 그 문자열의 시작 인덱스 리턴
void find_str(const char * src, const char * dst);























} // namespace my


#endif//MYLIB_HPP