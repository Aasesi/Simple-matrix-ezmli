#include "Mtx.h"
#include "Exceptionmatrix.h"
#include <iostream>

namespace ezmxli {
	template<typename M>
	inline Mtx<M>::Mtx()
	{
		rows = 1;
		columns = 1;
		number_of_elements = 1;
		m_data = new M[number_of_elements];
		m_data[0] = 0;
	}

	template<typename M>
	Mtx<M>::Mtx(int rows_, int columns_)
	{
		rows = rows_;
		columns = columns_;
		number_of_elements = rows_ * columns_;
		m_data = new M[number_of_elements];
		for (int i = 0; i < number_of_elements; i++)
		{
			m_data[i] = 0;
		}
	}

	template<typename M>
	Mtx<M>::Mtx(int rows_, int columns_, const M* data)
	{
		rows = rows_;
		columns = columns_;
		number_of_elements = rows_ * columns_;
		m_data = new M[number_of_elements];
		if (sizeof(data) < number_of_elements)
		{
			for (int i = 0; i < number_of_elements; i++)
			{
				if (sizeof(data) > i)
				{
					m_data[i] = data[i];
				}
				else {
					m_data[i] = 0;
				}
			}
		}
		else {
			for (int i = 0; i < number_of_elements; i++)
			{
				m_data[i] = data[i];
			}
		}
	}

	template<typename M>
	Mtx<M>::~Mtx()
	{
		if (m_data != nullptr)
		{
			delete[] m_data;
		}
	}

	template<typename M>
	M Mtx<M>::operator()(int row_, int column_) const
	{
		return m_data[(row_ - 1) * columns + (column_ - 1)];
	}

	template<typename M>
	M& Mtx<M>::operator()(int row_, int column_)
	{
		return m_data[(row_ - 1) * columns + (column_ - 1)];
	}

	template<typename M>
	bool Mtx<M>::operator==(const Mtx<M>& diff)
	{
		if ((this->columns != diff.columns) && (this->rows != rows))
		{
			return false;
		}
		else
		{
			bool flag = true;
			for (int i = 0; i < this->number_of_elements; i++)
			{
				if (this->m_data[i] != diff.m_data[i])
				{
					flag = false;
					break;
				}
			}
			return flag;
		}
	}

	template<typename T>
	Mtx<T> operator+(const Mtx<T>& _another, const Mtx<T>& _diff)
	{
		
		if ((_another.rows == _diff.rows) && (_another.columns == _diff.columns))
		{
			int newrows = _another.rows;
			int newcolumns = _another.columns;
			int new_number_of_elements = newrows * newcolumns;
			T* newdata = new T[new_number_of_elements];
			for (int i = 0; i < new_number_of_elements; i++)
			{
				newdata[i] = _another.m_data[i] + _diff.m_data[i];
			}
			Mtx<T> sum(newrows, newcolumns, newdata);
			delete[] newdata;
			return sum;
		}
		else
		{
			std::cout << "Incompatible rows, columns." << std::endl;
			Mtx<T> mistake;
			return mistake;
		}
		
	}

	template<typename T>
	Mtx<T> operator+(const Mtx<T>& _another, const T& _value)
	{
		int newrows = _another.rows;
		int newcolumns = _another.columns;
		int new_number_of_elements = newrows * newcolumns;
		T* newdata = new T[new_number_of_elements];
		for (int i = 0; i < new_number_of_elements; i++)
		{
			newdata[i] = _value + _another.m_data[i];
		}
		Mtx<T> sum(newrows, newcolumns, newdata);
		delete[] newdata;
		return sum;
	}

	template<typename T>
	Mtx<T> operator+(const T& _value, const Mtx<T>& _diff)
	{
		int newrows = _diff.rows;
		int newcolumns = _diff.columns;
		int new_number_of_elements = newrows * newcolumns;
		T* newdata = new T[new_number_of_elements];
		for (int i = 0; i < new_number_of_elements; i++)
		{
			newdata[i] = _value + _diff.m_data[i];
		}
		Mtx<T> sum(newrows, newcolumns, newdata);
		delete[] newdata;
		return sum;
	}

	template<typename T>
	Mtx<T> operator-(const Mtx<T>& _another, const Mtx<T>& _diff)
	{
		if ((_another.rows == _diff.rows) && (_another.columns == _diff.columns))
		{
			int newrows = _another.rows;
			int newcolumns = _another.columns;
			int new_number_of_elements = newrows * newcolumns;
			T* newdata = new T[new_number_of_elements];
			for (int i = 0; i < new_number_of_elements; i++)
			{
				newdata[i] = _another.m_data[i] - _diff.m_data[i];
			}
			Mtx<T> diffrence(newrows, newcolumns, newdata);
			delete[] newdata;
			return diffrence;
		}
		else
		{
			std::cout << "Incompatible rows, columns." << std::endl;
			Mtx<T> mistake;
			return mistake;
		}
	}

