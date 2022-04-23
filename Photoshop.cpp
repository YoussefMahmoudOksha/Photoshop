// FCAI � Programming 1 � 2022 - Assignment 3
// Program Name: Photoshop .
// Last Modification Date: 4/22/2022
// Author1 and ID and Group: Moaz Alaa Eldin Megahed - 20210587
// Author2 and ID and Group: Mariam Ramadan Abd El-Hameed - 20210381
// Author3 and ID and Group: Youssef Mahmoud Okasha Mahmoud - 20210486


#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
void loadImage ();
void loadImage2 ();
void saveImage ();
void BlackAndWhiteImage ();
void InvertImage () ;
void Merge();
void FlipImageHorizontal ();
void FlipImageVertical ();
void RotateImage () ;
void Darken_Lighten ();
void filterDetectEdges();
void shrink ();
void filterMirrorImage ();
void filterEnlargeImage ();
void filterShuffleImage ();
void blur () ;


int main()
{
    string choise ;
    cout << "Ahlan ya user ya habibi \n";
    loadImage ();
    while (true)
    {
        cout << "Please select a filter to apply or 0 to exit: \n"
                "  1-Black & White Filter \n"
                "  2-Invert Filter \n"
                "  3-Merge Filter \n"
                "  4-Flip Image \n"
                "  5-Rotate Image \n"
                "  6-Darken and Lighten Image \n"
                "  7-Detect Image Edges\n"
                "  8-Enlarge image \n"
                "  9-Shrink Image \n"
                "  a-Mirror 1/2 Image \n"
                "  b-Shuffle Image \n"
                "  c-Blur Image \n"
                "  s-Save the image to a file \n"
                "  n-New Image \n"
                "  0-Exit \n";
        cin >> choise ;
        if (choise == "1")
        {
            BlackAndWhiteImage ();
        }
        else if (choise == "2")
        {
            InvertImage ();
        }
        else if (choise == "3")
        {
            loadImage2 ();
            Merge();
        }
        else if (choise == "4")
        {
            char enter ;
            cout << "Flip (h)orizontally or (v)ertically ? \n";
            cin >> enter ;
            if (enter== 'h')
                FlipImageHorizontal ();
            if (enter = 'v')
                FlipImageVertical ();
        }
        else if (choise == "5")
        {
            RotateImage () ;
        }
        else if (choise == "6")
        {
            Darken_Lighten ();
        }
        else if (choise == "7")
        {
            filterDetectEdges();
        }
        else if (choise == "8")
        {
            filterEnlargeImage ();
        }
        else if (choise=="9")
        {
            shrink();
        }
        else if (choise == "a")
        {
            mirror ();
        }
        else if (choise == "b")
        {
            filterShuffleImage ();
        }
        else if (choise == "c")
        {
            blur();
        }
        else if (choise == "s")
        {
            saveImage();
        }
        else if (choise == "n")
        {
            loadImage ();
        }
        else if (choise == "0")
        {
            break;
        }
        else
        {
            cout << "this input is invalid \n";
        }
    }
    return 0;
}
// load Image function

void loadImage()
{
    char ImageFileName [100];

    cout << "Please enter file name of the image \n";
    cin >> ImageFileName ;

    strcat (ImageFileName,".bmp");
    readGSBMP (ImageFileName,image);
}
// load Image2 function

void loadImage2 ()
{
    char ImageFileName [100];

    cout << "Please enter name of image file to merge with: \n";
    cin >> ImageFileName ;

    strcat (ImageFileName,".bmp");
    readGSBMP (ImageFileName,image2);
}
// save Image function

void saveImage ()
{
    char ImageFileName [100];

    cout << "enter the target image file name : \n";
    cin >> ImageFileName ;

    strcat (ImageFileName,".bmp");
    writeGSBMP (ImageFileName,image);
}

void filterBlackAndWhiteImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
}

// the invert image filter

