#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

Pixel** createImage(int width, int height)
{
  cout << "Start createImage... " << endl;
 // Create a one dimensional array on the heap of pointers to Pixels 
 //    that has width elements (i.e. the number of columns)

  Pixel** image = new Pixel*[width];
  bool fail = false;
  for (int i=0; i < width; ++i) { // loop through each column

    // assign that column to a one dimensional array on the heap of Pixels

    //  that has height elements (i.e. the number of rows)

    image[i] = new Pixel[height];

    if (image[i] == nullptr) 
    {                           // failed to allocate
      fail = true;
    }

  }

  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }

    delete [] image; // delete array of pointers

    return nullptr;

  }

  // initialize cells

  //cout << "Initializing cells..." << endl;

  for (int row=0; row<height; ++row) 
  {
    for (int col=0; col<width; ++col) 
    {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = { 0, 0, 0 };
    }
  }

  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {

  cout << "Start deleteImage..." << endl;

  // avoid memory leak by deleting the array

  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap

  }

  delete [] image;
  image = nullptr;

}

// implement for part 1

int* createSeam(int length) {

  return nullptr;

}

void deleteSeam(int* seam) {

}

bool loadImage(string filename, Pixel** image, int width, int height) 
{
  string fileString ;
  int width1, height1, max, pix ;
  ifstream filee ;
  filee.open(filename) ;

  if(!filee)
  {
    cout << "Error: failed to open input file - " << filename << endl ;
    return false ;
  }

  filee >> fileString ;
  if(fileString != "P3" && fileString != "p3")
  {
    cout << "Error: type is " << fileString << " instead of P3" << endl ;
    return false ;
  } 

  filee >> width1 ;
  if (filee.fail()) 
  {
    cout << "Error: read non-integer value" << endl;
    return false;
  }
  if(width1 != width)
  {
    cout << "Error: input width (" << width << ") does not match value in file (" << width1 << ")" << endl ;
    return false ;
  }

  filee >> height1 ;
  if (filee.fail()) 
  {
      cout << "Error: read non-integer value" << endl;
      return false;
  }
  if(height1 != height)
  {
    cout << "Error: input height (" << height << ") does not match value in file (" << height1 << ")" << endl ;
    return false ;
  }
    
  filee >> max ;
  if(filee.fail()) 
  {
    if (filee.eof()) 
    {
      cout << "Error: not enough color values" << endl;
      return false;
    }

    cout << "Error: read non-integer value" << endl;
    return false;
  }

  if (max != 255) 
  {
    cout << "Error: colorMax not 255" << endl;
    return false;
  }

  int red, green, blue ;
  for (int i = 0; i < height; i++) 
  {
    for (int j = 0; j < width; j++) 
    {
      filee >> red ;
      if (filee.fail()) 
      {
        if (filee.eof()) 
        {
          cout << "Error: not enough color values" << endl;
          return false;
        }
        cout << "Error: read non-integer value" << endl;
        return false;
      }

      filee >> green ;
      if (filee.fail()) 
      {
        if (filee.eof()) 
        {
          cout << "Error: not enough color values" << endl;
          return false;
        }
        cout << "Error: read non-integer value" << endl;
        return false;
      }

      filee >> blue ;
      if (filee.fail()) 
      {
        if (filee.eof()) 
        {
          cout << "Error: not enough color values" << endl;
          return false;
        }
        cout << "Error: read non-integer value" << endl;
        return false;
      }
      if (red < 0 || red > max) 
      {
        cout << "Error: invalid color value " << red << endl;
        return false;
      } 
      else if (green < 0 || green > max) 
      {
        cout << "Error: invalid color value " << green << endl;
        return false;
      } 
      else if (blue < 0 || blue > max) 
      {
        cout << "Error: invalid color value " << blue << endl;
        return false;
      }
        struct Pixel p;
        p.r = red ;
        p.g = green ;
        p.b = blue ;
        image[j][i] = p;                    // column and row
      }
  }

char space ;                                // whitespace
filee >> space ;
while (filee.eof() == false) 
{
  if (isspace(space) == false) 
  {
    cout << "Error: too many color values" << endl;
    return false ;
  }
  filee >> space ;
}
return true ;
}

bool outputImage(string filename, const Pixel*const* image, int width, int height) {
  return true;
}

