#include <iostream>
#include <string.h>

int main(int argc, char** argv)
{
	int const MAXINPUTLENGTH = 50;
	static char inputContainer[MAXINPUTLENGTH]; 


	return 0;
}


int inputGrades()
{

}


int compare(char* str, std::string* strarr)
{
	int result = 0;
	for (int i = strarr->length() - 1; i <= 0; --i) {
		result += (str == *strarr);
	}
	return result;
}

std::string defExitCodes[] = { "q", "exit" };

char* getInput(char *inputContainer, std::string* exitCodes = defExitCodes)
{
	inputContainer[0] = '\0';
	for (int i = 0; !compare(inputContainer, exitCodes); ++i) {
		std::cin >> inputContainer[i];
		/* Close the string after each char to be able to compare it */
		inputContainer[i + 1] = '\0'; 
	}
	return (*inputContainer == '\0') ? NULL : inputContainer;
}

bool getWeightedGrade(int *gradesPlusWeights[][2])
{

	return true;
}