void InvertImage ()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            image[i][j] = abs(image[i][j] - 255);
        }
    }
}
 // this filter to merge two image
void Merge()
{
    for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j< SIZE; j++)
      {
          //calculate the average of two pixel
          image[i][j]=(image[i][j]+image2[i][j])/2;
      }
    }
}

void filterFlipImageHorizontal() {
    unsigned char tempImage[SIZE][SIZE];


    //To Flip Image Horizontal Into Temp Image
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            tempImage[i][j] = image[255-i][j];
        }
    }

    //To Replace Image With Temp Image
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            image[i][j] = tempImage[i][j];
        }
    }
}

void filterFlipImageVertical() {
    unsigned char tempImage[SIZE][SIZE];


    // Flip Image Horizontal Into Temp Image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tempImage[i][j] = image[i][255 - j];
        }
    }

    // Replace Image With Temp Image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = tempImage[i][j];
        }
    }
}

// the rotate image filter

void RotateImage ()
{
    int deg;
    cout << "enter the deg (90 ,180, 270): ";
    cin >> deg ;
    unsigned char templmage1[SIZE][SIZE];

    // check the input number

    if (deg == 90)
    {
        // rotate imgege 90 deg
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
               templmage1[i][j] = image[255-j][i] ;
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image[i][j] = templmage1[i][j] ;
            }
        }
    }
    else if (deg == 180)
    {
        // rotate imgege 180 deg
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
               templmage1[i][j] = image[255-i][255-j] ;
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image[i][j] = templmage1[i][j] ;
            }
        }
    }
    else if (deg == 270)
    {
        // rotate imgege 270 deg
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
               templmage1[i][j] = image[j][255-i] ;
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image[i][j] = templmage1[i][j] ;
            }
        }
    }


    // if the imput is wrong

    else
    {
        cout << "wrong input" << endl;

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image[i][j] = image[i][j]
            }
        }

    }

}
// this filter to make image darken or lighten
void Darken_Lighten ()
{
    char select ;
    cout << "Do you want to (d)arken or (l)ighten? \n";
    cin >> select;
    for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j< SIZE; j++)
      {
          if (select == 'l')
          {
                image[i][j]=(image[i][j]+255)/2;
                if (image[i][j]>255)
                    image[i][j]=255;
          }
          else if(select == 'd')
          {
              image[i][j]=image[i][j]/2;
          }
          else
          {
              cout << "this input is invalid , try again \n";
              return Darken_Lighten ();
          }
      }
    }
}

void filterDetectEdges()
{
    long average = 0;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            average += image[i][j]; // taking the sum of all elements in the photo
        }
    }
    average /= (SIZE * SIZE); // to calculate the average color of the photo
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            if ( ( image[i][j] < average ) and ( image[i][j+1] < average ) ){
                while ( image[i][j+4] < average){
                    if (image[i+1][j]<average){
                        // if there is a black cell and black cells after it , makes these two cells white
                        image[i][j+2]=255;
                        j+=1;
                    }
                    else{
                        j+=1;
                    }
                }
            }
            if (image[i][j]>average){
                image[i][j] = 255; // if cell is more than average color of photo make it white
            }
        }
    }
}

// the enlarge image filter

