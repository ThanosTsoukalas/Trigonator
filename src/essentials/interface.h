#ifndef INTERFACE_H
#define INTERFACE_H 

// Γενικές πληροφορίες της εφαρμογής

#include <iostream>
#include <vector>

#include <calculator.h>

#include "types.h"
#include "appinfo.h"

extern const char* dnl; /*double new line*/

std::string DisplayAndGetOption(std::vector<std::string> options);

Triangle GetTriangleVertices();
void DisplayTriangleInfo(TriangleProperties givenTriangle);

Rect GetRectVertices();
void DisplayRectInfo (RectProperties givenRect);

void SetGreekCharScheme();
void ClearTerminal();
void DisplayApplicationInfo();

void SetApplicationTitle(std::string title);

#endif