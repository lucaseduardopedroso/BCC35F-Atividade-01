#include <windows.h>
#include <GL/glut.h>

int init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    //A janela de recorte deve aceitar valores de x e y entre [0, 100]//
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);

}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);
    //O programa ao executar deve mostrar um quadrado vermelho de lado 10 alinhado ao canto inferior esquerdo da janela//
     glBegin(GL_QUADS);
        glVertex3f(10.0, 10.0, 0.0);
        glVertex3f(0.0, 10.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(10.0, 0.0, 0.0);
     glEnd();

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    //A janela do OpenGL deve ter 500 × 500 de tamanho//
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("square");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