void filterEnlargeImage ()
{
    int quart;
    unsigned char templmage1[SIZE][SIZE];
    unsigned char templmage2[SIZE][SIZE];

    cout << "enter the quart number (1, 2, 3, 4): ";
    cin >> quart;

     // check the input

    if (quart == 1)
    {
     // cut the quart for the input number
       for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j < SIZE/2; j++)
            {
               templmage1[i][j] = image[i][j] ;
            }
        }

        // enlarge image

        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j < SIZE/2; j++)
            {
               templmage2[i * 2][j * 2] = templmage1[i][j] ;
               templmage2[i * 2][(j * 2) + 1] = templmage1[i][j] ;
               templmage2[(i * 2) + 1][j * 2] = templmage1[i][j] ;
               templmage2[(i * 2) + 1][(j * 2) + 1] = templmage1[i][j] ;
            }
        }
     // save the image

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
               image[i][j] = templmage2[i][j] ;
            }
        }

    }

    else if (quart == 2)
    {
     // cut the quart for the input number
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = SIZE/2; j< SIZE; j++)
            {
               templmage1[i][j - (SIZE/2)] = image[i][j] ;
            }
        }
     // enlarge image
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j < SIZE/2; j++)
            {
               templmage2[i * 2][j * 2] = templmage1[i][j] ;
               templmage2[i * 2][(j * 2) + 1] = templmage1[i][j] ;
               templmage2[(i * 2) + 1][j * 2] = templmage1[i][j] ;
               templmage2[(i * 2) + 1][(j * 2) + 1] = templmage1[i][j] ;
            }
        }
     // save the image
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
               image[i][j] = templmage2[i][j] ;
            }
        }

    }

    else if (quart == 3)
    {
     // cut the quart for the input number
       for (int i = SIZE/2; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE/2; j++)
            {
               templmage1[i - (SIZE/2)][j] = image[i][j] ;
            }
        }

     // enlarge image
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j< SIZE/2; j++)
            {
               templmage2[i * 2][j * 2] = templmage1[i][j] ;
               templmage2[i * 2][(j * 2) + 1] = templmage1[i][j] ;
               templmage2[(i * 2) + 1][j * 2] = templmage1[i][j] ;
               templmage2[(i * 2) + 1][(j * 2) + 1] = templmage1[i][j] ;
            }
        }

     // save the image

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
               image[i][j] = templmage2[i][j] ;
            }
        }

    }

    else if (quart == 4)
    {
     // cut the quart for the input number
        for (int i = SIZE/2; i < SIZE; i++)
        {
            for (int j = SIZE/2; j < SIZE; j++)
            {
               templmage1[i - (SIZE/2)][j - (SIZE/2)] = image[i][j] ;
            }
        }
     // enlarge image
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j< SIZE/2; j++)
            {
               templmage2[i * 2][j * 2] = templmage1[i][j] ;
               templmage2[i * 2][(j * 2) + 1] = templmage1[i][j] ;
               templmage2[(i * 2) + 1][j * 2] = templmage1[i][j] ;
               templmage2[(i * 2) + 1][(j * 2) + 1] = templmage1[i][j] ;
            }
        }
     // save the image
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
               image[i][j] = templmage2[i][j] ;
            }
        }
    }
 // if the input is wrong
    else
    {
        cout << "wrong input" << endl;
    }
}
// this filter to shrink the image
void shrink ()
{
    unsigned char templmage1[SIZE][SIZE];
    unsigned char templmage2[SIZE][SIZE];
    string select ;

    cout << "Shrink to (1/2), (1/3) or (1/4)? \n";
    cin >> select ;
    // shrink image to 1/2
    if (select == "1/2")
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
               templmage1[i][j] = image[i][j] ;
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
               templmage2[i / 2][j / 2] = templmage1[i][j] ;
               templmage2[i / 2][(j / 2) - 1] = templmage1[i][j] ;
               templmage2[(i / 2) - 1][j / 2] = templmage1[i][j] ;
               templmage2[(i / 2) - 1][(j / 2) - 1] = templmage1[i][j] ;
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
               image[i][j] = templmage2[i][j] ;
            }
        }
    }
    // shrink image to 1/3
    else if (select == "1/3")
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
               templmage1[i][j] = image[i][j] ;
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
               templmage2[i / 3][j / 3] = templmage1[i][j] ;
               templmage2[i / 3][(j / 3) - 1] = templmage1[i][j] ;
               templmage2[(i / 3) - 1][j / 3] = templmage1[i][j] ;
               templmage2[(i / 3) - 1][(j / 3) - 1] = templmage1[i][j] ;
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
               image[i][j] = templmage2[i][j] ;
            }
        }
    }
    // shrink image to 1/4
    else if (select == "1/4")
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
               templmage1[i][j] = image[i][j] ;
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
               templmage2[i / 4][j / 4] = templmage1[i][j] ;
               templmage2[i / 4][(j / 4) - 1] = templmage1[i][j] ;
               templmage2[(i / 4) - 1][j / 4] = templmage1[i][j] ;
               templmage2[(i / 4) - 1][(j / 4) - 1] = templmage1[i][j] ;
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
               image[i][j] = templmage2[i][j] ;
            }
        }
    }
    // if input don't equal 1/2 or 1/3 or 1/4 ,this is invalid input
    else if(select!="1/2" || select!="1/3" || select!="1/4")
    {
        cout << "this value invalid ,please try again \n";
    }
}
void filterMirrorImage() {
    char choise;
    cout << "mirror 1/2 image \n"
            "Mirror (l)eft , (r)ight , (u)pper , (d)own  side ? ";
    cin >> choise;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0;
             j < SIZE; j++) {
            if (choise == 'l') {
                if (j >= 127) {
                    image[i][j] = image[i][255 - j];
                }
            }

            if (choise == 'u') {
                if (i >= 127) {
                    image[i][j] = image[255 - i][j];
                }
            }
            if (choise == 'r')
                image[i][j] = image[i][255 - j];

            if (choise == 'd')
                image[i][j] = image[255 - i][j];
        }
    }
}

