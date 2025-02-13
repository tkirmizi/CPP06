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

		// bool functions
		static bool isChar(std::string const &str);
		static bool isInt(std::string const &str);
		static bool isFloat(std::string const &str);
		static bool isDouble(std::string const &str);

	public:
		static void convert(std::string const &literal);
};

bool ScalarConverter::isChar(std::string const &str){
	int flag;
	flag = 1;
	if (str.length() != 3)
		flag = 0;
	else if (str[0] != '\'')
		flag = 0;
	else if (str[2] != '\'')
		flag = 0;
	else if (!std::isprint(str[1]))
		flag = 0;
	return flag;
}
