#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <unistd.h>

#define translado 30
#define escala 3
int rotating=0, timeOfDay=0, skyColor=255;

void DesenharCena();
void making_cube();
void making_door();
void making_roof();
void making_floor();
void making_sun();
void making_macaneta();
void making_window();
void making_sky();

//Declara��o de Vari�veis Globis
int projecao=0; //Vari�vel L�gica para Definir o Tipo de Proje��o (Perspectiva ou Ortogonal)
float posx=0, posy=30, posz=200; //Vari�veis que definem a posi��o da c�mera
float oy=30,ox=0,oz=0;         //Vari�veis que definem para onde a c�mera olha
int lx=0, ly=1,  lz=0;     //Vari�veis que definem o eixo da c�mera


GLfloat angulox=0.0;
GLfloat anguloy=0.0;

int x_temp=-1; //Armazena posi��o X do ponteiro do mouse
int y_temp=-1; //Armazena posi��o Y do ponteiro do mouse
int rotacao = 0; //Controla eixo de rota��o do mouse
int i;//controle do for

void making_door(){
  //PORTA GROSSA
  glColor3ub(101, 67, 33);
  glTranslatef(0, -3.5, 9.5);
  glScalef(0.3, 0.65, 0.05);
  glutSolidCube(19.8);

  //Ma�aneta
  glPushMatrix();
  glTranslatef(6.8, 0, 10.2);
  glScaled(1, 1, 0);
  glColor3ub(255, 255, 0);
  gluSphere(gluNewQuadric(), 0.6, 100,100);
  glPopMatrix();
  }

void making_roof(){
  glBegin(GL_QUADS);
  glPushMatrix();
  glColor3ub(0, 255, 0);
  glVertex3f(10, 10, 10);
  glVertex3f(-10, 10, 10);
  glVertex3f(-10, 10, -10);
  glVertex3f(10, 10, -10);
  glPopMatrix();
  glEnd();

  glBegin(GL_TRIANGLES);
  glPushMatrix();
  glColor3ub(0, 255, 0);
  glVertex3f(-10, 10, 10);
  glVertex3f(10, 10, 10);
  glVertex3f(0, 25, 0);
  glPopMatrix();

  glPushMatrix();
  glColor3ub(0, 255, 0);
  glVertex3f(-10, 10, 10);
  glVertex3f(-10, 10, -10);
  glVertex3f(0, 25, 0);
  glPopMatrix();

  glPushMatrix();
  glColor3ub(0, 255, 0);
  glVertex3f(10, 10, 10);
  glVertex3f(10, 10, -10);
  glVertex3f(0, 25, 0);
  glPopMatrix();

  glPushMatrix();
  glColor3ub(0, 255, 0);
  glVertex3f(-10, 10, -10);
  glVertex3f(10, 10, -10);
  glVertex3f(0, 25, 0);
  glPopMatrix();
  glEnd();
}

void making_floor(){
  glBegin(GL_QUADS);
  glPushMatrix();
  glColor3ub(130, 160, 0);
  glVertex3f(-200, -10, 200);
  glVertex3f(200, -10, 200);
  glVertex3f(200, -10, -200);
  glVertex3f(-200, -10, -200);
  glPopMatrix();
  glEnd();
}

void making_sun(){
  glTranslatef(-40, 300, 0);
  glColor3ub(255, 165, 0);
  gluSphere(gluNewQuadric(), 40, 100, 100);
}

void making_cube() {
  //parede da porta (FRENTE-CIMA)
  glPushMatrix();
  glTranslatef(0, 6.5, 9.5);
  glScalef(0.32,0.35,0.05);
  glColor3ub(0, 0, 255);
  glutSolidCube(19.8);
  glPopMatrix();
  glPushMatrix();
  glColor3ub(0, 0, 0);
  glutWireCube(20);
  glPopMatrix();

  //parede da porta (FRENTE-DIREITA)
  glPushMatrix();
  glTranslatef(6, 0, 9.5);
  glScalef(0.32, 1, 0.05);
  glColor3ub(0, 0, 255);
  glutSolidCube(19.8);
  glPopMatrix();
  glPushMatrix();
  glColor3ub(0, 0, 0);
  glutWireCube(20);
  glPopMatrix();

  //parede da porta (FRENTE-ESQUERDA)
  glPushMatrix();
  glTranslatef(-6, 0, 9.5);
  glScalef(0.32, 1, 0.05);
  glColor3ub(0, 0, 255);
  glutSolidCube(19.8);
  glPopMatrix();
  glPushMatrix();
  glColor3ub(0, 0, 0);
  glutWireCube(20);
  glPopMatrix();

  //parede da DIREITA
  glPushMatrix();
  glTranslatef(9.5, 0, 0);
  glScalef(0.05, 1, 1);
  glColor3ub(0, 0, 255);
  glutSolidCube(19.8);
  glPopMatrix();
  glPushMatrix();
  glColor3ub(0, 0, 0);
  glutWireCube(20);
  glPopMatrix();

  //parede da ESQUERDA
  glPushMatrix();
  glTranslatef(-9.5, 0, 0);
  glScalef(0.05, 1, 1);
  glColor3ub(0, 0, 255);
  glutSolidCube(19.8);
  glPopMatrix();
  glPushMatrix();
  glColor3ub(0, 0, 0);
  glutWireCube(20);
  glPopMatrix();

  //parede de TRAS
  glPushMatrix();
  glTranslatef(0, 0, -9.5);
  glScalef(1, 1, 0.05);
  glColor3ub(0, 0, 255);
  glutSolidCube(19.8);
  glPopMatrix();
  glPushMatrix();
  glColor3ub(0, 0, 0);
  glutWireCube(20);
  glPopMatrix();
};

