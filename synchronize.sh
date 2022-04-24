#!/bin/bash

rsync -a --delete "/C/Programme_2/POV-Ray-v3.7/include/Eagle3D/" povray
rsync -a --delete "/C/J_Programme/Eagle-7.6.0/ulp/" ulp

git status
