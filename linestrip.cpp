/***********************************************************************/
/*                           HW#2-1 : GL_MODELING-2D Primitives 구현              */
/*  작성자 : 노민성                             날짜 : 2021년 9월 24일           */
/*                                                                              */
/* 문제 정의 :                                                                 */
/*   Points, Lines, LineStrip, LineLoop, TrangleFan, Triangles, TriangleStrip */
/*                Polygons, Quads, QuadStrip 구현                            */
/* 기능 :                                                                   */
/*       2D triangle Gasket을 아래와 같은 3D tetrahedron Gasket으로 변경   */
//       z 값은 모두 0으로 지정하고, x축과 y축 값만 고려                  //
/*************************************************************************/

#include <GL/glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);   //배경을 하얀색으로 설정하였습니다
	glColor3f(1.0, 0, 0);                //빨간색으로 설정하여 잘보이게 하였습니다

	// *** GL_LINE_STRIP 입니다 
	glBegin(GL_LINE_STRIP);   //연결된 성분 점을 추가할때마다 계속 연결됨
	glVertex3f(-0.25, -0.5, 0.0);  // 각 점의 좌표를 설정하여줌 v0~v5
	glVertex3f(0.25, -0.5, 0.0);    //GL_LINE_STRIP는 연결된 선분을 그리는 방법으로 선분의 끝점이 다음 선분의 시작점이 됨, 마지막 점이 처음 시잠점과 연결되지는 않음
	glVertex3f(0.5, 0.0, 0.0);      
	glVertex3f(0.25, 0.5, 0.0);
	glVertex3f(-0.25, 0.5, 0.0);
	glVertex3f(-0.5, 0.0, 0.0);

	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);     //GLUT library 초기화
	glutCreateWindow("GLUT Modeling Test");   //새로운 window 생성
	glutDisplayFunc(MyDisplay);  //MyDisplay 콜백함수 등록
	glutMainLoop();
	return 0;
}