#ifndef FRACTAL_H
#define FRACTAL_H
#include <iostream>
#include <complex>


// should be refactored to use the advantages of OOP
class Fractal
{
    public:
        Fractal();
        void render(char* field, int height, int width);

};

#endif // FRACTAL_H
