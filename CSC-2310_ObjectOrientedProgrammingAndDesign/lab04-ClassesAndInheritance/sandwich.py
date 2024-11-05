"""
Author: Matthew Love
Date: 2024-10-22, Tue
Purpose: Practice creating classes in python
"""

class Sandwich:
    def __init__(self, order_number: int, bread_type: str, meat_type: str):
        self._order_number = order_number
        self._bread_type = bread_type
        self._meat_type = meat_type
        self._toppings = []
    
    @property
    def order_number(self):
        return self._order_number

    @property
    def bread_type(self):
        return self._bread_type

    @bread_type.setter
    def bread_type(self, value):
        self._bread_type = value

    @property
    def meat_type(self):
        return self._meat_type

    @meat_type.setter
    def meat_type(self, value):
        self._meat_type = value

    def add_topping(self, topping):
        self._toppings.append(topping)

    def remove_topping(self, topping):
        if(topping not in self._toppings):
            # Could raise exception, but do nothing if you try to remove topping that does not exist
            return
        self._toppings.remove(topping)

    @property
    def price(self):
        return (3.75 + (0.50 * len(self._toppings)))

    def info(self):
        print(
            "--- Sandwich Details ---\n",
            "Order number:", self._order_number, "\n",
            "Bread type:", self._bread_type, "\n",
            "Meat type:", self._meat_type, "\n",
            "Toppings:", self._toppings, "\n",
            "Price:", (3.75 + (0.50 * len(self._toppings))), "\n",
        )
    
class Meal(Sandwich):
    def __init__(self, order_number: int, bread_type: str, meat_type: str, drink: str, side: str):
        super().__init__(order_number, bread_type, meat_type)
        self._drink = drink
        self._side = side

    @property
    def drink(self):
        return self._drink

    @drink.setter
    def drink(self, value):
        self._drink = value

    @property
    def side(self):
        return self._side

    @side.setter
    def side(self, value):
        self._side = value

    @property
    def price(self):
        return (6.75 + (0.50 * len(self._toppings)))

    def info(self):
        print(
            "--- Meal Details ---\n",
            "Order number:", self._order_number, "\n",
            "Bread type:", self._bread_type, "\n",
            "Meat type:", self._meat_type, "\n",
            "Toppings:", self._toppings, "\n",
            "Drink:", self._drink, "\n",
            "Side:", self._side, "\n",
            "Price:", (3.75 + (0.50 * len(self._toppings))), "\n",
        )

class KidsMeal(Meal):
    def __init__(self, order_number: int, bread_type: str, meat_type: str, drink: str, side: str, toy: str):
        super().__init__(order_number, bread_type, meat_type, drink, side)
        self._toy = toy

    @property
    def toy(self):
        return self._toy

    @toy.setter
    def toy(self, value):
        self._toy = value

    @property
    def price(self):
        return (4.75 + (0.30 * len(self._toppings)))

    def info(self):
        print(
            "--- Meal Details ---\n",
            "Order number:", self._order_number, "\n",
            "Bread type:", self._bread_type, "\n",
            "Meat type:", self._meat_type, "\n",
            "Toppings:", self._toppings, "\n",
            "Drink:", self._drink, "\n",
            "Side:", self._side, "\n",
            "Toy:", self._toy, "\n",
            "Price:", (3.75 + (0.50 * len(self._toppings))), "\n",
        )


cool_sandwich = Sandwich(9348392, "Wheat", "Ham")
cool_meal = Meal(284323, "White", "Bacon", "Sprite Cranberry", "Ice Cream and Apple Pie")
cool_kids_meal = KidsMeal(3984294, "Plastic", "Dirt", "Mud", "Mushroom", "AK-47")

cool_sandwich.info()
cool_meal.info()
cool_kids_meal.info()