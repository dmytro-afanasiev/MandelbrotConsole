#include "Fractal.h"

Fractal::Fractal()
{

}

void Fractal::render(char* field, int height, int width){
    double relation = (double) width / height;
    double pixel_relation = 11.0f / 23.0f;  // for my console
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            double y = (double)i / height * 4.0f - 2.0f;
            double x = (double)j / width * 4.0f - 2.0f;
            x *= relation * pixel_relation;
            if (x*x + y*y <= 1){
                field[j + i*width] = '@';
            } else {
                field[j + i*width] = ' ';
            }
        }
    }
}
