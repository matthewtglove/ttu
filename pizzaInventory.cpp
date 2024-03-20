/*
    Title: pizzaInventory.cpp
    Author: Matthew Love
    Date: 2024-03-15, Fri
    Purpose: A pizza inventory system
*/

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Toppings {
    enum Topping { PEPPERONI,
                   SAUSAGE,
                   OLIVES };
};

class Pizza {
private:
    string sauce;
    string cheese;
    Toppings::Topping topping;
    float price;
    bool isCheeseCrust;

public:
    Pizza() {
        sauce = "marinara";
        cheese = "mozzarella";
        topping = Toppings::PEPPERONI;
        price = 9.99;
        isCheeseCrust = false;
    }

    Pizza(string sauce, string cheese, Toppings::Topping topping, float price, bool isCheeseCrust) {
        this->sauce = sauce;
        this->cheese = cheese;
        this->topping = topping;
        this->price = price;
        this->isCheeseCrust = isCheeseCrust;
    }

    void print() {
        cout << "Sauce: " << sauce << endl;
        cout << "Cheese: " << cheese << endl;
        cout << "Topping: ";
        switch (topping) {
        case Toppings::PEPPERONI:
            cout << "Pepperoni";
            break;
        case Toppings::SAUSAGE:
            cout << "Sausage";
            break;
        case Toppings::OLIVES:
            cout << "Olives";
            break;
        }
        cout << endl;
        cout << "Price: $" << fixed << setprecision(2) << price << endl;
        cout << "Cheese Crust: " << (isCheeseCrust ? "Yes" : "No") << endl;
    }
};

int main() {
    Pizza p1;
    p1.print();
    cout << endl;

    Pizza p2("alfredo", "parmesan", Toppings::SAUSAGE, 12.99, true);
    p2.print();
    cout << endl;

    // Additional tests
    Pizza p3("marinara", "mozzarella", Toppings::OLIVES, 10.99, false);
    p3.print();
    cout << endl;

    Pizza p4("marinara", "cheddar", Toppings::PEPPERONI, 11.99, true);
    p4.print();
    cout << endl;

    return 0;
}