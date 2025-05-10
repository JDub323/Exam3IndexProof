cmake_minimum_required(VERSION 3.29)
project(Exam3SpectrogramProof)

set(CMAKE_CXX_STANDARD 20)

add_executable(Exam3SpectrogramProof main.cpp
        Spectrogram.cpp
        Spectrogram.h)

# before find_package:
set(FFTW3_DIR "C:/Users/jwhal/.vcpkg-clion/vcpkg/packages/fftw3_x64-mingw-dynamic/share/fftw3/")
find_package(FFTW3 CONFIG REQUIRED)
target_link_libraries(Exam3SpectrogramProof PRIVATE FFTW3::fftw3)