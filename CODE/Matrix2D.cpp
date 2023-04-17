#include "Matrix2D.h"

Matrix2D::Matrix2D():Matrix2D(DEFAULT_ROWS,DEFAULT_COLS,DEFAULT_BG_COL)
{


}

 Matrix2D::Matrix2D(int intRows, int intCols, int intBGColour){

 alloc(intRows, intCols, intBGColour);



 }


 Matrix2D::Matrix2D(const Matrix2D& objOriginal){

 alloc(objOriginal._rows, objOriginal._cols, DEFAULT_BG_COL);
 clone(objOriginal);

 }

//Since the pixels ,rows and column memmbers of the class are private we create function to return the values for use outside the class.

 int Matrix2D::getRows() const{
    return _rows;
}

int Matrix2D::getCols() const{
    return _cols;
}

int Matrix2D::getPixels(int intRow ,int intCol) const{

   return _pixels[intRow][intCol];
}

void Matrix2D::setPixels(int intRow ,int intCol,int intValue){

             enforceRange(intRow, 0, _rows - 1);
             enforceRange(intCol, 0, _cols - 1);
             enforceRange(intValue,MIN_INTENSITY, MAX_INTENSITY);
             _pixels[intRow][intCol]= intValue;

}


 string Matrix2D::toString() const{
 stringstream ssPPM;
             // P2 for PGM.
             ssPPM << "P2" << endl
             << _cols << ' ' << _rows << endl
             << 255 << endl;
             for(int r = 0; r < _rows; r++){
             for(int c = 0; c < _cols; c++){
             ssPPM << _pixels[r][c] << ' ';
             }
             ssPPM << endl;
             }
             return ssPPM.str();
 }

 void Matrix2D::drawCircle(int intCRow, int intCCol, int intRadius, int intPixel){

         for(int r = 0; r < _rows; r++){
         for(int c = 0; c < _cols; c++){
         if(distance(r, intCRow, c, intCCol) <= intRadius){
         _pixels[r][c] = intPixel;
         }
           }
             }
       }

 Matrix2D::~Matrix2D(){
 dealloc();
 }

 void Matrix2D::alloc(int intRows, int intCols, int intBGColour){
         enforceRange(intRows, MIN_DIMENSION_SIZE, MAX_DIMENSION_SIZE);
         enforceRange(intCols, MIN_DIMENSION_SIZE, MAX_DIMENSION_SIZE);
         enforceRange(intBGColour,MIN_INTENSITY, MAX_INTENSITY);
         _rows = intRows;
         _cols = intCols;
         _bgColour = intBGColour;
        _pixels = new int*[_rows];
          for(int r = 0; r < _rows; r++){
            _pixels[r] = new int[_cols];
            for(int c = 0; c < _cols; c++){

         _pixels[r][c] = _bgColour;
         }
          }

     }

 void Matrix2D::dealloc(){
         for(int r = 0; r < _rows; r++){
            delete [] _pixels[r];
         }
             delete [] _pixels;

}

 void Matrix2D::clone(const Matrix2D& objOriginal){
         for(int r = 0; r < _rows; r++){
             for(int c = 0; c < _cols; c++){

               _pixels[r][c] = objOriginal._pixels[r][c];
          }
           }
     }

 void Matrix2D::enforceRange(int intArg, int intMin, int intMax) const{
         if( intArg < intMin || intArg > intMax){
         cerr << "Input ->"<<intArg << " :Must be within this range[" << intMin << ", " << intMax << "]" << endl;
          exit(ERROR_RANGE);
             }
      }

double Matrix2D::distance(int intX1, int intX2, int intY1, int intY2) const
{
    return sqrt(pow(intX1 - intX2, 2) + pow(intY1 - intY2, 2));

 }








