class circulo {
	private:
		double radio;
public:
	circulo(double r) : radio(r) {}
	
	double area() {
		return M_PI * pow(radio, 2);
	}
	
	double perimetro() {
		return 2 * M_PI * radio;
	}	
};
