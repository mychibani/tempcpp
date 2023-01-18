#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <list>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _v;
    public:
        Span(unsigned int n);
        Span(Span const &src);
        ~Span();
        Span &operator=(Span const &rhs);
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        class ContainerFullException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Container is full";
                }
        };
        class ContainerEmptyException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Container is empty";
                }
        };
};

#endif