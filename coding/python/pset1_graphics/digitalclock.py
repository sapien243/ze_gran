from graphics import *
import math
import time


class DigitalClock(object):
	def __init__(self, anchor):
		self.text = Text(anchor, "hello")
		self.text.setSize(24)
		self.text.setFace("courier")
		self.text.setStyle("bold")
		# self.hour = 0, self.minute = 0, self.second = 0
		self.hands = Hands()
		self.edge1 = Circle(Point(150, 200), 78)
		self.edge2 = Circle(Point(150, 200), 80)

	def draw(self, window):
		self.text.draw(window)
		self.hands.draw(window)
		self.edge1.draw(window)
		self.edge2.draw(window)
		time.sleep(1)
		while True:
			sys_time = int(time.time())
			hour = (sys_time//3600+3)%24
			minute = (sys_time//60)%60
			second = sys_time%60
			# mnth = (secs//2629743)%12+1, ears = secs//31556926+1970
			self.text.setText(f"{hour:0>2d}:{minute:0>2d}:{second:0>2d}")
			self.hands.update(window, hour, minute, second)
			time.sleep(0.999999)


class Hands(object):
	def __init__(self, center=0):
		self.secs = [Point(150, 200), Point(150, 270)]
		self.mins = [Point(150, 200), Point(150, 260)]
		self.hour = [Point(150, 200), Point(150, 250)]

	def update(self, window, hr, mn, sc):
		self.undraw()
		self.secs[1].move(self.secs[0].getX()+70*math.cos(-(3/2+sc/30)*math.pi)-self.secs[1].getX(),
				  		  self.secs[0].getY()+70*math.sin(-(3/2+sc/30)*math.pi)-self.secs[1].getY())
		self.mins[1].move(self.mins[0].getX()+60*math.cos(-(3/2+mn/30)*math.pi)-self.mins[1].getX(),
				  		  self.mins[0].getY()+60*math.sin(-(3/2+mn/30)*math.pi)-self.mins[1].getY())
		self.hour[1].move(self.hour[0].getX()+50*math.cos(-(3/2+hr/6)*math.pi)-self.hour[1].getX(),
				  		  self.hour[0].getY()+50*math.sin(-(3/2+hr/6)*math.pi)-self.hour[1].getY())
		self.draw(window)

	def draw(self, window):
		self.secsH = Line(self.secs[0], self.secs[1])
		self.secsH.setOutline("red1")
		self.minsH = Line(self.mins[0], self.mins[1])
		self.minsH.setArrow("last")
		self.hourH = Line(self.hour[0], self.hour[1])
		self.hourH.setArrow("last")
		self.hourH.draw(window)
		self.minsH.draw(window)
		self.secsH.draw(window)

	def undraw(self):
		self.secsH.undraw()
		self.minsH.undraw()
		self.hourH.undraw()


def main() -> None:
	window = GraphWin("clock", 300, 300)
	window.setCoords(0, 0, 300, 300)

	anchor = Point(150, 75)
	time = DigitalClock(anchor)

	window.getMouse()
	time.draw(window)

	window.getMouse()


main()
