def main():
    sentence = input("->")
    print(convert(sentence))

def convert(phrase):
    phrase = phrase.replace(":)","🙂").replace(":(","🙁")
    return phrase

main()