#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	/// This is the function which will be called to reproduce the sound each
	/// animal makes.
	virtual void makeSound() const = 0;

	/// This is our factory. You need to code the missing implementation.
	static Animal* create(const std::string& name);

	/// This function will terminate the class instance.
	static void destroy(Animal* animal)
	{
		delete animal;
	}
};

// Write your classes here

class Bird: public Animal
{
    void makeSound() const{
        cout << "tweet\n";
    }
};

class Cat: public Animal
{
    void makeSound() const{
        cout << "meow\n";
    }
};

class Cow: public Animal
{
    void makeSound() const{
        cout << "moo\n";
    }
};

class Dog: public Animal
{
    void makeSound() const{
        cout << "woof\n";
    }
};

class Duck: public Animal
{
    void makeSound() const{
        cout << "quack\n";
    }
};

class Elephant: public Animal
{
    void makeSound() const{
        cout << "toot\n";
    }
};

class Fish: public Animal
{
    void makeSound() const{
        cout << "blub\n";
    }
};

class Frog: public Animal
{
    void makeSound() const{
        cout << "croak\n";
    }
};

class Mouse: public Animal
{
    void makeSound() const{
        cout << "squeek\n";
    }
};

class Seal: public Animal
{
    void makeSound() const{
        cout << "ow ow ow\n";
    }
};

// This is the function you need to change in order to instantiate the required
// classes.
Animal* Animal::create(const std::string& name)
{

    Animal* animal;

    if (name.compare("bird") == 0){
        animal = new Bird();
    } else if (name.compare("cat") == 0){
        animal = new Cat();
    } else if (name.compare("cow") == 0){
        animal = new Cow();
    } else if (name.compare("dog") == 0){
        animal = new Dog();
    } else if (name.compare("duck") == 0){
        animal = new Duck();
    } else if (name.compare("elephant") == 0){
        animal = new Elephant();
    } else if (name.compare("fish") == 0){
        animal = new Fish();
    } else if (name.compare("frog") == 0){
        animal = new Frog();
    } else if (name.compare("mouse") == 0){
        animal = new Mouse();
    } else if (name.compare("seal") == 0){
        animal = new Seal();
    } else
        return NULL;

	return animal;
}

void makeSound(const std::string& name)
{
	// Create our instance
	Animal* animal = Animal::create(name);

	if (animal == NULL)
        cout << name << " is not an animal\n";
	else
        animal->makeSound();

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
