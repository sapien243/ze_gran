from graphics import *
import math
import time


def main() -> None:
	# Create window
	window = GraphWin("hands", 200, 200)
	window.setCoords(0, 0, 200, 200)

	center = Point(100, 100)
	last = Point(100, 175)
	line = Line(center, last)
	line.setArrow("last")
	line.draw(window)

	window.getMouse()
	for ang in range(-90+6, 360-90+6, 6):
		time.sleep(1)
		line.undraw()
		last.move(center.getX()+75*math.cos(-math.radians(ang))-last.getX(),
				  center.getY()+75*math.sin(-math.radians(ang))-last.getY())
		line = Line(center, last)
		line.setArrow("last")
		line.draw(window)

	window.getMouse()


main()
