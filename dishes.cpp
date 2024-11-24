#include <iostream>
#include <string>
#include <array>

using namespace std;

class Dish {
private:
    string description;

public:
    Dish(string description) {
        this->description = description;
    }

    string get_description() const {
        return this->description;
    }
};

class DishStack {
private:
    static const int MAX_SIZE = 10; 
    array<Dish*, MAX_SIZE> stackArray;  
    int currentSize;  

public:

    DishStack() : currentSize(0) {
        for (int i = 0; i < MAX_SIZE; ++i) {
            stackArray[i] = nullptr;  
        }
    }

    void push(Dish* dish) {
        if (currentSize < MAX_SIZE) {
            stackArray[currentSize] = dish;  
            currentSize++;  
        } else {
            cout << "Stack is full. Cannot push the dish onto the stack." << endl;
        }
    }

    Dish* pop() {
        if (currentSize > 0) {
            currentSize--;  
            Dish* dish = stackArray[currentSize];
            stackArray[currentSize] = nullptr;  
            return dish;
        } else {
            cout << "Stack is empty. Cannot pop from an empty stack." << endl;
            return nullptr;
        }
    }

    Dish* peek() const {
        if (currentSize > 0) {
            return stackArray[currentSize - 1]; 
        } else {
            cout << "Stack is empty. Cannot peek." << endl;
            return nullptr;  
        }
    }

  
    int size() const {
        return currentSize;
    }
};


int main() {
    DishStack stack;  

    Dish* fish_dish = new Dish("fish pattern");
    Dish* dog_dish = new Dish("dog pattern");
    Dish* cat_dish = new Dish("cat pattern");
    Dish* frog_dish = new Dish("frog pattern");
    Dish* bird_dish = new Dish("bird pattern");

    int stack_size = stack.size();
    cout << "Starting stack size: " << stack_size << endl;

    stack.push(fish_dish);
    stack.push(dog_dish);
    stack.push(cat_dish);
    stack.push(frog_dish);
    stack.push(bird_dish);

    int size_after_pushes = stack.size();
    cout << "Size after pushes: " << size_after_pushes << endl;

    Dish* peeked_dish = stack.peek();
    if (peeked_dish) {
        cout << "Peeked dish: " << peeked_dish->get_description() << endl;
    }

    Dish* popped_dish = stack.pop();
    if (popped_dish) {
        cout << "Popped dish: " << popped_dish->get_description() << endl;
        delete popped_dish;  
    }

    Dish* another_popped_dish = stack.pop();
    if (another_popped_dish) {
        cout << "Another popped dish: " << another_popped_dish->get_description() << endl;
        delete another_popped_dish; 
    }

    peeked_dish = stack.peek();
    if (peeked_dish) {
        cout << "Peeked dish: " << peeked_dish->get_description() << endl;
    }

    int final_size = stack.size();
    cout << "Final stack size: " << final_size << endl;

    while (stack.size() > 0) {
        Dish* dish = stack.pop();
        delete dish;  
    }

    return 0;
}
