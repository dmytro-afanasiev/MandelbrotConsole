#ifndef APP_H
#define APP_H
#include <sys/ioctl.h>
#include <iostream>
#include <unistd.h>
#include "Fractal.h"

class App
{
    public:
        App();
        ~App();
        void run();
        void print_field();

    private:
        int width;
        int height;
        char *field;
        Fractal* f;
};

#endif // APP_H
