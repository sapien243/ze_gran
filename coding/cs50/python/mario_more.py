# TODO
def main():
    # Check if input fits required conditions
    while True:
        try:
            height = int(input("Height: "))
        except ValueError:
            print("Input not an int")
            continue
        if height > 0 and height < 9:
            break
        print("Choose int from 1 to 8")

    # Print out pyramid of input height
    for i in range(height):
        line = i + 1
        side = height - line
        print(" "*side + "#"*line + "  " + "#"*line)


main()