#include "Matrix2D.h"


int main()
{

    Matrix2D objOriginal(500,500,0); // The parameters represent number of rows ,Columns and the background colour
    objOriginal.drawCircle(150, 150, 50, 255); // The parameters represent center point row ,col ,the raduis length and intensity of circle
    cout << objOriginal.toString() << endl;
    return 0;
}
