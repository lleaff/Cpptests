#include <iostream>
#include <string>
#include <string.h> // strcpy()

#define OPTIONSC 5
#define MAXOPTIONNAMELENGTH 20

int processArgs(int* const argc, char** const argv, char* arguments[], 
		bool* flags, char optionsNames[][MAXOPTIONNAMELENGTH]);
std::string getName(std::istream& stream = std::cin);
bool isLastName(std::string name);
bool isUppercase(std::string str);

class Person {
	private:
	public:
		std::string firstName;
		std::string lastName;
};


int main(int argc, char** argv)
{
	Person myPerson;

	bool options[OPTIONSC];
	char optionsNames[OPTIONSC][MAXOPTIONNAMELENGTH] = {
		"print",
		"firstname",
		"lastname"
	};

	char* names[argc - 1];
	int arguments = processArgs(&argc, argv, names, options, optionsNames);

	if (arguments < 2) {
		std::cout << "Please input first name:\n" << "> ";
		myPerson.firstName = getName();
	} else {
		if (arguments < 3) {
			myPerson.firstName = argv[1];
			std::cout << "Please input last name:\n" << "> ";
			myPerson.lastName = getName();
		} else {

		}
	}
	return 0;
}


int processOption(int* const argc, char** const argv, bool flags[], int optionsC)
{
	flags;
}

// Returns the number of regular arguments
int processArgs(int* const argc, char** const argv, char* arguments[], 
		bool* flags, char optionsNames[][MAXOPTIONNAMELENGTH])
{
	int options = 0;
	for (int i = 1; i < *argc; ++i) {
		if (argv[0][0] == '-') {
			++options;
			flags[processOption(argc, argv, flags, options)] = true;
		} else {
			strcpy(arguments[i - options], argv[i]);
		}
	}
	return *argc - options;
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
