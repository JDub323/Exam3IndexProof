//
// Created by jwhal on 5/8/2025.
//

#include "Spectrogram.h"

#include <cmath>
#include <iostream>

double Spectrogram::abs(const fftw_complex n) {
    return sqrt(n[0] * n[0] + n[1] * n[1]);
}

void Spectrogram::graphInput() const {
    for (int i = 0; i < SAMPLE_COUNT; i++)
        graphVal(inputData[i]);
}

void Spectrogram::graphOutput() {
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        std::cout << "index: " << i;
        graphVal(abs(outputData[i]));
    }
}

void Spectrogram::graphVal(double val) {
    static constexpr double maxVal = 4000;
    static constexpr double width = 40;
    if (val > 0) {
        for (int i = 0; i < 10; i++) std::cout << " ";

        for (double i = 0; i < val; i += maxVal / width)
            std::cout << "#";
    }
    if (val < 0) {
        int count = 0;
        for (double i = 0; i < val; i += maxVal / width) {
            count++;
            std::cout << " ";
        }

        for (; count < width; count++) {
            std::cout << "#";
        }
    }
    std::cout << std::endl;
}

Spectrogram::Spectrogram(const int timeInterval, const int numSamples, const double freq) :
timeInterval(timeInterval), SAMPLE_COUNT(numSamples), freq(freq) {
    //sample count, time interval, and freq all initialized by init list. Note that
    //for the purposes of this demonstration, the sample count does not actually matter

    //allocate memory for inputData
    inputData.reserve(SAMPLE_COUNT);

    //allocate memory for outputData
    outputData = static_cast<fftw_complex *>(fftw_malloc(sizeof(fftw_complex) * (SAMPLE_COUNT)));
    if (outputData == nullptr) {
        printf("Could not allocate spectrogram data\n");
        exit(EXIT_FAILURE);
    }

    //creates the plan to be used for fftw
    p = fftw_plan_dft_r2c_1d(SAMPLE_COUNT, inputData.data(), outputData, FFTW_MEASURE);

    //init inputData with a cosine wave with frequency freq. Note that making the plan with FFTW_MEASURE makes all the values in
    //inputData 0, so this must be after the plan is made
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        inputData.push_back(10 * std::cos(2 * std::numbers::pi * freq * i));
    }

    //take the fft to init output. Note that output is a vector of complex values, so I will
    //have to take the complex absolute value to get the magnitude of the frequency at that spot
    fftw_execute(p);
}

void Spectrogram::displayOutputData() {
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        std::cout << "Index: " << i << " has magnitude: " << abs(outputData[i]) << std::endl;
    }
}

void Spectrogram::displayImportantData() {
    for (int i = 152; i < 161; i++) {
        std::cout << "Index: " << i << " has magnitude: " << abs(outputData[i]) << std::endl;
    }
}
