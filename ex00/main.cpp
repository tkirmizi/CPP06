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

	public:
		static bool isDouble(std::string const &str);
		static bool isFloat(std::string const &str);
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
			return false;
		return true;
}

bool ScalarConverter::isInt(std::string const &str)
{
	int flag = 1;
	size_t sign = 0;

	if (str.empty())
		flag = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		sign = 1;
		if (str.length() == 1)
			flag = 0;
	}

	for (; sign < str.length(); sign++)
	{
		if (!std::isdigit(str[sign]))
			return false;
	}
	if (!flag)
		return false;
	return true;
}

bool ScalarConverter::isFloat(std::string const &str)
{
	int flag = 1;
	size_t sign = 0;
	size_t dot = 0;

	if (!str[0])
		return false;

	if (str == "nanf" || str == "+inff" || str == "-inff")
		return true;

	if (str.empty())
		return false;
		
	if (str[str.length() - 1] != 'f')
		flag = 0;

	if (str[0] == '-' || str[0] == '+')
	{
		sign = 1;
		if (str.length() == 1)
			flag = 0;
	}

	for (; sign < str.length(); sign++)
	{
		if (!std::isdigit(str[sign]) && str[sign] != '.')
			flag = 0;
		if (str[sign] == '.')
			dot++;
	}
	if (dot > 1)
		flag = 0;	
	return true;
}


bool ScalarConverter::isDouble(std::string const &str)
{
	int flag = 1;
	size_t sign = 0;
	size_t dot = 0;

	if (!str[0])
		return false;
	if (str == "nan" || str == "+inf" || str == "-inf")
		return true;

	if (str.empty())
		return false;
		
	if (str[0] == '-' || str[0] == '+')
	{
		sign = 1;
		if (str.length() == 1)
			return false;
	}

	for (; sign < str.length(); sign++)
	{
		if (!std::isdigit(str[sign]) && str[sign] != '.')
			return false;
		if (str[sign] == '.')
			dot++;
	}
	if (dot > 1)
		return false;
	return true;
}


int main(){
std::cout << ScalarConverter::isDouble("abc") << std::endl;   // false
std::cout << ScalarConverter::isDouble("") << std::endl; // false
std::cout << ScalarConverter::isDouble("42.0f") << std::endl; // false 
std::cout << ScalarConverter::isDouble("42.0") << std::endl;  // true
std::cout << ScalarConverter::isDouble("-42.42") << std::endl;// true
std::cout << ScalarConverter::isDouble("nan") << std::endl;   // true
std::cout << ScalarConverter::isDouble("+inf") << std::endl;  // true
std::cout << ScalarConverter::isDouble("-inf") << std::endl;  // true
std::cout << ScalarConverter::isDouble("42.0.1") << std::endl;// false
}