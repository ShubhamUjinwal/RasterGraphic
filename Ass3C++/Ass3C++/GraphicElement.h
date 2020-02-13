/****************************************************************************************************************************************
File name :						GraphicElement.cpp
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
Purpose :						GraphicElement contains vector of Images and concentante two GraphicElement and display them.
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Image.h"

/****************************************************************************************
Function Name :		operator+
Purpose :			concate the two graphicElement and its contents.
In parameters :		GraphicElement& g
Out parameters :	GraphicElement newGraphicElement
version:			1.0
Author :			Shubham ujinwal

******************************************************************************************/
GraphicElement GraphicElement::operator+(GraphicElement & g)
{
	string  new_fileName = fileName + "_" + g.fileName; /*concat file names */
	vector <Image> i = Images;
	vector <Image> o = g.Images;
	vector <Image> newImage;

	newImage.reserve(i.size() + i.size()); // preallocate memory
	newImage.insert(newImage.end(), i.begin(), i.end()); /*insert old GRaphicElement to new one*/
	newImage.insert(newImage.end(), o.begin(), o.end()); /* insert new IMage to new one*/

														 /* constructs new GraphicElement object*/
	GraphicElement newGraphicElement = GraphicElement(new_fileName, newImage);

	return newGraphicElement;
}
/****************************************************************************************
Function Name :		operator<<
Purpose :			display all the GraphicElemets and its content.
In parameters :		ostream &stream, GraphicElement &graphicElement
Out parameters :	ostream stream
version:			1.0
Author :			Shubham ujinwal

******************************************************************************************/
ostream & operator<<(ostream &stream, GraphicElement &graphicElement)
{
	int count = 0;
	vector<Image>::iterator i;

	/*Display the contents of GraphicElement*/
	stream << "	fileName = " << graphicElement.fileName << endl;
	for (i = graphicElement.Images.begin(); i != graphicElement.Images.end(); i++) {
		stream << "	Image #" << count++ << ";" << *i << endl;
	}
	return stream;
}

