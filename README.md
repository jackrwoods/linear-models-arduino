# linear-models-arduino

## Introduction

For a capstone project, my team needed to know how fast we could evaluate a linear model on a small microprocessor. I chose to write this small library to *potentially* make my effort more useful at a later stage in this project. This library allows you to evaluate multivariate linear models on an Arduino.


## Usage

### Installing the Library

First, make a directory containing your current Arduino sketchbook. Create another directory inside of your sketchbook's directory called `libraries`. Unzip the LinearModelEvaluator.zip in this directory.

Now, your sketchbook directory structure should look something like this:

```
my_sketchbook/
└── libraries/
    └── LinearModelEvaluator/
        ├── LinearModelEvaluator.h
        └── LinearModelEvaluator.cpp
```

Now launch the Arduino environment. If you open the Sketch > Import Library menu, you should see LinearModelEvaluator inside. The library will be compiled with sketches that use it.

### Using the Library

First, you will need to configure your linear model.

```{c}
// Example Evaluator Function for X^2
double xSquaredEvaluator(double input) {
	return Math.pow(input, 2);
}

// Example Evaluator Function for X
double xEvaluator(double input) {
	return input;
}

LinearModel l; // Declared in the global scope

setup {

	// Creates an empty linear model
	l = new LinearModel();

	// Add any number of explanatory variables
	// Adding these two creates Y ~ 3x^2 + 2x
	l.addVariable((double) 3, &xSquaredEvaluator);
	l.addVariable((double) 2, &xEvaluator);
}
```

Now, you can evaluate the linear model's prediction by providing an array of input values of type `double`.


```{c}
loop {
	double[2] inputs = [15.5, -2.4];
	double result = l.evaluate(inputs);
}
```