// the shuffle image filter

void filterShuffleImage ()
{
    int first, second, third, foirth ;
    unsigned char templmage[SIZE][SIZE];

    // show the input number then put the quart in the new place

    cout << "Enter the first number in the order : ";
    cin >> first ;

    if (first == 1)
    {
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j < SIZE/2; j++)
            {
                    templmage[i][j] = image[i][j] ;
            }
        }
    }

    else if (first == 2)
    {
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = SIZE/2; j< SIZE; j++)
            {
                    templmage[i][j - (SIZE/2)] = image[i][j] ;
            }
        }
    }

    else if (first == 3)
    {
        for (int i = SIZE/2; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE/2; j++)
            {
                   templmage[i - (SIZE/2)][j] = image[i][j] ;
            }
        }
    }

    else if (first == 4)
    {
        for (int i = SIZE/2; i < SIZE; i++)
        {
            for (int j = SIZE/2; j < SIZE; j++)
            {
                    templmage[i - (SIZE/2)][j - (SIZE/2)] = image[i][j] ;
            }
        }
    }
    // if the input is wrong the quart in will be same
    else
    {
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j < SIZE/2; j++)
            {
                templmage[i][j] = image[i][j] ;
            }
        }
    }

    // show the input number then put the quart in the new place

    cout << "Enter the second number in the order : ";
    cin >> second ;

    if (second == 1)
    {
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j < SIZE/2; j++)
            {
                templmage[i][j + (SIZE/2)] = image[i][j] ;
            }
        }
    }

    else if (second == 2)
    {
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = SIZE/2; j< SIZE; j++)
            {
                templmage[i][j] = image[i][j] ;
            }
        }
    }

    else if (second == 3)
    {
        for (int i = SIZE/2; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE/2; j++)
            {
                templmage[i - (SIZE/2)][j + (SIZE/2)] = image[i][j] ;
            }
        }
    }

    else if (second == 4)
    {
        for (int i = SIZE/2; i < SIZE; i++)
        {
            for (int j = SIZE/2; j < SIZE; j++)
            {
                    templmage[i - (SIZE/2)][j] = image[i][j] ;
            }
        }
    }
 // if the input is wrong the quart in will be same
    else
    {
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = SIZE/2; j< SIZE; j++)
            {
                    templmage[i][j] = image[i][j] ;
            }
        }
    }


 // show the input number then put the quart in the new place

    cout << "Enter the third number in the order : ";
    cin >> third ;

    if (third == 1)
    {
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j < SIZE/2; j++)
            {
                    templmage[i + (SIZE/2)][j] = image[i][j] ;
            }
        }
    }

    else if (third == 2)
    {
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = SIZE/2; j< SIZE; j++)
            {
                templmage[i + (SIZE/2)][j - (SIZE/2)] = image[i][j] ;
            }
        }
    }

    else if (third == 3)
    {
        for (int i = SIZE/2; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE/2; j++)
            {
                templmage[i][j] = image[i][j] ;
            }
        }
    }

    else if (third == 4)
    {
        for (int i = SIZE/2; i < SIZE; i++)
        {
            for (int j = SIZE/2; j < SIZE; j++)
            {
                templmage[i][j - (SIZE/2)] = image[i][j] ;
            }
        }
    }
 // if the input is wrong the quart in will be same
    else
    {
        for (int i = SIZE/2; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE/2; j++)
            {
                templmage[i][j] = image[i][j] ;
            }
        }
    }
 // show the input number then put the quart in the new place


    cout << "Enter the fourth number in the order : ";
    cin >> foirth ;

    if (foirth == 1)
    {
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j < SIZE/2; j++)
            {
                templmage[i + (SIZE/2)][j + (SIZE/2)] = image[i][j] ;
            }
        }
    }

    else if (foirth == 2)
    {
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = SIZE/2; j< SIZE; j++)
            {
                templmage[i + (SIZE/2)][j] = image[i][j] ;
            }
        }
    }

    else if (foirth == 3)
    {
        for (int i = SIZE/2; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE/2; j++)
            {
                templmage[i][j + (SIZE/2)] = image[i][j] ;
            }
        }
    }

    else if (foirth == 4)
    {
        for (int i = SIZE/2; i < SIZE; i++)
        {
            for (int j = SIZE/2; j < SIZE; j++)
            {
                templmage[i][j] = image[i][j] ;
            }
        }
    }
 // if the input is wrong the quart in will be same
    else
    {
        for (int i = SIZE/2; i < SIZE; i++)
        {
            for (int j = SIZE/2; j < SIZE; j++)
            {
                templmage[i][j] = image[i][j] ;
            }
        }
    }
 // save the final results in the main image
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = templmage[i][j];
        }
    }
}
// this filter to blur image
void blur ()
{
    for (int i = 1; i <= SIZE; i++) {
     for (int j = 1; j<= SIZE; j++) {
                 image[i][j]=(image[i][j]+image[i-1][j-1]+image[i-1][j]+image[i+1][j]+image[i][j-1]
                              +image[i][j+1]+image[i-1][j+1]+ image[i][j+1]+image[i+1][j+1]
                              +image[i-2][j-2]+image[i-2][j+2]+image[i-1][j-2]+image[i-1][j+2]+
                              image[i][j-2]+image[i][j+2]+image[i+1][j-2]+image[i+1][j+2]
                              +image[i+2][j-2]+image[i+2][j-1]+image[i+2][j]+image[i+2][j+1]+
                              image[j+2][i+2])/24;
  }
  }
  for (int i = 1; i <= SIZE; i++) {
    for (int j = 1; j<= SIZE; j++) {
         image[i][j]=(image[i][j]+image[i-1][j-1]+image[i-1][j]+image[i+1][j]+image[i][j-1]
                      +image[i][j+1]+image[i-1][j+1]+ image[i][j+1]+image[i+1][j+1]
                      +image[i-2][j-2]+image[i-2][j+2]+image[i-1][j-2]+image[i-1][j+2]+
                      image[i][j-2]+image[i][j+2]+image[i+1][j-2]+image[i+1][j+2]
                      +image[i+2][j-2]+image[i+2][j-1]+image[i+2][j]+image[i+2][j+1]+
                      image[j+2][i+2])/24;
  }
  }

}
