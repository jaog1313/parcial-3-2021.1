#ifndef ROMBERGMETHOD_H_
#define ROMBERGMETHOD_H_
#include <cmath>

#include "TrapezoidalRule.h"



#include "CalculationStrategy.h"


class RombergMethod: public CalculationStrategy {
	
private:
	
	int maxSteps;
	
	double accuracy;
	
public:
	
	static const int DEFAULT_MAX_STEPS = 100;
	
	RombergMethod(double accuracy, double maxSteps): 
		maxSteps(maxSteps), accuracy(accuracy) {
	}
	
	RombergMethod(double accuracy):
		maxSteps(DEFAULT_MAX_STEPS), accuracy(accuracy) {
	}
	
	double calculate(const Function& function, double a, double b){
		double r[maxSteps][maxSteps];
		double h = b - a; // step size
		TrapezoidalRule firstTrapezoidalRule(h);
		r[0][0] = firstTrapezoidalRule.calculate(function, a, b);
		int i = 1;
		do {
			TrapezoidalRule trapezoidalRule(h / (double) pow(2, (double) i));
			r[i][0] = trapezoidalRule.calculate(function, a, b);
			for (int j = 1; j <= i; j++) {
				r[i][j] = ((double) pow(2, 2.0 * j) * r[i][j - 1] - r[i - 1][j - 1])
					/ ((double) pow(2, 2.0 * j) - 1.0);
			}
			i++;
		} while ((fabs(r[i - 1][i - 1] - r[i - 2][i - 2]) > accuracy)
			&& (i < maxSteps));
		return r[i - 1][i - 1];
	}
	
	virtual ~RombergMethod(){
		
	}
	
};

#endif
