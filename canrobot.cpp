/***********************************************************************/
/*                           HW#4-2 : ���� Can Robot �𵨸�             */
/*  �ۼ��� : ��μ�                             ��¥ : 2021�� 10�� 16��           */
/*                                                                              */
/* ���� ���� :                                                                 */
/*  �Ʒ��� ���� �κ��� �̹����� �����ϰ�, ���ݱ��� ��� �𵨸� ����� ����Ͽ� �ִ��� �����ϰ� ����(Full Body)�� �𵨸�
���� �ڼ��� �ʱ� �⺻�ڼ��� �����Ͽ� �𵨸�
�޴� ����
<�Ӹ� �����̱�>
<������ �����̱�>
<������ �����̱�>
<�����ٸ� �����̱�>
<���ʴٸ� �����̱�>
�޴� Ŭ��
�ش� �޴��� �´� ��ü�� �ѹ� �������ٰ� ���� �ڼ��� ���ƿ� S ������ �����̴� ��ü�� ����
*/
/* ��� :                                                                   */
/*    ������ ���콺 ������ �޴��� ������ �����Ͽ��� �Ӹ��� ��� ���������� �������� ���� ���·� ���ƿ��� �����Ͽ����ϴ� 
������ �� �ٸ��� ��� ���� ���� �����̸� ���� ���·� ���ƿ��� �Ͽ��� S ��ư ������ ��� ���߰� �Ͽ����ϴ� //
/*************************************************************************/

#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>

float body = 0, rightarm = 0, rightarm2 = 0, leftarm = 0, leftarm2 = 0, rightleg = 0, rightleg2 = 0, leftleg = 0, leftleg2 = 0, neck = 0,eye=0, head=0;
//�� rotate���� �̵��� ����� �����̰� 0���� �ʱ�ȭ �� �����Ͽ����ϴ�
int neckchange = 1, rightarmchange = 1, leftarmchange = 1, rightlegchange=1, leftlegchange=1;
//�̵��ϸ� �ִ� ���� ������ ���� ��ȯ�� �ϱ� ���� ������ �����Դϴ� ó���� 1�� �����Ͽ����ϴ�
bool stop_1 = false, stop_2 = false, stop_3 = false, stop_4 = false, stop_5 = false;  //�� bool�� true �̸� ����ϴ�, flase�� ��� �����̰� �մϴ�
GLUquadricObj* qobj = gluNewQuadric();  //���ο� Quadric ����

//����� �Լ� ����, 
void Timer6(int value);
void Stop1(int value);
void Stop2(int value);
void Stop3(int value);
void Stop4(int value);
void Stop5(int value);

void Timer1(int value) {   //�Ӹ������ӿ� ���õ� Ÿ�̸� �Դϴ�
    if (stop_1 == true) {  //����  bool�� ���� true �� ��� ����ϴ�
        neck = neck;
        eye = eye;
        head = head;
    }
    else {  //bool�� ���� false �� ���, �����Դϴ�
        if (neckchange == 1) {   //change�� 1�ϰ��� ���������� �����Դϴ�
            neck = neck + 0.5;
            eye = eye + 0.2;
            head = head + 0.2;
        }
        else if (neckchange == -1) {  //���� change�� ������ �������� �����Դϴ�
            neck = neck - 0.5;
            eye = eye - 0.2;
            head = head - 0.2;
        }
        if (neck >= 20.00000) {  //�̵������� �Ѿ�� change�� ��ȣ�� �ٲ��ݴϴ�
            neckchange = -1;
        }
        if (neck <= 0.00000) {  //ó�����·� ���ƿ��� ���ߴ� �Լ��� ȣ���մϴ�
            neckchange = 1;
            glutTimerFunc(40, Stop1, 1);
        }
        glutPostRedisplay();   //��� ��ȭ�������ϸ� �ٽ� Ÿ�̸Ӹ� ȣ���մϴ�
        glutTimerFunc(40, Timer1, 1);
    }
}

