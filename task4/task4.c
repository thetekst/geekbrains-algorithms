#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

/*
 **Написать функции 1а и 1d - с использованием арифметики указателей.
 1.	Создать массив из 100 элементов. Написать программу, которая содержит функции для

	a.	заполнения массива случайными числами;

	b.	подсчета среднего арифметическое элементов;

	c.	нахождения номера элемента, который максимально отличается от среднего арифметического;

	d.	находит максимальное абсолютное число в массиве;

 	e.	*считывает массив из файла. Массив в файле не может быть больше 100 эл-тов

 2.	*Выполнить пункты a, b, c, d первого задания для двумерного массива
 */

#define CAPACITY 100
#define MaxFileSize 30

void printArray(int *arr, int length) {
	for (int i = 0; i < length; ++i)
	{
		printf("%d\n", arr[i]);
	}
}

int get_positive(int num) {
	if (num < 0)
	{
		num *= -1;
	}
	return num;
}

// task 1a
void fillArrayRandom(int *arr, int length, int min, int max) {
	srand(time(NULL));


	for (int i = 0; i < length; ++i)
	{
		*(arr+i) = (rand() % max + 1 - min) + min;
	}
}

// task 1b
int average(int *arr, int length) {
	int sum = 0;
	
	for (int i = 0; i < length; ++i)
	{
		sum += arr[i];
	}
	return sum / length;
}

// task 1c
int max_diff(int *arr, int length, int average) {
	int max = 0;
	int min = 0;

	// find min and max
	for (int i = 0; i < length; ++i)
	{
		if (0 == i)
		{
			max = arr[i];
			min = arr[i];
			continue;
		}

		if (max < arr[i])
		{
			max = arr[i];
		}

		if (min > arr[i])
		{
			min = arr[i];
		}
	}

	// find max diff
	if (max - average > average - min)
	{
		return max;
	}

	return min;

}

// task 1d
int max_abs(int *arr, int length) {
	int max_abs = 0;
	int positive = 0;

	for (int i = 0; i < length; ++i)
	{

		positive = *(arr+i);

		if (*(arr+i) < 0)
		{
			positive = *(arr+i) * -1;
		}

		if (max_abs < positive)
		{
			max_abs = positive;
		}
	}
	return max_abs;
}

// task 1e
void readFile(char *file_name) {
	char str[MaxFileSize];
	FILE *in;
	in=fopen(file_name,"rb");

	if (NULL != in)
	{
		int count = 0;

		while(!feof(in) && count < 100) {
			printf("%c", fgetc(in));
			count++;
		}
		printf("\n");

		fclose(in);
	}
}

// task 2a
// Что-то не работает
void fillArrayRandomTwo(int *arr) {
	// srand(time(NULL));

	// int i,k;

	// for (int i = 0; i < length_1; i++)
	// {
	// 	for (int k = 0; k < length_2; k++)
	// 	{
	// 		arr+i*length_2+k = (rand() % max + 1 - min) + min;
	// 	}
	// }
}

int main()
{
	int arr[CAPACITY];
	int arr2[10][10];

	// task 1a
	// fillArrayRandom(arr, CAPACITY, -170, 110);
	// arr[45] = -1;
	// printArray(arr, CAPACITY);

	// task 1b
	// printf("%d\n", average(arr, CAPACITY));

	// task 1c
	// printf("%d\n", max_diff(arr, CAPACITY, average(arr, CAPACITY)));

	// task 1d
	// printf("%d\n", max_abs(arr, CAPACITY));

	// task 1e
	// readFile("data.txt");

	// task 2a
	fillArrayRandomTwo(arr2);

	return 0;
}