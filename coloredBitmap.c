#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   // YOUR CODE HERE - BEGIN
   // Calculate the size in bytes (3 bytes per pixel for RGB)
    long sizeInBytes = w * h * 3;

    // Convert to requested unit
    if (strcmp(unit, "bt") == 0) {
        // Return size in bits
        return sizeInBytes * 8.0; // 1 byte = 8 bits
    } else if (strcmp(unit, "ko") == 0) {
        // Return size in kilobits
        return (sizeInBytes * 8.0) / 1000.0; // 1 kilobit = 1000 bits
    } else if (strcmp(unit, "mo") == 0) {
        // Return size in megabits
        return (sizeInBytes * 8.0) / (1000.0 * 1000.0); // 1 megabit = 1000 kilobits
    } else if (strcmp(unit, "go") == 0) {
        // Return size in gigabits
        return (sizeInBytes * 8.0) / (1000.0 * 1000.0 * 1000.0); // 1 gigabit = 1000 megabits
    } else {
        // If an unknown unit is provided, return -1 or some error value
        printf("Unknown unit: %s\n", unit);
        return -1;
    }
}

// Main function to demonstrate the usage of coloredBitmap function
int main() {
    int width, height;
    char unit[3];

    // Prompt user for input
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the desired unit (bt/ko/mo/go): ");
    scanf("%s", unit);

    // Calculate size in specified unit
    float sizeInUnit = coloredBitmap(width, height, unit);

    // Print result
    if (sizeInUnit != -1) {
        printf("Size of colored image: %.2f %s\n", sizeInUnit, unit);
    }

   // YOUR CODE HERE - END
   return 0;
}
