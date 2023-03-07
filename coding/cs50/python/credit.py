# TODO
def main():
    # Check if input is a string of numbers
    while True:
        card = input("Number: ")
        if card.isnumeric():
            break
        print("Input is not a number")

    # Get card number length & pass number through luhn's algorithm
    clen = len(card)
    check = luhn(card, clen)

    # Check the validity of the card
    if clen == 15 and check and card[0] == "3" and (card[1] in {"4", "7"}):
        print("AMEX")

    elif clen == 16 and check and card[0] == "5" and (card[1] in {"1", "2", "3", "4", "5"}):
        print("MASTERCARD")

    elif (clen == 13 or clen == 16) and check and card[0] == "4":
        print("VISA")

    else:
        print("INVALID")


def luhn(card, clen):
    # a counts from ones, a - 1 from tenths
    a = clen - 1
    sum = 0

    # Loop through the digits performing luhn's algo & +2 for a
    while a >= 0:
        x = int(card[a])
        y = 0 if a == 0 else int(card[a - 1]) * 2
        y = y // 10 + y % 10
        sum = sum + x + y
        a -= 2

    # Check if sum is divisible by 10 to return true
    if sum % 10 == 0:
        return True

    # If not, return false
    return False


main()