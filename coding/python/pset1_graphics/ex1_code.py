
# Defining a class called object
class obj:
    # (1.a)
    #   An object attribute is a variable that is associated with a class.
    #   The variable attribute1 is an attribute of obj.
    attribute1 = 0

    # (2)
    #   A constructor is a method of an object that is called when the object is created.
    #   The method below is a constructor for the object obj.
    def __init__(self, initial) -> None:
        self.attribute2 = initial
        pass

    # Define a method called do_something() for (3)
    def do_something(self) -> None:
        self.attribute1 += 1


# Defining main function
def main() -> None:
    # (1.b)
    #   A local variable is a variable associated with a function or part of a program.
    #   The variable test is a local variable of the main function.
    test = obj(3)

    # (3)
    #   Calling a method follows the format 'class_variable.class_method()'.
    #   Eg. calling obj's attribute do_something()
    test.do_something()

    # Print all test attributes
    print(f"{test.attribute1}, {test.attribute2}")


# Calling main
if __name__ == "__main__":
    main()
