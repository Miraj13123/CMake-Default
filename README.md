# CMake_Defaults

A minimal CMake learning tool and template for C++ projects.

---

## 📦 Requirements

- **CMake** (version 3.5 or newer) must be installed and available in your PATH.
- A **C++ compiler** must be installed and available in your PATH:
  - For C++ Compilers: [Visit This Link](https://github.com/Miraj13123/extras/blob/main/c_cpp_compilers.md)

---

## 📁 Project Structure

If you use this repository as a template, read this description!

- Folders such as `apps`, `utils` are just examples for organizing your `.cpp` files.  
  You can use any folder names and as many folders/subfolders as you like.
- The `bin` folder is just a suggested name for your build output.  
  You can change it to `build`, `out`, or anything else.

```
.
├── apps/           # Main source files (e.g., main.cpp) [store in any folder you prefer]
├── utils/          # Utility source files (e.g., nRoot.cpp) [store in any folder you prefer]
│                   # The number and names of these folders are up to you.
│
├── bin/            # Build output directory, compiled files (e.g., app.exe)
│
├── CMakeLists.txt  # Main CMake configuration file (required)
│
├── pages/          # Extra markdown tutorial files (optional, can be deleted)
│
└── readme.md       # This file (optional, can be deleted)
```

---

## 🚀 How to Build and Run

Before you begin, **make sure you have created a `CMakeLists.txt` file** in your project root.  
> **Note:** In this project, a suitable `CMakeLists.txt` is already provided in the same folder as this `readme.md`.  
> You can review or edit it as needed before following the steps below.  
> [View CMakeLists.txt](CMakeLists.txt)

### 1. Configure the Project

Open a terminal in the project root and run:

```sh
cmake -S . -B bin -G "MinGW Makefiles"
```

- `-S .` : Source directory (where `CMakeLists.txt` is located)
- `-B bin` : Build directory (where build files and cache will be generated)

### 2. Build the Project

After configuration, build the project with:

```sh
cmake --build bin
```

- This uses the cached settings in `bin` from the previous step.
- The resulting executable (e.g., `app.exe`) will be placed in the `bin` directory.

### 3. Run the Application

From the project root, run:

```sh
bin/app.exe
```
or, if you need to pass arguments:

```sh
bin/app.exe <base> <exponent>
```

---

## 🛠️ Notes

- You can change the build directory name (`bin`) to anything you like (e.g., `build`, `out`).
- To clean the build, simply delete the `bin` directory.
- If you change the generator or toolchain, always delete the build directory and re-run the configuration step.
- The `pages/` folder contains extra markdown tutorials for CMake (optional).

---

## 💡 CMake Command Reference

- **Configure:**  
  `cmake -S <source_dir> -B <build_dir> -G <build_tool>`
  - `-G <build_tool>`: if not set by default CMake uses NMake
  - Use `-G "MinGW Makefiles"` if you dont wanna use NMake and use the default mingw32-make generator that comes with your MinGW compiler

- **Build:**  
  `cmake --build <build_dir>`

- **Clean:**  
  `cmake --build <build_dir> --target clean`

- **Verbose Build:**  
  `cmake --build <build_dir> --verbose`

---

## 📚 Further Reading

- [CMake Official Documentation](https://cmake.org/cmake/help/latest/)
- [Modern CMake Tutorial](https://cliutils.gitlab.io/modern-cmake/)
- [pages/page1.md](pages/page1.md)
- [pages/page2.md](pages/page2.md)
- [pages/page3.md](pages/page3.md)
- [pages/page4.md](pages/page4.md)
- [pages/page5.md](pages/page5.md)
- [pages/page6.md](pages/page6.md)
- [pages/page7.md](pages/page7.md)
- [pages/page8.md](pages/page8.md)

---

Happy Coding! 🚀
