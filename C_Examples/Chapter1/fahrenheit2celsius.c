#include <stdio.h>

/* print Fahrenheit-Celsius table
	  for fahr = 0, 20, ..., 300 */
float convert(float fahrenheit){
  float celsius = 5 * (fahrenheit -32) /9;
  return celsius;
}

int main() {
  float fahren, celsius;
  printf("Farenheit: ");
  scanf("%f", &fahren);
  printf("Celsius: ");
  printf("%f\n", convert(fahren));
  return(0);
}
