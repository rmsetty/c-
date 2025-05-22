#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// Function Prototypes
void readImage(const string& filename, string& format, int& width, int& height, int& maxPixel, int imageData[1000][1000]);
void processImage(int width, int height, int maxPixel, const int original[1000][1000], int processed[1000][1000]);
void writeImage(const string& filename, const string& format, int width, int height, int maxPixel, const int imageData[1000][1000]);

int main()
{
    string inputFile, outputFile;

    // Read input and output file names from standard input
    getline(cin, inputFile);
    getline(cin, outputFile);

    string format;
    int width, height, maxPixel;
    int imageData[1000][1000] = {0};  // Original image data
    int newImageData[1000][1000] = {0};  // Processed image data

    // Step 1: Read the image from the input file
    readImage(inputFile, format, width, height, maxPixel, imageData);

    // Step 2: Process the image to detect edges
    processImage(width, height, maxPixel, imageData, newImageData);

    // Step 3: Write the processed image to the output file
    writeImage(outputFile, format, width - 2, height - 2, maxPixel, newImageData);

    return 0;
}

/**
 * Reads the PGM image from the given file and populates the provided variables.
 * 
 * @param filename  The name of the input file.
 * @param format    Reference to store the image format (e.g., "P2").
 * @param width     Reference to store the image width.
 * @param height    Reference to store the image height.
 * @param maxPixel  Reference to store the maximum pixel value.
 * @param imageData Array to store the image pixel data.
 */
void readImage(const string& filename, string& format, int& width, int& height, int& maxPixel, int imageData[1000][1000])
{
    ifstream inputFile(filename);
    if (!inputFile)
    {
        cerr << "Error: Cannot open input file " << filename << endl;
        return;
    }

    inputFile >> format; // Read the format (e.g., P2)
    if (format != "P2")
    {
        cerr << "Error: Unsupported file format." << endl;
        return;
    }

    inputFile >> width >> height >> maxPixel;

    // Read pixel data row by row
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            inputFile >> imageData[i][j];
        }
    }

    inputFile.close();
}

/**
 * Processes the image to create a new image with edge detection.
 * 
 * @param width      The width of the original image.
 * @param height     The height of the original image.
 * @param maxPixel   The maximum pixel value in the original image.
 * @param original   The original image data.
 * @param processed  The processed image data (output).
 */
void processImage(int width, int height, int maxPixel, const int original[1000][1000], int processed[1000][1000])
{
    for (int i = 1; i < height - 1; ++i)
    {
        for (int j = 1; j < width - 1; ++j)
        {
            // Calculate new pixel value
            int newValue = 4 * original[i][j]
                           - original[i - 1][j]
                           - original[i + 1][j]
                           - original[i][j - 1]
                           - original[i][j + 1];

            // Clamp the value to the range [0, maxPixel]
            processed[i - 1][j - 1] = max(0, min(maxPixel, newValue));
        }
    }
}

/**
 * Writes the processed image data to the given file in PGM format.
 * 
 * @param filename  The name of the output file.
 * @param format    The image format (e.g., "P2").
 * @param width     The width of the processed image.
 * @param height    The height of the processed image.
 * @param maxPixel  The maximum pixel value in the processed image.
 * @param imageData The processed image pixel data.
 */
void writeImage(const string& filename, const string& format, int width, int height, int maxPixel, const int imageData[1000][1000])
{
    ofstream outputFile(filename);
    if (!outputFile)
    {
        cerr << "Error: Cannot open output file " << filename << endl;
        return;
    }

    outputFile << format << endl;
    outputFile << width << " " << height << endl;
    outputFile << maxPixel << endl;

    // Write pixel data row by row
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            outputFile << imageData[i][j] << " ";
        }
        outputFile << endl; // End each row
    }

    outputFile.close();
}
