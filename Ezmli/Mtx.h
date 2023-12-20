#ifndef MTX_H_
#define MTX_H_


namespace ezmxli
{
	template<typename M>
	class Mtx
	{
	private:
		int rows;
		int columns;
		int number_of_elements;
		M* m_data;
	public:
		Mtx();
		Mtx(int rows_, int columns_);
		Mtx(int rows_, int columns_, const M* data);
		~Mtx();
		M operator()(int row_, int column_) const;
		M& operator()(int row_, int column_);
		bool operator==(const Mtx<M>& diff);
		template<typename T> friend Mtx<T> operator+(const Mtx<T>& _another, const Mtx<T>& _diff);
		template<typename T> friend Mtx<T> operator+(const Mtx<T>& _diff, const T& _value);
		template<typename T> friend Mtx<T> operator+(const T& _value, const Mtx<T>& _diff);
		template<typename T> friend Mtx<T> operator-(const Mtx<T>& _another, const Mtx<T>& _diff);
		template<typename T> friend Mtx<T> operator-(const Mtx<T>& _diff, const T& _value);
		template<typename T> friend Mtx<T> operator-(const T& _value, const Mtx<T>& _diff);
		template<typename T> friend Mtx<T> operator*(const Mtx<T>& _another, const Mtx<T>& _diff);
		template<typename T> friend Mtx<T> operator*(const Mtx<T>& _diff, const T& _value);
		template<typename T> friend Mtx<T> operator*(const T& _value, const Mtx<T>& _diff);
		Mtx<M>& operator=(const Mtx<M>& _diff);
		Mtx<M>& operator+=(const Mtx<M>& _diff);
		Mtx<M>& operator+=(const M& _value);
		Mtx<M>& operator-=(const Mtx<M>& _diff);
		Mtx<M>& operator-=(const M& _value);
		Mtx<M>& operator*=(const Mtx<M>& _diff);
		Mtx<M>& operator*=(const M& _value);
		Mtx operator^(M _value);
		Mtx<M> transpose() const;
		// Mtx inverse();
		M determinant();
		int n_rows() const;
		int n_columns() const;
		bool set(int row_, int column_, const M value);
		Mtx<M> r_row(int index);
		Mtx<M> r_column(int index);
		void print_mtx();
	};
}

#endif