

Welcome to AI DriverLess Car's GitHub page!

AI DriverLess Car is a high performance, flexible architecture which accelerates the development, testing, and deployment of Autonomous Vehicles.



## Table of Contents

1. [Introduction](#introduction)
2. [Prerequisites](#prerequisites)
3. [Individual Versions](#individual-versions)
4. [Architecture](#architecture)
5. [Installation](#installation)
6. [Quick Starts](#quick-starts)
7. [Documents](#documents)

## Introduction

AI DriverLess Car is loaded with new modules and features but needs to be calibrated and configured perfectly before you take it for a spin. Please review the prerequisites and installation steps in detail to ensure that you are well equipped to build and launch AI DriverLess Car. You could also check out AI DriverLess Car's architecture overview for a greater understanding of AI DriverLess Car core technology and platforms.

## Prerequisites

 AI DriverLess Car platform (stable version) is now upgraded with software packages and library dependencies of newer versions including:

1. CUDA upgraded to version 11.1 to support Nvidia Ampere (30x0 series) GPUs,
   with NVIDIA driver >= 455.32
2. LibTorch (both CPU and GPU version) bumped to version 1.7.0 accordingly.

We do not expect a disruption to your current work, but to ease your life of
migration, you would need to:

1. Update NVIDIA driver on your host to version >= 455.32.
  ([Web link](https://www.nvidia.com/Download/index.aspx?lang=en-us))
2. Pull latest code and run the following commands after restarting and
  logging into AI DriverLess Car Development container:

```bash
# Remove Bazel output of previous builds
rm -rf /apollo/.cache/{bazel,build,repos}
# Re-configure bazelrc.


AI DriverLess Car is currently tested on Lincoln MKZ)

* A machine with a 8-core processor and 16GB memory minimum

* NVIDIA Turing GPU is strongly recommended

* Ubuntu 18.04

* NVIDIA driver version 455.32.00 and above ([Web link](https://www.nvidia.com/Download/index.aspx?lang=en-us))

* Docker-CE version 19.03 and above ([Official doc](https://docs.docker.com/engine/install/ubuntu/))

* NVIDIA Container Toolkit ([Official doc](https://github.com/NVIDIA/nvidia-docker))

**Please note**, it is recommended that you install the versions of Apollo in the following order: **1.0 -> whichever version you would like to test out**. The reason behind this recommendation is that you need to confirm whether individual hardware components and modules are functioning correctly, and clear various version test cases before progressing to a higher and more capable version for your safety and the safety of those around you.

## Individual Versions:

The following diagram highlights the scope and features of each AI DriverLess Car release:

![](docs/02_Quick%20Start/demo_guide/images/Apollo_Roadmap_8_0.png)

[**AI DriverLess Car 1.0:**](docs/11_Hardware%20Integration%20and%20Calibration/%E8%BD%A6%E8%BE%86%E9%9B%86%E6%88%90/%E7%A1%AC%E4%BB%B6%E5%AE%89%E8%A3%85hardware%20installation/apollo_1_0_hardware_system_installation_guide.md)

AI DriverLess Car 1.0, also referred to as the Automatic GPS Waypoint Following, works in an enclosed venue such as a test track or parking lot. This installation is necessary to ensure that AI DriverLess Car works perfectly with your vehicle. The diagram below lists the various modules in AI DriverLess Car 1.0.



AI DriverLess Car1.5 is meant for fixed lane cruising. With the addition of LiDAR, vehicles with this version now have better perception of its surroundings and can better map its current position and plan its trajectory for safer maneuvering on its lane. Please note, the modules highlighted in Yellow are additions or upgrades for version 1.5.



AI DriverLess Car supports vehicles autonomously driving on simple urban roads. Vehicles are able to cruise on roads safely, avoid collisions with obstacles, stop at traffic lights, and change lanes if needed to reach their destination.  Please note, the modules highlighted in Red are additions or upgrades for version 2.0.

AI DriverLess Car allows the vehicle to autonomously run on geo-fenced highways with a camera for obstacle detection. Vehicles are able to maintain lane control, cruise and avoid collisions with vehicles ahead of them.



AI DriverLess Car is capable of navigating through complex driving scenarios such as residential and downtown areas. The car now has 360-degree visibility, along with upgraded perception algorithms to handle the changing conditions of urban roads, making the car more secure and aware. Scenario-based planning can navigate through complex scenarios, including unprotected turns and narrow streets often found in residential areas and roads with stop signs.


AI DriverLess Car is an effort to support volume production for Geo-Fenced Autonomous Driving.
The car now has 360-degree visibility, along with upgraded perception deep learning model to handle the changing conditions of complex road scenarios, making the car more secure and aware. Scenario-based planning has been enhanced to support additional scenarios like pull over and crossing bare intersections.


AI DriverLess Car enhances the complex urban road autonomous driving capabilities of previous Apollo releases, by introducing curb-to-curb driving support. With this new addition, AI DriverLess Car is now a leap closer to fully autonomous urban road driving. The car has complete 360-degree visibility, along with upgraded perception deep learning model and a brand new prediction model to handle the changing conditions of complex road and junction scenarios, making the car more secure and aware.


AI DriverLess Car incorporates new deep learning models to enhance the capabilities for certain modules. This version works seamlessly with new additions of data pipeline services to better serve Apollo developers. AI DriverLess Car is also the first version to integrate certain features as a demonstration of our continuous exploration and experimentation efforts towards driverless technology.


AI DriverLess Car incorporates 3 brand new deep learning models to enhance the capabilities for Perception and Prediction modules. 


AI DriverLess Car is an effort to provide an extensible software framework and complete development cycle for Autonomous Driving developer. It introduces easily-reused “Package” to organize software modules. It integrates the whole process of perception development ,by combining model training service, model deployment tool and end-to-end visual validation tool . And another 3 new deep learning models are incorporated in AI DriverLess Car for perception module. Simulation service is upgraded by integrating local simulator in Dreamview to provide powerful debug tool for PnC developer.



## Architecture


## Installation



Congratulations! You have successfully built out AI DriverLess Car without Hardware. If you do have a vehicle and hardware setup for a particular version, please pick the Quickstart guide most relevant to your setup:



## Documents

* [Installation Instructions](docs/01_Installation%20Instructions/)

* [Quick Start](docs/02_Quick%20Start/)

* [Package Management](docs/03_Package%20Management/)

* [CyberRT](docs/04_CyberRT/)

* [Localization](docs/05_Localization/)

* [Perception](docs/06_Perception/)

* [Prediction](docs/07_Prediction/)

* [Planning](docs/08_Planning/)

* [Decider](docs/09_Decider/)

* [Control](docs/10_Control/)

* [Hardware Integration and Calibration](docs/11_Hardware%20Integration%20and%20Calibration/)

* [Map acquisition](docs/12_Map%20acquisition/)

* [Apollo Tool](docs/13_Apollo%20Tool/)

* [Others](docs/14_Others/)

* [FAQs](docs/15_FAQS/README.md)



## Disclaimer

AI DriverLess Car open source platform only has the source code for models, algorithms and processes, which will be integrated with cybersecurity defense strategy in the deployment for commercialization and productization.
