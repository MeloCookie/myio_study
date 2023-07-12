#ifndef STACK_HPP_
#define STACK_HPP_

#include "container.hpp"
#include "mylib.hpp"

namespace my
{

using namespace Container;

namespace Stack
{

template <typename T>
struct stack
{
    my::container<T> * top;
    size_t size = 0;
    size_t current_idx_ = 0;//스택, 큐 인덱스 이터레이터(?)

    void push(T data){
        my::container<T> *new_con = new my::container<T>;
        new_con->set(data);
        if(!this->size){
            this->top = new_con;
        }else {
            new_con->next = this->top;
            this->top = new_con;
        }
        this->size++;
    }



    T pop(){
        if(!this->size){
            return -1;
        }
        T result = this->top->get();
        my::container<T> *update = this->top->next;
        delete this->top;
        this->top = update;
        this->size--;
        return result;
    }

    void arr_pop(T *result){
        size_t idx = 0;
        while(this->size){
            result[idx++] = this->pop();
        }
    }
};//struct Stack


} // namespace stack



} // namespace my

#endif//STACK_HPP_