void making_window(){
  glBegin(GL_QUADS);
  //janela
  glPushMatrix();
  glColor3ub(255, 255, 255);
  glVertex3f(4, 3, 10);
  glVertex3f(6, 3, 10);
  glVertex3f(6, 4, 10);
  glVertex3f(4, 4, 10);
  glPopMatrix();

  glPushMatrix();
  glColor3ub(255, 255, 255);
  glVertex3f(7, 3, 10);
  glVertex3f(9, 3, 10);
  glVertex3f(9, 4, 10);
  glVertex3f(7, 4, 10);
  glPopMatrix();

  glPushMatrix();
  glColor3ub(255, 255, 255);
  glVertex3f(7, 5, 10);
  glVertex3f(9, 5, 10);
  glVertex3f(9, 6, 10);
  glVertex3f(7, 6, 10);
  glPopMatrix();

  glPushMatrix();
  glColor3ub(255, 255, 255);
  glVertex3f(4, 5, 10);
  glVertex3f(6, 5, 10);
  glVertex3f(6, 6, 10);
  glVertex3f(4, 6, 10);
  glPopMatrix();
  glEnd();
}

void making_sky(){
  glPushMatrix();
  glColor3ub(0, skyColor, skyColor);
  glutSolidCube(2000);
  glPopMatrix();
}

