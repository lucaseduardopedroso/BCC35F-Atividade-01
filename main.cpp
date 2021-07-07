#include <windows.h>
#include <GL/glut.h>

float xr=0;
float yr=0;
float xt=0;
float yt=0;
float xs=1;
//O programa começa no modo de translação, antes de qualquer tecla ser pressionada//
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

   //Para translação em 2D, coloque tz=0.
    glTranslatef(xt, xt, 0);
    glTranslatef(5, 5, 0);
   //Para a escala 2D, coloque sz=1
    glScaled(xs, xs, 1);
   //Para a rotação em 2D, coloque vx=0, vy=0 e vz=1.
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
            //O usuário deve pressionar a teclar ‘r’ para entrar no modo de rotação//
            case 'R':
            case 'r':tec='r';
                     break;
            //O usuário deve pressionar a teclar ‘t’ para entrar no modo de translação//
            case 'T':
            case 't':tec='t';
                     break;
            //O usuário deve pressionar a teclar ‘s’ para entrar no modo de escala uniforme//
            case 'S':
            case 's':tec='s';
                     break;
    }
    glutPostRedisplay();
}

void PressedKey(int key, int x, int y){
    switch (tec) {
            //As teclas do teclado ← e → devem alterar o ângulo de rotação θ adequadamente. Adotando-se o centroide do quadrado como ponto de rotação, considerando-se eventuais transformações geométricas que ele possa ter sofrido anteriormente//
            case 'r'://Rota��o para a direita//
                     if(key == GLUT_KEY_RIGHT){
                        yr--;
                     }
                     //Rota��o para a esquerda//
                     else if(key == GLUT_KEY_LEFT){
                        yr++;
                     }
                     break;
            //As teclas do teclado de setas ←, →, ↑ e ↓ devem alterar os fatores de translação tx e ty apropriadamente//
            case 't'://Translação para a direita//
                     if(key == GLUT_KEY_RIGHT){
                        xt++;
                     }
                     //Translação para esquerda//
                     else if(key == GLUT_KEY_LEFT){
                        xt--;
                     }
                     //Translação para cima//
                     else if(key == GLUT_KEY_UP){
                        yt++;
                     }
                      //Translação para baixo//
                     else if(key == GLUT_KEY_DOWN){
                        yt--;
                     }
                     break;
            //As teclas do teclado ↑ e ↓ devem alterar os fatores de escala. Adotando-se o centroide do quadrado como ponto fixo, considerando-se eventuais transformações geométricas que ele possa ter sofrido anteriormente//
            case 's'://Aumenta a escala//
                    if(key == GLUT_KEY_UP){
                        xs=xs+0.1;
                     }
                      //Diminui a escala//
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
    //A janela do OpenGL deve ter 500 � 500 de tamanho//
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Atividade Pr�tica 1");
    glutKeyboardFunc(KeyboardFunc);
    glutSpecialFunc(PressedKey);
    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
