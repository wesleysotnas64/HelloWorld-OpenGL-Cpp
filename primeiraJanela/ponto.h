#ifndef PONTO_H
#define PONTO_H

class Ponto{
    private:
        float coord[3];

    public:
        Ponto();
        void set_coord(float x, float y, float z);
        void set_coord_x(float x);
        void set_coord_y(float y);
        void set_coord_z(float z);

        Ponto get_coord();
        float get_coord_x();
        float get_coord_y();
        float get_coord_z();
};

#endif
