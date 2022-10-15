#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

/*
error
parameter string s
throw a runtime error with s description
*/
void error(string s)
{
    throw runtime_error(s); //throw runtime error with s description
}

/*
wordExchange()
parameter string numString
purpose: translate int number to vector of strings
then proceed to read out said number in words
*/

vector<string> wordExchange(string numString)
{
    string original = numString;
    vector<string> translated; //create a vector of strings
    int length = original.length(); //get the amount of digits
    int additive = 0; //which indice to view

    if(length == 4) //if the length of the int is four digits
    {
        switch(original[additive]) //switch statement, takes first digit and compares to 1-9 cases
        {
            case '1':
                translated.push_back("One thousand "); //push "One thousand " onto the vector
                break; //break from case
            case '2':
                translated.push_back("Two thousand "); 
                break;
            case '3':
                translated.push_back("Three thousand ");
                break;
            case '4':
                translated.push_back("Four thousand ");
                break;
            case '5':
                translated.push_back("Five thousand ");
                break;
            case '6':
                translated.push_back("Six thousand ");
                break;
            case '7':
                translated.push_back("Seven thousand ");
                break;
            case '8':
                translated.push_back("Eight thousand ");
                break;
            case '9':
                translated.push_back("Nine thousand ");
                break;
        }
        length--;
        additive++;
    }
    if(length == 3) //if length is of integer is 3 digits, or length is now 3 digits
    {
        switch(original[additive])
        {
            case '1':
                translated.push_back("One hundred ");
                break;
            case '2':
                translated.push_back("Two hundred ");
                break;
            case '3':
                translated.push_back("Three hundred ");
                break;
            case '4':
                translated.push_back("Four hundred ");
                break;
            case '5':
                translated.push_back("Five hundred ");
                break;
            case '6':
                translated.push_back("Six hundred ");
                break;
            case '7':
                translated.push_back("Seven hundred ");
                break;
            case '8':
                translated.push_back("Eight hundred ");
                break;
            case '9':
                translated.push_back("Nine hundred ");
                break;
        }
        length--;
        additive++;
    }
    if(length == 2) //if length is in the tens
    {

        if(original[additive] == '1') //for the numbers 10 through 19, do not print the same
        {
            switch(original[additive+1])
            {
                case '1':
                    translated.push_back("Eleven");
                    break;
                case '2':
                    translated.push_back("Twelve");
                    break;
                case '3':
                    translated.push_back("Thirteen");
                    break;
                case '4':
                    translated.push_back("Fourteen");
                    break;
                case '5':
                    translated.push_back("Fifteen");
                    break;
                case '6':
                    translated.push_back("Sixteen");
                    break;
                case '7':
                    translated.push_back("Seventeen");
                    break;
                case '8':
                    translated.push_back("Eighteen");
                    break;
                case '9':
                    translated.push_back("Nineteen");
                    break;
            } 
        }
        else
        {
            switch(original[additive]) //for the numbers 20-99
            {
                case '2':
                    translated.push_back("Twenty-");
                    break;
                case '3':
                    translated.push_back("Thirty-");
                    break;
                case '4':
                    translated.push_back("Forty-");
                    break;
                case '5':
                    translated.push_back("Fifty-");
                    break;
                case '6':
                    translated.push_back("Sixty-");
                    break;
                case '7':
                    translated.push_back("Seventy-");
                    break;
                case '8':
                    translated.push_back("Eighty-");
                    break;
                case '9':
                    translated.push_back("Ninety-");
                    break;
            }
            length--;
            additive++;
        }
    }
    if(length == 1)
    {
        switch(original[additive]) //if in the single digits
            {
                case '1':
                    translated.push_back("One");
                    break;
                case '2':
                    translated.push_back("Two");
                    break;
                case '3':
                    translated.push_back("Three");
                    break;
                case '4':
                    translated.push_back("Four");
                    break;
                case '5':
                    translated.push_back("Five");
                    break;
                case '6':
                    translated.push_back("Six");
                    break;
                case '7':
                    translated.push_back("Seven");
                    break;
                case '8':
                    translated.push_back("Eight");
                    break;
                case '9':
                    translated.push_back("Nine");
                    break;
            } 
    }
    return translated;
}

int main(int argc, char* argv[])
{  
    char index = '1';
    vector<string> printlist;
    if(argv[1] == NULL) //if incorrect entry or no entry
    {
        error("No integer was read");
    }
    
    else
    {
        if(argv[1][1] == index) //if second digit equals 1
        {
            error("Second digit is one"); //send error message
        }
        else //if not 1
        {
            printlist = wordExchange(argv[1]); //call wordExchange and send string of digits, set result to printlist vector
            cout << argv[1] << ": "; //print original number
            for(int i = 0; i < printlist.size(); i++)
            {
                cout << printlist[i]; //print every entry in the vector of strings
            }
        }
    }
    return 0;
}