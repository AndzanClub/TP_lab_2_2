#include "helper.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

bool isSplitterSuggestion(const char& ch) {
	return ch == '.' || ch == '?' || ch == '!' || ch == ')' || ch == '(' || ch == '\n' || ch == '\0';
}

bool checkSuggestion(const string& s) {
	for (char ch : s)
		if (ch == ',')
			return false;
	return true;
}

std::string task(const string& s) {
	std::string ans = "";
	bool isSuggestion = false;
	int startSuggestoin = 0;
	for (int i = 0; i < s.size(); i++) {
			if (isSplitterSuggestion(s[i])) {
				string suggestoin = s.substr(startSuggestoin, i + 1 - startSuggestoin);
				if (checkSuggestion(suggestoin))
					ans.append(suggestoin);
				startSuggestoin = i + 1;
			}
	}
	return !ans.empty() ? ans : "В файле нет предложений заданной длины\n";
}

string readFile(ifstream& input) {
	string s = "";
	string tmpS;
	while (getline(input, tmpS))
		s.append(tmpS).append("\n");
	return s;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string filename;
	processInputNameOfInputFile(filename);
	ifstream input(filename);
	cout << "Результат работы:\n" << task(readFile(input));
	input.close();
}