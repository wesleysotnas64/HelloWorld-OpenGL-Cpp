/*
COMPILAR: g++ main.cpp camera.cpp ponto.cpp -lGL -lGLU -lglut
PROPRIEDADES DA CÂMERA:
    W -> Mover câmera para cima
    S -> Mover câmera para baixo
    A -> Mover câmera para esquerda
    D -> Mover câmera para direita
    F -> Zoom out
    R -> Zoom in
    T -> Aumentar velocidade
    G -> Diminuir velocidade
*/

#include <GL/glut.h>
#include <iostream>

#include "camera.h"

#define LARG 700
#define ALTU 600

void desenha();
void inicio();
void teclado(unsigned char tecla, int x, int y);
void update();

void piramide(float altura, float base);
void eixos(float tamanho);

Camera camera;

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(LARG, ALTU);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Primeira Janela!");

    inicio();

    glutIdleFunc(update);
    glutKeyboardFunc(teclado);
    glutDisplayFunc(desenha);
    glutMainLoop();
    
    return 0;
}

void inicio(){
    glClearColor(0.0f, 0.0f, 0.0f, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);

    camera.set_raio(3);
    camera.set_velocidade(1);
    camera.reposiciona_eye();
}

void update(){
    desenha();
}

void teclado(unsigned char tecla, int x, int y){
    if(tecla == 'w') camera.move_latitude( camera.get_velocidade());
    if(tecla == 's') camera.move_latitude(-camera.get_velocidade());
    if(tecla == 'a') camera.move_longitude(-camera.get_velocidade());
    if(tecla == 'd') camera.move_longitude( camera.get_velocidade());
    if(tecla == 'r') camera.move_dolly(-camera.get_velocidade()*0.1f);
    if(tecla == 'f') camera.move_dolly( camera.get_velocidade()*0.1f);
    if(tecla == 't') camera.set_velocidade(camera.get_velocidade()+0.1f);
    if(tecla == 'g') camera.set_velocidade(camera.get_velocidade()-0.1f);
}

void desenha(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa buffer

    //aspect ratio
    float largura, altura;
    altura  = 1.0f;
    largura = (1.0f*LARG)/ALTU;

    /*as próximas linhas definem o modo de projeção e tamanho da matriz da tela*/
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-largura/2,largura/2,-altura/2,altura/2,1,10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Define posição da câmera, para onde olha e orientação ("em pé")
    gluLookAt(camera.get_eye_x(), camera.get_eye_y(), camera.get_eye_z(), 0,0,0, 0,1,0);

    //Desenho
    eixos(1);
    piramide(0.75f, 1);

    glutSwapBuffers();
}

void piramide(float altura, float base){

    float v1[3] = {-base/2, 0,  base/2};
    float v2[3] = {-base/2, 0, -base/2};
    float v3[3] = { base/2, 0, -base/2};
    float v4[3] = { base/2, 0,  base/2};
    float v5[3] = {0, altura, 0};

    //Desenha BASE
    glColor3f(1, 1, 0);
    glBegin(GL_QUADS);
        glVertex3fv(v1);
        glVertex3fv(v2);
        glVertex3fv(v3);
        glVertex3fv(v4);
    glEnd();

    //Desenha lados
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex3fv(v5);
        glVertex3fv(v1);
        glVertex3fv(v4);

        glColor3f(0, 1, 0);
        glVertex3fv(v5);
        glVertex3fv(v4);
        glVertex3fv(v3);

        glColor3f(0, 0, 1);
        glVertex3fv(v5);
        glVertex3fv(v3);
        glVertex3fv(v2);

        glColor3f(1, 1, 1);
        glVertex3fv(v5);
        glVertex3fv(v2);
        glVertex3fv(v1);
        
    glEnd();
}

void eixos(float tamanho){
    glBegin(GL_LINES);
        //Eixo X
        glColor3f(1, 0, 0);
        glVertex3f(0,0,0);
        glVertex3f(tamanho,0,0);

        //Eixo Y
        glColor3f(0, 1, 0);
        glVertex3f(0,0,0);
        glVertex3f(0, tamanho,0);

        //Eixo Z
        glColor3f(0, 0, 1);
        glVertex3f(0,0,0);
        glVertex3f(0, 0, -tamanho);
    glEnd();
}