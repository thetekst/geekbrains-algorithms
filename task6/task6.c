#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <malloc.h>
#include <string.h>

/*
 1.	С клавиатуры вводится строка символов:
	 a.	И вводится символ. Написать функцию, которая подсчитывает, 
	 	сколько раз символ входит в строку;
	 b.	Написать функцию, которая определяет, есть ли в строке гласные буквы;
	 c.	Написать собственную функцию аналог strlen.

 2.	*Для двух строк напишите функцию, определяющую, является ли одна строка перестановкой другой.
 
 3.	**Реализовать функцию, осуществляющую сжатие строки, на основе счётчика повторяющихся символов. 
 	Например, строка aabcccccaaa должна превратиться в a2b1c5a3. 
 	Если “сжатая” строка оказывается длиннее исходной, функция должна вернуть исходную строку.
 
 4.	*Реализовать функцию void shift(char *str), которая будет циклически сдвигать строку.
    string -> trings | gstrin
 */

#define LEN 11

// task 1c
int strLen(char* str) {
	int len = 0;

	while(*str != 0) {
		str++;
		len++;
	}
	return len;
}

// task 1a
int findChar(char* str, char ch) {
	int len = strLen(str);
	int match = 0;

	for (int i = 0; i < len; ++i)
	{
		if (str[i] == ch) match++;
	}
	
	return match;
}

// task 1b
int findVowels(char* str) {
	int len = strLen(str);
	char vowels[] = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};
	int lenVolwes = strLen(vowels);

	for (int i = 0; i < len; ++i)
	{
		for (int k = 0; k < lenVolwes; ++k)
		{
			if (str[i] == vowels[k]) {
				return 1;
			}
		}
	}

	return 0;
}

// task 2
int isMirorr(char* one, char* two) {

	int len1 = strLen(one);
	int len2 = strLen(two);

	if (len1 != len2) return 0;

	char revert[len1];
	int begin = 0;
	int end = len1 - 1;

	while(end >= 0) {

		if (one[begin] != two[end]) return 0;

		begin++;
		end--;
	}

	return 1;
}

// task 3
// попытка реализовать функцию
int compression(char* s) {
	char prev = s[0];
	int cnt = 1;
	int len = 12; 
	char* shortStr = (char*) malloc(len * sizeof(char));

	if(shortStr == NULL) {
        puts("Out of memory");
        return 1;
    }

	int i = 1;
	int relen = 0;


	while(len > i) {

		if (prev == s[i])
		{
			cnt++;
		} else {
			relen = strLen(shortStr);
			shortStr[relen] = prev;
			relen = strLen(shortStr);
			shortStr[relen] = cnt+'0';
			prev = s[i];
			cnt = 1;
		}
	
		i++;
	}

	// if (strlen(shortStr) > strlen(s)) shortStr = s;

	int cc = strLen(shortStr);

	for (int i = 0; i < cc; ++i)
	{
		printf("%c", *(shortStr+i));
	}

	printf("\n");

	free(shortStr);

	

	return 0;
}

// task 4
void shift(char *str) {
	int len = strlen(str);
	char begin = str[0];


	for (int i = 0; i < len - 1; ++i)
	{
		str[i] ^= str[i+1];
		str[i+1] ^= str[i];
		str[i] ^= str[i+1];
	}
}

int main()
{

	char str[] = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod";
	char* one = "room";
	char* two = "moor";
	char three[] = "aabcccccaaa";
	char* newStr;
	char shiftStr[] = "revert";
	int cc = 0;

	// printf("%d\n", findChar(str, 'c'));
	// printf("%d\n", findVowels(str));
	// printf("%d\n", strLen(str));
	// printf("%d\n", isMirorr(one, two));
	// compression(three);
	

	/*for (int i = 0; i < 6; ++i)
	{
		shift(shiftStr);

		cc = strlen(shiftStr);

		for (int i = 0; i < cc; ++i)
		{
			printf("%c", *(shiftStr+i));
		}
		printf("\n");
	}*/

	

	return 0;
}