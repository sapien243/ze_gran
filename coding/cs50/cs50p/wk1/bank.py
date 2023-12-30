def main():
    greet = input("Greeting: ")
    greet = greet.lower().strip()

    if (greet[0] == "h") and (first(greet) == "hello"):
        print("$0")
    elif (greet[0] == "h"):
        print("$20")
    else:
        print("$100")


def first(sentence):
    word = ''
    for char in sentence:
        if (char == ' ') or (char == '?') or (char == ',') or (char == '!'):
            break
        else:
            word = word + char

    return word


main()
