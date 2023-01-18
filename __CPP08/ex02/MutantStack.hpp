#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<int>
{
    public:
        MutantStack() : std::stack<int>() {}
        MutantStack(MutantStack const &src) : std::stack<int>(src) {}
        ~MutantStack() {}
        MutantStack &operator=(MutantStack const &rhs)
        {
            std::stack<int>::operator=(rhs);
            return *this;
        }
        typedef std::deque<int>::iterator iterator;
        iterator begin() { return std::stack<int>::c.begin(); }
        iterator end() { return std::stack<int>::c.end(); }
};

#endif