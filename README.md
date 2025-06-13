# MicrocontrollerToolkit

A PlatformIO-based toolkit for microcontroller projects, featuring modular components for sensors, actuators, and displays. This guide will help you set up and run the project in Visual Studio Code on a fresh machine.

---

## Prerequisites

Before you begin, ensure you have the following installed:

- **Visual Studio Code**: [Download here](https://code.visualstudio.com/)
- **PlatformIO IDE Extension for VS Code**: Install from the [VS Code Marketplace](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)
- **Python 3.7+**: [Download here](https://www.python.org/downloads/)
- **Git**: [Download here](https://git-scm.com/downloads)

---

## 1. Clone the Repository

Open a terminal and run:

```sh
git clone <REPOSITORY_URL>
cd MicrocontrollerToolkit
```
Replace `<REPOSITORY_URL>` with your repository's URL (e.g., from GitHub).

---

## 2. Open the Project in VS Code

1. Launch Visual Studio Code.
2. Click **File > Open Folder...** and select the `MicrocontrollerToolkit` directory.
3. If prompted, click **Yes** to open the workspace.

---

## 3. Install PlatformIO & Dependencies

- If you haven't already, install the **PlatformIO IDE** extension from the Extensions sidebar (`Ctrl+Shift+X` or `Cmd+Shift+X`).
- PlatformIO will automatically detect the `platformio.ini` file and install required toolchains and libraries on first build.
- To manually install dependencies, open the PlatformIO sidebar (alien icon) and click **Install** under **Quick Access**.

---

## 4. Build, Upload, and Monitor the Project

### Build the Project

Click the checkmark (**Build**) icon in the blue PlatformIO toolbar at the bottom, or run:

```sh
platformio run
```

### Upload to the Microcontroller

Connect your board via USB, then click the right-arrow (**Upload**) icon or run:

```sh
platformio run --target upload
```

### Monitor Serial Output

Click the plug (**Monitor**) icon or run:

```sh
platformio device monitor
```

---

## 5. Troubleshooting & FAQs

### PlatformIO Not Found
- Ensure the PlatformIO extension is installed and VS Code has been restarted.
- If using the CLI, ensure `platformio` is in your PATH. Try restarting your terminal or reinstalling PlatformIO.

### Serial Port Not Detected
- Check your USB cable and connection.
- Ensure you have the correct drivers for your board (e.g., CH340, FTDI).
- On macOS, you may need to grant permission to the serial port.

### Library or Dependency Errors
- Open the PlatformIO sidebar and click **Projects > Rebuild IntelliSense Index**.
- Run `platformio run` in the terminal to force dependency installation.

### Common Commands

| Action         | VS Code Button         | Terminal Command                |
|----------------|-----------------------|---------------------------------|
| Build          | ✓ (checkmark)         | `platformio run`                |
| Upload         | → (right arrow)       | `platformio run --target upload`|
| Monitor        | Plug (serial monitor) | `platformio device monitor`     |

---

## 6. Additional Configuration

- Edit `platformio.ini` to change board type, add libraries, or adjust build flags.
- Place your custom libraries in the `lib/` directory.
- Place header files in `include/` and main code in `src/`.

---

## 7. Environment Variables

No special environment variables are required for basic setup. If you add features that require API keys or secrets, document them here.

---

## 8. More Resources

- [PlatformIO Documentation](https://docs.platformio.org/)
- [Arduino Framework Docs](https://www.arduino.cc/reference/en/)
- [PlatformIO Community](https://community.platformio.org/)

---

## 9. Contributing

Pull requests are welcome! For major changes, please open an issue first to discuss what you would like to change.

---

## 10. License

[MIT](LICENSE)
