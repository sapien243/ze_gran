def main():
    express = input("Expression: ")
    express = express.strip().split(' ', 3)

    x = float(express[0])
    z = float(express[2])

    if express[1] == "+":
        print(x + z)
    elif express[1] == "-":
        print(x - z)
    elif express[1] == "/":
        print(x / z)
    elif express[1] == "*":
        print(x * z)
    else:
        print("Incorrect format.")


main()
