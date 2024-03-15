#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include "libbmp.h"
using namespace std;

int main() {
	int size = 0;
	cout << "Enter size: ";
	cin >> size;
	BmpImg img(size, size);
	srand(time(0));
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			img.set_pixel(j, i, 0xff, 0xff, 0xff);
		}
	}

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j <= i; j++)
		{
			img.set_pixel(j, i, rand() % 0xff, rand() % 0xff, rand() % 0xff);
		}
	}
	img.write("my.bmp");
}