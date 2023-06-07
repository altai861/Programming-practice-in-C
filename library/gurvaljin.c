#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


//gurvaljin_tosoo olohod ashiglana.
void gurvaljin_swap(double* xp, double* yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//gurvaljin_tosoo olohod ashiglana.
void gurvaljin_sort(double massive[], int urt){
    
    bool swapped;
    for (int i = 0; i < urt - 1; i++){
        swapped = false;
        for (int j = 0; j < urt - i - 1; j++){
            if (massive[j] < massive[j + 1]){
                gurvaljin_swap(&massive[j], &massive[j+1]);
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
    }
    
}

//gurvaljin mon esehiig 3 utgaas ni shalgana.
bool gurvaljin_mun_by_values(double a, double b, double c) {
    if (a<=0&&b<=0&&c<= 0)
        return false;
    if (a+b>c&&b+c>a&&c+a>b)
        return true;
    else{
    	return false;
	}
    	
}

//gurvaljin mon esehiig massive aas shalgana.
bool gurvaljin_mun_by_massive(double tri[]){
    int size = sizeof(tri) / sizeof(tri[0]);
    if (size != 3) {
        return false;
    }
    return gurvaljin_mun_by_values(tri[0], tri[1], tri[2]);
}


//gurvaljingiin talbaig 3 utgaas ni olno.
double gurvaljin_talbai(double a,double b,double c)	{
	if(gurvaljin_mun_by_values(a,b,c))
	{
		double s = (a+b+c)/2;
		double talbai=sqrt(s*(s-a)*(s-b)*(s-c));
		return talbai;
	}
	else
	{
		return -1;
	}


}

//2 gurvaljingiin tosoog olno.
bool gurvaljin_tosoo(double taluud1[], double taluud2[]){
    if (gurvaljin_mun_by_massive(taluud1) || gurvaljin_mun_by_massive(taluud2)){
        return false;
    } else {
        gurvaljin_sort(taluud1, 3);
        gurvaljin_sort(taluud2, 3);
        double ratio1 = taluud1[0] / taluud2[0];
        double ratio2 = taluud1[1] / taluud2[1];
        double ratio3 = taluud1[2] / taluud2[2];

        double tolerance = 0.0001;

        if (fabs(ratio1 - ratio2) < tolerance && fabs(ratio2 - ratio3) < tolerance && fabs(ratio1 - ratio3) < tolerance) {
            return true;  // Triangles are similar
        } else {
            return false; // Triangles are not similar
        }
    }
}

// c^2=a^2 + b^2 - 2*a*b*cos(alpha)
double gurvaljin_3_dahi_tal(double a, double b, double angleC) {
    double c;

    double radianC = angleC * (M_PI / 180.0);

    c = sqrt(pow(a, 2) + pow(b, 2) - (2 * a * b * cos(radianC)));

    return c;
}

double gurvaljin_radius(double a, double b, double c)
{
	if (gurvaljin_mun_by_values(a, b, c)){
        double r,h,s,p,radian,pifagor;
	
        pifagor = pow(a,2) + pow(b,2);
        p = (a + b + c)/2;
        
        if(a == b && b == c)
        {
            radian = 60*3.14/180;
            h = a * sin(radian);
            r = h / 3;
            return r;
        }
        else if (pifagor == (c * c))
        {
            r = (a + b - c) / 2;
            return r;
        }
        else 
        {
            s = sqrt(p * (p - a) * (p - b) * (p - c));
            r = s * 2 / (p * 2);
            return r;
        }
    } else {
        return -1;
    }
	
}


double gurvaljin_ondor(double a, double b, double c) {
    double ondor;

    double talbai = gurvaljin_talbai(a, b, c);

    ondor = (2 * talbai) / a;

    return ondor;
}

double gurvaljin_2_tal_nuguu_untsug(double A, double B, double C) {
    double untsug = acos((pow(A, 2) + pow(B, 2) - pow(C, 2)) / (2 * A * B));
    untsug = untsug * 180 / M_PI;
    return untsug;
}
