#ifndef VECTOR_H
#define VECTOR_H

class Vector {

public:
  const static unsigned long n = 3;

Vector()
  {
		for (int i = 0; i < n; i++)
			coords_[i] = 0;
  };

explicit Vector(double number)
  {
		for (int i = 0; i < n; i++)
			coords_[i] = number;
	};

Vector(const Vector &other)
  {
		for (int i = 0; i < n; i++)
			coords_[i] = other.coords_[i];
  };

Vector &operator=(const Vector &other)
  {
		for (int i = 0; i < n; i++)
			coords_[i] = other.coords_[i];
  };
double operator[](unsigned long i) const
	{
		return coords_[i];
	};

double &operator[](unsigned long i)
	{
		return coords_[i];
	};
	
Vector &operator+=(const Vector &other)
  {
		for (int i = 0; i < n; i++)
			coords_[i] = coords_[i] + other.coords_[i];
  };

Vector &operator-=(const Vector &other)
  {
		for (int i = 0; i < n; i++)
			coords_[i] = coords_[i] - other.coords_[i];
  };

Vector &operator*=(double number)
  {
		for (int i = 0; i < n; i++)
			coords_[i] = coords_[i] * number;
  };

Vector &operator/=(double number)
  {
		for (int i = 0; i < n; i++)
			coords_[i] = coords_[i] / number;
  };

friend bool operator==(const Vector &our, const Vector &other)
  {
		for (int i = 0; i < n; ++i)
			if (our.coords_[i] != other.coords_[i])
			{
				return false;
			}
		return true;
  };

friend Vector operator+(const Vector &our, const Vector &other)
  {
		Vector Vector_return;
		for (int i = 0; i < n; i++)
			Vector_return.coords_[i] = our.coords_[i] + other.coords_[i];
		return Vector_return;
  };

friend Vector operator-(const Vector &our, const Vector &other)
  {
		Vector Vector_return;
		for (int i = 0; i < n; i++)
			Vector_return.coords_[i] = our.coords_[i] - other.coords_[i];
		return Vector_return;
  };

friend Vector operator*(const Vector &our, double number)
  {
		Vector Vector_return;
		for (int i = 0; i < n; i++)
			Vector_return.coords_[i] = our.coords_[i] * number;
		return Vector_return;
  };

friend Vector operator*(double number, const Vector &our)
  {
		Vector Vector_return;
		for (int i = 0; i < n; i++)
			Vector_return.coords_[i] = our.coords_[i] * number;
		return Vector_return;
  };

friend Vector operator/(const Vector &our, double number)
  {
		Vector Vector_return;
		for (int i = 0; i < n; i++)
			Vector_return.coords_[i] = our.coords_[i] / number;
		return Vector_return;
  };
  
void print()
	{
		for(int i = 0; i < n; i++)
			std::cout<<coords_[i]<<"   ";
		std::cout<<'\n';
	};
	
friend double operator^(const Vector &our, const Vector &other)
	{
		double sum[n];
		double sum_return = 0;
		for(int i = 0; i < n; i++)
			{
				sum[i] = our.coords_[i]*other.coords_[i];
				sum_return = sum_return + sum[i];
			}
		return sum_return;
	};

Vector operator-()const
	{
		Vector Vector_return;
		for (int i = 0; i < n; i++)
			Vector_return.coords_[i] = (-1)*coords_[i] ;
		return Vector_return;
  };
  
private:
  double coords_[n];
  
}; // class Vector

bool operator!=(const Vector &our, const Vector &other)
	{
		if (our == other)
			return false;
		else
			return true;
	};
#endif // VECTOR_H