void Timer2(int value) {     //������ �����ӿ� ���� Ÿ�̸��Դϴ�. 
    if (stop_2 == true) {    //����  bool�� ���� true �� ��� ����ϴ�
        rightarm = rightarm;
        rightarm2 = rightarm2;
    }
    else {   //bool�� ���� false �� ���, �����Դϴ�
        if (rightarmchange == 1) {     //change�� 1�� ��� ���������� �����Դϴ�
            rightarm = rightarm - 0.7;
            rightarm2 = rightarm2 - 0.3;      
        }
        else if (rightarmchange == -1) {  //���� change�� --1�̸� �������� �����Դϴ�
            rightarm = rightarm + 0.7;
            rightarm2 = rightarm2 + 0.3;
        }
        if (rightarm >= 0.00000) {   //ó�����·� ���ƿ��� ���ߴ� �Լ��� ȣ���մϴ�
            rightarmchange = 1;
            glutTimerFunc(40, Stop2, 1);
        }
        if (rightarm <= -20.00000) {   //���� �̵������� �����ϸ� �̵������� �ٲ��ݴϴ�
            rightarmchange = -1;
        }
        glutPostRedisplay();   //��� ��ȭ�������ϸ� �ٽ� Ÿ�̸Ӹ� ȣ���մϴ�
        glutTimerFunc(40, Timer2, 1);
    }
}

void Timer3(int value) {  //���� �����ӿ� ���� Ÿ�̸��Դϴ�
    if (stop_3 == true) {   //����  bool�� ���� true �� ��� ����ϴ�
        leftarm = leftarm;
        leftarm2 = leftarm2;
    }
    else {   //bool�� ���� false �� ���, �����Դϴ�
        if (leftarmchange == 1) {   //ó���� �������� �����Դϴ�
            leftarm = leftarm + 0.7;
            leftarm2 = leftarm2 + 0.3;
        }
        else if (leftarmchange == -1) {  //���� change�� -1�̸� ���������� �����Դϴ�
            leftarm = leftarm - 0.7;
            leftarm2 = leftarm2 - 0.3;
        }
        if (leftarm >= 20.00000) {  //������ �̵������� �Ѿ�� �̵������� �ٲ��ݴϴ�
            leftarmchange = -1;
        }
        if (leftarm <= 0.00000) {  //ó�����·� ���ƿ��� stop�� ȣ�����ݴϴ�
            leftarmchange = 1;
            glutTimerFunc(40, Stop3, 1);
        }
        glutPostRedisplay();   //�̵��� �ٷ� �����ϰ� Ÿ�̸Ӹ� ȣ���մϴ�
        glutTimerFunc(40, Timer3, 1);
    }
}

void Timer4(int value) {  //������ �ٸ� �����ӿ� ���� Ÿ�̸��Դϴ�
    if (stop_4 == true) {    //����  bool�� ���� true �� ��� ����ϴ�
        rightleg = rightleg;
        rightleg2 = rightleg2;
    }
    else {   //bool�� ���� false �� ���, �����Դϴ�
        if (rightlegchange == 1) {   //change�� 1�� ��� ���������� �����Դϴ�
            rightleg = rightleg - 0.5;
            rightleg2 = rightleg2 + 0.3;
        }
        else if (rightlegchange == -1) {  //change�� -1�ϰ�� �������� �����Դϴ�
            rightleg = rightleg + 0.5;
            rightleg2 = rightleg2 - 0.3;
        }
        if (rightleg > 0.00000) {  //ó������ ���ƿ��� ���ߴ� �Լ��� ȣ���մϴ�
            rightlegchange = 1;
            glutTimerFunc(40, Stop4, 1);
        }
        if (rightleg <= -30.00000) {  //���������� ����� �̵������� �ٲ��ݴϴ�
            rightlegchange = -1;
        }
        glutPostRedisplay();  //�ٷ� �����ϰ��ϰ� Ÿ�̸Ӹ� �ٽ� ȣ���մϴ�
        glutTimerFunc(40, Timer4, 1);
    }
}