int energy(const Pixel*const* image, int x, int y, int width, int height) 
{
  int redx, greenx, bluex, redy, greeny, bluey, gradx, grady, grad ;

  if(x == 0)
  {
    redx = image[x+1][y].r - image[width - 1][y].r ;
    bluex = image[x+1][y].b - image[width - 1][y].b ;
    greenx = image[x+1][y].g - image[width - 1][y].g ;

    gradx = pow(redx , 2) + pow(bluex , 2) + pow(greenx , 2) ;
    grady = 0 ;
  }

  else if(x == width - 1)
  {
    redx = image[0][y].r - image[x-1][y].r ;
    bluex = image[0][y].b - image[x-1][y].b ;
    greenx = image[0][y].g - image[x-1][y].g ;

    gradx = pow(redx , 2) + pow(bluex , 2) + pow(greenx , 2) ;
    grady = 0 ;
  }
  else
  {
    redx = image[x-1][y].r - image[x+1][y].r ;
    bluex = image[x-1][y].b - image[x+1][y].b ;
    greenx = image[x-1][y].g - image[x+1][y].g ; 
  }
  
  if(y == 0)
  {
    redy = image[x][height - 1].r - image[x][y+1].r ;
    bluey = image[x][height - 1].b - image[x][y+1].b ;
    greeny = image[x][height - 1].g - image[x][y+1].g ; 

    gradx = 0 ;
    grady = pow(redx , 2) + pow(bluex , 2) + pow(greenx , 2) ;
  }
  
  else if(y == height - 1)
  {
    redy = image[x][y-1].r - image[x][0].r ;
    bluey = image[x][y-1].b - image[x][0].b ;
    greeny = image[x][y-1].g - image[x][0].g ; 

    gradx = 0 ;
    grady = pow(redx , 2) + pow(bluex , 2) + pow(greenx , 2) ;
  }

  else
  {
    redy = image[x][y+1].r - image[x][y-1].r ;
    bluey = image[x][y+1].b - image[x][y-1].b ;
    greeny = image[x][y+1].g - image[x][y-1].g ;
  }
  gradx = pow(redx , 2) + pow(bluex , 2) + pow(greenx , 2) ;
  grady = pow(redy , 2) + pow(bluey , 2) + pow(greeny , 2) ;
  grad = gradx + grady ;

  return grad ;
}

// implement for part 2

// uncomment for part 2


int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) 
{
  int totalEnergy ;

  seam[0] = start_col ;                                             // Set seam for the first row to the starting column
  totalEnergy = energy(image, start_col, 0, width, height) ;        // initialising total energy to energy of pixel at (start_col , 0)

  
  int energyMiddle, energyLeft, energyRight ;

  for(int x = 1 ; x < height ; x++)
  {
    if(width == 1)                                                  // only one column
    {
      energyMiddle = energy(image, start_col , x, width, height) ;
      seam[x] = start_col ;
      totalEnergy = totalEnergy + energyMiddle ;
    }
    else if(start_col == width - 1)
    {
      energyRight = energy(image, start_col - 1 , x, width, height) ;
      energyMiddle = energy(image, start_col , x, width, height) ;

      if(energyRight < energyMiddle)
      {
        start_col = start_col - 1 ;                                    // moving right
        seam[x] = start_col  ;                                         // directions from path pov
        totalEnergy = totalEnergy + energyRight ;
      }
      else
      {
        seam[x] = start_col ;
        totalEnergy = totalEnergy + energyMiddle ;
      }
    }

    else if(start_col == 0)
    {
      energyLeft = energy(image, start_col + 1 , x, width, height) ;
      energyMiddle = energy(image, start_col , x, width, height) ;

      if(energyLeft < energyMiddle)
      {
        start_col = start_col + 1 ;                                    // moving right
        seam[x] = start_col  ;                                         // directions from path pov
        totalEnergy = totalEnergy + energyLeft ;
      }
      else
      {
        seam[x] = start_col ;
        totalEnergy = totalEnergy + energyMiddle ;
      }
    }

    else
    {
      energyLeft = energy(image, start_col + 1 , x, width, height) ;
      energyRight = energy(image, start_col - 1 , x, width, height) ;
      energyMiddle = energy(image, start_col , x, width, height) ;

      if(energyRight < energyLeft && energyRight < energyMiddle)
      {
        start_col = start_col - 1 ;                                    // moving right
        seam[x] = start_col  ;                                         // directions from path pov
        totalEnergy = totalEnergy + energyRight ;
      }
      else if(energyLeft < energyMiddle)
      {
        start_col = start_col + 1 ;                                   // moving left
        seam[x] = start_col ;
        totalEnergy = totalEnergy + energyLeft ;
      }
      else
      {
        seam[x] = start_col ;
        totalEnergy = totalEnergy + energyMiddle ;
      } 
    }
  }
  return totalEnergy ;
}

