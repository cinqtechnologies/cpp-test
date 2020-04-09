#include <iostream>
#include <string>
#include <vector>

class Animal
{
public:
	/// This is the function which will be called to reproduce the sound each
	/// animal makes.
	virtual void makeSound(){}// const = 0;


	/// This is our factory. You need to code the missing implementation.
	static Animal* create(const std::string& name);

	/// This function will terminate the class instance.
	static void destroy(Animal* animal)
	{
		delete animal;
	}
};

// Write your classes here
//class NewAnimal : public Animal
class NewAnimal
{
public:
    newAnimal(){}
    newAnimal(std::string _name)
    {
        setNome(_name);
    }
    void setNome(std::string name)
    {
        _name = name;
    }
    std::string getName(){
        return _name;
    }
    virtual makeSound()
    {
        int index = 0;
        std::string buffer = getName();
        while(animals.at(index) != buffer){
            index++;
        }
        switch(index)
        {
            case 0:
                std::cout << "woof" << std::endl;
                break;
            case 1:
                std::cout << "meow" << std::endl;
                break;
            case 2:
                std::cout << "tweet" << std::endl;
                break;
            case 3:
                std::cout << "squeek" << std::endl;
                break;
            case 4:
                std::cout << "moo" << std::endl;
                break;
            case 5:
                std::cout << "croak" << std::endl;
                break;
            case 6:
                std::cout << "toot" << std::endl;
                break;
            case 7:
                std::cout << "quack" << std::endl;
                break;
            case 8:
                std::cout << "blub" << std::endl;
                break;
            case 9:
                std::cout << "ow ow ow" << std::endl;
                break;
            case 10:
                std::cout << "ylvis" << std::endl;
                break;
            default:
                break;
        }
    }
private:
    std::string _name;
    std::vector<std::string> animals = {"dog","cat","bird","mouse","cow","frog","elephant","duck","fish","seal","fox"};

};

// This is the function you need to change in order to instantiate the required
// classes.
Animal* Animal::create(const std::string& name)
{
    Animal* an = new Animal;
    return an;
}

void makeSound(const std::string& name)
{
	// Create our instance
	Animal* animal = Animal::create(name);

	animal->makeSound();

	NewAnimal* an = new NewAnimal;
	an->setNome(name);
	an->makeSound();

	// Destroy our instance
	Animal::destroy(animal);

}

int main(int argc, char** argv)
{
	int n = 0;
	std::cin >> n;

	while(n--)
	{
		std::string animal;

		std::cin.ignore();
		std::cin >> animal;

		makeSound(animal);
	}

	return 0;
}
