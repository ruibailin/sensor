# Project README – Sensor Module Challenge

The final submitted version has been carefully designed to demonstrate not only functional correctness, but also robust architectural design and ease of future maintenance. Below are some key highlights of the implementation:

## Key Features

- **Well-defined layered architecture**: The lower layers hide hardware details from the upper layers, making it easy to upgrade hardware or software modules and improve reusability.
- **Comprehensive test environment and test cases**: Includes simulated tests, loopback tests, as well as tests in both bare-metal and OS environments to ensure correctness and robustness.
- **Clean code structure and concise coding style**: Emphasizes clarity and maintainability, following clear coding conventions.
- **Tiny OS-like kernel**: Provides thread-like behavior, as well as support for state saving and timer-based scheduling, similar to a lightweight operating system.
- **Keyboard input command support**: Allows interactive testing of sensor read/write operations, as well as detecting sensor insertion and removal statuses.

## Executable Programs

Additionally, compiled executable programs have been included in the GitHub repository:

- **sensor_bm.exe**: Bare-metal style version. It does not support keyboard input commands but can run directly in the Windows command line environment.
- **sensor_os.exe**: OS-style version. This version supports keyboard input commands for interactive testing. It can also run directly in the Windows command line environment.

Both executables allow you to easily verify the core logic and simulate real-world behavior without additional setup.

Please feel free to reach out if you have any questions or need further clarification.
