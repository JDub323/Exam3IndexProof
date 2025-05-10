#include <iostream>
#include "Spectrogram.h"

int main() {
    auto proof = Spectrogram(1095, 1095 * 1, 1.0 / 7);
    proof.displayImportantData();
    proof.graphOutput();
    return 0;
}
