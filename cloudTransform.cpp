#include "cloudTransform.h"



cloudTransform::cloudTransform()
{
	M = glm::mat4(1.0f);
	this->type = 1;
}
cloudTransform::cloudTransform(glm::mat4 in)
{
	M = in;
	this->type = 1;
}

cloudTransform::cloudTransform(glm::mat4 in, int type) {
	M = in;
	this->type = type;
}

cloudTransform::~cloudTransform()
{
}
void cloudTransform::addChild(cloudNode* child) {
	this->children.push_back(child);
}
void cloudTransform::deleteChild(int i) {
	auto it = children.begin();
	advance(it, i);
	this->children.erase(it);
}

void cloudTransform::draw(GLuint shaderProgram, glm::mat4 C) {
	C = M * C;
	if (this->children.front() == NULL) {
		return;
	}
	for (auto const& child: children) {
		child->draw(shaderProgram, C);
	}
}
void cloudTransform::update()
{
	if (type == 0)
	{
		for (auto const& child : children) {
			child->update();
		}
	}
	else {
		this->M = glm::translate(this->M, glm::vec3(0.0f, 0.0f, -0.001f));
		for (auto const& child : children) {
			child->update();
		}
	}
}

void cloudTransform::cull() {
	//int index = 0;
	deleteChild(0);
}
/*float Transform::getM() {
	return this->M[3][0];
}
*/
bool cloudTransform::deleteMe() {
	return false;
}