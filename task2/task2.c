#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
1. Ввести a и b и вывести квадраты и кубы чисел от a до b.

2. Даны целые положительные числа N и K. Используя только операции 
сложения и вычитания, найти частное от деления нацело N на K, 
а также остаток от этого деления.

3. Дано целое число N (> 0). С помощью операций деления нацело и 
взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры. 
Если имеются, то вывести True, если нет — вывести False.

4. С клавиатуры вводятся числа, пока не будет введен 0. 
Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.

5. Написать функцию нахождения максимального из трех чисел.

6. * Написать функцию, генерирующую случайное число от 1 до 100.

	а) с использованием стандартной функции rand()

	б) без использования стандартной функции rand()*/

void ex_1(int a, int b) {
	for (int i = a; i <= b; ++i)
	{
		printf("%d^2 = %d; %d^3 = %d \n", i, i*i, i, i*i*i);
	}
}

/*int ex_3(int num) {
	int prev = -1;
	int mod = 1;
	int current = 0;

	
	do {

		

		mod = mod * 10;
		printf("mod %d\n", mod);
		current = (num % mod);
		printf("%d\n", current);

		

		if (current % 2 == 1)
		{
			printf("%d\n", current);
			break;
		}

		if(prev > 0 && prev == current) {
			printf("%s\n", "find");
			break;
		}

		prev = current;
	} while(1);
}*/

void ex_4() {
	int array[] = {67,2,678,27,14,8,38,28};

	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
	{
		if (array[i] > 0 && (array[i] % 2) == 0 && (array[i] % 10) == 8)
		{
			printf("%d\n", array[i]);
		}
	}
}

int ex_5(int one, int two, int three) {
	int one_or_two = one > two ? one : two;
	int two_or_three = two > three ? two : three;

	return one_or_two > two_or_three ? one_or_two : two_or_three;
}

int ex_6a(int min, int max) {
	srand(time(NULL)); //нужно для того, чтобы генерировать не одно и тоже число
	return rand() % (max - min + 1) + min;
}

int main()
{
	// ex_1(4, 8);
	// printf("max: %d\n",ex_5(5, 32, 99));
	// printf("random: %d\n", ex_6a(5, 21));
	// ex_4();
	// printf("%s\n", ex_3(386));

	return 0;
}