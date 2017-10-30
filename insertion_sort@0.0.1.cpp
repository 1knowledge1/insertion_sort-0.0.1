#include <iostream>
#include <sstream>

using namespace std;

bool input(float * &elements, unsigned int num)
{
	float *tmp_elements;
	string str;

	getline(cin, str);

	tmp_elements = new float[num];

	for (string str; getline(cin, str); ) {
		std::istringstream stream(str);
		for (unsigned int j = 0; j < num; ++j) {
			if (!(stream >> tmp_elements[j])) {
				return false;
			}
		}
		break;
	}
	elements = tmp_elements;
	return true;
}

void inssort(float *elements, unsigned int num)
{
	for (int i = 1; i < num; i++)
		for (int j = i; (j>0) && (elements[j - 1] > elements[j]); j--)
			swap(elements[j - 1], elements[j]);
}

int main() {
	float *elements;
	unsigned int num;

	if (!(cin >> num))
	{
		cout << "An error has occured while reading input data.\n";
		return 0;
	}

	if (!(input(elements, num)))
	{
		cout << "An error has occured while reading input data.\n";
		return 0;
	}

	inssort(elements, num);
	for (int i = 0; i < num; i++) cout << elements[i] << ' ';

	return 0;
}
