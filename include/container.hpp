#ifndef CONTAINER_HPP_
#define CONTAINER_HPP_

#include<unistd.h>


namespace my
{
    
namespace Container
{

template<typename T>
struct container
{
    T _data;
    container<T> *next;//스택 : 현재 컨테이너 아래, 큐 : 현재 컨테이너 뒤
    container<T> *prev;//iterator 전용(?)
    // size_t end_idx = 0;//배열 데이터 마지막
    // size_t sq_idx = 0;//스택 큐 인덱스


    void set(const T value){//컨테이너에 데이터 저장
        this->_data = value;
    }

    T get(){//컨테이너에 들어있는 데이터 추출
        return this->_data;
    }
};


} // namespace container


} // namespace my





#endif//CONTAINER_HPP_