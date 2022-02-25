# HelloWorld-OpenGL-Cpp
 Neste repositório é exemplificado uma janela simples em OpenGL e GLUT no Ubuntu.
 
 ![printOpenGL](https://user-images.githubusercontent.com/94082665/155739790-4d2323a0-e60d-44d2-9d8f-80462ae05294.png)

 ### Elementos no código:
 - Janela (Na classe main.cpp, criada apartir da biblioteca glut)
 - Câmera (Com movimentação **w,s,a,d** e zoom in/out **r,f**)
 - Pirâmide (Desenhada a aprtir de um código em OpenGL)
 
 ## Passo a passo para instalar e rodar o programa
 #### Instale o compilador do C++, a biblioteca OpenGL e Glut
 1. $ sudo apt-get update
 2. $ sudo apt-get install g++
 3. $ sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
 
 #### Executar o programa
 4. Clone este repositório ou baixe os arquivos em uma pasta no seu sistema (Como exemplo, na pasta *Documentos*).
 5. Abra o termina **Ctrl+Alt+T**. 
 6. E navegue até a pasta onde você salvou o programa com: **$ cd Documentos/HelloWorld-OpenGL-Cpp/primeiraJanela**
 7. Agora compile o código com o seguitne comando: **$ g++ main.cpp camera.cpp ponto.cpp -lGL -lGLU -lglut**
 8. Para executar basta digitar no terminal: **$ ./a.out**

 ###### Referências de Instalação:  http://www.codebind.com/linux-tutorials/install-opengl-ubuntu-linux/
