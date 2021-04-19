#include <iostream>
#include <string>
#include <vector>
#include <exception>


template <typename T> struct S
{
S(T v):val{v}{}


private:
	T val;


public:
	T get();
	const T& get() const;
    void set(T v);
    S<T>& operator= (const T& v);
};




template <typename T>
T S<T>::get()
{
	return val;
}


template <typename T>
const T& S<T>::get() const
{
	return  &val;
}


template <typename T>
S<T>& S<T>::operator=(const T& v)
{
	val=v;
	return *this;
}


template<typename T>
void read_val(T& v)
{
	std::cin>>v;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v )
{

	os<<'{';

	for(int i=0;i<v.size();i++)
	{
		os<<v[i]<<", ";
	}

	os<<"}\n";


	return os;
}



template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v )
{


	char f;

	is>>f;

	if(f!='{')std::exception();
	T val;
	while(is>>val)
	{
		v.push_back(val);
		is>>f;
		if(f!=',')
			break;
	}
	
return is;
}




template <typename T>
void S<T>::set(T v)
{
	val=v;
}


int main()
{

int i;
S<int> s1(20);
read_val(i);
s1=i;


char c;
read_val(c);
S<char> s2('B');
s2=c;

std::vector<double> v;
S<std::vector<double>> s4(std::vector<int>{1.0,2.0,3.0});
read_val(v);

/*
std::string str;
S<std::string> s3("Kobal");
read_val(str);
 */


}		