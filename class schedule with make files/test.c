#include <stdio.h>
#include <string.h>

char getUserInput()//declare getUserInput to return a char
{
	char userInput;
	printf("Choices: \nn - print class given number\nd - print all classes for a given day combo\np - print all classes for a given professor\nq = quit\n");
	scanf(" %c", &userInput); //scan in the user input
	printf("\n");
	return userInput;
}
