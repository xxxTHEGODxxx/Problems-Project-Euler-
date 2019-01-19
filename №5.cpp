/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
-------------------------------------------------------------------------------------------------------------------------------------------
2520 - самое маленькое число, которое делится без остатка на все числа от 1 до 10.

Какое самое маленькое число делится нацело на все числа от 1 до 20?
*/
#include <pch.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	bool check = false;
	int result;
	for (result = 1; check != true; result++) {
		for (int j = 1; j < 21; j++) {
			if (result % j == 0) {
				check = true;
			}
			else {
				check = false;
				break;
			}
		}
	}
	cout << result - 1;
	return 0;
}
