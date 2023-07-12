#include "mylib.hpp"

namespace my
{

size_t strlen(const char * str){
    size_t idx = 0;
    while (str[idx] && str[idx] != '\0'){
        idx++;
    }
    return idx;
}

void C_memcpy(void * dst, void * src,  size_t size) {
    for (size_t i = 0; i < size; i++){
        ((char *)dst)[i] = ((char *) src)[i];
    }
}



} // namespace my