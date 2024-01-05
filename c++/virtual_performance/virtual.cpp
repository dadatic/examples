//  virtual.cpp
//  Some simple examples to test compiler optimisation of virtual functions.

/*
MIT License

Copyright (c) dadatic

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/


#include "virtual.hpp"


unsigned testdirect(VirtualDerived d)
{
// With optimisations on, calling a virtual function non virtually is as optimisable as if the function were not virtual.
// If the function can be evaluated at compile time, no actual call needs to be made at run time.
// In my system, the call `d.test()` can be inlined as a single amd64 instruction:
//    movl    $69, %eax

    return d.test();
}

unsigned testindirect(VirtualDerived& d)
{
// A virtual call cannot be fully optimised if the compiler does not know the actual class.
// The generated code must find whether `d` actually points to an object of class `VirtualDerived` or to some other derived class.
// In my system, the compiler is unable to inline the call `d.test()`.
    return  d.test();
}

unsigned testindirectvisible()
{
// Even if the function is called virtually, a smart compiler can fully optimise the call if the actual class can be determined at compile time.
// In my system, the call `b.test()` can again be inlined as a single amd64 instruction:
//    movl    $69, %eax

    VirtualDerived d;
    VirtualBase& b = d;
    return  b.test();
}

