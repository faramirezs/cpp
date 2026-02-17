/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:29:52 by alramire          #+#    #+#             */
/*   Updated: 2026/02/12 16:02:05 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <deque>
#include <iostream>
#include <algorithm>

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

    // Iterator accessors
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

};
