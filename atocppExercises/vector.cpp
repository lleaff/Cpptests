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

int main()
{
	using namespace std;
	vector<int> myVector = { 5, 9, -1, 200, 0 };
	printVector(myVector);
	sort(myVector.begin(), myVector.end(), myVector);
}
