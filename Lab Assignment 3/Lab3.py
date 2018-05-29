# Sorting a list of integers
list_int = [4, 65, 2, -31, 0, 99, 2, 83, 782]
list_int.sort()
print(*list_int, "\n")

# Sorting a list of floating point values
list_float = [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26]
list_float.sort()
print(*list_float, "\n")

# Sorting a list of characters
list_char = ['z', 'y', 'a', 't', 'p', 'q', 'l', 'k']
list_char.sort()
print(*list_char, "\n")

# Sorting a list of strings
list_string = ["apple", "zebra", "turtle", "yellow", "quest", "buffalo", "elephant"]
list_string.sort()
print(*list_string, "\n")

class Person:
    def __init__ (self, name, age):
        self.name = name
        self.age = age
    def __str__(self):
        return str(self.name) + "-" + str(self.age)

def cmp(x, y):
    return (x > y) - (x < y)

def cmp_age(x, y):
    return cmp(x.age, y.age)

# Sorting a list of objects
list_object = [Person("Hal", 20), 
               Person("Susann", 31),
               Person("Dwight", 19),
               Person("Kassandra", 21), 
			   Person("Lawrence", 25),
               Person("Cindy", 22), 
               Person("Cory", 27), 
               Person("Mac", 19),
               Person("Romana", 27), 
               Person("Doretha", 32),
               Person("Danna", 20), 
               Person("Zara", 23), 
               Person("Rosalyn", 26), 
               Person("Risa", 24), 
               Person("Benny", 28),
               Person("Juan", 33), 
               Person ("Natalie", 25)]
list_object.sort(key = lambda Person: Person.name) # sort by name
# list_object.sort(key = lambda Person: Person.age) # sort by age
print(*list_object, "\n");