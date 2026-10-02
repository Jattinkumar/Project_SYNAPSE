# Project SYNAPSE 📡

## Why I Am Building This (The Backstory)
I am Jattin, a 5th-semester BCA student from Kurukshetra University in Haryana, India . This project started out of raw curiosity. I hated blindly typing Linux commands without knowing what they actually did under the hood. Wondering how remote connections worked or how developers accidentally leave backdoors open on servers led me to build a basic network scanner in Python—before I even really knew Python.

Then, I looked at how corporate telecom monopolies spike mobile internet recharge prices (like ₹299/₹399). It made me think: *What happens if the entire network infrastructure goes down during an emergency or disaster? How can everyday people connect using only the hardware they already own in their pockets?* 

That's why I am building Project SYNAPSE—a decentralized, completely offline messaging engine that uses Bluetooth Low Energy (BLE) to pass messages from phone to phone (ad-hoc mesh) without relying on cell towers or internet access .

---

## My Starting Point (Zero Sugarcoating)
As of September 2026, I am stepping into this completely from scratch :
* I only know basic college-level C++ (mostly old Turbo C++ and basic OOP concepts) .
* I have **zero** prior experience with Dart, Flutter, or mobile UI development .
* I have **zero** experience with low-level memory management, pointers, or OS networking .

I am not copying a tutorial or taking shortcuts . I am learning systems engineering concepts step-by-step, breaking things on purpose, and documenting the entire process here . My goal is to build a working prototype that can pass messages between my two Samsung test devices .

---

## 🗺️ The Learning Roadmap & Progress
- [x] Set up my C++ compiler environment inside VS Code on my Ryzen 7 laptop .
- [ ] Phase 1: Master low-level C++ memory pointers, raw arrays, and bit-shifting .
- [ ] Phase 2: Build the core mesh logic (packet data serialization and duplicate loop prevention) .
- [ ] Phase 3: Learn Dart FFI to bridge C++ logic to a mobile application framework .
- [ ] Phase 4: Learn Flutter BLE APIs and build the Android Foreground Service to bypass background OS kills .
- [ ] Phase 5: Off-grid field testing with physical Samsung devices .

---

## 📐 The End-to-End Data Flow Graph
Here is the step-by-step journey of a message through the system, broken down cleanly by stage:

```text
[ 1. UI Layer (Flutter/Dart) ] 
       │ ➔ User types message & chooses network mode .
       ▼
[ 2. Core Logic & Fragmentation (C++) ] 
       │ ➔ Packs data, runs XOR checksum seal, splits large text into chunks .
       ▼
[ 3. Transport Layer (Bluetooth LE) ] 
       │ ➔ Broadcasts via free Advertising or streams via GATT Connected Mode .
       ▼
[ 4. Radio Airwaves ] 
       │ ➔ Physical RF pulses traveling through walls and concrete boundaries .
       ▼
[ 5. Receiver Parsing & Validation ] 
       │ ➔ Checks checksum lock, drops corrupted frames, reassembles text pieces .
       ▼
[ 6. Local Storage & UI Display ]
         ➔ Saves safely to local Hive DB, triggers persistent screen alert .
```

### 🚦 Network Operational Modes
*   **Emergency Mode:** Built for maximum speed. Short text messages bypass all connection handshakes and broadcast instantly to every node in range .
*   **Normal Mode:** Built for long text chats or file transmissions. Establishes a secure connection using Coded PHY to punch through concrete walls .
*   **Experimental Mode:** Used in our sandbox directory to calibrate custom mesh routing loops and tracking variables .

### 📦 Stage-by-Stage Architecture Breakdown

#### Stage 1: Input & Mode Selection (The Flutter UI)
The user types a message in the app UI and selects a transmission mode . The UI layer immediately transforms the high-level string into a raw array of bytes .

#### Stage 2: Packaging & Fragmentation (The C++ Core Engine)
The text data hits your C++ backend via Dart FFI . If the message exceeds the packet payload limits (~90 bytes to fit safely within Bluetooth Coded PHY constraints), the engine fragments it into sequential chunks . It wraps each chunk into a packed binary structure, calculates the XOR checksum, and appends metadata (`packet_id`, `sequence_index`, `total_chunks`) .

#### Stage 3: Transmission (The Bluetooth Stack)
*   **Emergency Broadcast:** The engine stuffs the data straight into a BLE Advertising payload (capped strictly at 31 bytes max) and flashes it blindly into the airwaves .
*   **Normal Mode Stream:** The engine streams the structured byte buffer over a GATT characteristic using Coded PHY at 125 kbps with heavy error-correction to penetrate walls .

#### Stage 4: The Airwave & Receiver Parsing
The physical Bluetooth chip modulates raw bytes into radio frequency waves. A nearby phone running Project Synapse catches the signal . The receiver reads the raw bytes, re-runs the checksum calculation, and validates it . If corrupted by interference, the packet is instantly dropped . If it passes, chunks are reassembled in a temporary RAM buffer .

