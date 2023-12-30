from graphics import *
import math
import time


class DigitalClock(object):
	def __init__(self, anchor):
		self.text = Text(anchor, "hello")
		self.text.setSize(20)
		self.text.setFace("courier")
		self.text.setStyle("bold")
		# self.hour = 0, self.minute = 0, self.second = 0
		self.hands = Hands()
		self.edge1 = Circle(Point(150, 230), 78)
		self.edge2 = Circle(Point(150, 230), 80)

	def draw(self, window):
		self.text.draw(window)
		self.hands.draw(window)
		self.edge1.draw(window)
		self.edge2.draw(window)
		time.sleep(2)
		while True:
			sys_time = int(time.time())
			hour = (sys_time//3600+3)%24
			minute = (sys_time//60)%60
			second = sys_time%60
			# mnth = (secs//2629743)%12+1, ears = secs//31556926+1970
			self.text.setText(f"{hour:0>2d}:{minute:0>2d}:{second:0>2d}")
			self.hands.update(window, hour, minute, second)
			time.sleep(0.99)


class Hands(object):
	def __init__(self, xd=150, yd=230):
		self.secs = [Point(xd, yd), Point(xd, yd+70)]
		self.mins = [Point(xd, yd), Point(xd, yd+60)]
		self.hour = [Point(xd, yd), Point(xd, yd+50)]

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
	window = GraphWin("clock", 300, 350)
	window.setCoords(0, 0, 300, 350)

	anchor = Point(150, 90)
	time = DigitalClock(anchor)
	time.draw(window)

	window.getMouse()


main()
