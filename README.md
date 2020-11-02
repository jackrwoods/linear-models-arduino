# linear-models-arduino

## Introduction

For a capstone project, my team needed to know how fast we could evaluate a linear model on a small microprocessor. I chose to write this small library to *potentially* make my effort more useful at a later stage in this project. This library allows you to evaluate multivariate linear models on an Arduino.


## Usage

### Installing the Library

First, make a directory containing your current Arduino sketchbook. In your Arduino IDE, click `sketch` -> `Include Library` -> `Add .zip Library`. Locate the LinearModelEvaluator.zip file (located in this repository) on your hard drive.

Now, if you open the Sketch > Import Library menu, you should see LinearModelEvaluator inside. The library will be compiled with sketches that use it.

### Using the Library

First, you will need to configure your linear model.

```{c}
// Example Evaluator Function for X^2
double xSquaredEvaluator(double input) {
	return pow(input, 2);
}

// Example Evaluator Function for X
double xEvaluator(double input) {
	return input;
}

LinearModel l; // Declared in the global scope

void setup {

	// Add any number of explanatory variables
	// Adding these two creates Y ~ 3x^2 + 2x
	l.addVariable((double) 3, &xSquaredEvaluator);
	l.addVariable((double) 2, &xEvaluator);
}
```

Now, you can evaluate the linear model's prediction by providing an array of input values of type `double`.


```{c}
void loop {
	double[2] inputs = [15.5, -2.4];
	double result = l.evaluate(inputs);
}
```

## Still Having Issues?

Download the linear model test sketch provided in this repo `linear_model_test_sketch.zip`. That was tested and is working with an Arduino Uno as of 11/1/2020.
