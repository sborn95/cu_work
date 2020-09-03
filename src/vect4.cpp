//Note: vect4 is a modified version of Lvect4, originally created by Leo Bellantoni
#include <math.h>

#define atStart true
#define atEnd false

//Constructor and destructor
vect4::vect4(double e, double x, double y, double z):X0(e),X1(x),X2(y),X3(z){}

vect4::~vect4(){}
//Getters and setters
//See any text on four vectors
double vect4::x0(){
	return X0;
}
double vect4::x1(){
	return X1;
}
double vect4::x2(){
	return X2;
}
double vect4::x3(){
	return X3;
}
void vect4::set_x0(double x){
	X0 = x;
}
void vect4::calcset_x0_p(double mass){
	X0 = sqrt((double)(mass*mass + X1*X1 + X2*X2 + X3*X3));	
}
void vect4::set_x1(double x){
	X1 = x;
}
void vect4::set_x2(double x){
	X2 = x;
}
void vect4::set_x3(double x){
	X3 = x;
}
void vect4::set_v3(double x, double y, double z){
	X1 = x; X2 = y; X3 = z;
}
void vect4::set_all(double e, double x, double y, double z){
	set_x0(e);
	set_x1(x);
	set_x2(y);
	set_x3(z);
}
void vect4::scale(double c){
	set_x0(c*X0);
	set_x1(c*X1);
	set_x2(c*X2);
	set_x3(c*X3);
}
void vect4::scalev3(double c){
	set_x1(c*X1);
	set_x2(c*X2);
	set_x3(c*X3);
}
//Algebra
vect4 vect4::operator+ (vect4 rhs) {
	vect4 temp;
	double e = x0() + rhs.x0(); 
	double x = x1() + rhs.x1();
	double y = x2() + rhs.x2();
	double z = x3() + rhs.x3();
	temp.set_all(e,x,y,z);
	return (temp);
}
vect4 vect4::operator- (vect4 rhs) {
	vect4 temp;
	double e = x0() - rhs.x0(); 
	double x = x1() - rhs.x1();
	double y = x2() - rhs.x2();
	double z = x3() - rhs.x3();
	temp.set_all(e,x,y,z);
	return (temp);
}
double vect4::operator* (vect4 rhs) {
	//Standard used in griffiths particle physics
	//If momentum, should produce inv. mass
	double product;
	double exe = x0()*rhs.x0(); 
	double xxx = x1()*rhs.x1();
	double yxy = x2()*rhs.x2();
	double zxz = x3()*rhs.x3();
	product = exe - xxx - yxy - zxz;
	return (product);
}
double vect4::operator| (vect4 rhs){
	double dp = x1()*rhs.x1() + x2()*rhs.x2() + x3()*rhs.x3();
	return dp;
}
//Quantities
double vect4::magv3(){
	double mag_sq = *this|*this;
	return sqrt(mag_sq);
}
double vect4::cos_ang(vect4 other){
	double dp = *this|other;
	double mag1 = sqrt(*this|*this);
	double mag2 = sqrt(other|other);
	double cosA = dp/(mag1*mag2);
	return cosA;
}
double vect4::ang(vect4 other){
	double cosA = cos_ang(other);
	double angle;
	//Returns nan ~ bug fix
	if(1.1 >= fabs(cosA) && 1 <= fabs(cosA)){
		angle = acos((int)cosA);
		return angle;
	}
	angle = acos(cosA);
	return angle;
}
double vect4::deltav3(vect4 other){
	double dx = x1()-other.x1();
	double dy = x2()-other.x2();
	double dz = x3()-other.x3();
	return sqrt(dx*dx + dy*dy + dz*dz);
}
double vect4::beta(){
	return magv3()/x0();
}
double vect4::beta_(int component){
	double beta_comp;
	double comp;
	if(component == 1) comp = x1();
	if(component == 2) comp = x2();
	if(component == 3) comp = x3();

	beta_comp = beta()*(comp/magv3());
	return beta_comp;


}
double vect4::gamma(){
	double Beta = (*this).beta();
	double gmma = 1/sqrt(1-Beta*Beta);
	return gmma;
}
double vect4::cos_ang_frame(vect4 vframe){
	//all of this will make sense if you write it out as expected and cancel some gammas
	double Beta = vframe.beta();
	double xproj = ((*this)|vframe)/vframe.magv3(); //x projection this state onto frame
	double xnew = xproj-Beta*x0();
	//The sqrt might be a bad thing - I don't know if leo did this. you may be misunderstanding.
	double mag_new = xnew*xnew + (magv3()-xproj)*(magv3()+xproj)*(1.0-Beta)*(1.0+Beta);
	return xnew/sqrt(mag_new);
}
double vect4::mag_p_frame(vect4 vframe){
	//As far as you know this is not working yet
	double Beta = vframe.beta();
	double gamma = vframe.gamma();
	double xproj = ((*this)|vframe)/vframe.magv3();
	double xnew = gamma*(xproj-Beta*x0());
	double mag_new = sqrt(xnew*xnew + (magv3()-xproj)*(magv3()+xproj));
	return mag_new;
}

double vect4::delta(int i, int j){
	if(i == j) return 1;
	return 0;
}
//Takes this and boosts to frame of parent
vect4 vect4::boost(vect4 parent_frame){
	vect4 return_vect; 
	//Costruct matrix
	//note that all but the first components are negative so that we can get
	//matrix multiplication by just multiplying four-vectors
	double gmma = parent_frame.gamma();
	double Beta [4] = {0, parent_frame.beta_(1), parent_frame.beta_(2), parent_frame.beta_(3)};
	double n [4] = {0, Beta[1]/parent_frame.beta(), Beta[2]/parent_frame.beta(), Beta[3]/parent_frame.beta()};
	vect4 row_1,row_2,row_3,row_4;
	row_1.set_all(gmma, gmma*Beta[1], gmma*Beta[2], gmma*Beta[3]);
	row_2.set_all(-gmma*Beta[1], -1-(gmma-1)*pow(n[1],2), -(gmma-1)*n[1]*n[2], -(gmma-1)*n[1]*n[3]);
	row_3.set_all(-gmma*Beta[2], -(gmma-1)*n[2]*n[1], -1-(gmma-1)*pow(n[2],2), -(gmma-1)*n[2]*n[3]);
	row_4.set_all(-gmma*Beta[3], -(gmma-1)*n[3]*n[1], -(gmma-1)*n[3]*n[2], -1-(gmma-1)*pow(n[3],2));
	//
	//Matrix multiply
	return_vect.set_x0((*this)*row_1);
	return_vect.set_x1((*this)*row_2);
	return_vect.set_x2((*this)*row_3);
	return_vect.set_x3((*this)*row_4);
	cout << "(" << return_vect.x0() << "," << return_vect.x1() << "," << return_vect.x2() << "," << return_vect.x3() << ")" << endl;
	return return_vect;

	
}
