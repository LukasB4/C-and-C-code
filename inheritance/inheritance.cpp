#include <iostream>

using namespace std;

class Animal
{
    protected:
        int speed;
    public:
        Animal(int s)
        {
            speed = s;
            cout << "I am an animal. " << endl;
        }

        int GetSpeed()
        {
            return speed;
        }
};

class cat : public Animal
{
    cat()
    {
        speed = 30;
        cout << "I am a cat. " << endl;
    }
};

class dog : public Animal
{
    dog()
    {
        speed = 20;
        cout << "I am a dog. " << endl;
    }
};

class giraffe : public Animal
{
    giraffe()
    {
        speed = 37;
        cout << "I am a giraffe. " << endl;
    }
}

int main()
{
    cat c;
    dog d;
    giraffe g;

    return 0;
}