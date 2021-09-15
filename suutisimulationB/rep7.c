#include<stdio.h>
#include<math.h>

// d(dx/dt)/dt
double f(double x, double y, double t){
    return -2.0 * x - 2.0 * y;
}

// dx/dt
double g(double x, double y, double t){
    return y;
}

// 厳密解
double trueValue(double t){
    return exp(-1.0*t) * cos(t);
}

int main(void){
    double x = 1.0;                 // 初期値
    double y = -1.0;                // 初期値
    double pi = 3.14159265358979323846;
    double h = 0.1 * 2.0 * pi;    // 刻み幅
    double start = 0.0;             // 始点
    double finish = 2.0 * pi;     // 終点
    
    double k1, k2, k3, k4;
    double l1, l2, l3, l4;
    double t = start;

    printf("   Step = %f\n\n", h);

    while(t < finish){
        k1 = g(x, y, t);
        l1 = f(x, y, t);
        k2 = g(x+h*k1/2.0, y+h*l1/2.0, t+h/2.0);
        l2 = f(x+h*k1/2.0, y+h*l1/2.0, t+h/2.0);
        k3 = g(x+h*k2/2.0, y+h*l2/2.0, t+h/2.0);
        l3 = f(x+h*k2/2.0, y+h*l2/2.0, t+h/2.0);
        k4 = g(x+h*k3, y+h*l3, t+h);
        l4 = f(x+h*k3, y+h*l3, t+h);
        x = x + h * (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        y = y + h * (l1 + 2*l2 + 2*l3 + l4) / 6.0;
        t += h;
        
        // 途中経過表示
        printf("   ### t = %f ###\n", t);
        printf("      x         = %.10f\n", x);
        printf("      TrueValue = %.10f\n", trueValue(t));
        printf("      Error     = %.10f\n", fabs(x-trueValue(t)));
    }
    return 0;
}