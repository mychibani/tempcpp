#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

#include <cstddef>
#include <iostream>

template<typename T>

class Array
{
    public :
        Array() : __array(NULL), __size(0) {}
        Array(int n) : __array(new T[n]), __size(n) {}
        Array(const Array &rhs) {*this = rhs;}
        ~Array(){delete [] __array;}
        Array &operator=(const Array &rhs)
        {
            this->__array = new T[rhs.__size];
            this->__size = rhs.__size;
            for (int i = 0; i < __size; i++)
                __array[i] = rhs.__array[i];
            return (*this);
        }
        T &operator[](int elem)
        {
            if (elem > -1 && elem < this->__size)
                return (__array[elem]);
            else
                throw ElemOutOfArray();
        };
        int size (void)
        {
            return (__size);
        }
        class ElemOutOfArray : public std::exception
		{
			public:
				virtual const char * what (void) const throw() {return "Element number is out of the array";}
		};

    private :
        T* __array;
        int __size;

};


#endif