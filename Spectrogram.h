//
// Created by jwhal on 5/8/2025.
//

#ifndef SPECTROGRAM_H
#define SPECTROGRAM_H

#include <complex>
#include <vector>
#include <fftw3.h>


class Spectrogram {
private:
    const int timeInterval;
    const int SAMPLE_COUNT;
    const double freq;
    std::vector<double> inputData;
    fftw_complex* outputData;
    fftw_plan p;

    static double abs(const fftw_complex);
    static void graphVal(double val);

public:
    Spectrogram(int timeInterval, int numSamples, double freq);
    void displayOutputData();
    void displayImportantData();
    void graphInput() const;
    void graphOutput();
    ~Spectrogram() {
        fftw_destroy_plan(p);
        fftw_free(outputData);
    }
};



#endif //SPECTROGRAM_H
