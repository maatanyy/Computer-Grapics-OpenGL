/***********************************************************************/
/*                           HW#1 : 3D Sierpinski Gasket                      */
/*  작성자 : 노민성                             날짜 : 2021년 9월 19일       */
/*                                                                          */
/* 문제 정의 :                                                             */
/*    2D triangle Gasket을 아래와 같은 3D tetrahedron Gasket으로 변경     */
/*                Reshape Callback을 사용하여 왜곡문제 해결              */ 
/* 기능 :                                                               */
/*                2D triangle Gasket을 아래와 같은 3D tetrahedron Gasket으로 변경  
  Reshape Callback 을 사용하여 윈도우의 크기를 바꿔도 왜곡이 안생기도록 함*/
//    https://slideplayer.com/slide/13772155/85/images/39/3D+Sierpinski+Gasket+Program.jpg를 참고하여 좌표를 설정하였고   //
//     reshape 와 나머지 부분들은 강의자료와 수업 동영상을 참고하여 작성하였습니다    //
/***********************************************************************/

#include <GL/glut.h>

void MyDisplay() {
	float vertices[4][3] = { {0.0, 0.0, 0.0}, {250.0, 500.0, 100.0},{500.0, 250.0, 250.0}, {250.0, 100.0, 250.0} };   //vertices[4][3] 선언, 도형의 꼭지점이 됨
	float p[3] = { 250.0,50.0,250.0}; //   찍힐 포인트, 처음 도형의 내부에 임의의 점 하나를 찍음
	int i, j;
	glClear(GL_COLOR_BUFFER_BIT);
	for (j = 0; j <100000; j++) {     //10만번 반복하며 내부에 계속 
		i = rand() % 4;   //임의의 점 선택
		p[0] = (p[0] + vertices[i][0]) / 2.0;  // 새로 선택된 점과 현재 점을 기준으로 새로운 점 위치 계산
		p[1] = (p[1] + vertices[i][1]) / 2.0;  // 새로 선택된 점과 현재 점을 기준으로 새로운 점 위치 계산
		p[2] = (p[2] + vertices[i][2]) / 2.0;  // 새로 선택된 점과 현재 점을 기준으로 새로운 점 위치 계산
		glBegin(GL_POINTS);
		glVertex3fv(p);  //찍힐 위치에 점 찍기
		glEnd();
	}
	glFlush();
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);   //배경 흰색으로 설정
	glColor3f(1.0, 0.0, 0.0);    //그림 빨간색으로 설정
	glMatrixMode(GL_PROJECTION);  //현재 스택을 투영 행렬 스택으로 바꿔주기 위해 사용
	glLoadIdentity();
	glOrtho(0.0, 500.0, 0.0, 500.0, 500, -500); //가시 부피  [0, 500] × [0,500] × [500,-500]
}

void MyReshape(int NewWidth, int NewHeight) {  //윈도우 크기를 변경했을 때 호출 
	glViewport(0, 0, NewWidth, NewHeight);  //viewport 에 새로운 NewWidth 와 NewHeight 지정
	GLfloat Widthfactor = (GLfloat)NewWidth / (GLfloat)500;  //Widthfactor 계산, 원래 윈도우의 크기가 500이었으므로 500으로 나눔
	GLfloat Heightfactor = (GLfloat)NewHeight / (GLfloat)500;  //Heightfactor 계산, 원래 윈도우의 크기가 500이었으므로 500으로 나눔
	glMatrixMode(GL_PROJECTION);  //투영행렬 쓰기위해 지정
	glLoadIdentity();
	glOrtho(0.0 * Widthfactor, 500.0 * Widthfactor, 0.0 *  //위에서 계산한 Widthfactor, Heightfactor 비율 만큼 가시부피를 바꿔줌
		Heightfactor, 500.0 * Heightfactor, 500.0, -500.0);
}

void main(int argc, char** argv)  //메인 함수
{
	glutInit(&argc, argv);  //GLUT library 초기화
	glutInitDisplayMode(GLUT_RGB);  //Display 모드 설정
	glutInitWindowSize(500, 500);  //윈도우 사이즈는 500 * 500
	glutInitWindowPosition(0, 0);   //윈도우 시작좌표 0,0으로 지정
	glutCreateWindow("Sierpinski Gasket"); //새로운 window 생성
	glutDisplayFunc(MyDisplay);  //MyDisplay 콜백함수 등록
	glutReshapeFunc(MyReshape); //MyReshape 함수 등록
	MyInit();  // MyInit() 호출
	glutMainLoop();
}
