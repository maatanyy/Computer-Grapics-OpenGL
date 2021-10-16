#include <GL/glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);   //배경을 하얀색으로 설정하였습니다
	glColor3f(1.0, 0, 0);                //빨간색으로 설정하여 잘보이게 하였습니다

	// *** GL_POINTS 입니다
	glPointSize(10.0);       //GL_POINT 의 크기를 10으로함
	glBegin(GL_POINTS);        //GL_POINTS를 사용하여 점을 찍음
	glVertex3f(-0.25, -0.5, 0.0);  //각 점의 좌표를 설정하여줌 v0~v5
	glVertex3f(0.25, -0.5, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.25, 0.5, 0.0);
	glVertex3f(-0.25, 0.5, 0.0);
	glVertex3f(-0.5, 0.0, 0.0);

	//// *** GL_LINES 입니다 
	//glBegin(GL_LINES);      //두개의 정점들을 이어 선분을 만듬
	//glVertex3f(-0.25, -0.5, 0.0);  // 각 점의 좌표를 설정하여줌 v0~v5
	//glVertex3f(0.25, -0.5, 0.0);
	//glVertex3f(0.5, 0.0, 0.0);
	//glVertex3f(0.25, 0.5, 0.0);
	//glVertex3f(-0.25, 0.5, 0.0);
	//glVertex3f(-0.5, 0.0, 0.0);

	//// *** GL_LINE_STRIP 입니다 
	//glBegin(GL_LINE_STRIP);   //연결된 성분 점을 추가할때마다 계속 연결됨
	//glVertex3f(-0.25, -0.5, 0.0);  // 각 점의 좌표를 설정하여줌 v0~v5
	//glVertex3f(0.25, -0.5, 0.0);
	//glVertex3f(0.5, 0.0, 0.0);
	//glVertex3f(0.25, 0.5, 0.0);
	//glVertex3f(-0.25, 0.5, 0.0);
	//glVertex3f(-0.5, 0.0, 0.0);

	//// *** GL_LINE_LOOP 입니다 
	//glBegin(GL_LINE_LOOP);    //시작점과 끝점을 이어주는 선분, vertex를 추가하면 그 점도 이어줌
	//glVertex3f(-0.25, -0.5, 0.0);  // 각 점의 좌표를 설정하여줌 v0~v5
	//glVertex3f(0.25, -0.5, 0.0);
	//glVertex3f(0.5, 0.0, 0.0);
	//glVertex3f(0.25, 0.5, 0.0);
	//glVertex3f(-0.25, 0.5, 0.0);
	//glVertex3f(-0.5, 0.0, 0.0);

	//// *** GL_POLYGON 입니다 
	//glBegin(GL_POLYGON);   //정점을 이어주는 연결된 블록 다각형을 만듬
	//glVertex3f(-0.25, -0.5, 0.0);  // 각 점의 좌표를 설정하여줌 v0~v5
	//glVertex3f(0.25, -0.5, 0.0);
	//glVertex3f(0.5, 0.0, 0.0);
	//glVertex3f(0.25, 0.5, 0.0);
	//glVertex3f(-0.25, 0.5, 0.0);
	//glVertex3f(-0.5, 0.0, 0.0);

	//// *** GL_TRIANGLES 입니다 
	//glBegin(GL_TRIANGLES);    //정점을 세개씩 이어서 삼각형을 만들어줍니다
	//glVertex3f(-0.25, -0.5, 0.0);  // 각 점의 좌표를 설정하여줌 v0~v5
	//glVertex3f(0.25, -0.5, 0.0);
	//glVertex3f(0.5, 0.0, 0.0);
	//glVertex3f(0.25, 0.5, 0.0);
	//glVertex3f(-0.25, 0.5, 0.0);
	//glVertex3f(-0.5, 0.0, 0.0);

	//// *** GL_TRIANGLE_STRIP 입니다 
	//glBegin(GL_TRIANGLE_STRIP);    //정점을 계속 연결해가며 연결된 삼각형을 만들어줍니다
	//glVertex3f(0.75, -0.5, 0.0);  // 각 점의 좌표를 설정하여줌 v0~v6
	//glVertex3f(0.5, 0.3, 0.0);
	//glVertex3f(0.25, -0.2, 0.0);
	//glVertex3f(-0.1, 0.3, 0.0);
	//glVertex3f(-0.4, -0.3, 0.0);
	//glVertex3f(-0.7, 0.1, 0.0);
	//glVertex3f(-0.9, -0.4, 0.0);

	//// *** GL_TRIANGLE_FAN 입니다
	//glBegin(GL_TRIANGLE_FAN);    //정점을 계속 연결해가며 중심을 공유하는 연결된 삼각형을 만들어줍니다
	//glVertex3f(-0.5, -0.3, 0.0);  // 각 점의 좌표를 설정하여줌 v0~v5
	//glVertex3f(0.5, -0.15, 0.0);
	//glVertex3f(0.4, 0.0, 0.0);
	//glVertex3f(0.35, 0.2, 0.0);
	//glVertex3f(0.0, 0.5, 0.0);
	//glVertex3f(-0.3, 0.55, 0.0);

	//// *** GL_QUADS 입니다
	//glBegin(GL_QUADS);    //정점을 네개씩 연결해가며 사각형을 만들어줍니다
	//glVertex3f(0.3, -0.15, 0.0);  // 각 점의 좌표를 설정하여줌 v0~v7
	//glVertex3f(0.4, 0.0, 0.0);  
	//glVertex3f(0.15, 0.1, 0.0);  
	//glVertex3f(0.0, -0.15, 0.0);  
	//glVertex3f(-0.1, 0.0, 0.0);  
	//glVertex3f(-0.05, 0.3, 0.0); 
	//glVertex3f(-0.3, 0.25, 0.0);  
	//glVertex3f(-0.35, 0.15, 0.0);  

	//// *** GL_QUADS_STRIP 입니다
	//glBegin(GL_QUAD_STRIP);    //정점을 연결해가며 연결된 사각형을 만들어줍니다
	//glVertex3f(0.3, -0.15, 0.0);  // 각 점의 좌표를 설정하여줌 v0~v7
	//glVertex3f(0.4, 0.0, 0.0);   
	//glVertex3f(0.0, -0.15, 0.0);  
	//glVertex3f(0.15, 0.1, 0.0);   
	//glVertex3f(-0.1, 0.0, 0.0);   
	//glVertex3f(-0.05, 0.3, 0.0);   
	//glVertex3f(-0.35, 0.15, 0.0);
	//glVertex3f(-0.3, 0.25, 0.0);
	

	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}