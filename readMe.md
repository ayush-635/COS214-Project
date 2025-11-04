<p align="center">
  <img src="Data Files/214.png" alt="Nursery Manager Logo" width="200" />
</p>

<h1 align="center">Nursery Manager – Design Patterns Final Project</h1>

<p align="center">
  <b>University of Pretoria | COS 214 | 2025</b><br>
  <i>A plant nursery management simulation built with C++, Boost, and Design Patterns.</i><br><br>
<img src="https://img.shields.io/github/actions/workflow/status/ayush-635/COs214-Project/ci.yml?label=CI&logo=githubactions&logoColor=white&style=for-the-badge" alt="CI Status"/>
</p>

---

## Table of Contents
- [Overview](#-overview)
- [Project Structure](#-project-structure)
- [WSL Setup & Dependencies](#️-wsl-setup--dependencies)
- [Build & Run Instructions](#-build--run-instructions)
- [Testing](#-testing)
- [Documentation Links](#-documentation-links)
- [Team Members](#-team-members)

---

## Overview
**Nursery Manager** is a C++ simulation game where players run a virtual plant nursery cultivating, selling, and managing plants while applying advanced software design principles.

This project demonstrates:
- **Object-Oriented Design** and SOLID principles  
- **Software Design Patterns**:
  - Singleton
  - Observer
  - Factory
  - Strategy
  - Composite
  - Builder  
  - Mediator
  - Prototype
  - Command
  - FlyWeight
  - Iterator
  - State
  - Visitor
  - Façade
- **Boost Libraries** for filesystem and utilities  
- **Doctest Framework** for testing  
- **Makefile Build System** for streamlined compilation  
- **Optional Web Interface** (HTTP server)

---

## Project Structure
```bash
NurseryManager/
├── src/                # C++ source files
├── tests/              # Unit tests (Doctest)
├── WebServer.cpp         # Web server implementation
├── Data Files/         # Assets and data (includes logo)
├── docs/               # Documentation (PDFs, UML, reports)
├── Makefile            # Build system
└── README.md   
```
<details> <summary><b>WSL Setup & Dependencies</b></summary>
 Prerequisites

Make sure you are using WSL (Ubuntu) and install the required packages:<br>
```sudo apt update
sudo apt install build-essential make g++ git
sudo apt install libboost-all-dev
sudo apt install doctest-dev
```

</details>

<details> <summary><b>Build & Run Instructions</b></summary>
Clone the Repository
`git clone https://github.com/ayush-635/COS214-Project`
`cd COS214-Project`

Build Options
| Command                 | Description                                                      |
| ----------------------- | ---------------------------------------------------------------- |
| `make` or `make all`    | Build both console and web versions                              |
| `make console`          | Build only the console version                                   |
| `make web`              | Build only the web server                                        |
| `make run`              | Run console version                                              |
| `make run-web`          | Run web version ([http://localhost:8080](http://localhost:8080)) |
| `make test`             | Run all tests                                                    |
| `make test_plants`      | Run plant-related tests                                          |
| `make test_patterns`    | Run design pattern tests                                         |
| `make test_integration` | Run integration tests                                            |
| `make clean`            | Remove build artifacts                                           |
| `make rebuild`          | Clean and rebuild everything                                     |
| `make check-boost`      | Check if Boost is installed                                      |
| `make help`             | Display help message                                             |

make console
./bin/nursery_console
</details>

Testing

The project uses Doctest for lightweight, high-speed unit testing.

To run all tests:
make test

Documentation Links
| Resource                                                        | Description                                          |
| --------------------------------------------------------------- | ---------------------------------------------------- |
| [Report](https://github.com/ayush-635/COS214-Project/tree/main/docs)                                  | Comprehensive project report                         |
| [Doxygen Documentation](https://github.com/ayush-635/COS214-Project/tree/main/docs)              | Auto-generated Doxygen reference                     |
| [UML Diagrams](https://github.com/ayush-635/COS214-Project/tree/main/docs)                      | Class & sequence diagrams                            |

Team Members
| Team Member | Skillz |
|--------------|----------|
| <img src="Data Files/Ayush.png" width="100"> | **Jasveer Ramdhaw** <br> State, Visitor, Flyweight, Documentation|
| <img src="Data Files/Jazz.png" width="100"> | **Ayush Sanjith** <br> Command, Singleton, Mediator, Integration|
| <img src="Data Files/member3.png" width="100"> | **Jano Venter** <br> Factory Method, Prototype |
| <img src="Data Files/member4.png" width="100"> | **Kwaku Asiedu** <br> Command, Strategy|
| <img src="Data Files/member4.png" width="100"> | **Heinrich Romer** <br> Singleton, Observer, Template|
| <img src="Data Files/member4.png" width="100"> | **Zaynab Samir** <br> Builder, Strategy|
| <img src="Data Files/member4.png" width="100"> | **Ryan Lynn** <br> Composite, Iterator|


<p align="center"> <sub>Built with C++, Boost, and Design Patterns.</sub> </p>
