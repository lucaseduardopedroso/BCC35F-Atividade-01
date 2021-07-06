#include <windows.h>
#include <GL/glut.h>

float xr=0;
float yr=0;
float xt=0;
float yt=0;
float xs=1;
char tec='t';

int init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //A janela de recorte deve aceitar valores de x e y entre [0, 100]//
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(xt, xt, 0);
    glTranslatef(5, 5, 0);
    glScaled(xs, xs, 1);
    glRotatef(yr, 0, 0, 1);
    glTranslatef(-5, -5, 0);

    glColor3f(1,0,0);
    //O programa ao executar deve mostrar um quadrado vermelho de lado 10 alinhado ao canto inferior esquerdo da janela//
     glBegin(GL_QUADS);
        glVertex2f(10.0, 10.0);
        glVertex2f(0.0, 10.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(10.0, 0.0);
     glEnd();

    glFlush();
}

void KeyboardFunc(unsigned char key, int x, int y){
    switch (key) {
            case 'R':
            case 'r':tec='r';
                     break;
            case 'T':
            case 't':tec='t';
                     break;
            case 'S':
            case 's':tec='s';
                     break;
    }
    glutPostRedisplay();
}

void PressedKey(int key, int x, int y){
    switch (tec) {
            case 'r':// rotação para direita
                     if(key == GLUT_KEY_RIGHT){
                        yr--;
                     }
                     // rotação para esquerda
                     else if(key == GLUT_KEY_LEFT){
                        yr++;
                     }
                     break;
            case 't':// translação para direita
                     if(key == GLUT_KEY_RIGHT){
                        xt++;
                     }
                     // translação para esquerda
                     else if(key == GLUT_KEY_LEFT){
                        xt--;
                     }
                     // translação para cima
                     else if(key == GLUT_KEY_UP){
                        yt++;
                     }
                      // translação para baixo
                     else if(key == GLUT_KEY_DOWN){
                        yt--;
                     }
                     break;
            case 's':// aumenta
                    if(key == GLUT_KEY_UP){
                        xs=xs+0.1;
                     }
                      // diminui
                     else if(key == GLUT_KEY_DOWN){
                        xs=xs-0.1;
                     }
                     break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    //A janela do OpenGL deve ter 500 × 500 de tamanho//
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Atividade Prática 1");
    glutKeyboardFunc(KeyboardFunc);
    glutSpecialFunc(PressedKey);
    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
