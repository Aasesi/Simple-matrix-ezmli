#include "Exceptionmatrix.h"

const char* invalid_row_or_col::what() const throw()
{
	return "Incorect number of rows or columns cannot perform operation.";
}

