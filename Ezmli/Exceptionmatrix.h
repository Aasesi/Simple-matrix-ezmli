#ifndef EXCEPTIONMATRIX_H_
#define EXCEPTIONMATRIX_H_

#include <iostream>
#include<memory>
class invalid_row_or_col : public std::exception
{
public:
	const char* what() const throw();
};

#endif