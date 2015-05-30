#include "include/Node.h"

map<char, Node::Type> Node::typeMappings = {{' ', NORMAL}, {'X', OBSTACLE}};

Node::Node(): costFromStart(0), costToTarget(0), totalCost(0){
	this->parent = nullptr;
}

Node::Node(char type): costFromStart(0), costToTarget(0), totalCost(0), state(UNVISITED) {
	this->type = Node::typeMappings.at(type);
	this->parent = nullptr;
}

Node::~Node() {
	if(this->parent != nullptr){
		delete this->parent;
		this->parent = nullptr;
	}
}

void Node::calculateTotalCost(){
	totalCost = costFromStart + costToTarget;
}

float Node::getCostFromStart(){
	return this->costFromStart;
}

float Node::getCostToTarget(){
	return this->costToTarget;
}

float Node::getTotalCost(){
	return this->totalCost;
}

Node * Node::getParent(){
	return this->parent;
}

Node::State Node::getState(){
	return this->state;
}

Node::Type Node::getType(){
	return this->type;
}

void Node::setCostFromStart(float cost){
	this->costFromStart = cost;
}

void Node::setCostToTarget(float cost){
	this->costToTarget = cost;
}

void Node::setTotalCost(float cost){
	this->totalCost = cost;
}

void Node::setType(char type){
	this->type = typeMappings.at(type);
}

void Node::setState(State state){
	this->state = state;
}