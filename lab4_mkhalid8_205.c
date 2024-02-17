/*
Momin Khalid and G01265434
CS 262, Lab section 205
Lab 3
*/

#include <stdio.h>
#include <stdlib.h> // For abs()

// Calculates the inner angle between hour and minute hands, considering discrete movement
double calculateAngle(int hour, int minute) {

	double minuteAngle = minute * 6; // Each minute is 6 degrees (360 degrees / 60 minutes)
	double hourAngle = (hour % 12) * 30 + (minute * 0.5); // Each hour is 30 degrees (360 degrees / 12 hours), plus the minute's effect on the hour hand

	double angle = minuteAngle - hourAngle; // Calculate angle from hour to minute hand, ensuring it's the clockwise direction

	// Normalize the angle to be within 0 to 360 degrees
	if (angle < 0) {
		angle += 360; // Adjust if the angle is negative, ensuring clockwise direction
	}

	return angle;
}

int main() {
	double A;
	
	
	printf("Enter the angle (0 to 180): ");
	scanf("%lf", &A);

	if (A < 0 || A > 180) {
		printf("Angle must be between 0 and 180 degrees.\n");
		return 1;
	}
	int timesFound = 0;

	 for(int hour = 0; hour < 24; hour++) {
		for(int minute = 0; minute < 60; minute++) {
			if(calculateAngle(hour, minute) == A) { // Considering floating-point precision
				if(timesFound == 0) {
					printf("Times when the hands are %d degrees apart:\n", (int)A);
				}

				printf("%02d:%02d\n", hour, minute);
				timesFound++;
			}
		}
	}

	if(timesFound == 0) {
		printf("There is no hour where the hands are %d degrees apart.\n", A);
	} else {
		printf("Total occurrences: %d\n", timesFound);
	}

	return 0;
}


