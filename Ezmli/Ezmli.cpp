#include <iostream>
#include "Mtx.h"
#include "Mtx.cpp"


int main()
{
    ezmxli::Mtx<int> some;
    ezmxli::Mtx<int> somee(2, 2);
    int data[4] = { 1, 2, 3, 4 };
    int data2[4] = { 2, 3, 4, 5 };
    ezmxli::Mtx<int> a(2, 2, data);
    ezmxli::Mtx<int> b(2, 2, data2);
    ezmxli::Mtx<int> c = a + b;
    c.print_mtx();
    std::cout << std::endl;
    std::cout << std::endl;
    ezmxli::Mtx<int> e = 5 + a;
    e.print_mtx();
    std::cout << std::endl;
    std::cout << std::endl;
    ezmxli::Mtx<int> d = 10 * c;
    d.print_mtx();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << c(2, 1) << std::endl;
    c = c + b;
    c.print_mtx();
    std::cout << std::endl;
    std::cout << std::endl;
    ezmxli::Mtx<int> ga = c.r_row(1);
    ga.print_mtx();
}

