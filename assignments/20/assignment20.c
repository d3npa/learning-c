#include <stdio.h>

struct customstruct {
	int myint;
	char mychar;
	float myfloat;
};

void main() {
	struct customstruct mystruct;

	mystruct.myint = 50;
	mystruct.mychar = 'M';
	mystruct.myfloat = 3.14;

	printf("{\n\t'myint': %d,\n\t'mychar': '%c',\n\t'myfloat': %.2f\n}\n",
			mystruct.myint, mystruct.mychar, mystruct.myfloat);
}
