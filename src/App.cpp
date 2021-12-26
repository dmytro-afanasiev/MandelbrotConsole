#include "App.h"

App::App()
{
    winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    this->height = w.ws_row;
    this->width = w.ws_col;
    this->field = new char[this->height * this->width];
    Fractal f;
    this->f = &f;
}
App::~App(){
    delete [] this->field;
}

void App::print_field(){
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            printf("\033[%d;%dH%c", i, j, this->field[j + i*this->width]);
        }
    }
}

void App::run(){
    while (1){
        this->f->render(this->field, this->height, this->width);
        this->print_field();
    }
}
