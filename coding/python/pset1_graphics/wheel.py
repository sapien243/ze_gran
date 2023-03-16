from graphics import *


class Wheel(object):
	def __init__(self, centre, wheel_radius, tire_radius):
		self.tire_circle = Circle(centre, tire_radius)
		self.wheel_circle = Circle(centre, wheel_radius)

	def draw(self, win):
		self.tire_circle.draw(win)
		self.wheel_circle.draw(win)

	def move(self, dx, dy):
		self.tire_circle.move(dx, dy)
		self.wheel_circle.move(dx, dy)

	def set_color(self, wheel_color, tire_color):
		self.tire_circle.setFill(tire_color)
		self.wheel_circle.setFill(wheel_color)

	def undraw(self):
		self.wheel_circle.undraw()
		self.tire_circle.undraw()

	def get_size(self):
		return self.tire_circle.getRadius()

	def get_centre(self):
		return self.tire_circle.getCentre()

	def animate(self, win, dx, dy, n):
		if n > 0:
			self.move(dx, dy)
			win.after(100, self.animate, win, dx, dy, n-1)


def main() -> None:
	window = GraphWin("wheel", 400, 300)
	window.setCoords(0, 0, 400, 300)

	wheel_center = Point(150, 100)
	wheel = Wheel(wheel_center, 40, 50)
	wheel.set_color("dark slate grey", "black")
	# left_point = Point(0, 49)
	# right_point = Point(400, 49)
	# line = Line(left_point, right_point)

	wheel.draw(window)
	# line.draw(window)
	window.getMouse()

	wheel.animate(window, 1, 0, 100)
	window.getMouse()

	wheel.undraw()
	# line.undraw()


main()