void Timer5(int value) {  //���� �ٸ� �����ӿ� ���� Ÿ�̸��Դϴ�
    if (stop_5 == true) {   //����  bool�� ���� true �� ��� ����ϴ�
        leftleg = leftleg;
        leftleg2 = leftleg2;
    }
    else {    //bool�� ���� false �� ���, �����Դϴ�
        if (leftlegchange == 1) {   //change �� 1�ϰ�� �������� �����Դϴ�
            leftleg = leftleg + 0.5;
            leftleg2 = leftleg2 - 0.3;
        }
        else if (leftlegchange == -1) {  //���� change�� -1�̸� ���������� �����Դϴ�
            leftleg = leftleg - 0.5;
            leftleg2 = leftleg2 + 0.3;
        }
        if (leftleg >= 30.00000) {  //������ ���������� ����� �̵������� �ٲ��ݴϴ�
            leftlegchange = -1;
        }
        if (leftleg <= 0.00000) {  //ó�����·� ���ƿ��� �����ݴϴ�
            leftlegchange = 1;
            glutTimerFunc(40, Stop5, 1);
        }
        glutPostRedisplay();  //�ٷ� ��������ְ� Ÿ�̸Ӹ� ȣ�����ݴϴ�
        glutTimerFunc(40, Timer5, 1);
    }
}

void Stop1(int value) {  //�Ӹ������̴°� ���ߴ� �Լ��Դϴ�
    stop_1 = true;  //stop_1�� true�� ���ְ� �����Ű�� Ÿ�̸Ӹ� ȣ���մϴ�
    glutPostRedisplay();
    glutTimerFunc(40, Timer1, 1);
} 
void Stop2(int value) { //�������� �����̴°� ���ߴ� �Լ��Դϴ�
    stop_2= true;   //stop_2�� true�� ���ְ� �����Ű�� Ÿ�̸Ӹ� ȣ���մϴ�
    glutPostRedisplay();
    glutTimerFunc(40, Timer2, 1);
}
void Stop3(int value) { //�������� �����̴°� ���ߴ� �Լ��Դϴ�
    stop_3 = true;   //stop_3�� true�� ���ְ� �����Ű�� Ÿ�̸Ӹ� ȣ���մϴ�
    glutPostRedisplay();
    glutTimerFunc(40, Timer3, 1);
}
void Stop4(int value) { //������ �ٸ��� �����̴°� ���ߴ� �Լ��Դϴ�
    stop_4 = true;   //stop_4�� true�� ���ְ� �����Ű�� Ÿ�̸Ӹ� ȣ���մϴ�
    glutPostRedisplay();
    glutTimerFunc(40, Timer4, 1);
}
void Stop5(int value) { //���� �ٸ��� �����̴°� ���ߴ� �Լ��Դϴ�
    stop_5 = true;  //stop_5�� true�� ���ְ� �����Ű�� Ÿ�̸Ӹ� ȣ���մϴ�
    glutPostRedisplay();
    glutTimerFunc(40, Timer5, 1);
}

void Timer6(int value) {   //��δ� ���ߴ� timer�Դϴ� ��� stop_�� true�� �� �� ��� Ÿ�̸Ӹ� ȣ���մϴ�
    stop_1 = true;
    stop_2 = true;
    stop_3 = true;
    stop_4 = true;
    stop_5 = true;
    glutPostRedisplay();
    glutTimerFunc(40, Timer1, 1);
    glutTimerFunc(40, Timer2, 1);
    glutTimerFunc(40, Timer3, 1);
    glutTimerFunc(40, Timer4, 1);
    glutTimerFunc(40, Timer5, 1);
}

void MyMainMenu(int entryID) {  //�޴���Ͽ� ���� �Լ��Դϴ�
    if (entryID == 1) {  //�Ӹ� �����̱�
        stop_1 = false;   //bool false�� �ٲ��༭ �����̰���
        glutTimerFunc(40, Timer1, 1);
    }
    else if (entryID == 2) {  //������ �����̱�
        stop_2 = false; //bool false�� �ٲ��༭ �����̰���
        glutTimerFunc(40, Timer2, 1);
    }
    else if (entryID == 3) {  //������ �����̱�
        stop_3 = false; //bool false�� �ٲ��༭ �����̰���
        glutTimerFunc(40, Timer3, 1);
    }
    else if (entryID == 4) {  //�����ٸ� �����̱�
        stop_4 = false; //bool false�� �ٲ��༭ �����̰���
        glutTimerFunc(40, Timer4, 1);
    }
    else if (entryID == 5) {  //���ʴٸ� �����̱�
        stop_5 = false; //bool false�� �ٲ��༭ �����̰���
        glutTimerFunc(40, Timer5, 1);
    }
    glutPostRedisplay();
}

