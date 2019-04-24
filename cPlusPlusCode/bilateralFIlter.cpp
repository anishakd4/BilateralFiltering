#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    //Read image
    Mat image = imread("../assets/putin_noise.jpg");

    //check if image exists
    if(image.empty()){
        cout<<"can not find image"<<endl;
        return 0;
    }

    //define diameter of the pixel neighbourhood to be used for filter
    int diameter = 15;

    double sigmaColor = 80;

    double sigmaSpace = 80;

    Mat result;

    //Apply bilateral filter
    bilateralFilter(image, result, diameter, sigmaColor, sigmaSpace);

    //create windows to display images
    namedWindow("image", WINDOW_NORMAL);
    namedWindow("result", WINDOW_NORMAL);

    //display images
    imshow("image", image);
    imshow("result", result);

    //press esc to exit the program
    waitKey(0);

    //close all the opened windows
    destroyAllWindows();

    return 0;
}