#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cmath>

/*
	static_cast
	base_type = static_cast<base_type>(converted_var)
	base_type = dynamic_cast<base_type>(converted_var)
	std
	isnan
	isinf
	isprint
	numeric_limits<type>::min()
	numeric_limits<type>::max()

	std::precision -> kac basamak goruntuleceginni belirler. numberden once gelir
	std::precison ile kullanildiginda precision noktadan sonra kac basamak gelcegini ayarlar

	TODO FOR TOMORROW
	do it without exception
	then implement exceptions


*/


// int main(){
// 	class A{};
// 	class B{};

// 	A *a = new A();
// 	B *b = static_cast<B*>(a); 
// }




 // Infinity değerleri için

// int main(){
// 	float pos = 1.0f / 0.0;
// 	float neg = -1.0f / 0.0;

// 	std::cout << pos <<  " " << neg << std::endl;
// }

// int main(){
// 	double nbr = 3.142984;
// 	std::cout << std::setprecision(4)  << nbr << std::endl;
// }


class ScalarConverter{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();

		// all bool will be private !
		static bool isFloat(std::string const &str);
		static bool isDouble(std::string const &str);

	public:
		static bool isInt(std::string const &str);
		static bool isChar(std::string const &str);
		static void convert(std::string const &literal);

		class NonDisplayableException : public std::exception{
		public:
			virtual const char* what() const throw(){ return "Non displayable character";}};

		class ImpossibleException : public std::exception {
		public:
			virtual const char* what() const throw() {return "Impossible conversion";}};

		class OverflowException : public std::exception{
		public:
			virtual const char* what() const throw() {return "Overflow";}};
};

bool ScalarConverter::isChar(std::string const &str)
{
	int flag = 1;

		if (str.length() != 3)
			flag = 0;
	
		if (str[0] != '\'')
			flag = 0;
	
		if (str[2] != '\'')
			flag = 0;
	
		if (!std::isprint(str[1]))
			flag = 0;
	
		if (!flag)
			return false
		return ture;
	}
	catch(const NonDisplayableException& e)
	{
		throw;
	}
	catch(const ImpossibleException& e)
	{
		throw;
	}
}
bool ScalarConverter::isInt(std::string const &str)
{
	if (str.empty())
		throw ImpossibleException(std::string("char: wrong length"));
	
	size_t sign = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		sign = 1;
		if (str.length() == 1)
			throw ImpossibleException();
	}

	for (; sign < str.length(); sign++)
	{
		if (!std::isdigit(str[sign]))
			throw ImpossibleException();
	}

	try
	{
		int value = std::stoi(str);
		if (value > std::numeric_limits<int>::max())
			throw OverflowException();
	}
	catch (const std::out_of_range&)
	{
		throw OverflowException();
	}
	catch (const std::invalid_argument&)
	{
		throw ImpossibleException();
	}

	return true;
}


