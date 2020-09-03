

# Compiling and Running CPP Programs

## <u>**General Overview**</u>
These are the instructions for setting up, compiling, building, running, and debugging C++ programs per platform. The settings included in this repo should work on any computer with Visual Studio Code. You will also need to have the proper compilers and debuggers installed (see below). These instructions assume the default directories for the compilers.


## <u>**Using VSC**</u>
Installation instructions for specific platforms are found in the subsequent sections. These next steps assume you have VSC and your compiler installed.

1. Open up the workspace using the file `_LaunchThis.code-workspace`. This should open up VSC as a workspace with all of the necessary settings. If the file type is not already associated with VSC, do so.
1. Create a new, blank file (`File->New File`) from VSC. 
1. Compile and run by hitting `[Ctrl]+[Shift]+B` on Windozzze or `[command]+[shift]+B` on Mac. You can also just use the menu `Terminal->Run Build Task...`. Select `Build and Run C/C++ Application`.
1. To debug, you can select `[F5]` or the menu `Debug->Start Debugging`.

> <b><u>File Names</u></b><br>
> All files MUST be named correctly as the assignment instructions dictate. This includes spacing (don't use any!), capitalization, name of the file, and the correct extensions (`.cpp`). Major points will be taken off for incorrect file names and/or missing files. 
>
> <b><u>Header Information</u></b><br>
> Please include all requested documents for this assignment in this repository. Each file MUST include a `COMMENT AREA` near the top of the page. The comment area must include the following three lines. All assignments for the remainder of this course must contain a variation of the following three lines. You will need to fill in the bracketed sections with the appropriate information (without the square brackets).
> ```
> Project Name: [Title of the Project]
> Author: [Your Full Name]
> Date Last Modified: [Date Modified]
> ```

---

## <u>**Installing (do these once)**</u>
### <u>General Installation (all platforms)</u>
#### Install Visual Studio Code ( https://code.visualstudio.com/ )
1. Go to the website above. Download and install the version appropriate to your computer.
1. The first time you launch VSC, it will probably try to install a few plugins for handling cpp files. This is good! If it needs a little push, you can start the plugin manager (`[command or Ctrl]+[Shift]+X`) and install `C/C++ for Visual Studio Code`.
1. Generally, you will start projects using the file `_LaunchThis.code-workspace`. This should open up VSC as a workspace with all of the necessary settings. If this file type is not already associated with VSC, do so.

---

### <u>Windows Installation Specifics</u>
#### Install MinGW ( http://www.mingw.org )

1. Install the default installer (`mingw-get-setup.exe`) with the default options (in the default location--`C:\MinGW\`).
1. The default installer will do a few things and then take you to the installation manager.
1. From here, under `Basic Setup`, select `mingw32-gcc-g++` and `mingw32-base`.
1. Click the menu `Installation`, then `Apply Changes` and apply the pending actions.
1. Installer will take a while to download and install necessary components. Make sure to reboot when done.

#### Set your Path
1. Click the Windozzze start button and type `advanced system settings` to bring up the system properties window.
1. Click on `Environment Variables` button.
1. In the `System variables` box at the bottom, select `Path` and press the `Edit` button (at the bottom!).
1. Click the `New` button and type `C:\MinGW\bin`.
1. Close all windows and make sure to reboot when done.

#### Optional: Install OpenGL and GLUT ( http://www.transmissionzero.co.uk/software/freeglut-devel/ )
1. Grab the latest version of FreeGLUT for MinGW from the link above and extract the files to your computer. Make sure to get the version for MinGW!
1. Go to the subdirectories of that archive and find three folders: `bin`, `include`, and `lib`. Each of these contains files that need to be copied to the correct location for your program to compile and run. Just use the 32-bit versions (ignore any x64 files or subfolders).
1. Copy the file `freeglut.dll` from bin to the `MinGW/bin` directory (by default, this should be something like `C:\MinGW\bin`).
1. Copy the four files in the folder `GL` under include to the `MinGW/include/GL` directory (by default, this should be `C:\MinGW\include\GL`).
1. Copy the two `a` (`libfreeglut.a` and `libfreeglut_static.a`) files from lib to the `MinGW/lib` directory (by default, this should be `C:\MinGW\lib`).

---

### <u>Mac Installation Specifics</u>

#### Install XCode with C++ Compiler

1. Launch the MacOS Terminal application. In case you are unfamiliar with this, it is a tool that allows you to type in commands and get their results as text output. You will be using the Terminal intermittently during the course. Type `[command]+space` to bring up Spotlight Search and type `terminal`. Press `[return]` to launch.
1. To install the basic C++ compiler and utilities, type `xcode-select --install` and hit `[return]`.  When you do this, it will prompt you to confirm installation. From this point on, the installation is graphical. You will see a download window showing download and installation progress.
   * Note the option `Get Xcode`. Xcode is Apple's integrated development environment for developing software for its computers, phones, and other devices. If you find that interesting, go ahead and download it! However, it is not needed for the course, it is a very large download (9+ GB), the install takes longer, and you can always download it again later.

#### Optional: Install OpenGL and GLUT
There is no need to install anything other than the above to get OpenGL working on a Mac. However, instead of including `<GL/glut.h>`, you will need to include `<GLUT/glut.h>` where ever appropriate. Also, note that not all features (especially advanced concepts like materials and textures) may not work properly.

---

### <u>Linux (Raspbian) Installation Specifics</u>

#### Install Visual Studio Code (Code-OSS)
1. If you've previously installed `code-oss` andit is not working properly (installs other than version 1.29), you'll need to purge it prior to starting:
    ```{bash}
    sudo apt-get purge code-oss
    ```
1. Download GPG signing key from PackageCloud: [https://packagecloud.io/headmelted/codebuilds/gpgkey](https://packagecloud.io/headmelted/codebuilds/gpgkey)
1. Import GPG key
    ```{bash}
    gpg --import /home/pi/Downloads/headmelted-code-oss-0CC3FD642696BFC8.pub.gpg
    gpg --list-keys
     ```
1. Install the PackageCloud repository for code-oss
    ```{bash}
    curl -s https://packagecloud.io/install/repositories/headmelted/codebuilds/script.deb.sh | sudo bash
    ```
1. Install code-oss
    ```{bash}
    sudo apt-get install code-oss=1.29.0-1539702238
    ```
1. Tell `apt` to hold at version 1.29, since 1.32 doesn't work properly
    ```{bash}
    sudo apt-mark hold code-oss
    ```

#### Install GLUT
1. From the terminal, simply type:
    ```{bash}
    sudo apt-get install freeglut3-dev g++
    ```

