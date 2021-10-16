/***********************************************************************/
/*                           HW#3-6 : timer callback ����             */
/*  �ۼ��� : ��μ�                             ��¥ : 2021�� 10�� 1��           */
/*                                                                              */
/* ���� ���� :                                                                 */
/*  ���α׷��� ����Ǹ� �ڵ�5-8�� �ִ� ������ ���������� 0.1�� ���������� ��
	���̰� �ϰ�, ������ ��迡 �ε����� ������ ������ ���ϰ� �� ��, �ٽ� ����
	�� �������� 0.1�� ���������� �����̴� ������ �ݺ���.
	? ���콺 ���� Ű�� ������ �����̴� ������ ����.
*/
/* ��� :                                                                   */
/*      ������ Idle callback�� �����ϰ� ������ Ű�� ���� �۵��� �ϰ� �Ͽ����ϴ�
		0.1�� �ҽ� �ӵ��� �ʹ� ���� ��ȭ�� �ߺ����� �ʾ� �ӵ��� ���� �����Ͽ����ϴ� */
//          ������ ���� ���� �� �������� �ٽ� �̵��ϰ�, ���� ���� ������ �ٽ� ���������� �̵��ϰ� �Ͽ����ϴ�  
//		���� ���� �� ���� ���� �ٲ�� �����Ͽ����� ���콺 ���� Ű�� ������ ������ ����ϴ� //
/*************************************************************************/
#include <GL/glut.h>
#include<stdio.h>

GLfloat right = 0.0, left =0.0;  //������ �����̿� �̿��� ���� ����
GLfloat red = 0.0, green = 0.5, blue = 0.8;  //�ʱ� �� ����
void MyIdle2();   //����� Idle �Լ� ���� 
void MyIdle();
void MyIdle3();

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(red,green,blue);
	glVertex3f(-1.0 + left, -0.5, 0.0);  //POLYGON vertex ����
	glVertex3f(0.0 + right, -0.5, 0.0);
	glVertex3f(0.0 + right, 0.5, 0.0);
	glVertex3f(-1.0 + left, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();
}

void MyIdle() {   //MyIdle ����
	if (right < 1.0) {   //�������� ���� ���� ������ ��� ���������� �����̰� �Ͽ����ϴ�
		right = right + 0.0001;  //0.0001�� right left ���������� �̵�
		left = left + 0.0001;
	}
	else if (right >= 1.0) {  //���� ���� ������
		red = 1.0;  //���� �ٲ�
		green = 0.0;
		blue = 0.0;
		glutIdleFunc(MyIdle2);  //MyIdle2 ȣ��
	}
	glutPostRedisplay();  //�ٷ� ����
}

void MyIdle2() {  //MyIdle2 ����
	if (left > 0) {  //������ ���� ���� ������ ��� �������� �����̰� �Ͽ����ϴ�
		left = left - 0.0001;  //0.0001�� right left �������� �̵�
		right = right - 0.0001;
	}
	else if (left < 0) {  //���� ���ʺ��� ������
		red = 0.0;   //���� �ٲ�
		green = 0.5;
		blue = 0.8;
		glutIdleFunc(MyIdle);  //���������� �̵��ϴ� MyIdle ȣ��
	}
	glutPostRedisplay();  //�ٷ� ����
}

void MyIdle3() {  //MyIdle3 ����
	left = left;    //left �� right�� ���� �ؼ� ���߰���
	right = right;
	glutPostRedisplay();  //�ٷ� ����
}

void MyTimer(int value) {    //Ÿ�̸� �Լ� ����
	glutIdleFunc(MyIdle);   //MyIdle �Լ� ����
	glutPostRedisplay();
}void mouseCallback(int button, int state, int x, int y) {   //mouseCallback �Լ� ����
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {  //���콺 ������ Ŭ���Ǿ��� ��
		glutIdleFunc(MyIdle3);   //����
	}
}void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);   //GLUT library �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);   //RGB����, �������
	glutInitWindowSize(300, 300);  //������ ũ�� ����
	glutInitWindowPosition(0, 0);   //������ ��ġ ����
	glutCreateWindow("Timer Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);   //MyDisplay �Լ� ���
	glutMouseFunc(mouseCallback);  //mouseCallback �Լ� ���
	glutTimerFunc(40, MyTimer, 1); //TimerFunc ���
	glutMainLoop();
	return 0;
}