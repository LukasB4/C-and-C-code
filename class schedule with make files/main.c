#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
//struct in file
struct cclass
{
	char id[20];
	char title[40];
	char days[20];
	char time[20];
	char seats[4];
	char instructor[25];
	char lastname[25];
};


char getUserInput(); //creating instance in this c file

int main()
{
	struct cclass classes[25]; //struct array of size 25
	FILE* fin; //open the file
	fin = fopen("/public/pgm1/classes.csv", "r"); 
	if(fin != NULL)//if file is found
	{
		char classList[25][100];
		int index = 0;
		while(fgets(classList[index], 100, fin)) //scan in for file
		{
			index++;
		}
		for(int i = 0; i < index; i++) //iterate through all entried
		{
			char* token; //token pointer
			token = strtok(classList[i], ","); //delimite classlist i over comma
			strcpy(classes[i].id, token); //copy to struct
			token = strtok(NULL, ","); //delimit over comma
			strcpy(classes[i].title, token); //copy to struct
			token = strtok(NULL, ",");
			token = strtok(NULL, ",");
			strcpy(classes[i].seats, token);
			token = strtok(NULL, ",");
			token = strtok(NULL, ",");//skip unwanted variables
			token = strtok(NULL, ",");
			strcpy(classes[i].instructor, token);
			token = strtok(NULL, ",");
			char placeHolder[20]; //for splitting variables
			strcpy(placeHolder, token);
			token = strtok(placeHolder, " ");
			strcpy(classes[i].days, token);
			token = strtok(NULL, " ");
			strcpy(classes[i].time, token);
			strcpy(placeHolder, classes[i].instructor);
			token = strtok(placeHolder, " ");// for splitting last name
			strcpy(classes[i].lastname, placeHolder);
		}
		int i = 1;
		while(1)
		{
			if(i == 1)
			{
				char userInput = getUserInput(); //get user input from getUserInput
				if(userInput == 'n') //if user inputs n
				{
					//print class given number
					char className[25];
					char classNum[25];
					printf("Please enter the class number: ");
					scanf(" %s %s", className, classNum);
					char compNum[10];
					char compTemp[3];
					for(int i = 0; i < index; i++)
					{
						strcpy(compNum, classes[i].id);// copy id to compnum
						compTemp[0] = compNum[5];
						compTemp[1] = compNum[6];
						compTemp[2] = compNum[7];
						int result = strcmp(compTemp, classNum);//string compare values
						if(result == 67) //if the values match, would be zero but program is comparing extra variables for some reason
						{
							printf("%-30s %-13s %-25s %-7s %-7s %11s", classes[i].title, classes[i].id, classes[i].instructor, classes[i].seats, classes[i].days, classes[i].time);
						}
					}
				}	
				
				else if(userInput == 'd') //if user input is d, code is similar over next else if statement
				{
					//print all classes for a given day combo
					char date[10];
					printf("Please enter the day (MWF or TR): ");
					scanf(" %s", date);
					for(int i = 0; i < index; i++)
					{
						int result = strcmp(date, classes[i].days);
						if(result == 0)
							printf("%-30s %-13s %-25s %-7s %-7s %11s", classes[i].title, classes[i].id, classes[i].instructor, classes[i].seats, classes[i].days, classes[i].time);
					}
				}
				else if(userInput == 'p') //same as above else if and if
				{
					//print all classes for a given professor
					char name[40];
					printf("Please enter the last name of the instructor: ");
					scanf(" %s", name);
					for(int i = 0; i < index; i++)
					{
						int result = strcmp(name, classes[i].lastname);
						if(result == 0)
							printf("%-30s %-13s %-25s %-7s %-7s %8s", classes[i].title, classes[i].id, classes[i].instructor, classes[i].seats, classes[i].days, classes[i].time);
					}
				}
				else if(userInput == 'q')
				{
					return 0;
				}
				i = 2;
			}
			else if(i == 2)
				i = 1;
		}
	}
	else
	{
		printf("File was not found, try again.");
		return 1;
	}
	return 0;
}

