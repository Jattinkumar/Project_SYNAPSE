# Project Synapse (Research & Architecture Phase)

A decentralized, infrastructure-free, peer-to-peer mobile mesh communication protocol designed for off-grid and resource-constrained environments.

---

##  Current Project Status: Research & Core Architecture Phase
This repository is currently in **Phase 0: R&D and Transport Layer Physics Testing**. 
Before writing any user interface layers, the focus is strictly on testing direct baseline functionality: manipulating the underlying hardware chipsets to transmit, hop, and validate raw byte streams directly across the airwaves completely offline.

---

##  Primary Objective (The Baseline Test)
The immediate technical milestone of this project is to execute a **Zero-Network 10-Byte Array Transmission Test**. 
* **The Mission:** Successfully pass a raw 10-character binary string packet directly from Device A to Device B over local 2.4 GHz radio waves without any central internet gateway, Wi-Fi router connectivity, cellular towers, or Layer 3 IP address allocations.

---

##  High-Level Protocol Architecture
To maximize battery preservation and runtime performance under heavy processing states, the utility follows a strict **95% Performance / 5% Minimalist UI** design philosophy. Flashy animations are completely excluded to protect local network chips and device thermal limits.

### 1. The Discovery & Control Plane (Flutter / Dart)
* Handles native background Bluetooth Low Energy (BLE) Peripheral Advertising and Central Scanning.
* Maps custom Service and Characteristic UUID slots directly inside the host operating system's native kernel space.
* Functions as the local antenna driver to intercept incoming raw radio frames out of the air.

### 2. The Logic Router Core (C++ Backend)
* Intercepts the raw data streams captured by the Dart antenna layer via high-speed, zero-latency **Dart FFI (Foreign Function Interface)** memory pipes.
* Manages ad-hoc in-memory Routing Tables to dynamically calculate hop paths between changing physical device locations.
* Enforces strict End-to-End Encryption (E2EE) using native public/private key structures generated inside volatile memory.
* Employs tight input character sanitization to scrub raw text streams and drop malicious executable code blocks instantly.

---

##  Repository Directory Blueprint
To prevent messy developmental scratchpads from cluttering production deployment streams, the repository layout utilizes targeted tracking blocks:

* `main.dart` -> The core platform-independent user interface framework shell (Text-only minimalist console layout).
* `mesh_engine.cpp` -> The primary high-performance decentralized mesh routing logic engine.

---

##  How to Track Development
Every technical milestone, protocol flow chart diagram, data frame ledger log, and physical hardware validation proof will be continuously updated live inside this document as the system transitions from raw antenna discovery tests into full ad-hoc network routing execution lines.
