class Car:
    def __init__(self, make: str, model: str, year: int):
        self.make = make
        self.model = model
        self.__year = year

    def start_engine(self):
        print("The engine is now running")

    def display_info(self):
        print("Make: ", self.make)
        print("Model: ", self.model)
        print("Year: ", self.year)

    @property
    def year(self):
        return self.__year

    @year.setter
    def year(self, value):
        if(value <= 1800):
            raise Exception("Year must be greater than 1800")

        self.__year = value
        

best_car = Car("Jeep", "Liberty", 2006)

best_car.start_engine()
best_car.display_info()

best_car.year = 1800

best_car.display_info()
