/***********************************************************************/
/*                           HW#3-2 : keyboard callback ����2             */
/*  �ۼ��� : ��μ�                             ��¥ : 2021�� 9�� 29��           */
/*                                                                              */
/* ���� ���� :                                                                 */
/*  �� : 4���� vertex ��ǥ�� �����ϰ� �������� 0.1�� �̵�
	�� : 4���� vertex ��ǥ�� �����ϰ� �Ʒ������� 0.1�� �̵�
	�� : 4���� vertex ��ǥ�� �����ϰ� �������� 0.1�� �̵�
	�� : 4���� vertex ��ǥ�� �����ϰ� ���������� 0.1�� �̵�
	PageUp : 4���� vertex ��ǥ�� �̷���� Polygon�� �� �������� 0.1��
	���������� Ȯ��(Zoom In)
	PageDown : 4���� vertex ��ǥ�� �̷���� Polygon�� �� �������� 0.1��
	���������� ���(Zoom Out)
               */
	/* ��� :                                                                   */
	/*      left,right,up,down�� �����Ͽ� �� Ű�� �°� �����ϼ� �ֵ��� �Ͽ����ϴ�.
			�׸��� ���ǹ��� ���� ���� �Ѿ�� �ʵ��� �Ͽ����ϴ�. 
			                                                                  */
	//                       //
	/*************************************************************************/
#include <GL/glut.h>

GLdouble left = 0.0, right = 0.0, up = 0.0, down = 0.0, count = 5;    // x ,y �� ������ ���� ���� ���� ó���� 0���� �ʱ�ȭ,
//�ּҷ� �پ��� ������°��� �����ϱ� ���� count �߰�


void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);  //��������
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);  //glOrtho ����
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);  //POLYGON �� ����
	glBegin(GL_POLYGON);
	glVertex3f(-0.5 + left, -0.5 + down, 0.0);  // POLYGON ���� �Ʒ� ��ǥ
	glVertex3f(0.5 + right, -0.5 + down, 0.0);   // POLYGON ������ �Ʒ� ��ǥ
	glVertex3f(0.5 + right, 0.5 + up, 0.0);    // POLYGON ������ �� ��ǥ
	glVertex3f(-0.5 + left, 0.5 + up, 0.0);   // POLYGON ���� �� ��ǥ
	glEnd();
	glFlush();
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'Q': exit(0); break;   //q �Ǵ� Q : ���� 
	case 'q': exit(0); break;
	case 27: exit(0); break;
	}
	glutPostRedisplay();   //������ display event �߻� -> ������ �ٲ� ���� �����ϰ� ��
}

void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:    // �� : 4���� vertex ��ǥ�� �����ϰ� �������� 0.1�� �̵�
		if (left > -0.5) {     
			left = left - 0.1;     //left ,right �� ���� 0.1�� �ٿ����ϴ�
			right = right - 0.1;
		}
		break;
	
	case GLUT_KEY_UP:   // �� : 4���� vertex ��ǥ�� �����ϰ� �������� 0.1�� �̵�
		if (up < 0.5) {
			up = up + 0.1;    //up, down�� ���� 0.1�� �÷Ƚ��ϴ�
			down = down + 0.1;
		}
		break;

	case GLUT_KEY_DOWN:   //  �� : 4���� vertex ��ǥ�� �����ϰ� �Ʒ������� 0.1�� �̵�
		if (down > -0.5) {
			down = down - 0.1;   //up,down�� ���� 0.1�� �ٿ����ϴ�
			up = up - 0.1;
		}
		break;

	case GLUT_KEY_RIGHT: //  �� : 4���� vertex ��ǥ�� �����ϰ� ���������� 0.1�� �̵�
		if (right < 0.5) {
			right = right + 0.1;  //right, left �� ���� 0.1�� �÷Ƚ��ϴ�
			left = left + 0.1;
		}
		break;

	case GLUT_KEY_PAGE_UP:  //  PageUp : 4���� vertex ��ǥ�� �̷���� Polygon�� �� �������� 0.1�� 	���������� Ȯ��(Zoom In)
		if ((right < 0.5) && (up < 0.5) && (down > -0.5) && (left > -0.5)) {
			count = count + 1;  //Ȯ���ϸ� ī��Ʈ 1����
			right = right + 0.1; //right,up�� 0.1�� �ø��� left,down �� 0.1�� �ٿ����ϴ�
			up = up + 0.1;
			left = left - 0.1;
			down = down - 0.1;
		}
		break;
	
	case GLUT_KEY_PAGE_DOWN:  //PageDown : 4���� vertex ��ǥ�� �̷���� Polygon�� �� �������� 0.1�� ���������� ���(Zoom Out)
		if (count==0) {  //�ּҷ� �پ�� ��� ���̻� ���پ��� ��
			right = right;
			up = up;
			left = left;
			down = down;
			break;
		}

		else if ((right <= 0.5) && (up <= 0.5) && (down >= -0.5) && (left >= -0.5)) {  //�ε�ȣ�� �߰��Ͽ� ������ ���� �������� �پ��� �ְ��Ͽ����ϴ�.
			count = count - 1;   //����ϸ� ī��Ʈ�� �ϳ� ����
			right = right - 0.1;  //right up�� 0.1�� ���̰� left, down�� 0.1�� �÷Ƚ��ϴ�
			up = up - 0.1;
			left = left + 0.1;
			down = down + 0.1;
		}
		break;
			

	default:
		break;
	}
	glutPostRedisplay();  //������ display event �߻� -> ������ �ٲ� ���� �����ϰ� ��
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);  //GLUT library �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB);  //RGB����
	glutInitWindowSize(300, 300);  //������ ũ�� 300 * 300
	glutInitWindowPosition(0, 0);  //������ ��ġ 0,0
	glutCreateWindow("Keyboard Callback");  //���ο� window ����
	MyInit();   //MyInit()�Լ�����
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial);  //MySpecial �Լ� ���
	glutMainLoop();
	return 0;
}
