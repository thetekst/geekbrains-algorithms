#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

/*
 1.	Попробовать оптимизировать пузырьковую сортировку. 
 Описать в комментариях к программе что дают эти улучшения. 
 Сравнить количество операций сравнения оптимизированной и не 
 оптимизированной программы.

 2.	Реализовать шейкерную сортировку.

 3.	Реализовать бинарный алгоритм поиска в виде функции, которой 
 передается отсортированный массив. Функция возвращает индекс 
 найденного элемента или -1, если элемент не найден.

 4.	*Подсчитать количество операций для каждой из сортировок.

 */

#define LEN 11

void printArray(int *arr, int length) {
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int *a, int *b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

// task 2, 4
void cocktail_sort(int *arr, int length, int verbose) {
	int counter = 0;
	int left = 0;
	int right = length -1;

	while(left <= right) {
		for (int i = left; i < right; i++) {
			if(arr[i] > arr[i+1]) {
				arr[i] ^= arr[i+1];
                arr[i+1] ^= arr[i];
                arr[i] ^= arr[i+1];
				// swap(&arr[i], &arr[i+1]);
				counter++;
			}
		}
		right--;

		for (int i = right; i > left; i--) {
			if(arr[i] < arr[i-1]) {
				arr[i] ^= arr[i-1];
                arr[i-1] ^= arr[i];
                arr[i] ^= arr[i-1];
				// swap(&arr[i], &arr[i+1]);
				counter++;
			}
		}
		left++;
	}
	if(1 == verbose) printf("counter: %d\n", counter);
}

// task 3, 4
int binary_search(int *arr, int length, int value, int verbose) {
	int counter = 0;
	int L = 0, R = length - 1;
	int m = L + ((R - L)/2);
	
	while (L <= R && arr[m]!= value){
		counter++;

	    if(arr[m] < value)
	        L = m + 1;
	    else
	        R = m - 1;
	    m = L + ((R - L)/2);

	    
	}

	if(1 == verbose) printf("counter: %d\n", counter);

	if (arr[m] == value)
    	return m;

    return -1;
}



int main()
{
	int unsort_arr[] = {45, 43, 2, 0, 56, 34, 23, 645, 23, 3, 4};
	int sort_arr[] = {1, 4, 20, 39, 45, 54, 56, 67, 94, 100, 105};
	int value = 105;

	// printf("%d\n", binary_search(sort_arr, LEN, value, 1));
	// cocktail_sort(unsort_arr, LEN, 1);
	// printArray(unsort_arr, LEN);

	return 0;
}