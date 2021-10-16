/***********************************************************************/
/*                           HW#3-1 : keyboard callback ����             */
/*  �ۼ��� : ��μ�                             ��¥ : 2021�� 9�� 29��           */
/*                                                                              */
/* ���� ���� :                                                                 */
/*  a �Ǵ� A : 4���� vertex ��ǥ�� �����ϰ� �������� 0.1�� �̵�
    f �Ǵ� F : 4���� vertex ��ǥ�� �����ϰ� ���������� 0.1�� �̵�
    r �Ǵ� R : 4���� vertex ��ǥ�� �����ϰ� �Ʒ������� 0.1�� �̵��ϰ�,
    ���������� Polygon ĥ��
    v �Ǵ� V : 4���� vertex ��ǥ�� �����ϰ� �������� 0.1�� �̵�
    b �Ǵ� B : �Ķ������� Polygon ĥ��                      */
/* ��� :                                                                   */
/*      movex, movey �� glColor3f�� ������ ���� �����ؼ� ������ Ű�� �˸°� �����Ҽ� �ֵ��� �Ͽ����ϴ�  */
//                       //
/*************************************************************************/
#include <GL/glut.h>

float movex = 0, movey = 0;    // x ,y �� ������ ���� ���� ���� ó���� 0���� �ʱ�ȭ
float redcolor = 0.5, greencolor = 0.5, bluecolor = 0.5;   //RGB�� �����ϱ� ���� ���� ���� ó���� �� 0.5�� �ʱ�ȭ

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);  //��������
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);  //glOrtho ����
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(redcolor, greencolor, bluecolor);   //ó�� POLYGON ���� ������ 0.5�� �����Ͽ��⿡ ȸ������ ��
	glBegin(GL_POLYGON);
	glVertex3f(-0.5 + movex, -0.5 + movey, 0.0);  // POLYGON ���� �Ʒ� ��ǥ
	glVertex3f(0.5 + movex, -0.5 + movey, 0.0);   // POLYGON ������ �Ʒ� ��ǥ
	glVertex3f(0.5 + movex, 0.5 + movey, 0.0);    // POLYGON ������ �� ��ǥ
	glVertex3f(-0.5 + movex, 0.5 + movey, 0.0);   // POLYGON ���� �� ��ǥ
	glEnd();
	glFlush();
}

void MyKeyboard(unsigned char key, int x, int y) {   //MyKeyboard �ݹ��Լ� 
	switch (key) {   //switch ���� ���� ���̽� ����
	case 'a': movex = movex - 0.1;      // a �Ǵ� A : 4���� vertex ��ǥ�� �����ϰ� �������� 0.1�� �̵�
			  break;
	case 'A': movex = movex - 0.1;
			  break;

	case 'f': movex = movex + 0.1;    // f �Ǵ� F : 4���� vertex ��ǥ�� �����ϰ� ���������� 0.1�� �̵�
		      break;
	case 'F': movex = movex + 0.1;
		      break;

	case 'r': movey = movey - 0.1;   //r �Ǵ� R : 4���� vertex ��ǥ�� �����ϰ� �Ʒ������� 0.1�� �̵��ϰ� ���������� Polygon ĥ��
			  redcolor = 1.0;
			  greencolor = 0;
			  bluecolor = 0;
		      break;

	case 'R': movey = movey - 0.1;
		      break;
	
	case 'v': movey = movey + 0.1;   //v �Ǵ� V : 4���� vertex ��ǥ�� �����ϰ� �������� 0.1�� �̵�
		      break;
	case 'V': movey = movey + 0.1;
		      break;

	case 'b': redcolor = 0;        //b �Ǵ� B : �Ķ������� Polygon ĥ��  
		      greencolor = 0;
			  bluecolor = 1;
		break;
	case 'B': redcolor = 0;
			  greencolor = 0;
		      bluecolor = 1;
		      break;

	case 'Q': exit(0); break;   //q �Ǵ� Q : ���� 
	case 'q': exit(0); break;
	}
	glutPostRedisplay();  //������ display event �߻� -> ������ �ٲ� ���� �����ϰ� ��
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);   //GLUT library �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB);   //RGB����
	glutInitWindowSize(300, 300);   //������ ũ�� 300 * 300
	glutInitWindowPosition(0, 0);   //������ ��ġ 0,0
	glutCreateWindow("Keyboard Callback");   //���ο� window ����
	MyInit();       //MyInit()�Լ�����
	glutDisplayFunc(MyDisplay);   //MyDisplay �ݹ��Լ� ���
	glutKeyboardFunc(MyKeyboard);   //MyKeyboard �ݹ��Լ� ���
	glutMainLoop();
	return 0;
}