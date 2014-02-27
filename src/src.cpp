
#include "GeUI.h"
#include "GeList.h"
#include "GeObj.h"
#include <iostream>

using namespace std;


// TEST!
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	drawLine(10, 15, 100, 80);

	glFlush();
}

int main(int argc, char* argv[])
{
	// Init GUI
	GeUI gui;
	gui.MyDraw = draw;
	gui.init(&argc, argv);

	//////////////////////

	int v = 1;
	std::cout << "v = " << v << std::endl;

	GePoint p;


	GePoint p1(p);

	p1.selected = true;

	GeList<int> li;
	li.add(2);
	li.add(3);
	li.add(5);

	li.rewind();
	while (li.canMove()){
		if (li.getData() == 34) {
			li.getData() = 35;
		}
		else{
		}
		std::cout << li.getData() <<std::endl;
		li.next();
	}

	return 0;
}