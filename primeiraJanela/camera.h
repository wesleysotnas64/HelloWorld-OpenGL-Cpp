#ifndef CAMERA_H
#define CAMERA_H

#include "ponto.h"

class Camera{
    private:
        Ponto eye, at;
        float raio;
        float velocidade;
        float longitude;
        float latitude;

    public:
        Camera();

        void move_latitude(float vel);
        void move_longitude(float vel);
        void move_dolly(float vel);
        void move_x(float vel);
        void move_z(float vel);
        void reposiciona_eye();

        void recalc_raio(Ponto alvo);

        //SETTERS
        void set_eye(float x, float y, float z);
        void set_eye_x(float x);
        void set_eye_y(float y);
        void set_eye_z(float z);

        void set_at(float x, float y, float z);
        void set_at_x(float x);
        void set_at_y(float y);
        void set_at_z(float z);

        void set_velocidade(float v);
        void set_raio(float r);
        void set_longitude(float lon);
        void set_latitude(float lat);

        //GETTERS
        Ponto get_eye();
        float get_eye_x();
        float get_eye_y();
        float get_eye_z();

        Ponto get_at();
        float get_at_x();
        float get_at_y();
        float get_at_z();

        float get_velocidade();
        float get_raio();
        float get_latitude();
        float get_longitude();
};

#endif
