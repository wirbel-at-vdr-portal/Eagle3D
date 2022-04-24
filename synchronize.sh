#!/bin/bash

rsync -a --delete "/C/Programme_2/Povray3.7/include/Eagle3D/" povray
rsync -a --delete "/C/Programme_2/EAGLE-7.6.0/ulp/" ulp

git status
