# OpenAuto Desktop Head Unit

### Build for Raspberry Pi 3

1. install packages for aasdk

       sudo apt install -y libboost-all-dev libusb-1.0-0-dev libssl-dev cmake libprotobuf-dev protobuf-c-compiler protobuf-compiler

2. install packages for openauto

       sudo apt install -y libqt5multimedia5 libqt5multimedia5-plugins libqt5multimediawidgets5 qtmultimedia5-dev libqt5bluetooth5 libqt5bluetooth5-bin qtconnectivity5-dev pulseaudio librtaudio-dev librtaudio5a

3. clone this repository

       git clone --recursive https://github.com/imchos/openauto-dhu.git
       cd openauto-dhu

5. build

       mkdir build; cd build
       cmake -DCMAKE_BUILD_TYPE=Release -DRPI3_BUILD=TRUE ..
       make -j3
       cd ..

6. run

       ./openauto/bin/autoapp
