#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include "container.hpp"
#include "mylib.hpp"

namespace my
{

using namespace Container;

namespace Queue
{


template <typename T>
struct queue
{
    my::container<T> * first;
    my::container<T> * rear;
    size_t size = 0;

    void push(T value){
        my::container<T> * new_con = new my::container<T>;
        new_con->set(value);
        if (!this->size){
            this->first = new_con;
            this->rear = this->first;
        }else {
            this->rear->next = new_con;
            this->rear = new_con;
        }
        this->size++;
    }

    T pop(){
        if(!this->size){
            return -1;
        }
        T data = this->first->get();
        my::container<T> * update = this->first->next;
        delete this->first;
        this->first = update;
        this->size--;
        return data;
    }

    void arr_pop(T *result){
        size_t idx = 0;
        while(this->size){
            result[idx++] = this->pop();
        }
    }
};


} // namespace queue


} // namespace my




#endif//QUEUE_HPP_