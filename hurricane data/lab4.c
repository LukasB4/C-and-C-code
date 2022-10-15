#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
/*
 * fileCheck
 * check if there is a file
 * takes pointer to fin pointer
 * file found return true, otherwise false
 */
bool fileCheck(FILE** fin)
{
	if( *fin != NULL)//if the pointer to file in is not NULL
		return true;

	return false;
}
/*
 * sortNprint
 * param: stringset[][100], int s
 * purpose: sort the array given store it into pointer array
 * then print out from pointer array
 * return: none
 */
void sortNprint(char stringset[][100], int s)
{
	int MAX_STRINGS = 150;//maximum number of indices
	int size = s;
	char** strArr; //pointer to pointer array
	char string[100];
        strArr = malloc( MAX_STRINGS * sizeof(char*)); //allocate memory for 150 char pointers
        for(int i = 0; i < MAX_STRINGS; i++)//allocate individual string pointer memory
        {
                // String can be up to 101 characters plus a terminating NULL
		strArr[i] = malloc( (101) *sizeof(char));
        }
	int arrPlace = 0;
	while(size > 0)
	{
		strcpy(string, stringset[0]); //copy string from first indice
		int index = 0;
		for(int i = 1; i <= size; i++) //iterate through array
		{
			if(strncmp(string, stringset[i], 4) > 0)//if string is before current indice.
			{
				strcpy(string, stringset[i]); //copy if it is
				index = i;//set indice to location of string
			}
		}
		if(arrPlace == 0)
			arrPlace += 1;
		else
		{
			if(arrPlace == 1)
				arrPlace = 0;
			char* token;//make token pointer
			token = strtok(string, ","); //token is equal first entry in string
			strcpy(strArr[arrPlace++], token); //strArr at arrPlace is equal to token
			token = strtok(NULL, ","); //token is next entry in string
                        strcpy(strArr[arrPlace++], token);
			token = strtok(NULL, ",");
                        strcpy(strArr[arrPlace++], token);
			token = strtok(NULL, ",");
                        strcpy(strArr[arrPlace++], token);
		}
		strcpy(stringset[index], stringset[size]); //replace largest with end of the array
		if(size == 1) // if on final element
		{
			//all same as above with stringset[0] as source instead
			char* token;
			token = strtok(stringset[0], ",");
                        strcpy(strArr[arrPlace++], token);
                        token = strtok(NULL, ",");
                        strcpy(strArr[arrPlace++], token);
                        token = strtok(NULL, ",");
                        strcpy(strArr[arrPlace++], token);
                        token = strtok(NULL, ",");
                        strcpy(strArr[arrPlace++], token);
		}
		size--;//subtract from size
	}
	int p = 0;
	printf("Hurricanes in Florida with category and date\n");
	printf("--------------------------------------------\n");
	while(p < (arrPlace)) //iterate through p
	{
		printf("%-10s %-3c %-6s %s", strArr[p], strArr[p+1][9], strArr[p+2], strArr[p+3]);
		p += 4;
	}
	
        // Must free each of the allocated strings.
        for(int i = 0; i < MAX_STRINGS; i++)
        {
                free( strArr[i] );
        }

        // Must free the array as well
        free(strArr);
	return;
}

int main()
{
	FILE* fin; //declare file pointer
	fin = fopen("/public/lab4/hurricanes.csv", "r"); //open file to fin

	if(!fileCheck(&fin)) //send address of fin to fileCheck, if false
	{
		printf("Error: File was not found\n");
		return 1;
	} 
	else //if true 
	{
		char inputList[100][100]; //declare the array of 100x100
		int index = 0;//for recording size
		while(fgets(inputList[index], 100, fin)) //get every value from file and assign
		{
			index++;//add to index
		}
        	sortNprint(inputList, index); //send array and index size
	}
	return 0;
}
