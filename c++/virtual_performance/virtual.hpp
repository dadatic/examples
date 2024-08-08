//  virtual.hpp
//  Some simple examples to test compiler optimisation of virtual functions.

/*
MIT License

Copyright (c) 2020 dadatic

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


#ifndef virtual_hpp
#define virtual_hpp

#include <cstdlib>

class VirtualBase
{
public:
    virtual unsigned test() const noexcept
    {
        // Some random stuff that cannot be evaluated at compile time
        unsigned thing = std::rand();
        for (int i = 0; i < 10; ++i)
        {
            thing += std::rand();
        }
        return thing;
    }
    
    virtual ~VirtualBase() = default;
};

class VirtualDerived : public VirtualBase
{
public:
    unsigned test() const noexcept override
    {
        // Something very simple that can be evaluated at compile time
        return 69;
    }
};

unsigned testdirect(VirtualDerived d);

unsigned testindirect(VirtualDerived& d);

unsigned testindirectvisible();


#endif /* virtual_hpp */
