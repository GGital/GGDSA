#include <stdio.h>

double input(const char *message) {
  double num;
  printf(message);  scanf("%lf", &num);
  return num;
}

void input2(const char *message, double *num) {
  printf(message);
  scanf("%lf", num);
}


int main() {
    double in;
    in = input("Enter a number: ");
    printf("The input1 is %lf.\n", in);
    input2("Enter a number: ", &in);
    printf("The input2 is %lf.\n", in);
  //process();
  //output();

  return 0;
}
