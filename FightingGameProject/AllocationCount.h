#pragma once
#include <iostream>
#include <cstdlib>

int numObjects = 0;

void CurrentCount()
{
    //std::cout << "current allocation count: " << numObjects << std::endl;

    if (numObjects == 0)
    {
        std::cout << std::endl;
        std::cout << "numObjects is 0" << std::endl;
    }
}

void* operator new(std::size_t size)
{
    ++numObjects;
    
    //std::cout << "Allocating " << size << " bytes" << std::endl;
    
    return std::malloc(size);
}

void operator delete(void* ptr)
{
    --numObjects;
    
    //std::cout << "Deallocating" << std::endl;;
    
    std::free(ptr);

    CurrentCount();
}