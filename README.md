# TINCAN
A research project on Operating Systems and the ARM architecture. As of now, the project has only been tested on the STM32F429 microcontroller, and it's only expected to work there, but I'll add more support for other boards in the future.

## Goals
- Write a propper boot sequence for multiple architectures:
    - stm32f4xx
    - stm32f0xx
    - Others
- Develop a functional dynamic memory management framework
- Develop a process management system
- Implement a [`ELF`](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format) loading system
- Document everything

## Building And Flashing
Right now this is in a very, VERY, experimental (so basically incomplete) state, so even if you are able to build it, don't expect it to run properly. Also, while you can definetly build this repo and get a `.bin` file out, but it wont be of much use if you don't flash it somewhere. Now, I know this could be simulated in qemu (and if you look through the repo's history, you'll see that I was doing that with a RPI in the past), but I just haven't had the time to set that up again.

### Requirements
**Absolutely needed**
- make
- arm embedded toolchain
- st-flash

**Optional**
- openocd

### Seting Up A Build Environment
**Note: This guide is going to assume you're running Ubuntu or a derivative (and if you aren't you could probably do this steps on your own anyway)**
- Get required packages
    ```bash
    sudo apt update -y
    sudo apt install -y libncurses5 wget build-essential openocd git stlink-tools
    ```
- Clone the repository
    ```bash
    cd [wherever you want to download the repo in]
    git clone https://www.github.com/TheLastBilly/tincan
    cd tincan
    ```
- Download the Arm Development Toolchain

    **Note: Do this step WHILE INSIDE the repo**
    ```bash
    wget https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-rm/8-2018q4/gcc-arm-none-eabi-8-2018-q4-major-linux.tar.bz2
    tar -xvf gcc-arm-none-eabi-8-2018-q4-major-linux.tar.bz2
    mv gcc-arm-none-eabi-8-2018-q4-major-linux toolchain
    ```
    Now, you can use whatever version of the toolchain you like, but keep in mind, I'm using the 2018 major release, so I'd recommend you stick with that one as much as possible

### Build The Project
AS you may have already noticed, this project uses `make` as its build system, so you'll need to learn a couple of commands to get the project running:
- `make`: Will build the project and create a bin file for it
- `make clean`: Will clear any object files created by `make`
- `make rebuild`: Will run `make clean` followed by `make`
- `make flash`: Will flash the program into a board (needs `st-flash`, it will be already installed if you followed the guide)
- `make gdb`: Will start a `gdb` server with the connected board (needs `openocd`, it will be already installed if you followed the guide)

### Bonus: Debugging
#### Building a debug image
This is one of the things I need to work on, but in the mean time, just go into [`globals.config`](./globals.config) and add the `-g` option to `CFLAGS`.

#### GDB
You can of course just run `make gdb` and use the following command to launch a `gdb` client with the generated `tincan.elf` file like a true caveman:
```bash
toolchain/bin/arm-none-eabi-gdb ./tincan.elf -ex "target extended-remote localhost:3333"
```

**Note: I'm using the `3333` port because that's the one that my `make debug` command told me to use, but it may be different in your case.**

But I know you're better than that, and since I also ~~hope~~ know that you're using [`vscode`](https://code.visualstudio.com/), I'll show you how to do it from there instead:

- First, create a file called `./.vscode/launch.json` in the repo's directory and copy the following contents into it.
    ```json
    {
        "version": "0.2.0",
        "configurations": [
            {
                "name": "GDB",
                "type": "gdb",
                "request": "launch",
                "cwd": "${workspaceRoot}",
                "target": "${workspaceRoot}/tincan.elf",
                "gdbpath" : "${workspaceRoot}/toolchain/bin/arm-none-eabi-gdb",
                "autorun": [
                    "target remote localhost:3333",
                    ]
            }
        ]
    }
    ```
    **Note: If you alread have one created just copy the entry from `configurations` into yours (a.k.a: what's in between `"configurations": [` and `]`). Make sure you separate them with a comma.**
- Run `make run` on another terminal window on the repo's directory
- Go into any file you'd like to debug on vscode and click on the "Run and Debug" tab at the left of the screen. Then, select the "GDB" configuration option.
- Voilà!

## Useful Resources
- The [`doc/`]("docs/") folder. (I don't know if I should copy and paste PDFs like that, so I'll take notes out of them later instead)
- [STM32 Baremetal Examples Series](https://vivonomicon.com/category/stm32_baremetal_examples/)
- [Going Bare Metal On STM32](https://karooza.net/going-bare-metal-on-stm32)
- [The STM32F429 (and other MCUs) programming manual](https://www.st.com/resource/en/reference_manual/dm00031020-stm32f405-415-stm32f407-417-stm32f427-437-and-stm32f429-439-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf)