#include "LinearModelEvaluator.h"

#define NULL 0

ExplanatoryVariable::ExplanatoryVariable(double coefficient, double (*evaluate)(double)) {
	this->coefficient = coefficient;
	this->evaluate = evaluate;
	this->link = NULL;
}

LinearModel::LinearModel() {
	this->variables = NULL;
	this->tail = NULL;
}

void LinearModel::addVariable(double coefficient, double (*evaluate)(double)) {
	if (!this->variables) {
		this->variables = new ExplanatoryVariable(coefficient, evaluate);
		this->tail = this->variables;
	} else {
		this->tail->link = new ExplanatoryVariable(coefficient, evaluate);
		this->tail = this->tail->link;
	}
}

int LinearModel::removeVariable(int index) {
	ExplanatoryVariable* current = this->variables;
	ExplanatoryVariable* previous;
	while (index > 0 && current->link) {
		index--;
		previous = current;
		current = current->link;
	}

	// We found the element!
	if (index == 0) {
		// Remove it from the linked list
		previous->link = current->link;
		delete current;
		return 0;
	} else {
		return 1; // Exception handling is disabled on arduino?
	}

}

double LinearModel::evaluate(double* input) {
	double result = 0;
	int i = 0;
	ExplanatoryVariable* current = this->variables;
	while (current) {
		// Evaluate each explanatory variable and add its result to "result"
		result += current->coefficient * current->evaluate(input[i]);
		i++;
		current = current->link;
	}

	return result;
}

