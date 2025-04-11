# CPP Module 01: Memory Allocation, Pointers to Members, References, and Switch Statements

This module introduces advanced C++ concepts including dynamic memory management, pointer arithmetic, references, and control flow using switch statements. It also challenges you to use pointers to member functions in a practical scenario. The exercises in this module are:

- **Exercise 00: BraiiiiiiinnnzzzZ** – Learn the differences between stack and heap allocation by creating and managing Zombie objects.
- **Exercise 01: Moar brainz!** – Build a horde of Zombies using dynamic memory allocation in a contiguous block.
- **Exercise 02: HI THIS IS BRAIN** – Demystify pointers and references by printing memory addresses and values.
- **Exercise 03: Unnecessary violence** – Implement a scenario with Weapon and Human classes to understand composition and the different use cases of references versus pointers.
- **Exercise 04: Sed is for losers** – Perform file I/O and string manipulation without using `std::string::replace` to substitute text.
- **Exercise 05: Harl 2.0** – Use pointers to member functions to map complaint levels to function calls without if/else chains.
- **Exercise 06: Harl filter** – Filter Harl’s output messages based on the severity level using a switch statement.

*(Reference: en.subject (1).pdf citeturn2file0)*

---

## Table of Contents

- [General Concepts](#general-concepts)
- [Exercise 00: BraiiiiiiinnnzzzZ](#exercise-00-braiiiiiiinnnzzzz)
- [Exercise 01: Moar brainz!](#exercise-01-moar-brainz)
- [Exercise 02: HI THIS IS BRAIN](#exercise-02-hi-this-is-brain)
- [Exercise 03: Unnecessary violence](#exercise-03-unnecessary-violence)
- [Exercise 04: Sed is for losers](#exercise-04-sed-is-for-losers)
- [Exercise 05: Harl 2.0](#exercise-05-harl-20)
- [Exercise 06: Harl filter](#exercise-06-harl-filter)
- [Conclusion](#conclusion)

---

## General Concepts

### Memory Allocation
C++ allows you to allocate memory on the stack (automatic allocation) or on the heap (dynamic allocation).  
- **Stack Allocation:** Fast and automatically cleaned up when going out of scope.  
- **Heap Allocation:** Managed with `new` and `delete`; used when objects need to persist beyond the scope in which they were created.

### Pointers and References
- **Pointers:** Store memory addresses, can be reassigned and be null. They are essential for dynamic memory management.
- **References:** Act as aliases for existing variables and must be initialized upon declaration. They cannot be reseated.

### Switch Statements
Switch statements enable clean, multi-conditional branching especially when handling discrete cases (like log levels) and offer a concise alternative to lengthy if/else chains.

### Pointers to Member Functions
Pointers to member functions allow you to call class methods dynamically. They are particularly useful when you need to map keys (like strings indicating log levels) to function calls without multiple conditionals.

---

## Exercise 00: BraiiiiiiinnnzzzZ

### Objective
Create a `Zombie` class to demonstrate the difference between stack and heap allocation.

### Requirements
- **Zombie Class:**
  - Has a private `name` attribute.
  - Includes the member function `announce()` that prints:  
    `<name>: BraiiiiiiinnnzzzZ...`
  - The destructor must print a message with the Zombie's name for debugging.
- **Additional Functions:**
  - `Zombie* newZombie(std::string name);` – Allocates a Zombie on the heap.
  - `void randomChump(std::string name);` – Creates a Zombie on the stack and makes it announce itself.

### Code Example
**Zombie.hpp**
```cpp
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;
public:
    Zombie(std::string name);
    ~Zombie();
    void announce() const;
};

#endif
```

**Zombie.cpp**
```cpp
#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
    std::cout << name << " is born." << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " is destroyed." << std::endl;
}

void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
```

**newZombie.cpp**
```cpp
#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    return new Zombie(name); // Allocates Zombie on the heap
}
```

**randomChump.cpp**
```cpp
#include "Zombie.hpp"

void randomChump(std::string name) {
    Zombie zombie(name); // Allocated on the stack
    zombie.announce();
}
```

### Explanation
- **Heap vs. Stack:**  
  `newZombie` allows the Zombie to persist outside the function scope, whereas `randomChump` creates a temporary Zombie.
- **Destructor Message:**  
  Useful for ensuring that your memory cleanup is occurring as expected.

---

## Exercise 01: Moar brainz!

### Objective
Create a horde of Zombies by allocating an array of Zombie objects.

### Requirements
- Implement `Zombie* zombieHorde(int N, std::string name);` that allocates N Zombies in one allocation.
- Initialize each Zombie with the given name.
- Return a pointer to the first Zombie.  
- **Memory Management:** Must later deallocate the array using `delete[]`.

### Code Example
**zombieHorde.cpp**
```cpp
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return nullptr;
        
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        new (&horde[i]) Zombie(name); // Placement new to initialize each Zombie
    }
    return horde;
}
```

### Explanation
- **Array Allocation:**  
  Demonstrates how to allocate multiple objects contiguously on the heap.
- **Memory Management:**  
  Remember to use `delete[]` to deallocate the zombies once they are no longer needed to prevent memory leaks.

---

## Exercise 02: HI THIS IS BRAIN

### Objective
Explore pointers and references by printing the memory addresses and values of a string variable.

### Requirements
- Declare a string variable with `"HI THIS IS BRAIN"`.
- Create a pointer (`stringPTR`) to that string.
- Create a reference (`stringREF`) to that string.
- Print the addresses and values.

### Code Example
**main.cpp**
```cpp
#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;
    
    std::cout << "Address of brain: " << &brain << std::endl;
    std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Address held by stringREF: " << &stringREF << std::endl;
    
    std::cout << "Value of brain: " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
    
    return 0;
}
```

### Explanation
- **Pointers vs. References:**  
  Illustrates that pointers require dereferencing whereas references act like aliases.
- **Memory Addresses:**  
  Reinforces understanding of how data is stored and accessed in memory.

---

## Exercise 03: Unnecessary violence

### Objective
Design two classes, `HumanA` and `HumanB`, which use a `Weapon` object to attack.  
This exercise demonstrates the difference between storing a member as a reference or as a pointer.

### Requirements
- **Weapon Class:**
  - Private attribute `type`.
  - `getType()` returns a constant reference.
  - `setType()` updates the weapon type.
- **HumanA Class:**
  - Has a `name` and a Weapon passed as a reference (always armed).
  - Implements `attack()` that prints `<name> attacks with their <weapon type>`.
- **HumanB Class:**
  - Has a `name` and a Weapon via a pointer (weapon may be absent).
  - Implements `attack()` similarly; adds a setter for the weapon.

### Code Example

**Weapon.hpp**
```cpp
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
private:
    std::string type;
public:
    Weapon(std::string type);
    const std::string& getType() const;
    void setType(const std::string& type);
};

#endif
```

**Weapon.cpp**
```cpp
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

const std::string& Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string& type) {
    this->type = type;
}
```

**HumanA.hpp**
```cpp
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA {
private:
    std::string name;
    Weapon& weapon;
public:
    HumanA(std::string name, Weapon& weapon);
    void attack() const;
};

#endif
```

**HumanA.cpp**
```cpp
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
: name(name), weapon(weapon) {}

void HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
```

**HumanB.hpp**
```cpp
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
private:
    std::string name;
    Weapon* weapon;
public:
    HumanB(std::string name);
    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif
```

**HumanB.cpp**
```cpp
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
: name(name), weapon(nullptr) {}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}

void HumanB::attack() const {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with!" << std::endl;
}
```

### Explanation
- **Composition:**  
  Both classes use a Weapon; HumanA’s weapon is a mandatory reference (ensuring it is always armed) while HumanB’s is a pointer that may be null.
- **References vs. Pointers:**  
  Highlights when to use each depending on the required behavior.

---

## Exercise 04: Sed is for losers

### Objective
Create a program that performs text replacement in a file without using `std::string::replace`.

### Requirements
- The program takes three command-line arguments: a filename, and two strings (`s1` and `s2`).
- Open the file, and write its content into `<filename>.replace`, replacing every occurrence of `s1` with `s2`.
- Use allowed `std::string` methods and standard file I/O.

### Code Example
**main.cpp**
```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    
    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);
    std::ifstream infile(filename);
    
    if (!infile) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return 1;
    }
    
    std::stringstream buffer;
    buffer << infile.rdbuf();
    std::string content = buffer.str();
    infile.close();
    
    // Manual string replacement without using std::string::replace
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
    
    std::ofstream outfile(filename + ".replace");
    if (!outfile) {
        std::cerr << "Error: Cannot create output file." << std::endl;
        return 1;
    }
    outfile << content;
    outfile.close();
    
    std::cout << "Replacement complete. Output written to " << filename + ".replace" << std::endl;
    return 0;
}
```

### Explanation
- **File I/O:**  
  Demonstrates how to read a file into a string and write output using streams.
- **String Manipulation:**  
  Shows how to replace text manually by iterating over the string.

---

## Exercise 05: Harl 2.0

### Objective
Create a `Harl` class that maps string-based log levels to member functions using pointers to member functions.

### Requirements
- The Harl class has four private member functions: `debug()`, `info()`, `warning()`, and `error()`.
- The public function `complain(std::string level)` calls the appropriate private function based on the input string.
- Use pointers to member functions to eliminate the need for lengthy if/else chains.

### Code Example
**Harl.hpp**
```cpp
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
private:
    void debug();
    void info();
    void warning();
    void error();
public:
    void complain(std::string level);
};

#endif
```

**Harl.cpp**
```cpp
#include "Harl.hpp"

void Harl::debug() {
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!" << std::endl;
}

void Harl::warning() {
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error() {
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    typedef void (Harl::*HarlMemFn)();
    struct s_level {
        std::string level;
        HarlMemFn fn;
    };
    s_level levels[] = {
        {"DEBUG", &Harl::debug},
        {"INFO", &Harl::info},
        {"WARNING", &Harl::warning},
        {"ERROR", &Harl::error}
    };
    
    const int n = 4;
    for (int i = 0; i < n; i++) {
        if (levels[i].level == level) {
            (this->*levels[i].fn)();
            return;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
```

### Explanation
- **Pointers to Member Functions:**  
  The mapping between log level strings and the corresponding member functions simplifies the code and makes it more maintainable.
- **Scalability:**  
  This design is easily extendable if new log levels are introduced.

---

## Exercise 06: Harl filter

### Objective
Implement a filter that prints Harl’s messages based on a minimum log level using a switch statement.

### Requirements
- The program receives one command-line argument representing the starting log level.
- It prints all messages from that level and higher.
- Use a switch statement to direct the flow of output.
- If an invalid level is provided, print a default message.

### Code Example
**main.cpp**
```cpp
#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <log level>" << std::endl;
        return 1;
    }
    
    std::string level = argv[1];
    Harl harl;
    
    int index = 0;
    if (level == "DEBUG")
        index = 0;
    else if (level == "INFO")
        index = 1;
    else if (level == "WARNING")
        index = 2;
    else if (level == "ERROR")
        index = 3;
    else {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 0;
    }
    
    // Use switch statement to output messages from the given level and above.
    switch (index) {
        case 0:
            harl.complain("DEBUG");
            [[fallthrough]];
        case 1:
            harl.complain("INFO");
            [[fallthrough]];
        case 2:
            harl.complain("WARNING");
            [[fallthrough]];
        case 3:
            harl.complain("ERROR");
            break;
        default:
            break;
    }
    
    return 0;
}
```

### Explanation
- **Switch Statement with Fallthrough:**  
  The switch statement cascades from the chosen level to higher severities, printing all applicable messages.
- **Integration:**  
  This exercise demonstrates how to combine switch-case control flow with member function pointers (from Exercise 05) for a streamlined design.

---

## Conclusion

CPP_MODULE_01 has taken you deep into essential C++ topics:
- **Dynamic Memory Management:** Learn when to allocate on the heap versus the stack and how to avoid memory leaks.
- **Pointers and References:** Understand their roles and differences in real-world scenarios.
- **Pointers to Member Functions:** Use them to cleanly map operations without multiple conditionals.
- **Switch Statements:** Harness them for clear, multi-level control flow.

Studying these exercises and discussing their implementations with your peers will solidify your understanding of these advanced concepts. Keep experimenting with the code and remember to manage your memory responsibly!

Happy coding and enjoy your journey into deeper C++ mastery!

---
