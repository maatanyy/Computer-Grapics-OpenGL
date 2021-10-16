/***********************************************************************/
/*                           HW#3-6 : timer callback 응용             */
/*  작성자 : 노민성                             날짜 : 2021년 10월 1일           */
/*                                                                              */
/* 문제 정의 :                                                                 */
/*  프로그램이 실행되면 코드5-8에 있는 도형이 오른쪽으로 0.1씩 연속적으로 움
	직이게 하고, 오른쪽 경계에 부딪히면 도형의 색깔이 변하게 한 후, 다시 도형
	이 왼쪽으로 0.1씩 연속적으로 움직이는 과정을 반복함.
	? 마우스 왼쪽 키를 누르면 움직이는 도형이 멈춤.
*/
/* 기능 :                                                                   */
/*      각각의 Idle callback을 정의하고 누르는 키에 따라 작동을 하게 하였습니다
		0.1로 할시 속도가 너무 빨라 변화가 잘보이지 않아 속도를 조금 조절하였습니다 */
//          오른쪽 벽에 닿을 시 왼쪽으로 다시 이동하고, 왼쪽 벽에 닿을시 다시 오른쪽으로 이동하게 하였습니다  
//		벽에 닿을 때 마다 색이 바뀌도록 설정하였으며 마우스 왼쪽 키를 누르면 도형이 멈춥니다 //
/*************************************************************************/
#include <GL/glut.h>
#include<stdio.h>

GLfloat right = 0.0, left =0.0;  //도형의 움직이에 이용할 변수 선언
GLfloat red = 0.0, green = 0.5, blue = 0.8;  //초기 색 설정
void MyIdle2();   //사용할 Idle 함수 선언 
void MyIdle();
void MyIdle3();

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(red,green,blue);
	glVertex3f(-1.0 + left, -0.5, 0.0);  //POLYGON vertex 선언
	glVertex3f(0.0 + right, -0.5, 0.0);
	glVertex3f(0.0 + right, 0.5, 0.0);
	glVertex3f(-1.0 + left, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();
}

void MyIdle() {   //MyIdle 정의
	if (right < 1.0) {   //오른쪽이 벽에 닿지 않으면 계속 오른쪽으로 움직이게 하였습니다
		right = right + 0.0001;  //0.0001씩 right left 오른쪽으로 이동
		left = left + 0.0001;
	}
	else if (right >= 1.0) {  //만약 벽에 닿으면
		red = 1.0;  //색을 바꿈
		green = 0.0;
		blue = 0.0;
		glutIdleFunc(MyIdle2);  //MyIdle2 호출
	}
	glutPostRedisplay();  //바로 적용
}

void MyIdle2() {  //MyIdle2 정의
	if (left > 0) {  //왼쪽이 벽에 닿지 않으면 계속 왼쪽으로 움직이게 하였습니다
		left = left - 0.0001;  //0.0001씩 right left 왼쪽으로 이동
		right = right - 0.0001;
	}
	else if (left < 0) {  //만약 왼쪽벽에 닿으면
		red = 0.0;   //색을 바꿈
		green = 0.5;
		blue = 0.8;
		glutIdleFunc(MyIdle);  //오른쪽으로 이동하는 MyIdle 호출
	}
	glutPostRedisplay();  //바로 적용
}

void MyIdle3() {  //MyIdle3 정의
	left = left;    //left 와 right를 같게 해서 멈추게함
	right = right;
	glutPostRedisplay();  //바로 적용
}

void MyTimer(int value) {    //타이머 함수 정의
	glutIdleFunc(MyIdle);   //MyIdle 함수 실행
	glutPostRedisplay();
}void mouseCallback(int button, int state, int x, int y) {   //mouseCallback 함수 정의
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {  //마우스 왼쪽이 클릭되었을 때
		glutIdleFunc(MyIdle3);   //멈춤
	}
}void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);   //GLUT library 초기화
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);   //RGB설정, 더블버퍼
	glutInitWindowSize(300, 300);  //윈도우 크기 설정
	glutInitWindowPosition(0, 0);   //윈도우 위치 설정
	glutCreateWindow("Timer Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);   //MyDisplay 함수 등록
	glutMouseFunc(mouseCallback);  //mouseCallback 함수 등록
	glutTimerFunc(40, MyTimer, 1); //TimerFunc 사용
	glutMainLoop();
	return 0;
}