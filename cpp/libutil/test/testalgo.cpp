#include <assert.h>

#include <iostream>

#include "algo.hpp"

using namespace util;

void Test()
{
    std::cout << std::endl << "LexicalCast----------------:" << std::endl;
    {
        int i = 0;
        double d = 0.0;
        bool ret = LexicalCast(i, 12345);
        assert(ret);
        assert(i == 12345);
        std::cout << "12345 ->" << i << "(true)" << std::endl;
        ret = LexicalCast(d, 12345);
        assert(ret);
        // assert(d == 12345);
        std::cout << "12345 ->" << d << "(true)" << std::endl;
        ret = LexicalCast(d, 0.12345);
        assert(ret);
        // assert(d == 0.12345);
        std::cout << "0.12345 -> " << d << "(true)" << std::endl;
        ret = LexicalCast(i, 1.12345);
        assert(!ret);
        // assert(i == 1);
        std::cout << "1.12345 -> " << i << "(false)" << std::endl;
    }

    std::cout << std::endl << "StringToNumber----------------:" << std::endl;
    {
        int i = 0;
        double d = 0.0;
        bool ret = StringToNumber(i, "12345");
        assert(ret);
        assert(i == 12345);
        std::cout << "12345 -> " << i << "(true)" << std::endl;
        ret = StringToNumber(i, "a12345");
        assert(!ret);
        std::cout << "a12345 -> " << i << "(false)" << std::endl;
        ret = StringToNumber(i, "123a45");
        assert(!ret);
        std::cout << "123a45 -> " << i << "(false)" << std::endl;
        ret = StringToNumber(i, "12345a");
        assert(!ret);
        std::cout << "12345a -> " << i << "(false)" << std::endl;

        ret = StringToNumber(d, "0.12345");
        assert(ret);
        // assert(d == 0.12345);
        std::cout << "0.12345 -> " << d << "(true)" << std::endl;
        ret = StringToNumber(d, "a0.12345");
        assert(!ret);
        std::cout << "a0.12345 -> " << d << "(false)" << std::endl;
        ret = StringToNumber(d, "a0.12a345");
        assert(!ret);
        std::cout << "0.12a345 -> " << d << "(false)" << std::endl;
        ret = StringToNumber(d, "0.12345a");
        assert(!ret);
        std::cout << "0.12345a -> " << d << "(false)" << std::endl;

        ret = StringToNumber(d, "12345");
        assert(ret);
        // assert(d == 12345);
        std::cout << "12345 -> " << d << "(true)" << std::endl;

        ret = StringToNumber(i, "0x12345a", std::hex);
        assert(ret);
        assert(i == 0x12345a);
        std::cout << "0x12345a -> " << i << "(true)" << std::endl;
        ret = StringToNumber(i, "0x12345a");
        assert(!ret);
        std::cout << "0x12345a -> " << i << "(false)" << std::endl;
        ret = StringToNumber(i, "0x12345g");
        assert(!ret);
        std::cout << "0x12345g -> " << i << "(false)" << std::endl;
    }
}


int main()
{
    Test();
    return 0;
}
