#include <iostream>
#include <string>

void capitalizeWords(std::string& myString);

int main()
{
	std::string name;
	std::cout << "Input name\n";
	std::cin >> name;
	capitalizeWords(name);

	int age;
	std::cout << "Input age\n";
	std::cin >> age;

	std::cout << "...\n" << "name: " << name << "\nage: " << age << std::endl;
}

char toUpper(char myChar)
{
	return myChar >= 'a' && myChar <= 'z' ? myChar - 'a' + 'A' : myChar;
}
char toLower(char myChar)
{
	return myChar >= 'A' && myChar <= 'Z' ? myChar - 'A' + 'a' : myChar;
}
bool isWordDelimiter(char myChar)
{
	char wordDelimiters[] = "'\",.:()[]<>\\/";
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
