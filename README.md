# Herd Management and Tracking
The HMT (Herd Management and Tracking) system is a comprehensive cattle management platform that takes an individualized, animal-centric approach, from identifying each animal to tracking veterinary and pasture data. In addition to supplying animal-specific information, it also allows for herd enumeration and the detection of absent animals in particular property areas, such as pastures. 

![HMT-overview-modules](https://github.com/milliandrade/herd_identification/assets/7432858/f176e0b9-60b5-4fc8-af49-33228794e4af)

The figure above presents an overview of the HMT system components. The ground station (1) deploys the UAVs (3) to detect and count the cattle (4) using identification algorithms modeled for the farm module. The acquired information flows to the cloud (5) via the ground station. The management system (6) gathers data from the ground station, UAVs, and associated devices. It also sends parameters for virtual fence settings (2) to the ground station in order to delineate the path of the tracking UAVs.


# Farm module
The farm module holds the utmost significance for the HMT system as it provides an outline and monitoring mechanism for all activities related to the control and maintenance of PLF on farms. The livestock farm elements, including the devices and animals, are structured within the Farm subsystem, which comprises elements (1), (3), (4), and (5) as depicted in figure above. This module is all simulated using the[ GrADyS-SIM]([url](https://github.com/brunoolivieri/gradys-simulations)) simulator.

This repository contains simulations for the farm module, with information regarding the simulator utilized, elements, and scanning algorithm models executed by drones. The drones identify animals within their communication range in a delimited area that represents a farm pasture.

## Installation Guide

There are three methods for installing and utilizing Gradys-Sim, the essential tool for simulating the farm module identification and tracking algorithm. The initial approach is to obtain the offered virtual appliance, which can be imported into any virtual machine software supporting the .ova file format.  And finally, the third step is to execute a Docker image with the installation of GrADys-SIM. 

### Virtualization
Download the virtual appliance file (.ova) at [this link](https://drive.google.com/file/d/1IlgWMdPeYZH246wYP_pVjzWEvD9X_tZH/view?usp=sharing) and import it into any virtual machine software that supports the .ova format. The imported virtual machine should already contain a user named "gradys" with the password "gradys". We recommend using [Oracle's VirtualBox](https://www.virtualbox.org/).

### Local Instalation
In order to run the simulations and use the components in this repository you need to have both OMNeT++ and the INET framework installed.

Version 6.0.1 of OMNeT++ is required, to install it just follow [these instructions](https://brunoolivieri.github.io/InstallGuide.pdf). INET version 4.5.0 is also required, when first opening the OMNeT++ IDE you should be prompted with the option to install INET and all you need to do is accept it but if you need help [check out the installation instructions](https://inet.omnetpp.org/Installation.html).

After installing both OMNeT++ and INET you should be able to clone the repository to your active OMNeT++ IDE workspace. To do this select File > Import... then open the "git" section and select "Projects from git" then "Clone Url". After that just fill in the URL for this repository and finish the process following the displayed instructions.

Make sure you have INET installed in your workspace and that it is selected as project reference. If you see a directory named inet, inet4.5 in your workspace INET is installed and you only need to check if its also selected for the gradys-simulations project. This can be done the following way: Right Click on herd_identification project -> Properties -> Project References. Make sure INET is selected.

### Docker image
#### If you are using a Linux machine...
_**Requirements:** docker_

_Note: We recommend the use of Ubuntu 20.04 LTS distribution._

If there is no docker installed, update apt's package index and install packages to allow apt to use a repository over HTTPS:

    sudo apt update
    sudo apt install apt-transport-https ca-certificates curl software-properties-common

Add the official GPG key of the Docker repository:
   
    curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
    
Add the Docker repository to the system:

    sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"

Update apt's package index again and install Docker:

    sudo apt update
    sudo apt install docker-ce

Check that Docker has been installed correctly:

    sudo systemctl status docker

    
#### If you are using Windows 10 or higher...
_**Requirements:** WSL2, DOcker Desktop, Ubuntu 20.04_

First you will need to install the Docker Desktop, following [these instructions](https://docs.docker.com/desktop/install/windows-install/).

If you do not have the WSL2 installed in your machine, open the Microsoft Store app and search for WSL2 (Windows Subsystem for Linux) and click in the _Get_ button. Reboot your machine after the initial installation to complete the setup.

_Note: You can also install Ubuntu from the command line, following [these instructions](https://ubuntu.com/tutorials/install-ubuntu-on-wsl2-on-windows-11-with-gui-support#2-install-wsl)._

With WSL2 installed, open the Microsoft Store app and search for Ubuntu 20.04.6 LTS and click in the _Get_ button. After installation, you have two options to access the application: launch it directly from the store or search for Ubuntu using the Windows search bar.

_Note: You can also install Ubuntu from the command line, following [these instructions](https://ubuntu.com/tutorials/install-ubuntu-on-wsl2-on-windows-11-with-gui-support#3-download-ubuntu)._

On the first use, it will execute a setup, which can take a few time, and you will need to create a username and password (this does not need to match your Windows user credentials). When it is ready for use, we recomend to install the latest updates with the following commands, entering your password when prompted.

      sudo apt update        
      sudo apt full-upgrade
      
  Press Y when prompted.

Now that your linux instalation is set and updated, install a GUI package to be able to run and see the simulation in a 2D or 3D maps in GrADyS-SIM. Follow [these instructions](https://ubuntu.com/tutorials/install-ubuntu-on-wsl2-on-windows-11-with-gui-support#5-install-and-use-a-gui-package) to install and configure the GUI package.
    
#### Execute docker...

Configure the enviroment to run the docker image, enabling the execution of GUI application throught docker, entering the following commands:

      export DISPLAY=:0.0
      xhost +local:docker
      export LIBGL_ALWAYS_SOFTWARE=1
      export MESA_GL_VERSION_OVERRIDE=3.3

Then, execute the docker using the command: 

      docker run -ti -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix kamysek/gradys-simulations bash

If you want to store the information executed in docker in a local directory, you can map a directory changing the command above by:
      
      docker run -v <mapping_dir>:<mapping_dir> -ti -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix kamysek/gradys-simulations bash      

In the docker image, execute:

      omnetpp &


## Documentation
More information can be found on the [project's official documentation](link)
