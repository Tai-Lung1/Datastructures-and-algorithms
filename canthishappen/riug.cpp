#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}
};

int main() {
    // Create an array of Person objects with 3 elements
    Person people[3] = {{"Alice", 25}, {"Bob", 30}, {"Charlie", 35}};

    // Loop through the array and print details of each person
    for (int i = 0; i < 3; ++i) {
        std::cout << "Person " << i + 1 << ": " << people[i].name << ", Age: " << people[i].age << std::endl;
    }

    return 0;
}
