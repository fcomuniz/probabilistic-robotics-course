#!/usr/bin/env bash

function install_initial_dependecies(){

sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install libboost-all-dev
sudo apt-get install libgtk2.0-dev pkg-config python-numpy python-dev libavcodec-dev libavformat-dev libswscale-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libopencv-dev checkinstall yasm libjpeg-dev libjasper-dev libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev libxine2-dev libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev libv4l-dev python-dev python-numpy libtbb-dev libqt4-dev libgtk2.0-dev libmp3lame-dev libopencore-amrnb-dev libopencore-amrwb-dev libtheora-dev libvorbis-dev libxvidcore-dev x264 v4l-utils libois-dev libxaw7-dev v4l2ucp libqt4-opengl libqt4-opengl-dev libboost-all-dev libeigen3-dev libfreeimage3


}
function install_cmake(){

pushd $HOME
wget https://cmake.org/files/v3.5/cmake-3.5.2.tar.gz
tar -xvf cmake-3.5.2.tar.gz
cd cmake-3.5.2
./configure
sudo mkdir build
cd build
cmake ..
make -j 4
sudo make install
sudo ldconfig
popd

}

function install_eigen(){

pushd $HOME
wget http://bitbucket.org/eigen/eigen/get/3.2.8.tar.gz
tar -xvf 3.2.8.tar.gz
cd eigen-eigen-07105f7125
mkdir -p build
make -j 4
sudo make install
popd

}

function install_cpp_14(){
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install libboost-all-dev
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install gcc-5 g++-5 cpp-5
cd /usr/bin
sudo rm gcc g++ cpp
sudo ln -s gcc-5 gcc
sudo ln -s g++-5 g++
sudo ln -s cpp-5 cpp

}

function install_qt5(){
# https://wiki.qt.io/Install_Qt_5_on_Ubuntu
pushd $HOME
wget http://download.qt.io/official_releases/qt/5.7/5.7.0/qt-opensource-linux-x64-5.7.0.run
chmod +x qt-opensource-linux-x64-5.7.0.run
./qt-opensource-linux-x64-5.7.0.run
sudo apt-get install build-essential
sudo apt-get install libfontconfig1
sudo apt-get install mesa-common-dev
sudo apt-get install libglu1-mesa-dev -y
popd

}

#Installing files

install_cmake
install_cpp_14
install_eigen
install_qt5