void MyInit(void) {  //�ʱ� �����Դϴ�
    glClearColor(0.0, 0.0, 0.0, 1.0);  //�������� �� ���������� ���� 
    glShadeModel(GL_FLAT);
    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);  //�޴����
    glutAddMenuEntry("Move Head", 1);  //���� �̸��� ID�������ݴϴ�
    glutAddMenuEntry("Move Right Arm", 2);
    glutAddMenuEntry("Move Left Arm", 3);
    glutAddMenuEntry("Move Right Leg", 4);
    glutAddMenuEntry("Move Left Leg", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);  //������ ���콺 Ŭ���� �۵��ϰ� �Ͽ����ϴ�
}

void Body(void) {  //�κ��� ���� ���� �Լ��Դϴ�.
    glRotatef(-90, 1, 0, 0);    //rotate �� ����Ͽ� ������ 
    //DrawAxis();
    glPushMatrix();  //PUSH
    glColor3f(0, 204, 204);  //���� �ٲ���
    gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric�� ���� ���ϴ� Draw Style ���� -> GLU_LINE ���� �����Ͽ� wire-frame ���·� �𵨸���
    gluCylinder(qobj, 0.6, 0.6, 1.5, 40, 8);  //�Ʒ������� 0.6 �������� 0.6 ����1.5 ȸ������ 40 subdivision ���� 8�� ����
    glPopMatrix();  //�κ���ü������ ���� POP
}

void Rightarm(void) {  //�����ȿ� ���� �Լ��Դϴ�
    glPushMatrix();  //PUSH

    glRotatef(150, 0, 1,0);  //ROTATE���༭ ���� ȸ����Ű��
    glTranslatef(-0.9, -0.8, -0.9);  //��ġ�� �°� �̵������־����ϴ�
    glRotatef(rightarm,0, 1, 0);  //������ �߰��Ͽ� �����ϼ��ְ� �Ͽ����ϴ�
 
    //DrawAxis(); 
    glPushMatrix();   //�� ����� ���� �����Դϴ�
    glColor3f(255, 0, 0);  //�� ����
    gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric�� ���� ���ϴ� Draw Style ���� -> GLU_LINE ���� �����Ͽ� wire-frame ���·� �𵨸���
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //Cylinder ����
    glPopMatrix();  //

    glTranslatef(-0.05, 0, 0.9);     //�Ȳ�ġ�� ���� �����Դϴ� �̵��ϰ� ȸ���ϰ� ȸ���� ������ �߰��Ͽ����ϴ�
    glRotatef(40+rightarm2,0,1,0);
    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0); //���� �ٲ��־����ϴ�
    gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric�� ���� ���ϴ� Draw Style ���� -> GLU_LINE ���� �����Ͽ� wire-frame ���·� �𵨸���
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //Cylinder ���� ���� ����
    glPopMatrix();

    glTranslatef(0,0,1.0);  //�����տ� ���� �����Դϴ� �Ȳ�ġ���� �̵������ְ� ���� �������ְ� WireSphere�� ����� �־����ϴ�
    glColor3f(1.0, 1.0, 1.0);
    glutWireSphere(0.2,10,10);

    glPopMatrix();   //�������� POP���ݴϴ�

}

void Leftarm(void) {  //�����ȿ� ���� �����Դϴ�
    glPushMatrix();


    glRotatef(-150, 0, 1, 0);  //ȸ���ϰ� translate�� �̿��� ��ġ�� ã���ְ� rotate�� ������ �߰��Ͽ� ���߿� �����ϼ� �ְ� �������־����ϴ�
    glTranslatef(0.9, -0.8, -0.9);
    glRotatef(leftarm, 0, 1, 0);

    glPushMatrix();  //���� ����� ���� �����Դϴ�
    glColor3f(255, 0, 0);  //���� �������־����ϴ�
    gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric�� ���� ���ϴ� Draw Style ���� -> GLU_LINE ���� �����Ͽ� wire-frame ���·� �𵨸���
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //Cylinder �� ���� ����
    glPopMatrix();

    glTranslatef(+0.05, 0, 0.9);  //���� �Ȳ�ġ�� ���� �����Դϴ�
    glRotatef(-40 + leftarm2, 0, 1, 0);  //ȸ���ϰ� �̵��Ͽ� ��ġ�� �������ְ� ȸ�������� �߰��Ͽ����ϴ�
    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0);  //���� �������־����ϴ�
    gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric�� ���� ���ϴ� Draw Style ���� -> GLU_LINE ���� �����Ͽ� wire-frame ���·� �𵨸���
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //Cylinder �� ������ �������־����ϴ�
    glPopMatrix();

    glTranslatef(0, 0, 1.0); //�̵��ϰ� ���ٲٰ� ���� �� ������־����ϴ�
    glColor3f(1.0, 1.0, 1.0);
    glutWireSphere(0.2, 10, 10);

    glPopMatrix();
}

