/****************************************************************************************************************************************
File name :						RasterGraphic.cpp
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
Purpose  :						insert graphicElements in the RasterGraphic using forward_list and display all the
elements in the RasterGraphic.
*****************************************************************************************************************************************/
#include <iostream>
#include <string>
#include<vector>
#include <iomanip>
#include <forward_list>
using namespace std;

#include "Image.h"	
#include "GraphicElement.h"
#include "RasterGraphic.h"

/****************************************************************************************
Function Name :		InsertGraphicElement
Purpose :			add new GraphicElement to the RasterGraphic
In parameters :		none
Out parameters :	none
version:			1.0
Author :			Shubham ujinwal

******************************************************************************************/
void RasterGraphic::InsertGraphicElement()
{
	vector<Image> newImage;
	int numOfDisplay, x, y, duration;
	string fName;
	char displayName[100];

	int count = distance(GraphicElements.begin(), GraphicElements.end());
	int i = 0;
	/*get input from user*/
	cout << "Insert a GraphicElement in the RasterGraphic\n";
	cout << "Please enter the GraphicElement filename: ";
	cin >> fName;

	cout << "Entering the GraphicElement Images (the sets of dimesions and durations)" << endl;
	cout << "Please enter the number of Images: ";
	cin >> numOfDisplay;

	/*add the image elements*/
	for (i = 0; i < numOfDisplay; i++) {
		char* inputName;
		cout << "Please enter pixel x for Image #" << i << " pixel_x:";
		cin >> x;
		cout << "Please enter pixel y for Image #" << i << " pixel_y:";
		cin >> y;
		cout << "Please enter the duration sec for this Image: ";
		cin >> duration;
		cout << "Please enter the name for this Image: ";
		cin >> displayName;

		/*allocate new space for name*/
		inputName = new char[strlen(displayName) + 1];
		strcpy_s(inputName, strlen(displayName) + 1, displayName);
		newImage.push_back(Image(x, y, duration, inputName));
		delete inputName;
	}
	/*if the GraphicElement is empty then, insert the first element*/
	if (GraphicElements.empty()) {
		cout << "This is the first GraphicElement in the list" << endl;
		GraphicElements.push_front(GraphicElement(fName, newImage));
	}
	else {
		/*insert GraphicElement at the specific location*/
		int pos;

		if (count > 1) {
			cout << "There are " << count << " Frames in the list" << endl;
			do {
				cout << "Please specify the position, between 0 and " << count - 1 << " to insert after : ";
				cin >> pos;
				GraphicElements.insert_after(GraphicElements.begin(), GraphicElement(fName, newImage));
			} while (pos < 0 || pos > count - 1);
		}
		else {
			GraphicElements.push_front(GraphicElement(fName, newImage));
			GraphicElements.reverse();
		}
	}
}

/****************************************************************************************
Function Name :		DeleteGraphicElement
Purpose :			Delete graphicElement from the top of RasterGraphic
In parameters :		none
Out parameters :	none
version:			1.0
Author :			Shubham ujinwal
******************************************************************************************/
void RasterGraphic::DeleteGraphicElement()
{
	if (GraphicElements.empty()) {
		cout << "The graphicElement is empty." << endl;
	}
	else {
		/*delete first graphicElement from the rasterGraphic*/
		cout << "Delete the first GraphicElement from the RasterGraphic" << endl;
		GraphicElements.pop_front();
		cout << "GraphicElements deleted." << endl;
	}
	cout << endl;
}
/****************************************************************************************
Function Name :		operator[]
Purpose :			return the graphicELement at specific location.
In parameters :		unsigned int a
Out parameters :	GraphicElement& i
version:			1.0
Author :			Shubham ujinwal

******************************************************************************************/
GraphicElement& RasterGraphic::operator[](unsigned int a)
{
	forward_list<GraphicElement>::iterator i = GraphicElements.begin();
	unsigned int count = 0;
	/*looping through from all the list to get the specific index*/
	while (i != GraphicElements.end()) {
		if (count == a) {
			return *i;
		}
		++i;
		count++;
	}
	return *i;
}


/****************************************************************************************
Function Name :		operator+=
Purpose :			add RasterGraphic together
In parameters :		GraphicElement &gE
Out parameters :	none
version:			1.0
Author :			Shubham ujinwal

******************************************************************************************/
void RasterGraphic::operator+=(GraphicElement &gE)
{
	GraphicElement temp(gE);
	GraphicElements.push_front(temp);
	cout << endl;
}

/****************************************************************************************
Function Name :		operator<<
Purpose :			display all the GraphicElemets in the RasterGraphic
In parameters :		ostream &stream, RasterGraphic &rG
Out parameters :	ostream& stream
version:			1.0
Author :			Shubham ujinwal

******************************************************************************************/
ostream& operator<<(ostream &stream, RasterGraphic &rG) {
	forward_list<GraphicElement>::iterator i;
	/*check if the GrapphicElemets is empty or not*/
	if (rG.GraphicElements.empty()) {
		cout << "The rasterGraphic are empty.";
	}
	else {
		int temp = 0;
		/*display all the GraphicElemets and its contents*/
		stream << "RasterGraphic " << rG.name << "\n" << "Run the RasterGraphic" << endl;
		for (i = rG.GraphicElements.begin(); i != rG.GraphicElements.end(); i++) {
			stream << "GraphicElements #" << temp++ << ":" << endl;
			stream << *i << endl;
		}
	}
	stream << "Output finished" << endl;
	return stream;
}