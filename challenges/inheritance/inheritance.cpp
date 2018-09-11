#include <functional>
#include <iostream>
#include <map>
#include <string>

class Animal {
public:
  virtual ~Animal() {}

  /// This is the function which will be called to reproduce the sound each
  /// animal makes.
  virtual void makeSound() const = 0;

  /// This is our factory. You need to code the missing implementation.
  static Animal *create(const std::string &name);

  /// This function will terminate the class instance.
  static void destroy(Animal *animal) { delete animal; }
};

// Write your classes here

class Dog : public Animal {
  void makeSound() const override { std::cout << "woof" << std::endl; }
};

class Cat : public Animal {
  void makeSound() const override { std::cout << "meow" << std::endl; }
};

class Bird : public Animal {
  void makeSound() const override { std::cout << "tweet" << std::endl; }
};

class Mouse : public Animal {
  void makeSound() const override { std::cout << "squeek" << std::endl; }
};

class Cow : public Animal {
  void makeSound() const override { std::cout << "moo" << std::endl; }
};

class Frog : public Animal {
  void makeSound() const override { std::cout << "croak" << std::endl; }
};

class Elephant : public Animal {
  void makeSound() const override { std::cout << "toot" << std::endl; }
};

class Duck : public Animal {
  void makeSound() const override { std::cout << "quack" << std::endl; }
};

class Fish : public Animal {
  void makeSound() const override { std::cout << "blub" << std::endl; }
};

class Seal : public Animal {
  void makeSound() const override { std::cout << "ow ow ow" << std::endl; }
};

class Mute : public Animal {
public:
  Mute(const std::string &name) : _name{name} {}

private:
  std::string _name;
  void makeSound() const override {
    std::cout << _name << " is not an animal" << std::endl;
  }
};

// This is the function you need to change in order to instantiate the required
// classes.
Animal *Animal::create(const std::string &name) {
  const std::map<std::string, std::function<Animal *()>> m = {
      {"dog", []() { return new Dog(); }},
      {"cat", []() { return new Cat(); }},
      {"bird", []() { return new Bird(); }},
      {"mouse", []() { return new Mouse(); }},
      {"cow", []() { return new Cow(); }},
      {"frog", []() { return new Frog(); }},
      {"elephant", []() { return new Elephant(); }},
      {"duck", []() { return new Duck(); }},
      {"fish", []() { return new Fish(); }},
      {"seal", []() { return new Seal(); }}};
  const auto f = m.find(name);
  return ((f != m.end()) ? f->second() : new Mute(name));
}

void makeSound(const std::string &name) {
  // Create our instance
  Animal *animal = Animal::create(name);

  animal->makeSound();

  // Destroy our instance
  Animal::destroy(animal);
}

int main(int argc, char **argv) {
  int n = 0;
  std::cin >> n;

  while (n--) {
    std::string animal;

    std::cin.ignore();
    std::cin >> animal;

    makeSound(animal);
  }

  return 0;
}