void Rightleg(void) {  //������ �ٸ������� �Լ��Դϴ�
    glPushMatrix();

    glRotatef(180, 0, 1, 0);  //ȸ���ϰ� �̵��ϰ� ȸ������ �߰��Ͽ� ó�� ����� �κ� �׷��־����ϴ�
    //DrawAxis();
    glTranslatef(-0.25, -0.8, -0.1);
    glRotatef(rightleg, 0, 1, 0);

    glPushMatrix();
    glColor3f(255, 0, 0);  //���� �ٲ��־����ϴ�
    gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric�� ���� ���ϴ� Draw Style ���� -> GLU_LINE ���� �����Ͽ� wire-frame ���·� �𵨸���
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //Cylinder �� ���� ����
    glPopMatrix();

    glTranslatef(0, 0, 0.9);  //�̵� ȸ���� ���Ƹ� �κ� ����� �Ʒ��� �̾��־����ϴ�
    glRotatef(rightleg2, 0, 1, 0);
    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0);  //�� ����
    gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric�� ���� ���ϴ� Draw Style ���� -> GLU_LINE ���� �����Ͽ� wire-frame ���·� �𵨸���
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //�� ���� ����
    glPopMatrix();

    glTranslatef(0, 0, 0.9);  //�̵��� ���ٲٰ� Cylinder�� �� ����� �־����ϴ�
    glColor3f(1.0, 1.0, 1.0);
    gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric�� ���� ���ϴ� Draw Style ���� -> GLU_LINE ���� �����Ͽ� wire-frame ���·� �𵨸���
    gluCylinder(qobj, 0.25, 0.25, 0.15, 20, 8);  //�󼼽��� ����

    glPopMatrix();
}

void Leftleg(void) {  //���� �ٸ��� ���� �Լ��Դϴ�
    glPushMatrix();

    glRotatef(180, 0, 1, 0);  //ȸ���ϰ� �̵��ϰ� ȸ������ �߰��Ͽ� ���߿� ������ �� �ְ� �������־����ϴ�
    //DrawAxis();
    glTranslatef(0.25, -0.8, -0.1);
    glRotatef(leftleg, 0, 1, 0);

    glPushMatrix();
    glColor3f(255, 0, 0);  //���� �������־����ϴ�
    gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric�� ���� ���ϴ� Draw Style ���� -> GLU_LINE ���� �����Ͽ� wire-frame ���·� �𵨸���
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //�� ���� �������־����ϴ�
    glPopMatrix();

    glTranslatef(0, 0, 0.9);  //�̵��ϰ� ȸ���ϰ� ���� ���Ƹ� ����� �Ʒ��� �̾��־����ϴ�
    glRotatef(leftleg2, 0, 1, 0);
    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0);  //���������Ͽ����ϴ�
    gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric�� ���� ���ϴ� Draw Style ���� -> GLU_LINE ���� �����Ͽ� wire-frame ���·� �𵨸���
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //�󼼽��� ����
    glPopMatrix();

    glTranslatef(0, 0, 0.9);  //�̵��ϰ� �� �����ϰ� ���� �� ������־����ϴ�
    glColor3f(1.0, 1.0, 1.0);
    gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric�� ���� ���ϴ� Draw Style ���� -> GLU_LINE ���� �����Ͽ� wire-frame ���·� �𵨸���
    gluCylinder(qobj, 0.25, 0.25, 0.15, 20, 8);  //�Ʒ������� 1 �������� 1 ����2 ȸ������ 20 subdivision ���� 5�� ����*/

    glPopMatrix();
}

