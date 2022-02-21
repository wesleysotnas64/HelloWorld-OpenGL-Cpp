#include "ponto.h"

Ponto::Ponto(){

}

//SETTERS
void Ponto::set_coord(float x, float y, float z){
    set_coord_x(x);
    set_coord_y(y);
    set_coord_z(z);
}

void Ponto::set_coord_x(float x){
    coord[0] = x;
}

void Ponto::set_coord_y(float y){
    coord[1] = y;
}

void Ponto::set_coord_z(float z){
    coord[2] = z;
}

Ponto Ponto::get_coord(){
    Ponto p;
    
    p.set_coord_x(get_coord_x());
    p.set_coord_y(get_coord_y());
    p.set_coord_z(get_coord_z());

    return p;
}

float Ponto::get_coord_x(){
    return coord[0];
}

float Ponto::get_coord_y(){
    return coord[1];
}

float Ponto::get_coord_z(){
    return coord[2];
}
