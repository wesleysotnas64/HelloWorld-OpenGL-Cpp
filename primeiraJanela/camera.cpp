#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

#include "camera.h"
#include "ponto.h"

#define C (M_PI/180)

Camera::Camera(){
    set_at(0,0,0);
    set_latitude(0);
    set_longitude(0);

    reposiciona_eye();
}

void Camera::move_dolly(float vel){
    set_raio(get_raio()+(vel*0.1));
    //if(get_raio() >= 5) set_raio(5);

    reposiciona_eye();
}

void Camera::move_x(float vel){
    set_eye_x(get_eye_x()+vel);
}

void Camera::move_z(float vel){
    set_eye_z(get_eye_z()+vel);
}

void Camera::move_latitude(float vel){
    set_latitude(get_latitude()+vel);
    if(get_latitude() > 89) set_latitude( 89);
    if(get_latitude() < -89) set_latitude(-89);

    reposiciona_eye();
}

void Camera::move_longitude(float vel){
    set_longitude(get_longitude()+vel);
    if(get_longitude() > 360) set_longitude(0);
    if(get_longitude() < 0) set_longitude(360);

    reposiciona_eye();
}

void Camera::reposiciona_eye(){
    float lat = get_latitude() * C;
    float lon = get_longitude() * C;

    eye.set_coord_x(get_at_x()+get_raio()*cos(lat)*sin(lon));
    eye.set_coord_y(get_at_y()+get_raio()*sin(lat));
    eye.set_coord_z(get_at_z()+get_raio()*cos(lat)*cos(lon));

}

void Camera::recalc_raio(Ponto alvo){
    float distancia = sqrt(pow((alvo.get_coord_x()-get_eye_x()), 2)+
                           pow((alvo.get_coord_y()-get_eye_y()), 2)+
                           pow((alvo.get_coord_z()-get_eye_z()), 2));

    set_raio(distancia);
}

//SETTERS
void Camera::set_eye(float x, float y, float z){
    set_eye_x(x);
    set_eye_y(y);
    set_eye_z(z);
}

void Camera::set_eye_x(float x){
    eye.set_coord_x(x);
}

void Camera::set_eye_y(float y){
    eye.set_coord_y(y);
}

void Camera::set_eye_z(float z){
    eye.set_coord_z(z);
}

void Camera::set_at(float x, float y, float z){
    set_at_x(x);
    set_at_y(y);
    set_at_z(z);
}

void Camera::set_at_x(float x){
    at.set_coord_x(x);
}

void Camera::set_at_y(float y){
    at.set_coord_y(y);
}

void Camera::set_at_z(float z){
    at.set_coord_z(z);
}

void Camera::set_velocidade(float v){
    velocidade = v;
}

void Camera::set_raio(float r){
    raio = r;
}

void Camera::set_latitude(float lat){
    latitude = lat;
}

void Camera::set_longitude(float lon){
    longitude = lon;
}

//GETTERS
Ponto Camera::get_eye(){
    return eye;
}

float Camera::get_eye_x(){
    return eye.get_coord_x();
}

float Camera::get_eye_y(){
    return eye.get_coord_y();
}

float Camera::get_eye_z(){
    return eye.get_coord_z();
}

Ponto Camera::get_at(){
    return at;
}

float Camera::get_at_x(){
    return at.get_coord_x();
}

float Camera::get_at_y(){
    return at.get_coord_y();
}

float Camera::get_at_z(){
    return at.get_coord_z();
}

float Camera::get_velocidade(){
    return velocidade;
}

float Camera::get_raio(){
    return raio;
}

float Camera::get_latitude(){
    return latitude;
}

float Camera::get_longitude(){
    return longitude;
}

