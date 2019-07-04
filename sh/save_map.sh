#!/bin/bash

#rosservice call /finish_trajectory 0

#if the folder is not exist create it else do not thing
#createmapdir=${HOME}'/map/'
createmapdir='/root/tic_map/'
if [ ! -d ${createmapdir} ]
then	
    mkdir ${createmapdir}
    echo "Create map dir is ${createmapdir}!"
else
    echo "Dir is exist, continue create sub dir by time!"
fi


#foldername=`date +%Y%m%d`_`date +%H%M%S`
foldername=$1
if [ ! -d ${foldername} ]
then
    cd ${createmapdir}
    mkdir ${foldername}
    echo "Create map sub dir is ${foldername}!"
else
    echo "Sub dir is exist, continue create map pbstream file!"
fi


#if the file is not exist create it else do not thing
#createmapfiledir=${HOME}'/map/'${foldername}
createmapfiledir='/root/tic_map/'${foldername}
filename=`date +%Y%m%d`_`date +%H%M%S`
if [ ! -f ${filename} ]
then
    cd ${createmapfiledir}
    pbstreamname=${filename}'.pbstream'
    touch ${pbstreamname}
    echo "Create file is ${pbstreamname}!"
else
    echo "File is exist, save map!"
fi

#save map
#pbstreamnamedir=${HOME}'/map/'${foldername}/${pbstreamname}
pbstreamnamedir='/root/tic_map/'${foldername}/${pbstreamname}
rosservice call /write_state "{filename: ${pbstreamnamedir}, include_unfinished_submaps: true}"

#use default map name or user can define which they want to use
if [ $# -ge 1 ]
then
    mapname=$1
    echo "Create map is ${mapname}"
else
    mapname='ist_map'
    echo "Create default map is ${mapname}"
fi


rosrun ist_slam_ros ist_slam_pbstream_to_ros_map -map_filestem=${createmapfiledir}/${mapname} -pbstream_filename=${createmapfiledir}/${pbstreamname} -resolution=0.05
#MAPFILE=${createmapfiledir}/${mapname}'.yaml'
#echo "export MAPFILE=${MAPFILE}" >> ~/.bashrc
#source ~/.bashrc
#echo "Save map is ${MAPFILE}!"
if [ $? -eq 0 ]
then
    echo "Save map success!"
else
    echo "Save map failed, please try again!"
fi

