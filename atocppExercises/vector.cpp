#include <iostream>
#include <vector>
#include <algorithm>

template<typename T> 
void printVector(std::vector<T> vect)
{
	int vsize = vect.size();
	for (int i = 0; i < vsize; ++i) {
		std::cout << vect[i] << (i < vsize - 1 ? ", " : "");
	}
}

bool compInt(int el1, int el2)
{
	return (el1 < el2);
}
bool compString(std::string el1, std::string el2)
{
	return (el1 < el2);
}

int main()
{
	using namespace std;
	vector<int> intVect = { 5, 9, -1, 200, 0 };
	printVector(intVect); cout << "\n";
	cout << "...sort...\n";
	sort(intVect.begin(), intVect.end(), compInt);
	printVector(intVect); cout << "\n";

	cout << "\n";
	vector<string> strVect = { "Kant", "Plato", "Aristotle", "Kierkegard", "Hume" };
	printVector(strVect); cout << "\n";
	cout << "...sort...\n";
	sort(strVect.begin(), strVect.end(), compString);
	printVector(strVect); cout << "\n";

}
