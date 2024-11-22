#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   // YOUR CODE HERE - BEGIN
// Calculate total frames for each section
    long totalFramesColor = durationMovie * fps;
    long totalFramesBW = durationCredits * fps;

    // Calculate sizes in bytes
    long sizeColor = totalFramesColor * w * h * 3; // Color section (RGB)
    long sizeBW = totalFramesBW * w * h * 1;      // Black-and-white section

    // Total size in bytes
    long totalSizeBytes = sizeColor + sizeBW;

    // Convert to requested unit
    if (strcmp(unit, "bt") == 0) {
        return (float)totalSizeBytes; // Size in bytes
    } else if (strcmp(unit, "ko") == 0) {
        return (float)totalSizeBytes / 1000.0; // Size in kilobytes
    } else if (strcmp(unit, "mo") == 0) {
        return (float)totalSizeBytes / (1000.0 * 1000.0); // Size in megabytes
    } else if (strcmp(unit, "go") == 0) {
        return (float)totalSizeBytes / (1000.0 * 1000.0 * 1000.0); // Size in gigabytes
    } else {
        printf("Unknown unit: %s\n", unit);
        return -1; // Error value for unknown unit
    }
}

// Main function to demonstrate the usage of video function
int main() {
    int width, height, durationMovie, durationCredits, fps;
    char unit[3];

    // Prompt user for input
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the duration of the colored section (in seconds): ");
    scanf("%d", &durationMovie);
    printf("Enter the duration of the black-and-white section (in seconds): ");
    scanf("%d", &durationCredits);
    printf("Enter frames per second (fps): ");
    scanf("%d", &fps);
    printf("Enter the desired unit (bt/ko/mo/go): ");
    scanf("%s", unit);

    // Calculate size in specified unit
    float sizeInUnit = video(width, height, durationMovie, durationCredits, fps, unit);

    // Print result
    if (sizeInUnit != -1) {
        printf("Size of video: %.2f %s\n", sizeInUnit, unit);
    }
   // YOUR CODE HERE - END
   return 0;
}
