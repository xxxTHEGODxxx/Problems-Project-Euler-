/*
Число-палиндром с обеих сторон (справа налево и слева направо) читается одинаково. 
Самое большое число-палиндром, полученное умножением двух двузначных чисел – 9009 = 91 × 99.

Найдите самый большой палиндром, полученный умножением двух трехзначных чисел.
*/
#include <pch.h>
#include <iostream>
#include <string>

using namespace std;

bool palindrom(int first, int second);

int main()
{
	int result = 0;
	bool check;
	for (int first = 999; first > 99; first--) { // Перебирает все результаты умножений чисел от 100 до 999 и ищет наибольший палиндром.
		for (int second = 999; second > 99; second--) {
			if (first * second > result) { // Без этой проверки программа работала бы долго (секунд 20?!). Оптимизация кода :)
				check = palindrom(first, second);
			}
      
			if (check == true && result < first * second) {
				result = first * second;
			}
			check = false;
		}
	}

	cout << result;
	return 0;
}
bool palindrom(int first, int second) { // Проверка: является ли число палиндромом?
	int multiplication = first * second;
	int amount = 0;
	for (int i = 1; i < multiplication; i = i * 10) { // делает amount = из скольки чисел состоит число
		amount++;
	}
	string firstCheck;
	string secondCheck;
	string multiply = to_string(multiplication);
	int j = amount - 1;
	for (int i = 0; i < amount / 2; i++) {
		firstCheck += multiply[i];
		secondCheck += multiply[j];
		j--;
	}
	if (firstCheck == secondCheck) { // Если число - палиндром, return true;
		return true;
	}
	else {
		return false;
	}
}