#### Stage 5: Persistence & The OS Background Battle
Once reassembled, the message is written to a local embedded database (like Hive or SQLite) so history persists . To prevent modern mobile OS architectures from killing the background mesh scanning, the app utilizes a native **Android Foreground Service** with a permanent system notification tray badge .

---

## 📶 Engineering Logs & Hardware Diagnostics

### 📡 Log 01: Environment Setup, Compiler Realities & Basic Pointers
*   **Date:** September 15, 2026 
*   **Objective:** Set up the local C++ development environment from scratch and write my very first raw memory pointer tests without relying on modern high-level abstractions .
*   **The Problem:** Coming from basic college coursework (mostly old Turbo C++), setting up a modern VS Code toolchain with MinGW-w64 on a Ryzen 7 machine felt completely foreign . I didn't understand how memory addresses worked, why stack vs. heap allocation mattered, or what a segmentation fault actually was when a pointer went out of bounds .
*   **Doubts Confronted:** Battled severe imposter syndrome looking at low-level systems documentation . Accepted that I would write terrible, broken code before writing working code .
*   **The Breakthrough:** Successfully configured the compiler tasks, wrote a test script that manually dereferenced memory addresses using `&` and `*`, and printed out raw hexadecimal memory locations to the terminal . Realized that memory isn't magic—it's just numbered boxes in RAM .

### 📡 Log 02: Volatile Memory Extraction & Character De-Abstraction
*   **Date:** September 23, 2026 
*   **Objective:** Force the host 64-bit architecture to strip away human-readable text layers and reveal the raw numerical integer bytes sitting inside our structure's memory array .
*   **The Problem:** Low-level network validation loops (like Bitwise XOR Checksums) cannot execute on standard text characters . To prepare for data integrity testing, the compiler must be shown how to access memory boxes directly as raw positive numbers .
*   **Doubts Confronted:** Overcame severe contextual paralysis regarding modern C++ compilation syntax vs. legacy 1990 Turbo C++ mechanics . Dismantled academic misconceptions regarding compiler data storage limitations (Signed vs. Unsigned memory bit allocation) .
*   **The Breakthrough:** Independently established a dynamic `for` loop that iterates sequentially through the data fields of `mypacket.message`. Successfully extracted the raw electrical ASCII signatures live from the hardware cells :
    *   Slot 1 ('H') ➔ Integer Value: **72** 
    *   Slot 2 ('E') ➔ Integer Value: **69** 
    *   Slot 3 ('L') ➔ Integer Value: **76** 
    *   Slot 4 ('P') ➔ Integer Value: **80** 
    *   Slot 5 ('!') ➔ Integer Value: **33** 

### 📝 Log 03: Fixing Hidden Memory Gaps & Verifying Code Math
*   **Date:** September 26, 2026 
*   **My Objective:** Stop the computer from adding empty space inside our data layout and make sure our math loop calculates the exact correct verification number .
*   **The Problem I Faced:** The computer was secretly adding empty tracking bytes inside our structure to match its 64-bit hardware systems . Because of these hidden spaces, my code loop accidentally read wrong numbers from the next-door variables in RAM . This corrupted my final text calculation, changing my correct math answer from a `48` into an invalid `126` .
*   **How I Fixed It:** I added `#pragma pack(push, 1)` right above my structure . This tells the compiler: "Crush all empty space and glue these variables back-to-back with zero gaps ."
*   **Real Results Output:**
    *   **Data Size in RAM:** Dropped perfectly to exactly **12 Bytes** .
    *   **Text Loop Math:** Calculated exactly **48** (72 ^ 69 ^ 76 ^ 80 ^ 33) .
    *   **Final Output Key:** Combined `48` with our secret device key (`8699`) to print a clean success number: **8651** .

### 📡 Log 04: Raw Memory Pointer Arithmetic & Byte-Level Inspection via reinterpret_cast
* **Date:** October 2, 2026
* **Objective:** Implement low-level byte-level inspection of our custom packet struct using `reinterpret_cast` and pointer arithmetic to track and verify physical memory offsets in RAM.
* **The Problem:** C++ custom structs are not native arrays, so attempting array subscripting directly on the struct instance (`packet1[i]`) throws a compilation error. We needed a rigorous way to treat a complex structured data block as a continuous raw stream of bytes.
* **Doubts Confronted:** Overcame confusion regarding how the compiler handles custom user-defined data types in memory versus primitive arrays, and how to safely cast complex object pointers without triggering undefined behavior.
* **The Breakthrough:** Successfully utilized `uint8_t *byte_ptr = reinterpret_cast<uint8_t*>(&packet1);` to capture the base memory address of our packed struct, then iterated cleanly through `sizeof(packet1)` bytes using pointer arithmetic (`byte_ptr + i`) [cite: 3].
* **Real Results Output:**
  * **Memory Tracking:** Accurately mapped every offset, exact hexadecimal memory address, and numerical decimal value across all **12 Bytes** of the packet structure live in the terminal [cite: 3].
  * **Code Integration:** Locked in clean pointer traversal and verified that our packet layout contains zero compiler-inserted padding gaps thanks to `#pragma pack(push,1)`.