	template<typename T>
	Mtx<T> operator-(const Mtx<T>& _diff, const T& _value)
	{
		int newrows = _diff.rows;
		int newcolumns = _diff.columns;
		int new_number_of_elements = newrows * newcolumns;
		T* newdata = new T[new_number_of_elements];
		for (int i = 0; i < new_number_of_elements; i++)
		{
			newdata[i] = _value - _diff.m_data[i];
		}
		Mtx<T> diffrence(newrows, newcolumns, newdata);
		delete[] newdata;
		return diffrence;
	}

	template<typename T>
	Mtx<T> operator-(const T& _value, const Mtx<T>& _diff)
	{
		int newrows = _diff.rows;
		int newcolumns = _diff.columns;
		int new_number_of_elements = newrows * newcolumns;
		T* newdata = new T[new_number_of_elements];
		for (int i = 0; i < new_number_of_elements; i++)
		{
			newdata[i] = _value - _diff.m_data[i];
		}
		Mtx<T> diffrence(newrows, newcolumns, newdata);
		delete[] newdata;
		return diffrence;
	}

	template<typename T>
	Mtx<T> operator*(const Mtx<T>& _another, const Mtx<T>& _diff)
	{
		if (_another.columns == _diff.rows)
		{
			// It might me faster to give some variables values then just call all of it from some class i think
			int first_mtxr = _another.rows;
			int first_mtxc = _another.columns;
			int sec_mtxr = _diff.rows;
			int sec_mtxc = _diff.columns;
			T* new_data = new T[first_mtxr * sec_mtxc];
			for (int i = 0; i < _another.rows; i++)
			{
				for (int j = 0; j < _diff.columns; j++)
				{
					T sum = 0;
					for (int k = 0; k < _another.columns; k++)
					{
						sum += (_another.m_data[(i * first_mtxc) + k]) * _diff.m_data[(k*sec_mtxc)+j];
					}
					new_data[i * _diff.columns + j] = sum;
				}	
			}
			Mtx<T> new_mtx(first_mtxr, sec_mtxc, new_data);
			delete[] new_data;
			return new_mtx;
		}
		else
		{
			std::cout << "Incompatible rows, columns." << std::endl;
			Mtx<T> mistake;
			return mistake;
		}

	}

	template<typename T>
	Mtx<T> operator*(const Mtx<T>& _diff, const T& _value)
	{
		int newrows = _diff.rows;
		int newcolumns = _diff.columns;
		int new_number_of_elements = newrows * newcolumns;
		T* newdata = new T[new_number_of_elements];
		for (int i = 0; i < new_number_of_elements; i++)
		{
			newdata[i] = _value * _diff.m_data[i];
		}
		Mtx<T> multi(newrows, newcolumns, newdata);
		delete[] newdata;
		return multi;
	}

	template<typename T>
	Mtx<T> operator*(const T& _value, const Mtx<T>& _diff)
	{
		int newrows = _diff.rows;
		int newcolumns = _diff.columns;
		int new_number_of_elements = newrows * newcolumns;
		T* newdata = new T[new_number_of_elements];
		for (int i = 0; i < new_number_of_elements; i++)
		{
			newdata[i] = _value * _diff.m_data[i];
		}
		Mtx<T> multi(newrows, newcolumns, newdata);
		delete[] newdata;
		return multi;
	}

	template<typename M>
	Mtx<M>& Mtx<M>::operator=(const Mtx<M>& _diff)
	{
		if (this == &_diff)
		{
			return *this;
		}
		else
		{
			rows = _diff.rows;
			columns = _diff.rows;
			number_of_elements = _diff.number_of_elements;
			delete[] m_data;
			m_data = new M[number_of_elements];
			for (int i = 0; i < number_of_elements; i++)
			{
				m_data[i] = _diff.m_data[i];
			}
			return *this;
		}
	}

	template<typename M>
	Mtx<M>& Mtx<M>::operator+=(const Mtx<M>& _diff)
	{
		if (rows == _diff.rows && columns == _diff.columns)
		{
			for (int i = 0; i < number_of_elements; i++)
			{
				m_data[i] += _diff.m_data[i];
			}
			return *this;
		}
		else
		{
			std::cout << "Can't add matrixes. Not compatible rows or columns" << std::endl;
			return *this;
		}
	}

	template<typename M>
	Mtx<M>& Mtx<M>::operator+=(const M& _value)
	{
		for (int i = 0; i < number_of_elements; i++)
		{
			m_data[i] += _value;
		}
		return *this;
	}

	template<typename M>
	Mtx<M>& Mtx<M>::operator-=(const Mtx<M>& _diff)
	{
		if (rows == _diff.rows && columns == _diff.columns)
		{
			for (int i = 0; i < number_of_elements; i++)
			{
				m_data[i] -= _diff.m_data[i];
			}
			return *this;
		}
		else
		{
			std::cout << "Can't add matrixes. Not compatible rows or columns" << std::endl;
			return *this;
		}
	}

