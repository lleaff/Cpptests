#include <iostream>
#include <string>

std::string getFirstName(std::istream& stream = std::cin);
std::string getSecondName(std::istream& stream = std::cin);
bool isLastName(std::string name);
bool isUppercase(std::string str);

int main(int argc, char **argv)
{
	std::string firstName;
	if (argc < 2) {
		firstName = getFirstName();
	} else {
		firstName = argv[1];
	}
	return 0;
}

bool isUppercase(std::string str)
{

}

bool isLastName(std::string name)
{

}
