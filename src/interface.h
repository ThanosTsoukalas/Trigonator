#ifndef INTERFACE_H
#define INTERFACE_H 

// Γενικές πληροφορίες της εφαρμογής

#include <iostream>
#include <vector>

#include "types.h"
#include "appinfo.h"

std::string DisplayAndGetOption(std::vector<std::string> options);

Triangle GetTriangleVertices();
void DisplayTriangleInfo(TriangleProperties givenTriangle);

void SetGreekCharScheme();
void ClearTerminal();
void DisplayApplicationInfo();
#endif