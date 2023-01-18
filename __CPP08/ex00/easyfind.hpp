#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <list>


class IsNotInContainer : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "Value not found in container";
        }
};

template <typename T>

typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw IsNotInContainer();
    return it;
}

#endif