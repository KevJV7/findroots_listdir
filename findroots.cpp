// Find Roots

#include <iostream>

using namespace std;

bool RepetirPrograma() {

	bool respuestainvalidadeloop = true;
	while (respuestainvalidadeloop) {

		char restablecerChar;

		cout << "¿Quieres hacerlo otra vez? (S/N)" << endl;
		cin >> restablecerChar;

		if (restablecerChar == 'S' || restablecerChar == 's') {
			respuestainvalidadeloop = false;
			return true;

		}
		else if (restablecerChar == 'N' || restablecerChar == 'n') {
			respuestainvalidadeloop = false;

			cout << "Adios!!" << endl;
			return false;

		}
		else {
			cout << "\"" << restablecerChar << "\"" << " No es una respuesta valida.\n" << endl;
			respuestainvalidadeloop = true;
		}
	}
}

void FormulaCubica(double a, double b, double c, double d) { //inicia funcion FormulaCubica

	double f = (((3 * c) / a) - ((b * b) / (a * a))) / 3;
	double g = (((2 * (b * b * b) / (a * a * a)) - ((9 * b * c) / (a * a)) + ((27 * d) / a))) / 27;
	double h = ((g * g) / 4) + ((f * f * f) / 27);
	double i = sqrt(((g * g) / 4) - h);

	double alauntercio = 1.0 / 3.0;

	double x1, x2, x3;


	if (h > 0) {   // tpara 1 raiz


		double r = (-(g / 2.0)) + (sqrt(h));
		double s = pow(r, alauntercio);
		double t = (-(g / 2.0)) - (sqrt(h));

		double u;
		if (t < 0) {
			u = pow(-t, alauntercio) * (-1);
		}
		else {
			u = pow(t, alauntercio);
		}

		x1 = ((s + u) - (b / (3.0 * a)));
		cout << "{" << x1 << "}" << endl;
	}    // termina para 1 raiz


	if (h <= 0) { // las 3 raices son reales


		if (f == 0 && g == 0 && h == 0) {  // caso 1 si todas son iguales

			x1 = pow((d / a), alauntercio) * (-1);

			x1 = x1 + x1;
			cout << "Todas las raices son iguales" << endl;

			cout << "{" << x1 << x1 << x1 << endl;
		} //terminan las 3 raices iguales

		double j = pow(i, (1.0 / 3.0));
		double k = acos(-(g / (2 * i)));
		double l = j * (-1.0);
		double m = cos(k / 3.0);
		double n = sqrt(3.0) * sin(k / 3.0);
		double p = (b / (3 * a)) * (-1.0);

		x1 = ((2 * j) * (cos(k / 3.0))) - (b / (3 * a));
		x2 = (l * (m + n)) + p;
		x3 = (l * (m - n)) + p;

		cout << "{" << x1 << "," << x2 << "," << x3 << "}" << endl;

	}//termina para las 3 raices


}//termina FormulaCubica


int main() {

	double a, b, c, d;

	bool repetirLoop = true;

	cout << "Este programa es para la formula cubica" << endl;

	while (repetirLoop) {


		cout << "introduzca los valores de a, b, c, y d" << endl;

		cout << "Separados por un espacio: ";

		cin >> a >> b >> c >> d;

		FormulaCubica(a, b, c, d);

		repetirLoop = RepetirPrograma();
	}

	return 0;
}