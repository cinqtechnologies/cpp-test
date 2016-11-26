/***********************************************************
Desenvolvedor: Thiago Moreira
Engenheiro Eletrônico
thiagofrosty@hotmail.com
Programa: Inheritance
Processo Seletivo CINQ
************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	/// This is the function which will be called to reproduce the sound each
	/// animal makes.
	virtual void makeSound() = 0;

	/// This is our factory. You need to code the missing implementation.
	static Animal* create(const std::string& name);

	/// This function will terminate the class instance.
	static void destroy(Animal* animal)
	{
		delete animal;
	}
};

// Write your classes here

class Fish: public Animal
{
	void makeSound()
	{
		cout << "blub" << endl;
	}

};

class Bird: public Animal
{
	void makeSound()
	{
		cout << "tweet" << endl;
	}

};

class Frog: public Animal
{
	void makeSound()
	{
		cout << "croak" << endl;
	}

};

class Dog: public Animal
{
	void makeSound()
	{
		cout << "woof" << endl;
	}

};

class Cat: public Animal
{
	void makeSound()
	{
		cout << "meow" << endl;
	}

};

class Mouse: public Animal
{
	void makeSound()
	{
		cout << "squeek" << endl;
	}

};

class Cow: public Animal
{
	void makeSound()
	{
		cout << "moo" << endl;
	}

};

class Elephant: public Animal
{
	void makeSound()
	{
		cout << "toot" << endl;
	}

};

class Duck: public Animal
{
	void makeSound()
	{
		cout << "quack" << endl;
	}

};

class Seal: public Animal
{
	void makeSound()
	{
		cout << "ow ow ow" << endl;
	}

};

// This is the function you need to change in order to instantiate the required
// classes.
Animal* Animal::create(const std::string& name)
{
	Animal* animalDaVez;

	if(name == "fish")
	animalDaVez = new Fish();
	
	else if(name == "bird")
	animalDaVez = new Bird();

	else if(name == "frog")
	animalDaVez = new Frog();

	else if(name == "dog")
	animalDaVez = new Dog();

	else if(name == "cat")
	animalDaVez = new Cat();

	else if(name == "mouse")
	animalDaVez = new Mouse();

	else if(name == "cow")
	animalDaVez = new Cow();

	else if(name == "elephant")
	animalDaVez = new Elephant();

	else if(name == "duck")
	animalDaVez = new Duck();

	else if(name == "seal")
	animalDaVez = new Seal();

	else
	cout << name << " is not an animal" << endl;

	return animalDaVez;
}


void makeSound(const std::string& name)
{
	// Create our instance
	Animal* animal = Animal::create(name);

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
