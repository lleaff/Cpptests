#include <iostream>
#include <string>

void capitalizeWords(std::string& myString);
class Individual
{
	protected:
		std::string name;
		int age;
	public:
		void setName(char *cStyleString)	{ name = *cStyleString; capitalizeWords(name); }
		void setName(std::string stdString)	{ name = stdString; capitalizeWords(name); }
		std::string getName() { return name; }
		void setAge(int num) { age = num; }
		int getAge() { return age; }

		friend void operator>>(std::string str, Individual &ind);
		friend void operator>>(char *str, Individual &ind);
		friend void operator>>(int num, Individual &ind);
		friend std::ostream& operator<<(std::ostream& strm, Individual& ind);
};

void operator>>(std::string str, Individual &ind) {
	ind.setName(str);
}
void operator>>(char *str, Individual &ind) {
	ind.setName(str);
}
void operator>>(int num, Individual &ind) {
	ind.setAge(num);
}
std::ostream& operator<<(std::ostream& strm, Individual& ind) {
	strm << "Name: " << ind.getName() << "\nAge:   " << ind.getAge() << std::endl; 
	return strm; 
}



int stringToInt(std::string str)
{
	int num = 0;
	int strL = str.length();
	for (int i = 0; i < strL && (str[i] >= '0' && str[i] <= '9'); ++i) {
		num = num*10 + str[i] - '0';
	}
	return num;
}

static inline bool isQuitMsg(std::string& str)
{
	return (str == "quit" || str == "stop" || str[0] == EOF);
}

int main()
{
	const int MAXPERSONSC = 100;
	Individual persons[MAXPERSONSC];

	std::cout << "Input name and ages\n\"quit\" or \"stop\" to stop\n";
	std::string input;
	int age;
	int i;
	for (i = 0; i < MAXPERSONSC; ++i) {
		std::cout << "Person " << i + 1 << "\n";
		std::cout << "name: ";
		std::getline(std::cin, input);
		if (isQuitMsg(input)) {
			--i; break;
		} else {
			input >> persons[i];
		}

		std::cout << "age: ";
		std::getline(std::cin, input);
		if (isQuitMsg(input)) {
			--i; break;
		} else {
			age = stringToInt(input);
			if (age >= 0 && age <= 199) {
				stringToInt(input) >> persons[i];
			} else {
				std::cerr << "Invalid age: " << age << std::endl;
			}
		}
	}

	for (int j = 0; j <= i; ++j) {
		std::cout << "----person n" << j + 1 << "----\n";
		std::cout << persons[j];
		//std::cout << persons[j].getName() << '\n';
		//std::cout << persons[j].getAge() << " years old" << std::endl;
	}
}

inline char toUpper(char myChar)
{
	return myChar >= 'a' && myChar <= 'z' ? myChar - 'a' + 'A' : myChar;
}
inline char toLower(char myChar)
{
	return myChar >= 'A' && myChar <= 'Z' ? myChar - 'A' + 'a' : myChar;
}
static bool isWordDelimiter(char myChar)
{
	char wordDelimiters[] = " \t'\",.:()[]<>\\/";
	for (char ch : wordDelimiters) {
		if (ch == myChar) {
			return true;
		}
	}
	return false;
}
void capitalizeWords(std::string& myString)
{
	int length = myString.length();
	bool wordStart = true;
	for (int i = 0; i < length; ++i) {
		if (isWordDelimiter(myString[i])) {
			wordStart = true;
		} else {
			myString[i] = wordStart ? toUpper(myString[i]) : toLower(myString[i]);
			wordStart = false;
		}
	}
}
