/***********************************************************************/
/*                           HW#3-3 : mouse callback 응용             */
/*  작성자 : 노민성                             날짜 : 2021년 10월 1일           */
/*                                                                              */
/* 문제 정의 :                                                                 */
/*  마우스 왼쪽 버튼을 click
	 4개의 vertex 좌표가 동일하게 오른쪽으로 0.1씩 연속적으로 이동
	• 마우스 오른쪽 버튼을 click
	 이동하고 있는 Polygon이 멈춤

*/
/* 기능 :                                                                   */
/*      각각의 Idle callback을 정의하고 누르는 키에 따라 작동을 하게 하였습니다
			0.1로 할시 속도가 너무 빨라 변화가 잘보이지 않아 속도를 조금 조절하였습니다 */
			//          오른쪽 벽에 닿을 시 왼쪽으로 다시 이동하고, 왼쪽 벽에 닿을시 다시 오른쪽으로 이동하게 하였습니다             //
/*************************************************************************/
#include <GL/glut.h>
#include <stdio.h>

float right = 0.0, left = 0.0; //이용할 변수 선언 및 초기화
void MyIdle2();   //사용할 Idle 함수 선언 
void MyIdle();
void MyIdle3();

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5 + left, -0.5, 0.0);   //각 POLYGON 좌표 설정
	glVertex3f(0.5 + right, -0.5, 0.0);
	glVertex3f(0.5 + right, 0.5, 0.0);
	glVertex3f(-0.5 + left, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'Q': exit(0); break;  //q누를시 프로그램 종료
	case 'q': exit(0); break;
	case 27: exit(0); break;
	}
	glutPostRedisplay();
}


void MyIdle() {   //MyIdle 정의
		if (right<0.5) {   //오른쪽이 벽에 닿지 않으면 계속 오른쪽으로 움직이게 하였습니다
			right = right + 0.0001;  //0.0001씩 right left 오른쪽으로 이동
			left = left + 0.0001;
		}
		else if (right >= 0.5) {  //만약 벽에 닿으면
			glutIdleFunc(MyIdle2);  //MyIdle2 호출
		}
	glutPostRedisplay();  //바로 적용
}

void MyIdle2() {  //MyIdle2 정의
	if (left > -0.5) {  //왼쪽이 벽에 닿지 않으면 계속 왼쪽으로 움직이게 하였습니다
		left = left - 0.0001;  //0.0001씩 right left 왼쪽으로 이동
		right = right - 0.0001;
	}
	else if (left < -0.5) {  //만약 왼쪽벽에 닿으면
		glutIdleFunc(MyIdle);  //오른쪽으로 이동하는 MyIdle 호출
	}
	glutPostRedisplay();  //바로 적용
}

void MyIdle3() {  //MyIdle3 정의
	left = left;    //left 와 right를 같게 해서 멈추게함
	right = right;
	glutPostRedisplay();  //바로 적용
}

void mouseCallback(int button, int state, int x, int y) {
	if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN)) {  //마우스 오른쪽이 클릭되었을 때
		glutIdleFunc(MyIdle3);   //멈춤
	}
	else if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {  //마우스 왼쪽이 클릭되었을 때
		glutIdleFunc(MyIdle);  //MyIdle 실행 (오른쪽으로 이동) 
	}
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);  //GLUT library 초기화
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);  //RGB설정, 더블버퍼
	glutInitWindowSize(300, 300);  //윈도우 크기 설정
	glutInitWindowPosition(0, 0);  //윈도우 위치 설정
	glutCreateWindow("Keyboard Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);   //MyDisplay함수 등록
	glutKeyboardFunc(MyKeyboard);  //MyKeyboard 함수 등록

	glutMouseFunc(mouseCallback);  //mouseCallback 함수 등록

	glutMainLoop();
	return 0;
}