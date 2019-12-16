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
class Dog : public Animal{

public:

		Dog(): Animal(){

		}

		virtual void makeSound()const{
				cout << "woof" << endl;
		}

};

class Cow : public Animal{

public:

		Cow(): Animal(){

		}
		virtual void makeSound()const{
				cout << "moo" << endl;
		}

};

class Cat : public Animal{

public:

		Cat(): Animal(){

		}
		virtual void makeSound()const{
				cout << "meow" << endl;
		}

};

class Duck : public Animal{

public:

		Duck(): Animal(){

		}
		virtual void makeSound()const{
				cout << "quack" << endl;
		}

};

class Fish : public Animal{

public:

		Fish(): Animal(){

		}
		virtual void makeSound()const{
				cout << "blub" << endl;
		}

};

class Bird : public Animal{

public:

		Bird(): Animal(){

		}
		virtual void makeSound()const{
				cout << "tweet" << endl;
		}

};

class Frog : public Animal{

public:

		Frog(): Animal(){

		}
		virtual void makeSound()const{
				cout << "croak" << endl;
		}

};

// This is the function you need to change in order to instantiate the required
// classes.
Animal* Animal::create(const std::string& name)
{
	if(name == "dog")
			return new Dog();

	if(name == "cow")
			return new Cow();

	if(name == "cat")
			return new Cat();

	if(name == "duck")
			return new Duck();

	if(name == "fish")
			return new Fish();

	if(name == "bird")
			return new Bird();

	if(name == "frog")
			return new Frog();

	return NULL;
}

void makeSound(const std::string& name)
{
	// Create our instance
	Animal* animal = Animal::create(name);

	if(animal != NULL){
		animal->makeSound();

		// Destroy our instance
		Animal::destroy(animal);
	}
	else{
			cout << name << " is not an animal" << endl;
	}
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
