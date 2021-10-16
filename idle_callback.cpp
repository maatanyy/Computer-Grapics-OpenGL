/***********************************************************************/
/*                           HW#3-5 : Idle callback 응용2             */
/*  작성자 : 노민성                             날짜 : 2021년 10월 1일           */
/*                                                                              */
/* 문제 정의 :                                                                 */
/*  ↑ : 4개의 vertex 좌표가 동일하게 위쪽으로 0.1씩 이동
	↓ : 4개의 vertex 좌표가 동일하게 아래쪽으로 0.1씩 이동
	← : 4개의 vertex 좌표가 동일하게 왼쪽으로 0.1씩 이동
	→ : 4개의 vertex 좌표가 동일하게 오른쪽으로 0.1씩 이동

*/
/* 기능 :                                                                   */
/*      각각의 Idle callback을 정의하고 누르는 키에 따라 작동을 하게 하였습니다
			0.1로 할시 속도가 너무 빨라 변화가 잘보이지 않아 속도를 조금 조절하였습니다 */
																						 //                       //
/*************************************************************************/

#include <GL/glut.h>
#include <stdio.h>

GLdouble left = 0.0, right = 0.0, up = 0.0, down = 0.0;  //움직임에 이동할 변수 선언 및 초기화

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 0.8);
	glVertex3f(-1.0 + left, -0.5 + down, 0.0);   //POLYGON의 4좌표 설정
	glVertex3f(0.0 + right, -0.5 + down, 0.0);
	glVertex3f(0.0 + right, 0.5 + up, 0.0);
	glVertex3f(-1.0 + left, 0.5 + up, 0.0);
	glEnd();
	glutSwapBuffers();
}

void MyIdle() {   //MyIdle 정의
	if (right < 1.0) {   //오른쪽이 벽에 닿지 않으면 계속 오른쪽으로 움직이게 하였습니다
		right = right + 0.001;
		left = left + 0.001;
	}
	glutPostRedisplay();
}

void MyIdle2() {  //MyIdle2 정의
	if (left > 0.0) {  //왼쪽이 벽에 닿지 않으면 계속 왼쪽으로 움직이게 하였습니다
		left = left - 0.001;
		right = right - 0.001;
	}
	glutPostRedisplay();
}

void MyIdle3() {  //MyIdle3 정의
	if (down > -0.5) {   //아래쪽이 벽에 닿지 않으면 계속 아래쪽으로 움직이게 하였습니다
		down = down - 0.001;   //up, down을 각각 0.1씩 줄였습니다
		up = up - 0.001;
	}
	glutPostRedisplay();
}

void MyIdle4() {   //MyIdle4 정의
	if (up < 0.5) {   //위쪽이 벽에 닿지 않으면 계속 위쪽으로 움직이게 하였습니다
		up = up + 0.001;    //up, down을 각각 0.1씩 올렸습니다
		down = down + 0.001;
	}
	glutPostRedisplay();
}

void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:    // ← : 4개의 vertex 좌표가 동일하게 왼쪽으로 0.1씩 이동
		glutIdleFunc(MyIdle2);  //MyIdle2 실행
		break;

	case GLUT_KEY_UP:   // ↑ : 4개의 vertex 좌표가 동일하게 위쪽으로 0.1씩 이동
		glutIdleFunc(MyIdle4);  //MyIdle4 실행
		break;

	case GLUT_KEY_DOWN:   //  ↓ : 4개의 vertex 좌표가 동일하게 아래쪽으로 0.1씩 이동
		glutIdleFunc(MyIdle3);  //MyIdle3 실행
		break;

	case GLUT_KEY_RIGHT: //  → : 4개의 vertex 좌표가 동일하게 오른쪽으로 0.1씩 이동
		glutIdleFunc(MyIdle);  //MyIdle 실행
		break;

	default:
		break;
	}
	glutPostRedisplay();  //강제로 display event 발생 -> 위에서 바꾼 설정 적용하게 함
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);   //GLUT library 초기화
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);   //RGB설정, 더블버퍼
	glutInitWindowSize(300, 300);  //윈도우 크기 설정
	glutInitWindowPosition(0, 0);  //윈도우 위치 설정
	glutCreateWindow("Idle Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);  //MyDisplay함수 등록
	glutIdleFunc(MyIdle);  //MyIdle 실행
	glutSpecialFunc(MySpecial);  //MySpecial 함수 등록
	glutMainLoop();
	return 0;
}

