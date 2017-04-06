#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <malloc.h>
#include <string.h>

/*
 1.	Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
 
 2.	Реализовать функцию возведения числа a в степень b:
	 a.	без рекурсии;
	 b.	рекурсивно;
 
 3.	Исполнитель Калькулятор преобразует целое число, записанное на экране. 
 	У исполнителя две команды, каждой команде присвоен номер:
	 1. Прибавь 1
	 2. Умножь на 2
 
 Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза. 
 	Сколько существует программ, которые число 3 преобразуют в число 20.
	 а) с использованием массива;
	 б) с использованием рекурсии.
 
 4.	*Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и 
 	нахождение количество маршрутов.
 
 5.	**Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по 
 	одному разу. Здесь алгоритм решения такой же как и в задаче о 8 ферзях. Разница только 
 	в проверке положения коня.

 */


// task 1
// с возвратом строки не сообразил как сделать
// получилось только с printf
int decToBin(int dec, char *arr) {

	int result = dec / 2;
	int mod = dec % 2;

	if (result > 0)
	{
		decToBin(result, arr);
		// arr[strlen(arr)] = mod;

		printf("%d", mod);
		return mod;
	}

	printf("%d", mod);
	// arr[strlen(arr)] = mod;
}

// task 2a
int my_pow(int a, int b) {

	int sum = a;
	
	for (int i = 1; i < b; ++i)
	{
		sum *= a;
	}

	return sum;
}

// task 2b
int my_pow_recursive(int a, int b) {

	if (b >= 2)
	{
		return a * my_pow_recursive(a, --b);
	}
	return a;
}

int main()
{
	char arr[255];
	// char str2[20] = "";
	decToBin(247, arr);
	printf("\n");

	// strcpy(str2,arr);
	// arr[strlen(arr)] = '\0';

	// printf("%s\n", arr);

	// printf("%d\n", my_pow(2, 6));
	// printf("%d\n", my_pow_recursive(67, 3));
	return 0;
}