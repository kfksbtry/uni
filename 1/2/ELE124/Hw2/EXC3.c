#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Hunerler(float itemPrice, float* donationTotal, float* profitTotal);

int main(void) {
  srand(time(NULL));
  
  float donationTotal = 0, profitTotal = 0;
  FILE* outf = fopen("donations.txt", "w");
  
  for (int i = 0; i < 50; i++) {
  	float price = (float) (rand() % 2001) / 100;
  	
  	Hunerler(price, &donationTotal, &profitTotal);
  	
  	fprintf(outf, "Item is %.2f\n", price);
  }
  
  fprintf(outf, "Donation is %.2f\nProfit is %.2f\n", donationTotal, profitTotal);
  fclose(outf);

  system("pause");
}

void Hunerler(float itemPrice, float* donationTotal, float* profitTotal) {
  *profitTotal += (int) itemPrice;
  *donationTotal += itemPrice - (int) itemPrice;
}