#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Hunerler(float itemPrice, float* donationTotal, float* profitTotal);

int main(void) {
	srand(time(NULL));
  
	float donationTotal = 0, profitTotal = 0;

	FILE *outf = fopen("donations.txt", "r"), *temp = fopen("temp_donations.txt", "w");

	if (outf != NULL) {
		char line[50];
		int debounce = 0;

		do {
			fgets(line, sizeof(line), outf);
      
			if (line != NULL && line[0] == 'I') {
				float num;
				char snum[10];
      	
				for (int i = 8; i < strlen(line) - 1; i++) {
					snum[i - 8] = line[i];
				}
				
				num = atof(snum);
				Hunerler(num, &donationTotal, &profitTotal);
				snum[4] = '\0';
				
				fprintf(temp, "%s", line);
			} else debounce = 1;
		} while (!debounce);
	}

	for (int i = 0; i < 50; i++) {
		float price = (float) (rand() % 2001) / 100;
    
		Hunerler(price, &donationTotal, &profitTotal);
    
		fprintf(temp, "Item is %.2f\n", price);
	}
  
	fprintf(temp, "Donation is %.2f\nProfit is %.2f\n", donationTotal, profitTotal);
  
	fclose(outf);
	fclose(temp);

	remove("donations.txt");
	rename("temp_donations.txt", "donations.txt");
	
	system("pause");
}

void Hunerler(float itemPrice, float* donationTotal, float* profitTotal) {
  *profitTotal += (int) itemPrice;
  *donationTotal += itemPrice - (int) itemPrice;
}