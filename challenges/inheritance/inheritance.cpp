/* @Author: Carlos Eduardo L. de S. Grell Silva
for Cinq Technologies' hiring test */

#include <iostream>
#include <string>
using namespace std;

class Animal
{
	string sound;
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
class Dog : public  Animal
{
public:
	void makeSound() const
    {
        cout << "woof" << endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() const
    {
        cout << "meow" << endl;
    }
};

class Bird : public  Animal
{
public:
	void makeSound() const
    {
        cout << "tweet" << endl;
    }
};

class Mouse : public  Animal
{
public:
	void makeSound() const
    {
        cout << "squeek" << endl;
    }
};

class Cow : public  Animal
{
public:
	void makeSound() const
    {
        cout << "moo" << endl;
    }
};

class Frog : public  Animal
{
public:
	void makeSound() const
    {
        cout << "croak" << endl;
    }
};

class Elephant : public  Animal
{
public:
	void makeSound() const
    {
        cout << "toot" << endl;
    }
};

class Duck : public  Animal
{
public:
	void makeSound() const
    {
        cout << "quack" << endl;
    }
};

class Fish : public  Animal
{
public:
	void makeSound() const
    {
        cout << "blub" << endl;
    }
};

class Seal : public  Animal
{
public:
	void makeSound() const
    {
        cout << "ow ow ow" << endl;
    }
};

class NotAnAnimal : public  Animal
{
private:
    std::string name;
public:
    NotAnAnimal(std::string name)
    {
        this->name = name;
    }
	void makeSound() const
    {
        cout << name << " is not an animal" << endl;
    }
};

// This is the function you need to change in order to instantiate the required
// classes.
Animal* Animal::create(const std::string& name)
{
	Animal* newobj;
	if      (name == "dog")			 newobj = new Dog();
	else if (name == "cat") 		 newobj = new Cat();
	else if (name == "bird")		 newobj = new Bird();
	else if (name == "mouse")	   newobj = new Mouse();
	else if (name == "cow") 		 newobj = new Cow();
	else if (name == "frog")     newobj = new Frog();
	else if (name == "elephant") newobj = new Elephant();
	else if (name == "duck")		 newobj = new Duck();
	else if (name == "fish") 		 newobj = new Fish();
	else if (name == "seal") 		 newobj = new Seal();
  else											   newobj = new NotAnAnimal(name);
	return newobj;
}

void makeSound(const std::string& name)
{
	// Create our instance
	Animal* animal = Animal::create(name);
  if(animal) animal->makeSound();

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
