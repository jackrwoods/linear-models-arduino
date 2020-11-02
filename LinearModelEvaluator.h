// This file defines a core class for the library.

#ifndef LINEAR_MODEL_EVALUATOR
#define LINEAR_MODEL_EVALUATOR

// An interface describing an abstract explanatory variable
class ExplanatoryVariable {
	public:
		ExplanatoryVariable* link;	
		double coefficient; // The coefficient for this variable, produced by training the model
		ExplanatoryVariable(double coefficient, double (*evaluate)(double));
		double (*evaluate)(double); // Evaluates b * x_i
};

class LinearModel {
	private:
		ExplanatoryVariable* variables; // A linked list of expl vars
		ExplanatoryVariable* tail; // The last element in the linked list
	public:
		LinearModel();
		void addVariable(double coefficient, double (*evaluate)(double)); // Creates a new ExplanatoryVariable and adds it to variables
		int removeVariable(int index); // Remove an explanatory variable at index
		double evaluate(double* input); // Given an array of input doubles, evaluates 1 linear model prediction
};

#endif // LINEAR_MODEL_EVALUATOR
