#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include "iterator.hpp"
#include "container.hpp"
#include "mylib.hpp"



namespace my
{
    
using namespace Container;
using namespace Iterator;

namespace Array
{

template<typename T>
struct array//배열 열화판(?)
{   
    my::container<T *> _inner;//배열 저장 컨테이너 선언
    size_t _size = 0;
    my::iterator<T *> iter;
    //같은 구조체 내에서 같은 요소를 공유하는 원소는 자동으로 this를 지시?
    //절대 아닐 것 같지만 일단 궁금

    //컨테이너에 데이터(value) 저장
    void push(T value){
        if (!this->_size){
            this->_size = 1;
            T * new_data = new T[this->_size];
            new_data[0] = value;
            this->_inner.set(new_data);
        }else {
            T * new_data = new T[this->_size+1];
            my::memcpy(new_data,this->_inner._data,this->_size);
            new_data[this->_size] = value;
            delete this->_inner.get();
            this->_inner.set(new_data);
            this->_size++;
        }
        iter.target_con_ = &this->_inner;
    }

//이거랑 사이즈만큼 루프 돌려서 푸시하는거랑 차이??
    void push(T *value, size_t value_size){
        if(!this->_size){
            this->_size = value_size;
            T *new_data = new T[this->_size];
            my::memcpy(new_data,value,this->_size);
            this->_inner.set(new_data);
        }else{
            T *new_data = new T[this->_size+value_size];
            my::memcpy(new_data,this->_inner.get(),this->_size);
            my::memcat(new_data,value,this->_size,value_size);
            delete this->_inner.get();
            this->_inner.set(new_data);
            this->_size += value_size;
        }
    }
    
    T pop(size_t i = 0){
        if (!this->_size || i >= this->_size){
            return -1;
        }else if (this->_size && i < this->_size){
            while(this->_size){
                this->data_.get(i++);
                this->_size--;
            }
            delete this->_data;
            return 0;
        }
    }

    //파라미터로 주어진 인덱스에 데이터 끼워넣기
    void insert(T data, size_t idx){

    }

    //array 전체 데이터 삭제
    // void _delete();

    /*
    지정된 인덱스 컨테이너 삭제(파라미터 여러개 받아서 지우기???)
    지정된 범위 삭제
    */

};


} // namespace array




} // namespace my




#endif//ARRAY_HPP_