# Exam3SpectrogramProof

## Overview

This project is a simple spectrogram-style program written in C++ using basic object-oriented programming. It performs a Fast Fourier Transform (FFT) on a cosine wave to visualize frequency components numerically and graphically.

## Purpose

I created this program for three main reasons, in order of importance:

1. **To learn basic C++ object-oriented programming (OOP)** — This project helped me practice using classes, constructors, destructors, and method organization in C++.
2. **To refactor and improve my existing spectrogram code** — By separating logic into cleaner modules, this version lays the groundwork for cleaner future implementations.
3. **To demonstrate that Exam 3, Question 8 had a second valid answer** — I was marked off for using 0-based indexing in my answer, even though the question allowed for either MATLAB or Python (which use 1- and 0-indexing respectively). This program demonstrates that when using a 0-indexed environment, the frequency component at 1/7 Hz appears between indices 156 and 157, not 157 and 158.

## What the Program Does

- Initializes a cosine wave with:
  - **1095 samples**
  - **Frequency**: 1/7 Hz
  - **Sampling rate**: 1 sample per second
- Computes the FFT using the [FFTW3](http://www.fftw.org/) library
- Displays:
  - The magnitudes of the FFT output
  - A simple console-based graph of the signal

## Key Output

When the input signal has a frequency of 1/7 Hz, the FFT output shows clear peaks at **indices 156 and 157**. This confirms the expected bin alignment in a 0-indexed environment and supports the answer I gave on the exam.

## Build Instructions (note that I have not tested these)

### Dependencies

- [FFTW3](http://www.fftw.org/) (linked dynamically)
- CMake ≥ 3.29
- A C++20-capable compiler (e.g., MinGW-w64, MSVC, Clang)

### Build (with vcpkg or system-installed FFTW)

```bash
git clone https://github.com/yourusername/Exam3SpectrogramProof.git
cd Exam3SpectrogramProof
mkdir build && cd build
cmake ..
cmake --build .