void stroke_output(GLfloat x, GLfloat y, char *format,...)//fun��o para escrever em 3d
{
    va_list args;
    char buffer[200], *p;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    glPushMatrix();
    glScalef(0.05, 0.05, 0.05);
    for (p = buffer; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    glPopMatrix();
}

// Inicializa par�metros de rendering
void Inicializa(void)
{
    // Define a cor de fundo da janela de visualiza��o como preta
    glClearColor(0, 255, 255, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutWarpPointer(400,300);
    glutSetCursor(GLUT_CURSOR_NONE);
}

void DISPLAY(void)
{
    timeOfDay--;
    timeOfDay = timeOfDay%360;
    skyColor--;
    if(timeOfDay%360<=-0.5)
      skyColor=0;
    else if(skyColor<0)
      skyColor=255;
    
    glMatrixMode(GL_PROJECTION);/*glMatrixMode()- define qual matriz ser� alterada. SEMPRE defina o tipo de apresenta��o
                              (Ortogonal ou Perspectiva) na matriz PROJECTION.*/
    glLoadIdentity();//"Limpa" ou "transforma" a matriz em identidade, reduzindo poss�veis erros.
    if (projecao==1)
    {
        glOrtho(-200, 200, -200, 200, -200, 200);  //Define a proje��o como ortogonal
        if (rotacao=1)
            glRotatef(angulox,1.0,0.0,0.0);
        if (rotacao=2)
            glRotatef(anguloy,0.0,1.0,0.0);
    }
    if (projecao == 0)
    {
        gluPerspective(90,1,1,2000); //Define a proje��o como perspectiva
        if (rotacao=1)
            glRotatef(angulox,1.0,0.0,0.0);
        if (rotacao=2)
            glRotatef(anguloy,0.0,1.0,0.0);
    }

    glMatrixMode(GL_MODELVIEW);/*glMatrixMode()- define qual matriz ser� alterada. SEMPRE defina a c�mera
                              (Ortogonal ou Perspectiva) na matriz MODELVIEW (onde o desenho ocorrer�).*/
    glLoadIdentity(); ////"Limpa" ou "transforma" a matriz em identidade, reduzindo poss�veis erros.

    gluLookAt(posx,posy,posz,ox,oy,oz,lx,ly,lz); //Define a pos da c�mera, para onde olha e qual eixo est� na vertical.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* "limpa" um buffer particular ou combina��es de buffers,
                                                         onde buffer � uma �rea de armazenamento para informa��es da imagem.
                                                        Nesse caso, est� "limpando os buffers para suportarem anima��es */
    DesenharCena();
    glutSwapBuffers();
    glutPostRedisplay();
}

void DesenharCena ()
{
    /*Crosta Terrestre*/
    glColor3ub(100,200,0);
    glPushMatrix();
    glTranslatef(0,-0.02,0);
    glScalef(60,0.01,60);
    glutSolidCube(20);
    glPopMatrix();
    /******/

    /*TEXTO Exemplo*/
    glColor3ub(0,0,0);
    glPushMatrix();
    glTranslatef(-35, 41, 40.2);
    stroke_output(0, 0, "CASA ABRIDANTE EM openGL!!");
    glPopMatrix();
    
    glTranslatef(0, translado, 0);
    glScalef(escala, escala, escala);
    making_cube();
    making_window();
    
    glPushMatrix();
    glTranslatef(-3, 0, 10);
    glRotatef(rotating, 0, 1, 0);
    glTranslatef(3, 0, -10);
    making_door();
    glPopMatrix();
    
    making_roof();

    glPushMatrix();
    glRotatef(timeOfDay, 0, 0, 1);
    making_sun();
    glPopMatrix();

    making_sky();
}

void MOUSE_Button(int botao, int estado, int x, int y)
{
    //bot�o - recebe o c�digo do bot�o pressionado
    //estado - recebe se est� pressionado ou n�o
    //x, y - recebem respectivamente as posi��es do cursor do mouse
    switch (botao)
    {
    case GLUT_LEFT_BUTTON:
        if (estado == GLUT_DOWN)
        {
            projecao=1;
            posx=0;
            posy=0;
            posz=20;
            ox=0,oy=0,oz=0;
            lx=0, ly=1,lz=0;
            glutPostRedisplay();
        }
        break;

    case GLUT_RIGHT_BUTTON:
        if(estado == GLUT_DOWN)
        {
            projecao=0;
            posx=0;
            posy=30;
            posz=200;
            oy=30;
            ox=0;
            oz=0;
            lx=0, ly=1, lz=0;
            glutPostRedisplay();
        }
        break;
    }
}

void MOUSE(int x, int y)
{
    if (x > x_temp)
    {
        anguloy=anguloy+(x/100);
        if(anguloy > 360.0)
            anguloy = anguloy-360;
        rotacao = 2;
        glutPostRedisplay();
    }
    if (x < x_temp)
    {
        anguloy=anguloy-(x/100);
        if(anguloy > 360.0)
            anguloy = anguloy-360;
        rotacao = 2;
        glutPostRedisplay();
    }
    x_temp=x;
    if (y>y_temp)
    {
        angulox=angulox+(y/100);
        if(angulox > 360.0)
            angulox = angulox-360;
        rotacao = 1;
       glutPostRedisplay();
    }
    if (y<y_temp)
    {
        angulox=angulox-(y/100);
        if(angulox > 360.0)
            angulox = angulox-360;
        rotacao = 1;
        glutPostRedisplay();
    }
    y_temp = y;
    if(x>=500 || x<=300 || y>=400 || y<=200) //delimitar uma area de acesso ao mouse de 600x450
    {
        glutWarpPointer(400,300);
        glutPostRedisplay();
    }
    
}

void keyboard(unsigned char tecla, int x, int y)
{
    switch(tecla)
    {
    case 's':
        posx=posx+(5*cos((anguloy+90)/57.32));
        posz=posz+(5*sin((anguloy+90)/57.32));
        ox=ox+(5*cos((anguloy+90)/57.32));
        oz=oz+(5*sin((anguloy+90)/57.32));
        glutPostRedisplay();
        break;

    case 'w':
        posx=posx-(5*cos((anguloy+90)/57.32));
        posz=posz-(5*sin((anguloy+90)/57.32));
        ox=ox-(5*cos((anguloy+90)/57.32));
        oz=oz-(5*sin((anguloy+90)/57.32));
        glutPostRedisplay();
        break;

    case 'd':
        posx=posx+(5*sin((anguloy+90)/57.32));
        posz=posz-(5*cos((anguloy+90)/57.32));
        ox=ox+(5*sin((anguloy+90)/57.32));
        oz=oz-(5*cos((anguloy+90)/57.32));
        glutPostRedisplay();
        break;

    case 'a':
        posx=posx-(5*sin((anguloy+90)/57.32));
        posz=posz+(5*cos((anguloy+90)/57.32));
        ox=ox-(5*sin((anguloy+90)/57.32));
        oz=oz+(5*cos((anguloy+90)/57.32));
        glutPostRedisplay();
        break;
    case 'e':
      rotating++;
      if(rotating>=0)
        rotating=0;
      break;
    case 'r':
      rotating--;
      if(rotating<=-90)
        rotating=-90;
      break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

void TeclasEspeciais (int key, int x, int y)
{
    //Key - recebe o c�digo ASCII da tecla
//x, y - recebem respectivamente as posi��es do cursor do mouse (permite tratar os dois dispositivos)
    if (key==GLUT_KEY_PAGE_UP)
    {
        posy+=5;
        oy+=5;
    }
    else if (key==GLUT_KEY_PAGE_DOWN)
    {
        posy-=5;
        oy-=5;
    }
    glutPostRedisplay();
}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STENCIL); /*Define as caracter�sticas do espa�o vetorial.
                                                                        //  Nesse caso, permite anima��es (sem cintila��es), cores compostas por Verm. Verde e Azul,
                                                                //  Buffer que permite trablhar com profundidade e elimina faces escondidas.*/
    glutInitWindowSize(800,600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Aula 07");
    Inicializa();
    glutDisplayFunc(DISPLAY);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(MOUSE_Button);
    glutPassiveMotionFunc(MOUSE);
    glutSpecialFunc(TeclasEspeciais);
    glutMainLoop();
    return 0;
}
