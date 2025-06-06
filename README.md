# CMake_Defaults

A minimal CMake learning tool and template for C++ projects.

---

## 📁 Project Structure

```
.
├── apps/           # Application source files (e.g., main.cpp)
├── utils/          # Utility source files (e.g., nRoot.cpp)
├── bin/            # (Created by you) Build output directory
├── CMakeLists.txt  # Main CMake configuration file
└── readme.md       # This file
```

---

## 🚀 How to Build and Run

### 1. Configure the Project

Open a terminal in the project root and run:

```cmd
cmake -S . -B bin
```

- `-S .` : Source directory (where `CMakeLists.txt` is located)
- `-B bin` : Build directory (where build files and cache will be generated)

### 2. Build the Project

After configuration, build the project with:

```cmd
cmake --build bin
```

- This uses the cached settings in `bin` from the previous step.
- The resulting executable (e.g., `app.exe`) will be placed in the `bin` directory.

### 3. Run the Application

From the project root, run:

```cmd
bin\app.exe
```
or, if you need to pass arguments:

```cmd
bin\app.exe <base> <exponent>
```

---

## 🛠️ Notes

- You can change the build directory name (`bin`) to anything you like (e.g., `build`, `out`).
- To clean the build, simply delete the `bin` directory.
- If you change the generator or toolchain, always delete the build directory and re-run the configuration step.

---

## 💡 CMake Command Reference

- **Configure:**  
  `cmake -S <source_dir> -B <build_dir>`

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

---

Happy Coding! 🚀
