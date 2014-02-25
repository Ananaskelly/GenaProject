#include "GeList.h"
#include "GeObj.h"
#include <iostream>
int main(){
	int v = 1;
	int &rv;
	rv += 3;
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