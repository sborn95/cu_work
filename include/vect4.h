//Note: vect4 is a modified version of Lvect4, originally created by Leo Bellantoni
#ifndef VECT_4
#define VECT_4

#include <iostream>
using namespace std;

class vect4{
	public:
		//Constructors and destructors
		vect4(double e = 0.0, double x=0.0, double y=0.0, double z=0.0);
		~vect4();
		//Getters and setters
		double x0();
		double x1();
		double x2();
		double x3();
		void set_x0(double x);
		void calcset_x0_p(double mass);//x0 = E/c -- want to redefine one for position
		void set_x1(double x);
		void set_x2(double x);
		void set_x3(double x);
		void set_v3(double x, double y, double z);
		void set_all(double e, double x, double y, double z);
		void scale(double c);
		void scalev3(double c);
		//Algebra
		vect4 operator+ (vect4 rhs); //add four-vectors
		vect4 operator- (vect4 rhs); //subtract four-vectors
		double operator* (vect4 rhs); //multiply four-vectors
		double operator| (vect4 rhs); //position vector projection (dot product)
		//Quantities
		double magv3();
		double cos_ang(vect4 other);
		double ang(vect4 other);
		double deltav3(vect4 other);
		double beta();
		double beta_(int component);
		double gamma();
		double cos_ang_frame(vect4 vframe);
		double mag_p_frame(vect4 vframe);
		double delta(int i, int j);
		vect4 boost(vect4 parent_frame);
	private:
		double X0, X1, X2, X3;

};

#endif
