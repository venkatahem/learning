class Dog():
    species = 'Mammals'

    def __init__(self, name, breed, spots):
        self.name = name
        self.breed = breed
        self.spots = spots

    def bark(self, user):
        print(f'{self.name} says WOOF! to {user}')


# my_dog = Dog(name='Tom', breed='Lab', spots=False)

my_dog = Dog('Tommy', 'Lab', 'No spots')

my_dog.bark('Naruto')

# print(type(my_dog))

# print(my_dog.breed, my_dog.name, my_dog.spots)
