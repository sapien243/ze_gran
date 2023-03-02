def main():
    time = input("What time is it? ")
    time = time.strip()
    ctime = convert(time)

    if 7 <= ctime <= 8:
        print("breakfast time")
    elif 12 <= ctime <= 13:
        print("lunch time")
    elif 18 <= ctime <= 19:
        print("dinner time")
    else:
        print("")


def convert(time):
    time = time.split(':', 2)
    hr = 0
    if (time[1].endswith("p.m.")) and (time[0] != "12"):
        hr = 12

    min = time[1].split(' ')
    hr = hr + float(time[0])
    min = float(min[0])

    return hr + (min / 60)


if __name__ == "__main__":
    main()
