#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int intCheck(int integer) {
	while (cin.fail() || integer < 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка, вы должны ввести целое неотрицательное число." << endl << "Введите ещё раз: " << endl;
		cin >> integer;
	}
	return integer;
}

int main()
{
	setlocale(LC_ALL, "RU");
	int items, value;
	cout << "Введите количество вещей: " << endl;
	cin >> items;
	items = intCheck(items);

	vector<int> weight;

	for (int i = 0; i < items; i++) {
		cout << "Введите вес " << i + 1 << " вещи" << endl;
		cin >> value;
		value = intCheck(value);
		weight.push_back(value);
	}
	sort(weight.begin(), weight.end());

	int firstBag = 0, secondBag = 0;

	for (int i = weight.size() - 1; i >= 0; i--) {
		if (firstBag > secondBag || firstBag == secondBag) {
			secondBag += weight[i];
		}
		else {
			firstBag += weight[i];
		}
	}
	cout << "Вес первого рюкзака: " << firstBag << endl << "Вес второго рюкзака: " << secondBag;
	return 0;

}
