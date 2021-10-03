#ifndef TRAPECIO_H
#define TRAPECIO_H

#include<functional>

using std::function;

class trapecio {
public:
	double integrar(
					function<double(double)> f,
					double limite_inf,
					double limite_sup,
					int intervalos
					) {
		
		double result(0.0f);
		
		double h = (limite_sup - limite_inf)/ intervalos;
		
		double s = 0.0;
		double x;
		int i;
		
		for(i = 1, x = limite_inf +h; i < intervalos; i++, x +=h) {
			s += f(x);
		}
		
		//sumatoria 
		double suma = f(limite_inf) + (2 * s) + f(limite_sup);
		
		result =((limite_sup - limite_inf)* suma) / (2 * intervalos);
		
		return result;
	}
};
#endif
