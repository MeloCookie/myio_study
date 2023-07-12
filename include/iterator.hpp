#ifndef ITERATOR_HPP_
#define ITERATOR_HPP_

#include "container.hpp"


namespace my
{

using namespace Container;

namespace Iterator
{
    template<typename T>
    struct iterator
    {
        my::container<T> * target_con_;//컨테이너 포인터(베열가능) 선언
        size_t elem_idx_;//컨테이너의 데이터가 배열일 경우 사용
        size_t con_idx_;//컨테이너 포인터 조절

        //배열의 맨 앞의 주소 리턴 -> T[0]
        T * begin(){
            if (this->target_con_){
                this->elem_idx_ = 0;
                return &this->target_con_;
            }
        }

        //배열의 맨 뒤의 다음(쓰레기값)주소 리턴(루프 사용 용이)
        T * end(size_t size/*arr.size_*/){
            if(size){
                this->elem_idx_ = size;
                return &this->target_con_->data_+size;
            }
        }

        //현재 위치의 다음 지시
        T * next(){

        }

        T * select(size_t idx){

        }
    };
    

} // namespace iterator


} // namespace my





#endif//ITERATOR_HPP