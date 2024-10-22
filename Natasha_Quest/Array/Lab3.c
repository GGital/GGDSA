#include<stdio.h>
#include<math.h>

int main() {
    int n; scanf("%d" , &n);
    double sd = 0.0;
    double data[n];
    double mean = 0.0;
    for(int i = 0; i < n; i++) {
        scanf("%lf" , &data[i]);
        mean += data[i];
    }
    mean /= n;
    double sum = 0.0;
    for(int i = 0; i < n; i++) {
        sum += pow(data[i] - mean , 2);
    }
    sd = sqrt(sum / n);
    printf("%lf %lf %lf" , mean , sum , sd);
    return 0;
}
