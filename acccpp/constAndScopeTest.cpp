#include <iostream>
//#include <string>

int main()
{
	const std::string test = "IT'S A TEST";
	std::cout << test << std::endl;
	{
		const std::string test = "THIS IS NOT A TEST";
		std::cout << test << std::endl;
	}

	return 0;
}
