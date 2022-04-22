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
void mirror ();
void filterEnlargeImage ();
void filterShuffleImage ();
void blur () ;
int getchoice();



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

void loadImage()
{
    char ImageFileName [100];

    cout << "Please enter file name of the image \n";
    cin >> ImageFileName ;

    strcat (ImageFileName,".bmp");
    readGSBMP (ImageFileName,image);
}

void loadImage2 ()
{
    char ImageFileName [100];

    cout << "Please enter name of image file to merge with: \n";
    cin >> ImageFileName ;

    strcat (ImageFileName,".bmp");
    readGSBMP (ImageFileName,image2);
}

void saveImage ()
{
    char ImageFileName [100];

    cout << "enter the target image file name : \n";
    cin >> ImageFileName ;

    strcat (ImageFileName,".bmp");
    writeGSBMP (ImageFileName,image);
}

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