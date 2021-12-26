#include "Fractal.h"

Fractal::Fractal()
{

}

void Fractal::render(char* field, int height, int width){
    double relation = (double) width / height;
    //double pixel_relation = 11.0f / 23.0f;  // for my console
    double pixel_relation = 1.0f / 3.0f;  // for the highest console resolution I managed to get
    char gradient[] = " .:!/r(l1Z4H9W8$@";
	int gradient_size = std::size(gradient) - 2;

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            double y = (double)i / height * 2.3f - 1.15f;
            double x = (double)j / width * 2.3f - 1.3f;
            x *= relation * pixel_relation;
            std::complex<double> c(x, y);
            std::complex<double> z(0, 0);
            short max_iters = 30;
            short n_iters = 0;
            for (int i = 0; i < max_iters; i++){
                z = std::pow(z, 2) + c;
                if (std::abs(z) > 2){
                    break;
                }
                n_iters++;
            }
            int color = (int)gradient_size* (double)n_iters/ max_iters;
            field[j + i*width] = gradient[color];
        }
    }
}
