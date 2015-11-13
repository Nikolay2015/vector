#ifndef VECTOR_H
#define VECTOR_H

class Vector {

public:
	const static unsigned long n = 3;

Vector()
{
	for (unsigned long i = 0; i < n; i++)
	{
		coords_[i] = 0;
	}
};

explicit Vector(double number)
{
	for (unsigned long i = 0; i < n; i++)
	{
		coords_[i] = number;
	}
};

Vector(const Vector &other)
{
	for (unsigned long i = 0; i < n; i++)
	{
		coords_[i] = other.coords_[i];
	}
};

Vector &operator=(const Vector &other)
{
	for (unsigned long i = 0; i < n; i++)
	{
		coords_[i] = other.coords_[i];
	}
	return *this;
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
	for (unsigned long i = 0; i < n; i++)
	{
		coords_[i] += other.coords_[i];
	}
	return *this;
};

Vector &operator-=(const Vector &other)
{
	for (unsigned long i = 0; i < n; i++)
	{
		coords_[i] -=  other.coords_[i];
	}
	return *this;
};

Vector &operator*=(double number)
{
	for (unsigned long i = 0; i < n; i++)
	{
		coords_[i] *=  number;
	}
	return *this;
};

Vector &operator/=(double number)
{
	for (unsigned long i = 0; i < n; i++)
	{
		coords_[i] /=  number;
	}
	return *this;
};

friend bool operator==(const Vector &lhs, const Vector &rhs)
{
	for (unsigned long i = 0; i < n; ++i)
	{
		if (lhs.coords_[i] != rhs.coords_[i])
		{
			return false;
		}
	}
	return true;
};

friend Vector operator+(const Vector &our, const Vector &other)
{
	Vector Vector_return(our);
	return Vector_return += other;
};

friend Vector operator-(const Vector &our, const Vector &other)
{
	Vector Vector_return(our);
	return Vector_return -= other;
};

friend Vector operator*(const Vector &our, double number)
{
	Vector Vector_return(our);
	return Vector_return *= number;
};

friend Vector operator*(double number, const Vector &our)
{
	Vector Vector_return(our);
	return Vector_return *= number;
};

friend Vector operator/(const Vector &our, double number)
{
	Vector Vector_return(our);
	return Vector_return /= number;
};

friend std::ostream &operator<<(std::ostream &stream, const Vector &v)
{
	for (unsigned long i = 0; i < n; i++)
	{
		stream<<v.coords_[i]<<" ";
	}
	return stream;
}; 

friend double operator^(const Vector &our, const Vector &other)
{
	double sum_return = 0;
	for (unsigned long i = 0; i < n; i++)
	{
		sum_return = sum_return + our.coords_[i]*other.coords_[i];;
	}
	return sum_return;
};

Vector operator-()const
{
	Vector Vector_return;
	for (unsigned long i = 0; i < n; i++)
	{
		Vector_return.coords_[i] = (-1)*coords_[i] ;
	}
	return Vector_return;
};
  
private:
	double coords_[n];
  
}; // class Vector

bool operator!=(const Vector &our, const Vector &other)
{
	return !(our == other);
};

#endif // VECTOR_H
