
# (1)
class Address:
    def __init__(self, number, street_name) -> None:
        self.number = number
        self.street_name = street_name
        pass


# (2)
class Clock(object):
    def __init__(self, time):
        self.time = time

    def print_time(self):
        time = '6:30'
        print(self.time)


clock = Clock('5:30')
clock.print_time()


# (3)
class Clock(object):
    def __init__(self, time):
        self.time = time

    def print_time(self, time):
        print(time)


clock = Clock('5:30')
clock.print_time('10:30')


# (4)
class Clock(object):
    def __init__(self, time):
        self.time = time

    def print_time(self):
        print(self.time)


nairobi_clock = Clock('5:30')
cairo_clock = nairobi_clock
cairo_clock.time = '10:30'
nairobi_clock.print_time()
