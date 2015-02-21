#include <iostream>

void printCString(const char (&cstr)[100]);

int main()
{
	std::cout << "---program-start---\n";

	char cstring[100] = "Test string";

	printCString(cstring);
	std::cout << "\n";
}

void printCString(const char (&cstr)[100])
{
	using std::cout;
	for (const auto& ch: cstr) {
		cout << ch;
	}
}
