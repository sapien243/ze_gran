# TODO
def main():
    # Get input from user and pass it into grade()
    text = input("Text: ")
    index = grade(text)

    # Print the right grade according to the index
    if 0 < index < 16:
        print(f"Grade {index}")
    elif index >= 16:
        print("Grade 16+")
    else:
        print("Before Grade 1")


def grade(text):
    letters = 0
    words = 1
    sentences = 0

    # Initialize variables and loop through the char in text
    for i in text:
        # Add to letters if char is alphabetical
        if i.isalpha():
            letters += 1
        # Add to words if char is a space
        elif i == ' ':
            words += 1
        # Add to sentences if char indicates end of sentence
        elif i in ['.', '?', '!']:
            sentences += 1

    # Perform Coleman-Liau index and return the value
    letters = (letters / words) * 100
    sentences = (sentences / words) * 100
    index = round(0.0588 * letters - 0.296 * sentences - 15.8)

    return index


main()