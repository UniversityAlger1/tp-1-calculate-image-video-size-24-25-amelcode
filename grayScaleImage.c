#include "config/grayScaleImage.h"
// Parameters:
//   w: width of the image
//   h: height of the image
// Return value
//   grayScale size of the image Bitmap (in byte)
float grayScaleImage(int w, int h) {
   // YOUR CODE HERE - BEGIN
  // Calculate the size in bytes
    long sizeInBytes = w * h; // Each pixel is 1 byte

    return (float)sizeInBytes; // Return the size as a float
}

// Main function to demonstrate the usage of grayScaleImage function
int main() {
    int width, height;

    // Prompt user for input
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);

    // Calculate size in bytes
    float sizeInBytes = grayScaleImage(width, height);

    // Print result
    printf("Size of grayscale image: %.2f bytes\n", sizeInBytes);
   // YOUR CODE HERE - END
   return 0;
}
