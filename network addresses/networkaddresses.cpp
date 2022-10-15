#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
/*
class Network: Holds the net and host information for each network
*/
class Network
{
    private: 
        string net;
        string host;
    public:
        void setNet(string netInput)
        {
            net = netInput;
        }
        void setHost(string hostInput)
        {
            host = hostInput;
        }
        int getNetInt()
        {
            return stoi(net); //returns the int for net
        }
        string getNet()
        {
            return net;
        }
        string getHost()
        {
            return host;
        }
        //overloads the insertion operator, takes ostream reference and network reference
        friend ostream& operator << (ostream& output, Network &network)
        {
            output << "Network: " << network.getNet()
            << " Host: " << network.getHost() << endl; //variables inserted into output
            return output; //return output
        }
};

bool compare(Network left, Network right) //function to compare two network ip's
{
   return left.getNetInt() < right.getNetInt(); //return true or false
}
/*
class NetworkIndex
Purpose: Store all network objects in a vector
*/
class NetworkIndex 
{
    private:
        vector<Network> classA; //classA network objects stored here
        vector<Network> classB;
        vector<Network> classC;
    public:
        /*
        void insertAddress
        Purpose: decide what type of address the parameter string is
                 then split into net and host and insert into network
                 object and insert then into the vector pertaining to
                 its type.
        */
        void insertAddress(string address)
        {
            Network network; //network object
            string networkValue = address;
            string octetString;
            char delimiter = '.';
            int octetValue;
            while(1) //run continuously
            {
                if(networkValue[0] == delimiter) //if the first char is a '.'
                {
                    networkValue.erase(networkValue.begin() + 0); //delete first char
                    break;
                }
                else
                {
                    octetString = octetString + networkValue[0]; //add to octetString
                    networkValue.erase(networkValue.begin() + 0); //delete first char
                }
            }
            octetValue = stoi(octetString); //get int of octet
            if(octetValue < 128) //if class A
            {
                network.setNet(octetString); //set the net and host
                network.setHost(networkValue);
                classA.push_back(network); //add object to vector 
            }
            else if((octetValue > 127) && (octetValue < 192)) //if class B
            {
                octetString += ".";
                while(1)
                {
                    if(networkValue[0] != delimiter)
                    {
                        octetString = octetString + networkValue[0];
                        networkValue.erase(networkValue.begin() + 0);
                    }
                    else if(networkValue[0] == delimiter)
                    {
                        networkValue.erase(networkValue.begin() + 0);
                        break;
                    }
                }
                network.setNet(octetString);
                network.setHost(networkValue);
                classB.push_back(network);
            }
            else if((octetValue > 191) && (octetValue < 224)) //if class c
            {
                octetString += ".";
                int strike = 0;
                while(1)
                {
                    if(networkValue[0] != delimiter)
                    {
                        octetString = octetString + networkValue[0];
                        networkValue.erase(networkValue.begin() + 0);
                    }
                    else if(networkValue[0] == delimiter)
                    {
                        strike++;
                        if(strike == 2)//purpose to read past two decimals
                            break;
                        octetString = octetString + networkValue[0];
                        networkValue.erase(networkValue.begin() + 0);
                    }
                }
                networkValue.erase(networkValue.begin() + 0);
                network.setNet(octetString);
                network.setHost(networkValue);
                classC.push_back(network);
            }
        }
        /*
        void printStrings()
        Purpose: Sort the vectors, then print class type and size
                 Afterwards, use insertion operator overload to
                 print the values from each index in the vector
        */
        void printStrings()
        {
            sort(classA.begin(), classA.end(), &compare); //sort from beginning to end with compare
            sort(classB.begin(), classB.end(), &compare);
            sort(classC.begin(), classC.end(), &compare);
            cout << "Number of Class A Network Addresses: " << classA.size() << endl;
            for(int i = 0; i < classA.size(); i++) //iterate through each indice in vector
            {
                cout << classA[i]; //call << overload operator with network object
            }
            cout << "Number of Class B Network Addresses: " << classB.size() << endl;
            for(int i = 0; i < classB.size(); i++)
            {
                cout << classB[i];
            }
            cout << "Number of Class C Network Addresses: " << classC.size() << endl;
            for(int i = 0; i < classC.size(); i++)
            {
                cout << classC[i];
            }
        }
        /*
        friend ifstream& operator >>()
        Purpose: Take in the ifstream address to filePoint and NetworkIndex pointer
                 to object networkindex, add each line from filePoint file to
                 networkindex.insertAddress(). Return filepoint pointer.
        */
        friend ifstream& operator >> (ifstream& filePoint, NetworkIndex &networkindex)
        {
            string address;
            while(getline(filePoint, address)) //get all lines, add to address
            {
                networkindex.insertAddress(address); //pass address to the method insertAddress
            }
            return filePoint;
        }
};

int main()
{
    
    NetworkIndex networkindex; //new object of networkindex
    ifstream filePoint; //new ifstream object

    filePoint.open("filehere"); //open file
    if(filePoint.is_open()) //if the file is open
    {
        filePoint >> networkindex; //overload filePoint 
        networkindex.printStrings(); //call printstrings method
    }
    else //if file is not found
    {
        cout << "File was not found" << endl;
    }
    return 0;
}