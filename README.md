# Project SYNAPSE 📡

### Why I Am Building This (The Backstory)
I am Jattin, a 5th-semester BCA student from a Kurukshetra university in India. I got into this because of raw curiosity. I hated blindly typing Linux commands without knowing what they did under the hood, so which made me curious about the security threats like if i type a command can it make someone connect to my device remotely and like that when i was studying in college about backend and there was a concept that sometimes web developers leaves the backdoor on a server to get into website, so I wanted to know and find out about open port on a netwrok. I didn't know pyhton till that date which led me to build a basic network scanner in Python. 

Then I saw corporate telecom monopolies spiking mobile internet recharge prices (like ₹299/₹399). It made me think: *What happens if the entire network infrastructure goes down during an emergency or disaster? How can we connect using what we already own?* 

That's why I am building Project SYNAPSE—a decentralized, completely offline messaging engine that uses Bluetooth Low Energy (BLE) to bounce messages from phone to phone (ad-hoc mesh) without cell towers or internet.

### My Starting Point (Zero Sugarcoating)
As of September 2026, I am a beginner. 
- I only know college-level C++ (mostly old Turbo C++ and oop concepts).
- I have **zero** prior experience with Dart or Flutter.
- I have **zero** experience with low-level memory management.

I am not copying a tutorial. I am learning the systems engineering concepts step-by-step from scratch, breaking things on purpose, and documenting the journey here. My goal is to have a working prototype across my two Samsung test devices by January 2027.

### 🗺️ The Learning Roadmap & Progress
- [x] Set up my C++ compiler environment inside VS Code on my Ryzen 7 laptop.
- [ ] Phase 1: Master low-level C++ memory pointers, raw arrays, and bit-shifting.
- [ ] Phase 2: Build the core mesh logic (packet data serialization and duplicate loop prevention).
- [ ] Phase 3: Learn Dart FFI to bridge C++ logic to a mobile application framework.
- [ ] Phase 4: Learn Flutter BLE APIs and build the Android Foreground Service to bypass background kills.
- [ ] Phase 5: Off-grid field testing with physical Samsung devices.


### 📶 Log 02: Volatile Memory Extraction & Character De-Abstraction
*   **Date:** September 23, 2026
*   **Objective:** Force the host 64-bit architecture to strip away human-readable text layers and reveal the raw numerical integer bytes sitting inside our structure's memory array.
*   **The Problem:** Low-level network validation loops (like Bitwise XOR Checksums) cannot execute on standard text characters. To prepare for data integrity testing, the compiler must be shown how to access memory boxes directly as raw positive numbers.
*   **Doubts Confronted:** Overcame severe contextual paralysis regarding modern C++ compilation syntax vs. legacy 1990 Turbo C++ mechanics. Dismantled academic misconceptions regarding compiler data storage limitations (Signed vs. Unsigned memory bit allocation).
*   **The Breakthrough:** Independently established a dynamic `for` loop that iterates sequentially through the structural data fields of `mypacket.message`. Successfully extracted the raw electrical ASCII signatures live from the hardware cells:
    *   Slot 1 ('H') ➔ Integer Value: **72**
    *   Slot 2 ('E') ➔ Integer Value: **69**
    *   Slot 3 ('L') ➔ Integer Value: **76**
    *   Slot 4 ('P') ➔ Integer Value: **80**
    *   Slot 5 ('!') ➔ Integer Value: **33**
