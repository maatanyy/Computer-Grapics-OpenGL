/***********************************************************************/
/*                           HW#3-5 : Idle callback ����2             */
/*  �ۼ��� : ��μ�                             ��¥ : 2021�� 10�� 1��           */
/*                                                                              */
/* ���� ���� :                                                                 */
/*  �� : 4���� vertex ��ǥ�� �����ϰ� �������� 0.1�� �̵�
	�� : 4���� vertex ��ǥ�� �����ϰ� �Ʒ������� 0.1�� �̵�
	�� : 4���� vertex ��ǥ�� �����ϰ� �������� 0.1�� �̵�
	�� : 4���� vertex ��ǥ�� �����ϰ� ���������� 0.1�� �̵�

*/
/* ��� :                                                                   */
/*      ������ Idle callback�� �����ϰ� ������ Ű�� ���� �۵��� �ϰ� �Ͽ����ϴ�
			0.1�� �ҽ� �ӵ��� �ʹ� ���� ��ȭ�� �ߺ����� �ʾ� �ӵ��� ���� �����Ͽ����ϴ� */
																						 //                       //
/*************************************************************************/

#include <GL/glut.h>
#include <stdio.h>

GLdouble left = 0.0, right = 0.0, up = 0.0, down = 0.0;  //�����ӿ� �̵��� ���� ���� �� �ʱ�ȭ

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 0.8);
	glVertex3f(-1.0 + left, -0.5 + down, 0.0);   //POLYGON�� 4��ǥ ����
	glVertex3f(0.0 + right, -0.5 + down, 0.0);
	glVertex3f(0.0 + right, 0.5 + up, 0.0);
	glVertex3f(-1.0 + left, 0.5 + up, 0.0);
	glEnd();
	glutSwapBuffers();
}

void MyIdle() {   //MyIdle ����
	if (right < 1.0) {   //�������� ���� ���� ������ ��� ���������� �����̰� �Ͽ����ϴ�
		right = right + 0.001;
		left = left + 0.001;
	}
	glutPostRedisplay();
}

void MyIdle2() {  //MyIdle2 ����
	if (left > 0.0) {  //������ ���� ���� ������ ��� �������� �����̰� �Ͽ����ϴ�
		left = left - 0.001;
		right = right - 0.001;
	}
	glutPostRedisplay();
}

void MyIdle3() {  //MyIdle3 ����
	if (down > -0.5) {   //�Ʒ����� ���� ���� ������ ��� �Ʒ������� �����̰� �Ͽ����ϴ�
		down = down - 0.001;   //up, down�� ���� 0.1�� �ٿ����ϴ�
		up = up - 0.001;
	}
	glutPostRedisplay();
}

void MyIdle4() {   //MyIdle4 ����
	if (up < 0.5) {   //������ ���� ���� ������ ��� �������� �����̰� �Ͽ����ϴ�
		up = up + 0.001;    //up, down�� ���� 0.1�� �÷Ƚ��ϴ�
		down = down + 0.001;
	}
	glutPostRedisplay();
}

void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:    // �� : 4���� vertex ��ǥ�� �����ϰ� �������� 0.1�� �̵�
		glutIdleFunc(MyIdle2);  //MyIdle2 ����
		break;

	case GLUT_KEY_UP:   // �� : 4���� vertex ��ǥ�� �����ϰ� �������� 0.1�� �̵�
		glutIdleFunc(MyIdle4);  //MyIdle4 ����
		break;

	case GLUT_KEY_DOWN:   //  �� : 4���� vertex ��ǥ�� �����ϰ� �Ʒ������� 0.1�� �̵�
		glutIdleFunc(MyIdle3);  //MyIdle3 ����
		break;

	case GLUT_KEY_RIGHT: //  �� : 4���� vertex ��ǥ�� �����ϰ� ���������� 0.1�� �̵�
		glutIdleFunc(MyIdle);  //MyIdle ����
		break;

	default:
		break;
	}
	glutPostRedisplay();  //������ display event �߻� -> ������ �ٲ� ���� �����ϰ� ��
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);   //GLUT library �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);   //RGB����, �������
	glutInitWindowSize(300, 300);  //������ ũ�� ����
	glutInitWindowPosition(0, 0);  //������ ��ġ ����
	glutCreateWindow("Idle Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);  //MyDisplay�Լ� ���
	glutIdleFunc(MyIdle);  //MyIdle ����
	glutSpecialFunc(MySpecial);  //MySpecial �Լ� ���
	glutMainLoop();
	return 0;
}

