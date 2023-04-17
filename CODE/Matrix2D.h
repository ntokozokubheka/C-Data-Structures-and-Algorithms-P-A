#ifndef MATRIX2D_H_INCLUDED
#define MATRIX2D_H_INCLUDED
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;


 enum ERROR_CODE{
 SUCCESS,
 ERROR_RANGE
 };

 class Matrix2D{

 public:
 // Constructors
 Matrix2D();
 Matrix2D(int intRows,int intCols,int intbgColour);
 Matrix2D(const Matrix2D& objOriginal);

  // The acessor members functions .
 int getInitColour() const;
 int getRows() const;
 int getCols() const;
 int getPixels(int intRow,int intCol) const ;


 //The mutator member functions.
  void setPixels(int intRow ,int intCol,int intValue);


 //
 string toString() const;

 // Function for drawing a circle.

 void drawCircle(int intCRow, int intCCol, int inRadius, int intPixel);

 ~Matrix2D();

 // Constants.
 static const int DEFAULT_ROWS = 500;
 static const int DEFAULT_COLS = 500;
 static const int DEFAULT_BG_COL = 0;
 static const int MIN_DIMENSION_SIZE = 2;
 static const int MAX_DIMENSION_SIZE = 100000;
 static const int MAX_INTENSITY = 255;
 static const int MIN_INTENSITY=0;


 private:
 // Utility functions.

 void alloc(int intRows, int intCols, int intBGColour);
 void dealloc();
 double distance(int intX1, int intX2, int intY1, int intY2) const;
 void clone(const Matrix2D& objOriginal);
 void enforceRange(int intArg, int intMin, int intMax) const;


 // Member variables.
 int _rows;
 int _cols;
 int _bgColour;
 int** _pixels;

 };



#endif // MATRIX2D_H_INCLUDED
