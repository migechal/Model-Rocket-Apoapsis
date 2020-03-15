//CREATED BY MIKHAIL CHALAKOV 

//CALCULATES MODEL ROCKET APOAPSIS 

// 

// 

// 

// 

#include<cmath> 

#include<iostream> 

double g = 9.8; 

double diamiter = 0; 

double T = 1; 

double I = 1; 

double t = 0; 

double M = 0; 

double rho = 1.2; 

double Cd = 0.75; 

double A = 0; 

double k = 0; 

double q = 0; 

double x = 0; 

double v = 0; 

double yb = 0; 

double yc = 0; 

double pi = 3.14; 

double a = 0; 

double qa = 0; 

double qb = 0; 

double ta = 0; 

int main() 

{ 

std::cout <<"Enter T value: "; 

std::cin >> T; 

std::cout <<"Enter I value: "; 

std::cin >> I; 

std::cout <<"Enter M value: "; 

std::cin >> M; 

 

//EXAMPLE 

//T = 6; 

//I = 9; 

//M = 0.05398; 

//diamiter = 0.0247904 

 

std::cout << "Enter Diameter value: "; 

 

std::cin >> diamiter; 

 

t = I/T; 

for (int i = 0; i != 20; i++){ 

std::cout << std::endl; 

} 

//A = pi*(0.5*(diameter in inches/12)*0.3048)^2 = pi*r^2 

auto r = 0.5*diamiter; 

A = pi*r*r; 

 

std::cout << "A is " << A << std::endl; 

 

// k = 0.5*rho*Cd*A = 0.5*1.2*0.75*A 

k = 0.5*rho*Cd*A; 

 

std::cout <<"k is " << k << std::endl; 

//q = sqrt([T - M*g] / k) 

q = sqrt((T - M*g) / k); 

 

std::cout<<"q is "<< q << std::endl; 

 

//x = 2*k*q / M 

 

x = 2*k*q / M; 

 

std::cout<<"x is "<< x << std::endl; 

 

//v = q*[1-exp(-x*t)] / [1+exp(-x*t)] 

 

v = q*(1-exp(-x*t)) / (1+exp(-x*t)); 

 

std::cout <<"v (max velocity) is " << v << std::endl; 

 

//yb = [-M / (2*k)]*ln([T - M*g - k*v^2] / [T - M*g]) 

 

yb = (-M / (2*k))*log((T - M*g - k*v*v) / (T - M*g)); 

 

std::cout << "yb ( boost phase distance ) is " << yb << std::endl; 

 

//yc = [+M / (2*k)]*ln([M*g + k*v^2] / [M*g]) 

 

yc = (M / (2*k))*log((M*g + k*v*v) / (M*g)); 

 

std::cout<< "yc (coast phase distance) is "<< yc << std::endl; 

 

a = yb+yc; 

 

qa = sqrt(M*g / k); 

 

qb = sqrt(g*k / M); 

 

ta = atan(v / qa) / qb + t; 

 

if(a>=110){ 

 

std::cout << std::endl << "Apoapsis is equal to:   " << a << std::endl; 

std::cout << "Time to Apoapsis is equal to:   " << ta << std::endl; 

} 

 

else{ 

 

std::cout << "ERROR. APOAPSIS IS POSSIBLY INCORRECT: " << a << std::endl; 

 

} 

 

return 0; 

} 
