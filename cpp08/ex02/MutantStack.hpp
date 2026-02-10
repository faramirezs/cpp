/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:29:52 by alramire          #+#    #+#             */
/*   Updated: 2026/02/10 12:14:28 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    
    // Inherit constructors
    MutantStack() {}
    MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
    MutantStack& operator=(const MutantStack& other) {
        std::stack<T, Container>::operator=(other);
        return *this;
    }
    ~MutantStack() {}

    // Type aliases (required for STL compatibility)

    // typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    // typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // Iterator accessors
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
    
    // // Reverse iterators (optional but good practice)
    // reverse_iterator rbegin() { return this->c.rbegin(); }
    // reverse_iterator rend() { return this->c.rend(); }
};

#endif