/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:41:52 by alramire          #+#    #+#             */
/*   Updated: 2026/02/12 16:14:16 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"
#include <iostream>
#include <algorithm>
# include <list>

int main()
{
    std::cout << "========== MutantStack ==========" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout <<"We'll pop this: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout <<"Size: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);

        std::cout << "========== sorted ==========" << std::endl;
        std::sort(mstack.begin(), mstack.end());
        MutantStack<int>::iterator itt = mstack.begin();
        MutantStack<int>::iterator itte = mstack.end();
        ++itt;
        --itt;
        while (itt != itte)
        {
            std::cout << *itt << std::endl;
            ++itt;
        }

    }

    std::cout << std::endl;
    std::cout << "========== std::list ==========" << std::endl;
    {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        std::cout << "We'll back this: " <<lst.back() << std::endl;
        lst.pop_back();
        std::cout <<"Size: " << lst.size() << std::endl;
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        //[...]
        lst.push_back(0);
        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    return 0;
}