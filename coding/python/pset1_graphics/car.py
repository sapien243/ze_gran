from graphics import *


class Car(object):
	def __init__(self, xd=45, yd=120):
		self.car_body = CarBody()
		self.wheel1 = Wheel()
		self.wheel2 = self.wheel1.clone(320, 0)

	def draw(self, window):
		self.car_body.under.draw(window)
		self.wheel1.draw(window)
		self.wheel2.draw(window)
		self.car_body.draw(window)

	def undraw(self, window):
		pass

	def animate(self, window):
		pass

class CarBody(object):
	def __init__(self, xd=45, yd=120):
		# Car body
		front_wheel = [Point(xd+150, yd+0),  Point(xd+145, yd+5), Point(xd+135, yd+45),
					   Point(xd+130, yd+50), Point(xd+60, yd+50), Point(xd+55, yd+45),
					   Point(xd+45, yd+5),   Point(xd+40, yd+0)]
		front = [Point(xd+15, yd+0),  Point(xd+10, yd+5),    Point(xd+0, yd+40),
				 Point(xd+12, yd+45), Point(xd+30, yd+78),   Point(xd+165, yd+85)]
		top = [Point(xd+225, yd+132), Point(xd+242, yd+134), Point(xd+325, yd+133),
			   Point(xd+455, yd+90)]
		back = [Point(xd+505, yd+85), Point(xd+510, yd+50), Point(xd+520, yd+40),
				Point(xd+505, yd+5),  Point(xd+495, yd+0)]
		back_wheel = [Point(xd+470, yd+0),  Point(xd+465, yd+5),  Point(xd+455, yd+45),
					  Point(xd+450, yd+50), Point(xd+380, yd+50), Point(xd+375, yd+45),
					  Point(xd+365, yd+5),  Point(xd+360, yd+0)]
		body = front_wheel+front+top+back+back_wheel
		self.body = Polygon(body)
		self.body.setFill("dark slate gray")
		# Glass/windows on car
		glass = [Point(xd+174, yd+84), Point(xd+229, yd+127), Point(xd+320, yd+126),
				 Point(xd+372, yd+108), Point(xd+380, yd+88)]
		self.glass = Polygon(glass)
		self.glass.setFill("dark cyan")
		# Underside of the car
		self.under = Rectangle(Point(xd+35, yd), Point(xd+475, yd+65))
		self.under.setFill("gray10")

	def draw(self, window):
		self.body.draw(window)
		self.glass.draw(window)

class Wheel(object):
	def __init__(self, xd=45, yd=120):
		center = Point(xd+95, yd+21)
		# Draw tire
		self.tire = Circle(center, 40)
		self.tire.setFill("black")
		# Draw rim
		self.rim = Circle(center, 35)
		self.rim.setFill("gray47")
		# Draw hub
		self.hub = Circle(center, 10)
		self.hub.setFill("gray59")

	def move(self, dx=0, dy=0):
		self.tire.move(dx, dy)
		self.rim.move(dx, dy)
		self.hub.move(dx, dy)

	def clone(self, dx=0, dy=0):
		clone = Wheel()
		clone.move(dx, dy)
		return clone

	def draw(self, window):
		self.tire.draw(window)
		self.rim.draw(window)
		self.hub.draw(window)


def main() -> None:
	window = GraphWin("nice car", 600, 400)
	window.setCoords(0, 0, 600, 400)

	# Test: Draw ground line
	left_grnd = Point(0, 100)
	right_grnd = Point(600, 100)
	ground = Line(left_grnd, right_grnd)
	ground.draw(window)

	# Test: Draw car
	car = Car()
	car.draw(window)

	window.getMouse()
	window.close()


main()
