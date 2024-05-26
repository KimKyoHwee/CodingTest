#include <iostream>
#include <list>

using namespace std;
int main() {

	int num;
	string str;
	cin >> str;
	cin >> num;

	list <char> lt(str.begin(), str.end());
	auto cursor = lt.end();

	for (int i = 0; i < num; i++) {
		char temp;
		cin >> temp;

		if (temp == 'L') {
			if(cursor!=lt.begin()) cursor--;
		}
		else if (temp == 'D') {
			if(cursor!=lt.end()) cursor++;
		}
		else if (temp == 'B') {
			if (cursor != lt.begin()) cursor = lt.erase(--cursor); 
		}
		else if (temp == 'P') {
			char insertChar;
			cin >> insertChar;
			lt.insert(cursor, insertChar);
		}
	}

	for (auto i = lt.begin(); i != lt.end(); i++) {
		cout << *i;
	}

	return 0;
}