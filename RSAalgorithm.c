#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ham kiem tra so nguyen to
int isPrime(long long p){
	int i=2;
	if(p<2) return -1;
	for (i;i<=sqrt(p);i++){
		if(p%i==0 )return -1;		
	}
	return 1;
}
// ham tinh UCLN
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


// Ham tinh nghich dao modulo
long long tinhD(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1) return 0;

    // Euclid mo rong
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

// ham ma hoa RSA
long long maHoa(long long m, long long e, long long n){
    long long c = 1;
    while (e > 0) {
        if (e % 2 == 1)
            c = (c * m) % n;
        m = (m * m) % n;
        e /= 2;
    }
    return c;
}

// Ham giai ma RSA
long long giaiMa(long long c, long long d, long long n){
    long long m = 1;
    while (d > 0) {
        if (d % 2 == 1)
            m = (m * c) % n;
        c = (c * c) % n;
        d /= 2;
    }
    return m;
}

int main() {
    long long p, q, e;

    // nhap cac gia tri p,q,e tu ban phim
    while(1){
    	printf("Nhap so nguyen to p va q: ");
    	scanf("%lld %lld",&p, &q);
    	if(isPrime(p)==1 && isPrime(q)==1) break;
	}
	
	//tinh n
    long long n = p * q;
    // phi_n = (p-1)(q-1)
    long long phi_n = (p - 1) * (q - 1);
	while(1){
		printf("( 0 < e < phi_n, gcd(e,n)=1 ), nhap gia tri e: ");
		scanf("%lld",&e);
		if(gcd(e,n)==1 && 0<e &&e < phi_n) break;
	}
    //tinh d*e dong du voi 1(mod phi_n)
    long long d = tinhD(e, phi_n);

    //in ra khoa cong khai va khoa bi mat
    printf("Khoa cong khai (e, n): (%lld, %lld)\n", e, n);
    printf("Khoa bi mat (d, n): (%lld, %lld)\n", d, n);

    // nhap thong diep tu ban phim
    long long m;
    printf("Nhap vao thong diep can ma hoa: ");
    scanf("%lld", &m);

    // in ra thong diep da ma hoa
    long long c = maHoa(m, e, n);
    printf("Thong diep da duoc ma hoa: %lld\n", c);

    // in ra thong diep da giai ma
    long long g = giaiMa(c, d, n);
    printf("Thong diep da duoc giai ma: %lld\n", g);

    return 0;
}

