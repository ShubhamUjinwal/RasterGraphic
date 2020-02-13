/****************************************************************************************************************************************
File name :						Image.cpp
Version:						1.0
Author name :					Shubham Ujinwal
S/N :							040885893
Course name :					C++ programming CST8219_302
Lab Section:					302
Due date :						9 Nov 2018
Submission date :				9 Nov 2018
Assignment Name:				RasterGraphic in C++ using Container Classes and Overloaded Operators
Assignment Number:				2
Professor name :				MOHAMED ABOU SEIF
Purpose :						initialize elements and display them.
*****************************************************************************************************************************************/
#include <iostream>

using namespace std;

#include "Image.h"
/****************************************************************************************
Function Name :		Image
Purpose :			initialize the elements
In parameters :		int x, int y, int duration, char * name
Out parameters :	none
version:			1.0
Author :			Shubham ujinwal
******************************************************************************************/
Image::Image(int x, int y, int duration, char * name)
{
	pixel_x = x;
	pixel_y = y;
	this->duration = duration;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
/****************************************************************************************
Function Name :		GraphicElement
Purpose :			initialize the elements ( copy constructor)
In parameters :		const Image & image
Out parameters :	none
version:			1.0
Author :			Shubham ujinwal

******************************************************************************************/
Image::Image(const Image & image)
{
	pixel_x = image.pixel_x;
	pixel_y = image.pixel_y;
	this->duration = image.duration;
	this->name = new char[strlen(image.name) + 1];
	strcpy_s(this->name, strlen(image.name) + 1, image.name);
}
/****************************************************************************************
Function Name :		operator<<
Purpose :			display all the elements
In parameters :		ostream & stream, Image& i
Out parameters :	ostream & stream
version:			1.0
Author :			Shubham ujinwal

******************************************************************************************/
ostream& operator<<(ostream & stream, Image& i)
{
	/*Display the elements*/
	stream << "       name: " << i.name << "; pixel_x = " << i.pixel_x << "; pixel_y = " << i.pixel_y << "; duartion = " << i.duration << endl;

	stream << "	Counting seconds for display: ";
	for (int a = 1; a <= i.duration; a++) {
		stream << a << ", ";
	}

	return stream;
}
/****************************************************************************************
Function Name :		~Image
Purpose :			destructor that deletes object
In parameters :		none
Out parameters :	none
version:			1.0
Author :			Shubham ujinwal

******************************************************************************************/
Image::~Image()
{
	delete name;
}
