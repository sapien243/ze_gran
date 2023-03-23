from graphics import *
import math


def main() -> None:
    # Create graphic window
    win = GraphWin("circles", 200, 200)
    win.setBackground("gainsboro")
    win.setCoords(0, 0, 200, 200)

    # Create and draw center circle
    c = Circle(Point(100, 100), 20)
    c.setFill("cyan")
    c.draw(win)

    win.getMouse()
    # Create and draw edge circles
    e = []
    edges = [[160, 100, "red1"], [100, 160, "yellow"],
             [40, 100, "green1"], [100, 40, "blue1"]]
    for i, cord in enumerate(edges):
        e.append(Circle(Point(cord[0], cord[1]), 20))
        e[i].setFill(cord[2])
        e[i].draw(win)

    win.getMouse()
    # Rotate the edge circles
    for ang in range(360*10):
        for i, obj in enumerate(e):
            obj.move(100+60*math.cos(math.radians(ang+i*90))-obj.getCenter().getX(),
                     100+60*math.sin(math.radians(ang+i*90))-obj.getCenter().getY())

    win.getMouse()
    # Clear the edge circles
    for obj in e:
        obj.undraw()

    win.getMouse()
    # Close the window
    win.close()


main()
