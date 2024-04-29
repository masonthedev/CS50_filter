# CS50_filter

My assignment was to create filters you could apply to provided images. Below is the how each functionw as implemented. 

1. Grayscale Function (grayscale):
Converts a color image into grayscale by taking the average of the red, green, and blue components of each pixel and updating the pixel values to grayscale equivalents.

2. Sepia Function (sepia):
Applies a sepia tone effect to the image by transforming each pixel's color values based on predefined formulas to simulate an old-fashioned sepia tone.

3. Reflect Function (reflect):
Reflects the image horizontally by swapping pixel values between corresponding pixels on the left and right sides of the image.

4.Blur Function (blur):
Blurs the image by applying a box blur effect, which involves averaging the color values of each pixel and its neighboring pixels within a fixed-size window (e.g., 3x3) and updating the pixel values with the computed averages.
Each function operates on a 2D array representing the image, modifying the pixel values according to its specific purpose. The overall goal of these functions is to perform basic image processing tasks such as conversion to grayscale, applying artistic effects like sepia, and enhancing image quality through techniques like blurring and reflection.
