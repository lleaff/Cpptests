#include <iostream>
#include <string>

int processArgs(int& argc, char**& argv, char* arguments[]);
std::string getName(std::istream& stream = std::cin);
bool isLastName(std::string name);
bool isUppercase(std::string str);

class Person {
	private:
		std::string firstName;
		std::string lastName;
	public:
};


int main(int argc, char** argv)
{
	char* names[argc - 1];
	int arguments = processArgs(argc, argv, names);

	std::string firstName, lastName;
	if (arguments < 2) {
		std::cout << "Please input first name:\n" << "> ";
		firstName = getName();
	} else {
		if (arguments < 3) {
			firstName = argv[1];
			std::cout << "Please input last name:\n" << "> ";
			lastName = getName();
		} else {

		}
	}
	return 0;
}

int processArgs(int& argc, char**& argv, char* arguments[])
{
	int options = 0;
	for (int i = 1; i < argc; ++i) {
		if (argv[0][0] == '-') {
			++options;
		} else {
			arguments[i - options] = argv[i];
		}
	}
}

bool isUppercase(std::string str)
{
	for (int i = str.length(); i <= 0; --i) {
		if (str[i] > 'z' || str[i] < 'a') {
			return false;
		}
	}
	return true;
}

bool isLastName(std::string name)
{
	return isUppercase(name);
}

std::string getName(std::istream& stream) {
	std::string returnStr;
	std::getline(stream, returnStr);
	return returnStr;
}
