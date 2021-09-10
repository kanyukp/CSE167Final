#ifndef CLOUDTRANSFORM_H
#define CLOUDTRANSFORM_H
#include "cloudNode.h"
class cloudTransform :
	public cloudNode
{
public:
	glm::mat4 M;
	std::list<cloudNode*> children;
    void addChild(cloudNode* child);
	void draw(GLuint shaderProgram, glm::mat4 C);
	void deleteChild(int i);
	bool deleteMe();
	void cull();
	//float Transform::getM();
	cloudTransform();
	cloudTransform(glm::mat4 in);
	cloudTransform(glm::mat4 in, int type);
	int type = 1;
	~cloudTransform();

	int checkVal;

	int frames = 0;

	void update();
};
#endif