void NeckAndHead(void) {  //��� �Ӹ��� ���� �Լ��Դϴ�
    glPushMatrix();

    glRotatef(0, 0, 1, 0);  //ȸ���ϰ� �̵��Ͽ� ���� �� ���� ������־��� neck������ ���� ���Ŀ� �̵��Ҽ� �ֵ��� ���־����ϴ�
    glTranslatef(0, -0.8, 1.2);
    //DrawAxis();
    glRotatef(neck, 0, 1, 0);

    glPushMatrix();
    glColor3f(255.0, 255.0, 0.0);  //���� �������־����ϴ�
    gluQuadricDrawStyle(qobj, GLU_LINE);   //�Ǹ����� ������־����ϴ�
    gluCylinder(qobj, 0.2, 0.2, 0.4, 20, 8);  
    glPopMatrix();

    glPushMatrix();      //������ ��
    glRotatef(-60, 1, 0, 0);  //�� �������� �������� ���� ��ġ�� �������־����ϴ�
    glTranslatef(0.3, -0.5, 1.5);
    //DrawAxis();
    glRotatef(eye, 0, 1, 0);  //���� ������ �߰����ְ� �� �ٲٰ� Disk�� ������־����ϴ�
    glColor3f(0, 1.0, 0);
    gluDisk(qobj, 0.05, 0.1, 20, 3);
    glPopMatrix();
     
    glPushMatrix();         //���� ��
    glRotatef(-60, 1, 0, 0);  //�� �������� �������� ���� ��ġ�� �������־����ϴ�
    glTranslatef(-0.3, -0.5, 1.5);
    //DrawAxis();
    glRotatef(eye, 0, 1, 0);   //���� ������ �߰����ְ� �� �ٲٰ� Disk�� ������־����ϴ�
    glColor3f(0, 1.0, 0);
    gluDisk(qobj, 0.05, 0.1, 20, 3);
    glPopMatrix();

    glTranslatef(0, 0.7, 0.7);  //�Ӹ��� �̵��ϰ� ȸ���Ͽ� ������־����ϴ�
    glRotatef(head, 0, 1, 0);
    //DrawAxis();
    glPushMatrix();
    glColor3f(255.0, 255.0, 0.0);  //���� �������־�����
    gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric�� ���� ���ϴ� Draw Style ���� -> GLU_LINE ���� �����Ͽ� wire-frame ���·� �𵨸���
    gluCylinder(qobj, 0.6, 0.4, 0.5, 30, 4);  //Cylinder ������ �������־����ϴ�
    glPopMatrix();
  
    glPopMatrix();
}

void MyDisplay(void) {  //MyDispaly �Լ��� ���� �����Դϴ�
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    
    Body();  //������ ���� ��,������, �����ٸ� ���� �޴ٸ� ����Ӹ� �Լ��� ��� �߰��Ͽ����ϴ�
    Rightarm();
    Leftarm();
    Rightleg();
    Leftleg();
    NeckAndHead();

    glPopMatrix();
    glutSwapBuffers();
}

void MyReshape(int w, int h) {  //������ ũ�� ����� ����Ǵ� Reshape�Լ��Դϴ�
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void MyKeyboard(unsigned char key, int x, int y) {  //Ű���� ���� �Լ��̰� sŬ���� ��� ���߰� �����Ͽ����ϴ�
    switch (key) {
    case 's':
        glutTimerFunc(40, Timer6, 1);
        break;
    case 'S':
        glutTimerFunc(40, Timer6, 1);
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {  //�����Լ��Դϴ�
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  //RGB �� ������� ���
    glutInitWindowSize(800, 600);  //������ ũ�� ����
    glutInitWindowPosition(100, 100);  //������ ���� ��ġ ����
    glutCreateWindow("Can Robot");  //�����츸��
    MyInit();  //MyInit�Լ� ���
    glutDisplayFunc(MyDisplay); //MyDisplay�Լ� ���
    glutReshapeFunc(MyReshape);  //MyReshape�Լ� ���
    glutKeyboardFunc(MyKeyboard);   //MyKeyboard�Լ� ���
    glutMainLoop();
    return 0;
}