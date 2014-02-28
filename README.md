POKER Robotics's 2014 Aerial Assist robot code.

It requires the following from the [C++11 Toolchain for the cRIO](http://firstforge.wpilib.edu/sf/projects/c--11_toolchain):
* Binutils for vxWorks
* GCC for vxWorks
* The vxWorks headers
* C++11 WPILib
* frcmake
* wput (if you want to deploy code from the build machine)

For installation instructions, check out the [wiki](http://firstforge.wpilib.edu/sf/wiki/do/viewPage/projects.c--11_toolchain/wiki/HomePage).

To build the project:
1. Make a directory for the build: ```mkdir <build dir>```
2. ```cd``` into it and run ```frcmake <project dir>```
3. Run ```make``` to compile
4. When connected to the robot, run ```make deploy``` to deploy the code
5. Whenever you change the code, you can now just run ```make -C <build dir>``` from the project directory (or anywhere) to rebuild
6. Whenever you add, move, or delete files in the project, you can now just run ```frcmake <build dir>``` from the project directory (or anywhere) to remake the makefiles
