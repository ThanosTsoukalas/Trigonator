#ifndef INTERFACE_H
#define INTERFACE_H 

// Γενικές πληροφορίες της εφαρμογής

#include <iostream>
#include <vector>

#include "types.h"
#include "appinfo.h"

extern const char* dnl; /*double new line*/

std::string DisplayAndGetOption(std::vector<std::string> options);

Triangle GetTriangleVertices();
void DisplayTriangleInfo(TriangleProperties givenTriangle);

Rectangle GetRectangleVertices();
void DisplayRectangleInfo (RectangleProperties givenRectangle);

void SetGreekCharScheme();
void ClearTerminal();
void DisplayApplicationInfo();

void SetApplicationTitle(std::string title);

#endif