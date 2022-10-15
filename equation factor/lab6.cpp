#include <iostream>
#include <vector>
#include <string>

using namespace std;

class term //class for holding the term
{
    private:
        string numerator;
        int xplace;
        int exp;
        int numer;
        string exponent;
        string variable;

    public:
        term(string t) //constructor sets values and variable from string
        {
            variable = t;
            numer = 1;
            exp = 1;
        }
        void replaceTerm(string j) //if term is combined replace it
        {
            variable = j;
            setValues(); //set the values
        }
        string getString() //get the variable string
        {
            return variable;
        }
        void setValues() //to set the values of exponent, numerator, and where x is placed
        {
            xplace = 0; //x starts non existant
            if(variable.size() == 3) //if the variable is 3 characters
            {
                numerator = variable[0]; 
                numer = stoi(numerator); //convert numerator to int numer
                xplace = 1; //x is at the middle of the three numbers
                exponent = variable[2];
                exp = stoi(exponent); //convert exponent to int exp
            }
            else if(variable.size() == 2)
            {
                if(variable[1] == 'x') //if the last char is x
                {
                    numerator = variable[0];
                    numer = stoi(numerator);
                    xplace = 2; //last char is x
                }
                else //if the first char is x
                {
                    numerator = "1"; //set numerator to one
                    xplace = 1; //x is first variable
                    exponent = variable[1];
                    exp = stoi(exponent);
                }
            }
            else //if variable is one long
            {
                if(variable[0] == 'x') //first variable is zero
                {
                    xplace = 2; //x is last char
                }
                else
                {
                    xplace = 0; //no x value
                    numerator = variable[0];
                    numer = stoi(numerator);
                    exp = 0; //no exponent for sorting
                }
            }
        }
        int size()
        {
            return variable.size();
        }
        int getXplace()
        {
            return xplace;
        }
        string getNumerator()
        {
            return numerator;
        }
        string getExponent()
        {
            return exponent;
        }
        int getNumer()
        {
            return numer;
        }
        int getExp()
        {
            return exp;
        }
        void printTerm() //printing the variable
        {
            cout << variable;
        }
};
bool compare(term& left, term& right) //compares the two terms sent from sort
{
   return left.getExp() > right.getExp(); //returns which is larger
}
class equation //holds the equation
{
    private:
        vector<term> terms; //for vector of terms
    public:
        void insertVariable(term variable) //insert the variable given
        {
            bool inserted = false; //not yet inserted
            for(int i = 0; i < terms.size(); i++) //iterate through terms vector
            {
                if(terms[i].getExp() == variable.getExp()) // if the variable and term indice have same exponent
                {
                    int total = terms[i].getNumer() + variable.getNumer(); //add numerators
                    if(terms[i].getXplace() == 2) //if x is last
                        terms[i].replaceTerm(to_string(total) + "x"); //replace the term with total plus x
                    else if(terms[i].getXplace() == 1) //if x is middle term
                        terms[i].replaceTerm(to_string(total) + "x" + terms[i].getExponent());
                    else if(terms[i].getXplace() == 0) //if no x
                        terms[i].replaceTerm(to_string(total));
                    inserted = true; //change inserted to true
                }
                if(inserted == true)
                    break;
            }
            if(inserted == false) //if no like term add variable to vector
                terms.push_back(variable);
        }
        void sortEquation() //to sort the equation by exponent
        {
            sort(terms.begin(), terms.end(), &compare); //sort from beginning to end of terms with compare function
        }
        void printEquation() //iterate through equation and print terms from term class
        {
            sortEquation(); //sort
            for(int i = 0; i < terms.size(); i++)
            {
                terms[i].printTerm();
                if(i != terms.size()-1) //no plus at end space
                    cout << " + ";
            }
            cout << endl;
        }
};

int main()
{
    string equat;
    vector<term> hold; //vector of terms
    cout << "Enter your equation: " << endl;
    getline(cin, equat); //copy in the line
    string variable = ""; //to add to
    equation e; //new instance of equation
    
    for(int i = 0; i < equat.size(); i++) //iterate through vector
    {
        if(!isspace(equat[i])) //if equat index has a space
            variable = variable + equat[i]; //if not add it to variable
        else //if is a space add variable to new instance of term then add to vector hold, add 2 to index i, reset variable
        {
            term initial(variable);
            initial.setValues();
            hold.push_back(initial);
            variable = "";
            i += 2;
        }
        if(i+1 == equat.size()) //if the final entry do same as above
        {
            term initial(variable);
            initial.setValues();
            hold.push_back(initial);
            variable = "";
        }
    }

    for(int i = 0; i < hold.size(); i++) //to insert all variables from hold to e
    {
        e.insertVariable(hold[i]);
    }
    e.printEquation(); //print the equation
}