int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) 
{
  int totalEnergy ;

  seam[0] = start_row ;                                             // Set seam for the first row to the starting column
  totalEnergy = energy(image, start_row, 0, width, height) ;        // initialising total energy to energy of pixel at (start_col , 0)

  
  int energyMiddle, energyLeft, energyRight ;

  for(int x = 1 ; x < height ; x++)
  {
    if(height == 1)                                                  // only one column
    {
      energyMiddle = energy(image, start_row , x, width, height) ;
      seam[x] = start_row ;
      totalEnergy = totalEnergy + energyMiddle ;
    }
    else if(start_row == width - 1)
    {
      energyRight = energy(image, start_row + 1 , x, width, height) ;
      energyMiddle = energy(image, start_row , x, width, height) ;

      if(energyRight < energyMiddle)
      {
        start_row = start_row + 1 ;                                    // moving right
        seam[x] = start_row  ;                                         // directions from path pov
        totalEnergy = totalEnergy + energyRight ;
      }
      else
      {
        seam[x] = start_row ;
        totalEnergy = totalEnergy + energyMiddle ;
      }
    }

    else if(start_row == 0)
    {
      energyLeft = energy(image, start_row - 1 , x, width, height) ;
      energyMiddle = energy(image, start_row , x, width, height) ;

      if(energyLeft < energyMiddle)
      {
        start_row = start_row + 1 ;                                    // moving right
        seam[x] = start_row  ;                                         // directions from path pov
        totalEnergy = totalEnergy + energyLeft ;
      }
      else
      {
        seam[x] = start_row ;
        totalEnergy = totalEnergy + energyMiddle ;
      }
    }

    else
    {
      energyLeft = energy(image, start_row - 1 , x, width, height) ;
      energyRight = energy(image, start_row + 1 , x, width, height) ;
      energyMiddle = energy(image, start_row , x, width, height) ;

      if(energyRight < energyLeft && energyRight < energyMiddle)
      {
        start_row = start_row + 1 ;                                    // moving right
        seam[x] = start_row  ;                                         // directions from path pov
        totalEnergy = totalEnergy + energyRight ;
      }
      else if(energyLeft < energyMiddle)
      {
        start_row = start_row - 1 ;                                   // moving left
        seam[x] = start_row ;
        totalEnergy = totalEnergy + energyLeft ;
      }
      else
      {
        seam[x] = start_row ;
        totalEnergy = totalEnergy + energyMiddle ;
      } 
    }
  }
  return totalEnergy ;
}

int* findMinVerticalSeam(Pixel** image, int width, int height) 
{
  int* minEnergy = new int[height] ;      // path of minimum energy i.e the seam that is being built in load
  int energyMin ;                         // minimum energy
  int* seam = new int[height] ;           // array of path taken
  int i, energyy ;                        // total energy of each path (is returned from load)

  energyMin = INT32_MAX ;

  for(i = 0 ; i < width ; i++)            // iterating through each column
  {
    energyy = loadVerticalSeam(image, i, width, height, seam) ;       // total energy at the column value

    if(energyy < energyMin)               // total energy of that path is less than the maximum ;
    {
      energyMin = energyy ;               // minimum total energy is the total energy returned at that column value
      minEnergy = seam ;                  // path of minimum energy is the same as the path taken at that column value
    }
  }

  return minEnergy ;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) {

  return nullptr;

}

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) 
{
  int row, column ;

  for(row= 0 ; row <= height-1; row++)
  {
    for(column = verticalSeam[row] ; column < width-1; column++)
    {
      image[column][row].r = image[column+1][row].r ;
      image[column][row].g = image[column+1][row].g ;
      image[column][row].b = image[column+1][row].b ;

    }
  }
}


void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {

}

