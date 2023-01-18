#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(Span const &src)
{
    *this = src;
}

Span::~Span()
{
}

Span &Span::operator=(Span const &rhs)
{
    if (this != &rhs)
    {
        this->_n = rhs._n;
        this->_v = rhs._v;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (this->_v.size() == this->_n)
        throw Span::ContainerFullException();
    this->_v.push_back(n);
}

int Span::shortestSpan()
{
    if (this->_v.size() <= 1)
        throw Span::ContainerEmptyException();
    std::sort(this->_v.begin(), this->_v.end());
    int min = this->_v[1] - this->_v[0];
    for (unsigned int i = 1; i < this->_v.size() - 1; i++)
    {
        if (this->_v[i + 1] - this->_v[i] < min)
            min = this->_v[i + 1] - this->_v[i];
    }
    return min;
}

int Span::longestSpan()
{
    if (this->_v.size() <= 1)
        throw Span::ContainerEmptyException();
    std::sort(this->_v.begin(), this->_v.end());
    return this->_v[this->_v.size() - 1] - this->_v[0];
}
