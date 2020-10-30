// This file defines a core class for the library.

#ifndef LINEAR_MODEL_EVALUATOR
#define LINEAR_MODEL_EVALUATOR

class LinearModel {
	private:
		ExplanatoryVariable* variables; // An array of expl vars
		int length;
		int availableSize;
	public:
		LinearModel();
		void addVariable(double coefficient, double (*evaluate)(double)); // Creates a new ExplanatoryVariable and adds it to variables
		void removeVariable(int index); // Remove an explanatory variable at index
		double evaluate(double* input); // Given an array of input doubles, evaluates 1 linear model prediction
};

// An interface describing an abstract explanatory variable
class ExplanatoryVariable {
	public:	
		double coefficient; // The coefficient for this variable, produced by training the model
		ExplanatoryVariable(double coefficient, double (*evaluate)(double));
		double (*evaluate)(double); // Evaluates b * x_i
}

#endif // LINEAR_MODEL_EVALUATOR
