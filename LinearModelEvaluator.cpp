#include "LinearModelEvaluator.h"

LinearModel::LinearModel() {
	this->availableSize = 3; // Start with three
	this->length = 0;
	this->variables = new ExplanatoryVariable[this->availableSize];
}

LinearModel::addVariable(double coefficient, double (*evaluate)(double)) {
	// Is there enough space?
	if (length >= availableSize) {
		ExplanatoryVariable* temp = this->variables;
		this-> availableSize++;
		variables = new ExplanatoryVariable[this->availableSize];
		memcpy(variables, temp, sizeof(ExplanatoryVariable) * (this->availableSize - 1));
		delete[] temp;
	}

	// There is enough space now!
	// Add the new explanatory variable to the array
	this->variables[this->length] = ExplanatoryVariable(coefficient, evaluate);
	this->length++;
}

LinearModel::removeVariable(int index) {
	memcpy(&this->variables[index], &this->variables[index + 1], sizeof(ExplanatoryVariable) * (this->length - (index + 1)));
	this->length--;
}

LinearModel::evaluate(double* input) {
	double result = 0;
	for (int i = 0; i < this->length; i++) {
		// Evaluate each explanatory variable and add its result to "result"
		result += this->variables[i].coefficient * this->variables[i].evaluate(input[i]);
	}

	return result;
}

ExplanatoryVariable::ExplanatoryVariable(double coefficient, double (*evaluate)(double)) {
	this->coefficient = coefficient;
	this->evaluate = evaluate;
}
