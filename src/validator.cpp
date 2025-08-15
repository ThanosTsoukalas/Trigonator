#include <iostream>

#include "types.h"
#include "validator.h"

/*
    έλεγχος συνευθειακών σημείων που ΔΕΝ έχουν 
    ως κοινή ευθεία τον άξονα y'y 
*/
bool CheckForCollinearPoints(std::vector<Point> pointList)
{
    // Χρειαζόμαστε τουλάχιστον 3 σημεία για να ελέγξουμε αν είναι συνευθειακά
    // Προς το παρόν, αυτή η συνάρτηση χρησιμοποιείται μόνο για τρίγωνα
    if (pointList.size() != 3)
    {
        return false;
    }
    else
    {
        float slope_of_first_two_points = (
            (float)pointList[1].y - (float)pointList[0].y/
            (float)pointList[1].x - (float)pointList[0].x
        );

        StraightLineEquation equationOfFirstTwoPoints = {slope_of_first_two_points, pointList[0].y};

        if ((float)pointList[2].y == equationOfFirstTwoPoints.slope * (float)pointList[2].x + equationOfFirstTwoPoints.increment)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}