	template<typename M>
	Mtx<M>& Mtx<M>::operator-=(const M& _value)
	{
		for (int i = 0; i < number_of_elements; i++)
		{
			m_data[i] -= _value;
		}
		return *this;
	}

	template<typename M>
	Mtx<M>& Mtx<M>::operator*=(const Mtx<M>& _diff)
	{
			if (columns == _diff.rows)
			{
				int sec_mtxr = _diff.rows;
				int sec_mtxc = _diff.columns;
				M* new_data = new M[rows * sec_mtxc];
				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < _diff.columns; j++)
					{
						M sum = 0;
						for (int k = 0; k < columns; k++)
						{
							sum += (m_data[(i * columns) + k]) * _diff.m_data[(k * sec_mtxc) + j];
						}
						new_data[i * _diff.columns + j] = sum;
					}
				}
				Mtx<M> new_mtx(rows, sec_mtxc, new_data);
				delete[] new_data;
				return (*this = new_mtx);
			}
			else
			{
				std::cout << "Columns and rows are incompatible" << std::endl;
				return *this;
			}
		
	}

	template<typename M>
	Mtx<M>& Mtx<M>::operator*=(const M& _value)
	{
		for (int i = 0; i < number_of_elements; i++)
		{
			m_data[i] *= _value;
		}
		return *this;
	}

	template<typename M>
	Mtx<M> Mtx<M>::operator^(M _value)
	{
		if (_value == 0 && rows == columns)
		{
			M* new_data = new M[rows * columns];
			for (int i = 0; i < number_of_elements; i++)
			{
				new_data[i] = 1;
			}
			Mtx<M> result(rows, columns, new_data);
			delete[] new_data;
			return result;
		}
		
		if (rows == columns)
		{
			Mtx<M> result = *this;
			for (int i = 1; i < _value; i++) 
			{
				result *= *this;
			}
			return result;
		}
		else
		{
			std::cout << "Matrix needs to be square matrix to perform exponentiation." << std::endl;
			return *this;
		}
	}

	template<typename M>
	inline void Mtx<M>::print_mtx()
	{
		for (int i = 0; i < rows; i++)
		{
			if (i == 0)
			{
				std::cout << "[";
			}
			for (int j = 0; j < columns; j++)
			{
				if (j == 0 && i != 0)
				{
					std::cout<<" " << m_data[i * columns + j] << " ";
				}
				else if (j != (columns - 1))
				{
					std::cout << m_data[i * columns + j] << " ";
				}
				else {
					std::cout << m_data[i * columns + j];
				}
			}
			if (i == (rows - 1))
			{
				std::cout << "]";
			}
			std::cout << std::endl;
		}
	}

	template<typename M>
	Mtx<M> Mtx<M>::transpose() const
	{
		M* new_data = new M[rows*columns];
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				new_data[j * rows + i] = m_data[i * columns + j];
			}
		}
		Mtx<M> result(columns, rows, new_data);
		delete[] new_data;
		return result;
	}

	/**
	 * Determinant of matrix.
	 * Not efficient for matrixes larger then 2x2.
	 * 
	 * \return Determinant
	 */
	template<typename M>
	M Mtx<M>::determinant()
	{
		if (rows != columns)
		{
			std::cout << "It is not possible" << std::endl;
			return 0;
		}
		if (rows == 1)
		{
			return m_data[0];
		}
		if (rows == 2)
		{
			return m_data[0] * m_data[3] + m_data[1] * m_data[2];
		}
		else
		{
			// U¿yj laplace
			std::cout << "did not create implementation yet" << std::endl;
			return 0;
		}
	}

	template<typename M>
	Mtx<M> Mtx<M>::r_row(int index)
	{
		if (index - 1  > rows)
		{
			std::cout << "Index of a row out of bounds" << std::endl;
			Mtx<M> r;
			return r; // Need to make an exception
		}
		else
		{
			M* new_data = new M[columns];
			for (int i = 0; i < columns; i++)
			{
				new_data[i] = m_data[(index-1) * columns + i];
			}
			Mtx<M> result(1, columns, new_data);
			delete[] new_data;
			return result;
		}
	}

	template<typename M>
	Mtx<M> ezmxli::Mtx<M>::r_column(int index)
	{
		if (columns < index - 1)
		{
			std::cout << "Index of a row out of bounds" << std::endl;
			Mtx<M> r;
			return r; // Need to make an exception
		}
		else
		{
			M* new_data = new M[rows];
			for (int i = 0; i < rows; i++)
			{
				new_data[i] = m_data[i*columns+index];
			}
			Mtx<M> result(rows, 1, new_data);
			delete[] new_data;
			return result;
		}
	}

	template<typename M>
	int Mtx<M>::n_rows() const
	{
		return rows;
	}

	template<typename M>
	int Mtx<M>::n_columns() const
	{
		return columns;
	}
	
	template<typename M>
	bool Mtx<M>::set(int row_, int column_, const M value)
	{
		return false;
	}

	template class Mtx<int>;
	template class Mtx<double>;
	template class Mtx<float>;
	template class Mtx<long>;
}
