# Guessing Game Challenge

# Let's use `while` loops to create a guessing game.

# The Challenge:

# Write a program that picks a random integer from 1 to 100, and has players guess the number. The rules are:

# 1. If a player's guess is less than 1 or greater than 100, say "OUT OF BOUNDS"
# 2. On a player's first turn, if their guess is
#  * within 10 of the number, return "WARM!"
#  * further than 10 away from the number, return "COLD!"
# 3. On all subsequent turns, if a guess is
#  * closer to the number than the previous guess return "WARMER!"
#  * farther from the number than the previous guess, return "COLDER!"
# 4. When the player's guess equals the number, tell them they've guessed correctly *and* how many guesses it took!
from random import randint, random


x = randint(1, 100)
i = 0
j = 0
print(f'x = {x}')

guesses = []

while True:
    guesses.append(int(input('Enter a number: ')))
    y = abs(guesses[-1]-x)
    # print(guesses[-1])
    if (guesses[-1] > 0 and guesses[-1] < 101):
        if (guesses[-1] == x):
            break
        else:
            if (i == 0):
                if (y <= 10):
                    print('Warm')
                elif (y > 10):
                    print('Cold')
            else:
                if (y <= abs(x-guesses[-2])):
                    print('Warmer')
                elif (y > abs(x-guesses[-2])):
                    print('Colder')
        if (i == 0 and y <= 10):
            i = i+1
        j = j+1
    else:
        print('Out of bound')

print(f'You guessed the correct number at {j+1} turn')
