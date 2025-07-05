/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:42:58 by alramire          #+#    #+#             */
/*   Updated: 2025/07/05 14:14:41 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <cctype>
# include <algorithm>

class Fixed
{
    private:
        int integer;
        static const int scint = 8;
        
    public:
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed& operator=(Fixed const & rhs);
        Fixed(Fixed const & src);
        Fixed(void);
        ~Fixed(void);
};


#endif