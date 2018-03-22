#!/bin/bash

WORKSPACE=~/ADEPT_ws
SOURCE=$WORKSPACE/src
GIT=https://github.com/adept2018
GIT_ADEPT=$GIT/ADEPT.git
GIT_LOCALIZATION=$GIT/LOCALIZATION.git
GIT_PERCEPTION=$GIT/PERCEPTION.git
GIT_MOTIONPLANNING=$GIT/MOTIONPLANNING.git
GIT_CONTROL=$GIT/CONTROL.git
GIT_LAUNCH=$GIT/LAUNCH.git

echo 'Creating workspace folder at: ' $WORKSPACE 
mkdir -p $SOURCE
cd $SOURCE

echo 'Downloading repository: ' $GIT_LOCALIZATION
git clone $GIT_LOCALIZATION

echo 'Downloading repository: ' $GIT_PERCEPTION
git clone $GIT_PERCEPTION

echo 'Downloading repository: ' $GIT_MOTIONPLANNING
git clone $GIT_MOTIONPLANNING

echo 'Downloading repository: ' $GIT_CONTROL
git clone $GIT_CONTROL

echo 'Building...'
cd $WORKSPACE
catkin_make

