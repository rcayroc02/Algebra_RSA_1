#include <iostream>
#include<vector>
#include<time.h>
using namespace std;


int euclid_extent(int a, int b) {
    int  x, x0, y, y0, q, r, z0, z1;
    int g;

    x = 0;
    y = 1;

    x0 = 1;
    y0 = 0;

    while (a != 0) {
        q = b / a;
        r = b - q * a;
        z0 = x - (q * x0);
        z1 = y - (q * y0);

        b = a;
        a = r;

        x = x0;
        y = y0;

        x0 = z0;
        y0 = z1;
    }

    g = b;


    return x;

}


int euclides(int a, int b) {

    vector <int> arr;
    int gcd;
    int a1 = a, b1 = b, q, r, n = 0;

    q = a1 / b1;
    r = a1 - (q * b1);


    a1 = b1;
    b1 = r;
    arr.push_back(q);



    while (r > 0) {
        q = a1 / b1;
        r = a1 - (q * b1);
        arr.push_back(q);
        a1 = b1;
        b1 = r;
        n++;
    }

    return a1;

}

int inversa(int a, int b) {
    return euclid_extent(a, b);
}

int generador_e(int phi_n, int n) {

    int e = rand() %  (n-1)+ 2;

    if (euclides(e, phi_n) != 1) {

        while (euclides(e, phi_n) != 1) {
            e = rand() % (n - 1) + 2;
        }
    }

    return e;
}


int exp_modular(int a, int b, int M) {
    int r = 1;


    while (b > 0) {
        if (b % 2) {
            r = (r * a) % M;
        }
        a = (a * a) % M;
        b = b / 2;
    }
    return r;

}

class RSA_NAIVEGENERATOR{
public:
    int p ;
    int q;
    int n ;
    int phi_n ;
    int e ;
    int d;

    RSA_NAIVEGENERATOR(){
        p = 5;
        q = 7;
         n = p * q;
        phi_n = (p - 1) * (q - 1);
        e = generador_e(phi_n, n);
        d = inversa(e, phi_n);
    }

    int cifrar(int M) {
        
        int C = exp_modular(M, e, n);
        cout << "cifrado" << C << endl;

    }


    int descifrar(int M) {
        int D = exp_modular(M, d, n);
        cout << "descifrado" << D << endl;
    }


};




int main() {

    srand(time(NULL));
    RSA_NAIVEGENERATOR PRIMERO;
   
}