/***********************************************************************/
/*                           HW#4-1 : �κ� ��-�� �𵨸�             */
/*  �ۼ��� : ��μ�                             ��¥ : 2021�� 10�� 15��           */
/*                                                                              */
/* ���� ���� :                                                                 */
/*  �� �հ��� �� ������ 2�� �̻�
    <1 Ű�� ������> ù��° �հ����� ������ ���ƴ� �ݺ�
    <2 Ű�� ������> �ι�° �հ����� ������ ���ƴ� �ݺ�
    <3 Ű�� ������> ����° �հ����� ������ ���ƴ� �ݺ�
    <4 Ű�� ������> ��� �հ����� ������ ���ƴ� �ݺ�
    <S Ű�� ������> �����̴� �հ����� �������� ����
    <���콺 ���� ��ư�� Ŭ���ϸ�> ���, �Ȳ�ġ �� ��� �հ����� �������� Robot Arm��
    Ư�� ������ ��� ��ó�� ȸ��
    <���콺 ������ ��ư�� Ŭ���ϸ�> �Ȳ�ġ �� ��� �հ����� �������� Robot Arm�� ����
    ��ġ�� �ڼ��� �ǵ��ư����� ��.
*/
/* ��� :                                                                   */
/*    WireCube�� �̿��Ͽ� �����Ͽ����� �Ʒɿ �ϵ��� �����Ͽ����ϴ� */
//         ������ ��� 90������ �����ϰ� �����Ͽ����ϴ�              //
/*************************************************************************/
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>

float shoulder = -30, elbow = 30;  //�ʱ� ����� �Ȳ�ġ ���� ����, float��
float thirdfinger= 0, thirdfinger2 = 10, thirdfinger3 = 10, firstfinger = 40, firstfinger2 = 10, firstfinger3 = 10, secondfinger = 20, secondfinger2 = 10, secondfinger3 = 10;
//�հ��� 3�� ���� 3�� �ʱ� ���� �� �ʱ�ȭ
bool first = false, second = false, third = false;  //�հ��� ������ �������� �����ϱ� ���� 
int change = 1, change2 = 1, change3 = 1;  //������ ���ƴ� �ϱ����� ����� �����Դϴ�.
 
void MyInit(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);  //�ʱ� ������ ���� ���������� �Ͽ����ϴ�
    glShadeModel(GL_FLAT);
}

void MyDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();   //�׵���� I PUSH

    glTranslatef(-3.0, 0.0, 0.0);	 // Pivot ���� �� ��ü �̵�
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(1.0, 0.0, 0.0);	// Pivot���� ������ ��ġ�� �������� �̵�

    glPushMatrix();	// �� TRT PUSH
    glColor3f(1.0, 1.0, 1.0);   //���� ������� �Ͽ� scale��ŭ ����� WireCube ����
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();   //POP

 
    glTranslatef(1.0, 0.0, 0.0);	// Pivot ���� �� ��ü �̵�
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(1.0, 0.0, 0.0);	// Pivot���� ������ ��ġ�� �������� �̵�

    glPushMatrix();  //���� TRT PUSH 
    glColor3f(1.0, 1.0, 1.0);    //���� ������� �Ͽ� scale��ŭ ����� WireCube ����
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();   //POP
     

    glTranslatef(1.0, 0.0, 0.0);  //�հ����� �����ϴ� ������ �̵��ϰ�
    glPushMatrix(); //�ٸ� �հ����� ��쿡�� ����ϱ� ���� �̰��� PUSH�ؼ� �����Ѵ�

    glRotatef((GLfloat)firstfinger, 0.0, 0.0, 1.0);   //ù��° �հ����� ȸ���� �� rotate�� �������ְ�
    glTranslatef(0.5, 0.0, 0.0); //x����� 0.5��ŭ �Ű��ش�

    glPushMatrix();	      //ù��° �հ����� ù���� ������ش�
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
 
    glTranslatef(0.5, 0.0, 0.0);	//������ �� �� �̵��ؼ� �ι�° ����׸������� �غ��Ѵ�
    glRotatef((GLfloat)firstfinger2, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(0.5, 0.0, 0.0);  //������ �� �̵��Ѵ�

    glPushMatrix();   	// ù��° �հ����� �ι�° ���� ������ش�
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);  //����° ���� �׸������� ������ �� �۾��� �ݺ��Ѵ�
    glRotatef((GLfloat)firstfinger3, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();	// ù��° �հ����� ����° ���� �׷��ش�
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix(); //���⼭ POP�� �����μ� ������ �����ߴ� ù���� ���۵Ǵ� ������ �´�

    glPushMatrix(); //�ٸ� �հ����� ��쿡�� ����ϱ� ���� �̰��� PUSH�ؼ� �����Ѵ�, 62��°�ٰ� ���� �����̴�
    glRotatef((GLfloat)secondfinger, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(0.5, 0.0, 0.0);  

    glPushMatrix(); 	// �ι�° �հ����� ù��° ���� �׷��ش�
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);	// �ι�° ���� �׸������� �̵�
    glRotatef((GLfloat)secondfinger2, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(0.5, 0.0, 0.0);  // �ι�° ���� �׸������� �̵�

    glPushMatrix();	// �ι�° �հ����� �ι�° ���� �׷��ش�
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);    //����° ���� �׸������� �̵�
    glRotatef((GLfloat)secondfinger3, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(0.5, 0.0, 0.0);  //����° ���� �׸������� �̵�

    glPushMatrix();	// �ι�° �հ����� ����° ���� �׷��ش�
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();  //���⼭ POP�����μ� ���� TRT ��ĵ��� POP�ǰ� �հ��� ù���� �������� ����� TOP�� ���Ե�

    glPushMatrix(); //�� ����� ���߿� �ѹ� �� ����ϱ� ���� PUSH������  ������ �հ����̹Ƿ� ���ص� ��������ϴ�
    glRotatef((GLfloat)thirdfinger, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();	// ����° �հ����� ù���� �׷��ش�
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);	//�ι�° ���� �׸��� ���� �̵�
    glRotatef((GLfloat)thirdfinger2, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(0.5, 0.0, 0.0);  //�ι�° ���� �׸��� ���� �̵�

    glPushMatrix();	// ����° �հ����� �ι�° ���� �׷��ش�
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0); //����° ���� �׸��� ���� �̵�
    glRotatef((GLfloat)thirdfinger3, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(0.5, 0.0, 0.0);  //����° ���� �׸��� ���� �̵�

    glPushMatrix();	// ����° �հ����� ����° ���� �׷��ش�
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
 
    glPopMatrix();  //TRT ����� POP��

    glPopMatrix();  //�������� �հ��� ù ��ġ�� ����ϴ� ����� POP��
    glPopMatrix();
    glutSwapBuffers();
}

void MyReshape(int w, int h) {  //ReShape�Լ� 
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void FirstIdle() {   //�հ��� ������ ��ٿ� ���Ǵ� �Լ� Idle�̿�
    if (first == true) {  //���� first �� true �� ó�� �հ����� �����δ�
        if (change == 1) {   //ó�� change�� 1�� ���� �����ߴ�
            firstfinger += 0.07;  //change�� 1�̸� ������ ����� ������Ű��
            firstfinger2 += 0.03;
            firstfinger3 += 0.01;
        }
        else if (change == -1) {  //���� change�� ������ ������ ���ҽ�Ų��
            firstfinger -= 0.07;
            firstfinger2 -= 0.03;
            firstfinger3 -= 0.01;
        }
        if (firstfinger >= 110.00000) {  //������ 110���� �Ѿ�� ������ ���̰� change��ȣ�� �ٲ��ش�
            change = -1;
        }
        if (firstfinger <= 0.00000) {  //������ 0������ �۾����� ������ �ø��� change ��ȣ�� ����� ���ش�
            change = 1;
        }
    }
    if (second == true) {  //���� second �� true �� �ι�° �հ����� �����δ�
        if (change2 == 1) {  //ó�� change2�� 1�� ���� �����ߴ�
            secondfinger += 0.07;  //change2�� 1�̸� ������ ����� ������Ű��
            secondfinger2 += 0.03;  //change2�� 1�̸� ������ ����� ������Ű��
            secondfinger3 += 0.01;  //change2�� 1�̸� ������ ����� ������Ű��
        }
        else if (change2 == -1) {  //���� change2�� ������ ������ ���ҽ�Ų��
            secondfinger -= 0.07;
            secondfinger2 -= 0.03;
            secondfinger3 -= 0.01;
        }
        if (secondfinger >= 110.00000) {   //������ 110���� �Ѿ�� ������ ���̰� change2��ȣ�� �ٲ��ش�
            change2 = -1;
        }
        if (secondfinger <= 0.00000) {   //������ 0������ �۾����� ������ �ø��� change2 ��ȣ�� ����� ���ش�
            change2 = 1;
        }
    }
    if (third == true) {  //���� third�� true�� ����° �հ����� �����δ�
        if (change3 == 1) {   //ó�� change3�� 1�� ���� �����ߴ�
            thirdfinger += 0.07;  //change3�� 1�̸� ������ ����� ������Ű��
            thirdfinger2 += 0.03;  //change3�� 1�̸� ������ ����� ������Ű��
            thirdfinger3 += 0.01;  //change3�� 1�̸� ������ ����� ������Ű��
        }
        else if (change3 == -1) {   //���� change3�� ������ ������ ���ҽ�Ų��
            thirdfinger -= 0.07;
            thirdfinger2 -= 0.03;
            thirdfinger3 -= 0.01;
        }
        if (thirdfinger >= 110.00000) {  //������ 110���� �Ѿ�� ������ ���̰� change3��ȣ�� �ٲ��ش�
            change3 = -1;
        }
        if (thirdfinger <= 0.00000) {  //������ 0������ �۾����� ������ �ø��� change3 ��ȣ�� ����� ���ش�
            change3 = 1;
        }
    }
    glutPostRedisplay();  //�ٷιٷ� ����ǰ��Ѵ�
}

void Idle4() {  //��� �հ����� ������ ������ �ϴ� �Լ��ε� Idle�� �̿��߰� ��� �հ����� �����̰� �Ͽ��� �� ������ �����Ͽ��� �� ������ ���� FirstIdle�� ����
    if (change == 1) {
        firstfinger += 0.07;  
        firstfinger2 += 0.03;
        firstfinger3 += 0.01;
    }
    else if (change == -1) {
        firstfinger -= 0.07;  
        firstfinger2 -= 0.03;
        firstfinger3 -= 0.01;
    }
    if (firstfinger >= 110.00000) {
        change = -1;
    }
    if (firstfinger <= 0.00000) {
        change = 1;
    }
    if (change2 == 1) {
        secondfinger += 0.07;  
        secondfinger2 += 0.03;  
        secondfinger3 += 0.01;  
    }
    else if (change2 == -1) {
        secondfinger -= 0.07;  
        secondfinger2 -= 0.03;  
        secondfinger3 -= 0.01;  
    }
    if (secondfinger >= 110.00000) {
        change2 = -1;
    }
    if (secondfinger <= 0.00000) {
        change2 = 1;
    }
    if (change3 == 1) {
        thirdfinger += 0.07;  
        thirdfinger2 += 0.03;  
        thirdfinger3 += 0.01;  
    }
    else if (change3 == -1) {
        thirdfinger -= 0.07;  
        thirdfinger2 -= 0.03;  
        thirdfinger3 -= 0.01;  
    }
    if (thirdfinger >= 110.00000) {
        change3 = -1;
    }
    if (thirdfinger <= 0.00000) {
        change3 = 1;
    }
    glutPostRedisplay();
}

void StopIdle() {  //���ߴ� Idle ,SŰ�� �������� ���ȴ�
    firstfinger = firstfinger;  //firstfinger,secondfinger,thirdfinger ���� �ڽ��� �ǰ��Ͽ� �������� ���߾��־���
    secondfinger = secondfinger;
    thirdfinger = thirdfinger;
    glutPostRedisplay();
}

void Mouseright() {  //���콺 �������� ������ �� ����Ǵ� �Լ�
    if (shoulder >= -30.0000) {     //if���� �̿��Ͽ� ��δ� �ʱⰪ�� ���Ͽ� ������ ���ư��� ���־���
        shoulder = shoulder - 0.01;
    }
    if (elbow >= 30.0000) {
        elbow = elbow - 0.01;
    }
    if (firstfinger >= 40.0000) {
        firstfinger -= 0.07;
    }
    if (firstfinger2 >= 10.0000) {
        firstfinger2 -= 0.03;
    }
    if (firstfinger3 >= 10.0000) {
        firstfinger3 -= 0.01;
    }
    if (secondfinger >= 20.0000) {
        secondfinger -= 0.07;
    }
    if (secondfinger2 >= 10.0000) {
        secondfinger2 -= 0.03;
    }
    if (secondfinger3 >= 10.0000) {
        secondfinger3 -= 0.01;
    }
    if (thirdfinger >= 0.0000) {
        thirdfinger -= 0.07;
    }
    if (thirdfinger2 >= 10.0000) {
        thirdfinger2 -= 0.03;
    }
    if (thirdfinger3 >= 10.0000) {
        thirdfinger3 -= 0.01;
    }
    first = false;   //ó������ ���ư��� ������ ��� �հ����� ���¸� false�� �Ͽ� �������� ���� ���·� �ʱ�ȭ�Ͽ���
    second = false;
    third = false;
    glutPostRedisplay();  //�ٷ� ����ǰ� ��
}

void Mouseleft() {  //���콺 ������ ������ �� ����Ǵ� �Լ� 
    if (shoulder <= 15.000) {  //ũ�� shoulder�� �������� ��� shoulder�� ��ȭ��Ű�� �ٸ� �κе鵵 �����̰� �Ͽ���
        shoulder = shoulder + 0.01;
        elbow = elbow + 0.01;
        firstfinger += 0.01;
        firstfinger2 += 0.01;
        firstfinger3 += 0.01;
        secondfinger += 0.01;
        secondfinger2 += 0.01;
        secondfinger3 += 0.01;
        thirdfinger += 0.01;
        thirdfinger2 += 0.01;
        thirdfinger3 += 0.01;
    }
    glutPostRedisplay();  //�ٷ� ����ǰ� ��
}

void mouseCallback(int button, int state, int x, int y) {   //���콺 �ݹ��Լ� ����
    if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN)) {  //���콺 �������� Ŭ���Ǿ��� ��
        glutIdleFunc(Mouseright);    //Mouseright�Լ� ȣ��
    }
    else if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {  //���콺 ������ Ŭ���Ǿ��� ��
        glutIdleFunc(Mouseleft);  //Mouseleft�Լ� ȣ��
    }
}

void MyKeyboard(unsigned char key, int x, int y) {  //Ű���� �ݹ��Լ� ����
    switch (key) {
    case '1':  //1�� Ŭ���� FirstIdle ȣ��
        first = true;  //first�� true�� �ٲ���
        glutIdleFunc(FirstIdle);
        break;

    case '2':  //2�� Ŭ���� SecondIlde ȣ��
        second = true;  //second�� true�� �ٲ���
        glutIdleFunc(FirstIdle);
        break;

    case '3':  //3�� Ŭ���� ThirdIdle ȣ��
        third = true;  //third�� true�� �ٲ���
        glutIdleFunc(FirstIdle);
        break;

    case '4':  //4�� Ŭ���� Idle4 ȣ��
        glutIdleFunc(Idle4);  //��� �հ����� �����̰� �ϴµ� ������ ��� �հ����� �����̴� ��Ȳ������ stop�� �� �� ������ ���� true������ �������� �ʾҴ�
        break;

    case 's':  //s Ŭ���� StopIdle ȣ��
        first = false;  //��δ� false�� �ٲ㼭 �������� ���߰��Ͽ��� StopIdle�� ȣ���ؼ� ���߰� �Ͽ���
        second = false;
        third = false;
        glutIdleFunc(StopIdle);
        break;
    case 'S':
        first = false;  //��δ� false�� �ٲ㼭 �������� ���߰��Ͽ��� StopIdle�� ȣ���ؼ� ���߰� �Ͽ���
        second = false;
        third = false;
        glutIdleFunc(StopIdle);
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);  //������ ũ�� ����
    glutInitWindowPosition(100, 100);  //��������� ��ġ ����
    glutCreateWindow("Robot Arm");  //�����츸��
    MyInit();  //�ʱ� ����
    glutDisplayFunc(MyDisplay);  //MyDisplay�Լ����
    glutReshapeFunc(MyReshape);   //MyReschape�Լ����
    glutKeyboardFunc(MyKeyboard);   //MyKeyboard�Լ����
    glutMouseFunc(mouseCallback);  //mouseCallback �Լ� ���
    glutMainLoop();
    return 0;
}