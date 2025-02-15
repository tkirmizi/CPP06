#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cmath>
class ScalarConverter{
	// gonna add orthodox thing
	private:
		// ScalarConverter();
		// ScalarConverter(ScalarConverter const &other);
		// ScalarConverter &operator=(ScalarConverter const &other);
		// ~ScalarConverter();

		static bool isDouble(std::string const &str);
		static bool isFloat(std::string const &str);
		static bool isInt(std::string const &str);
		static bool isChar(std::string const &str);
	public:
		static void convert(std::string const &literal);
};

void ScalarConverter::convert(std::string const &literal)
{
	bool isCharFlag = isChar(literal);
	bool isIntFlag = isInt(literal);
	bool isFloatFlag = isFloat(literal);
	bool isDoubleFlag = isDouble(literal);

	std::cout << isCharFlag << isIntFlag << isFloatFlag << isDoubleFlag << std::endl;

	/*
    // Handle special values
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || 
	literal == "+inff" || literal == "-inff")
	{
		// gonna impelement this later
	}
	*/

	//char convert
	{
		std::cout << "char: ";
		if (isCharFlag)
			std::cout << "'" << literal[1] << "'" << std::endl;
		else if (isIntFlag)
		{
			int i = std::stoi(literal);
			if (i >= 32 && i <= 126)
				std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
			else
				std::cout << "Non displayable" << std::endl;
		}
	}
}

int main(int argc, char **argv)
{
	try 
	{
		if (argc != 2)
		{
			std::cout << "Error: program must take one argument" << std::endl;
			return 1;
		}
		ScalarConverter::convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}

bool ScalarConverter::isChar(std::string const &str)
{
	int flag = 1;

	if (str.length() != 3)
		flag = 0;
	else if (str[0] != '\'')
		flag = 0;
	else if (str[2] != '\'')
		flag = 0;
	if (!flag)
		return false;
	return true;
}

bool ScalarConverter::isInt(std::string const &str)
// overflow check
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
	size_t sign = 0;
	size_t dot = 0;

	if (!str[0])
		return false;

	if (str.empty())
		return false;

	if (str[str.length() - 1] != 'f')
		return false;

	if (str[0] == '-' || str[0] == '+')
	{
		sign = 1;
		if (str.length() == 1)
			return false;
	}

	for (; sign < str.length(); sign++)
	{
		if (!std::isdigit(str[sign]) && str[sign] != '.' && str[sign] != 'f')
			return false;
		if (str[sign] == '.')
			dot++;
	}

	if (dot != 1)
		return false;
	return true;
}


bool ScalarConverter::isDouble(std::string const &str)
{
	size_t sign = 0;
	size_t dot = 0;

	if (!str[0])
		return false;

	if (str.empty())
		return false;
		
	if (str.length() < 3)
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
	if (dot == 1)
	{
		size_t pos = str.find('.');
		if (!str[pos+1] || str[pos+1] == 'f')
			return false;
		return true;
	}
	if (dot != 1)
		return false;
	return true;
}

