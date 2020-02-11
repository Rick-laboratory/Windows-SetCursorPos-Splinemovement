#include <cstdio>
#include <cstdlib>
#include <vector>
#include<iostream>
#include "spline.h"
#include<Windows.h>

int main(int argc, char** argv)
{

    std::vector<double> X(5), Y(5);
    X[0] = 0.1;
    X[1] = 800.4;
    X[2] = 1000.2;
    X[3] = 2000.8;
    X[4] = 2560.0;
    Y[0] = 0.1;
    Y[1] = 400.7;
    Y[2] = 300.6;
    Y[3] = 600.1;
    Y[4] = 1079.0;

    tk::spline s;
    s.set_points(X, Y);    // currently it is required that X is already sorted

    for (size_t i = 0; i < 2560; i++)
    {
        SetCursorPos(i,(int)s(i));
        Sleep(1);
        printf("spline at %d is %f\n", i, s(i));
        //system("cls");
    }

    return EXIT_SUCCESS;
}