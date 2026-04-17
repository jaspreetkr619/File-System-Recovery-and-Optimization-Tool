# File System Recovery Tool
This project simulates a file system with features such as:
- File creation and management
- Directory structure handling
- Free space management
- File recovery system
- Optimization techniques

## Day 1 Progress (Person 1)
- Created personal branch: `person1-core`
- Created project structure using GitHub online
- Added `File` class declaration and implementation
- Added `Directory` class declaration and implementation
- Added `main.cpp` to test the file system structure
- Implemented a basic simulation of files and directories

## Current Day 1 Features
- Create a file with name and size
- Write content into a file
- Read file content
- Create directories
- Add files to directories
- Add subdirectories to directories
- List contents of a directory
  
## Day 2 Progress (Person 1)
- Implemented file deletion (soft delete)
- Added search functionality for files
- Introduced basic free space tracking
- Updated main.cpp to test new features

## Features Added in Day 2
- Delete file (marked as deleted instead of removing)
- Search file within a directory
- Track storage usage (used space and free space)

  ## Day 3 Progress (Person 1)
- Added `StorageManager` class
- Implemented block-based storage simulation
- Allocated blocks when files are created
- Freed blocks when files are deleted
- Integrated storage tracking in `main.cpp`

## Features Added in Day 3
- Storage divided into fixed-size blocks
- Block allocation for files
- Block deallocation after deletion
- Display current storage block status
