# File System Recovery Tool
This project simulates a file system with features such as:
- File creation and management
- Directory structure handling
- Free space management
- File recovery system
- Optimization techniques

## Day 1 Progress 
- Created personal branch: `person1-core`
- Created project structure using GitHub online
- Added `File` class declaration and implementation
- Added `Directory` class declaration and implementation
- Added `main.cpp` to test the file system structure
- Implemented a basic simulation of files and directories

## Features Added in Day 1 
- Create a file with name and size
- Write content into a file
- Read file content
- Create directories
- Add files to directories
- Add subdirectories to directories
- List contents of a directory
  
## Day 2 Progress 
- Implemented file deletion (soft delete)
- Added search functionality for files
- Introduced basic free space tracking
- Updated main.cpp to test new features

## Features Added in Day 2
- Delete file (marked as deleted instead of removing)
- Search file within a directory
- Track storage usage (used space and free space)

## Day 3 Progress 
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

## Day 4 Progress
- Implemented file access methods in the File class
- Added sequential access to read full file content
- Added direct access to read specific character positions
- Added range-based access to read partial file content
- Updated main.cpp to test file access functionalities

## Features Added in Day 4
- Sequential file access (read entire file)
- Direct access (read character at a specific position)
- Partial access (read a range of content)

## Day 5 Progress 
- Added file recovery functionality
- Restored deleted files using soft delete mechanism
- Updated `main.cpp` to test recovery
- Restored storage blocks and used space after recovery

## Features Added in Day 5
- Recover deleted file by name
- Re-display recovered file in directory listing
- Restore storage usage after file recovery

## Day 6 Progress
- Improved deleteFile() to handle already deleted files
- Improved recoverFile() to handle already active files
- Added showAllContents() for debugging and demonstration
- Added helper function to count active files in a directory
- Added storage summary functions to count used and free blocks
- Updated `main.cpp` to test all new features

## Features Added in Day 6
- Safe deletion handling (prevents double deletion)
- Safe recovery handling (prevents invalid recovery)
- Debug listing to display deleted and active files
- Active file count for directories
- Storage usage summary (used and free blocks)

## Day 7 Progress 
- Organized `main.cpp` into structured demo sections
- Improved output readability using clear headings
- Added system summary section for final results
- Performed final testing and validation of all features
- Cleaned and prepared project for submission

## Features Added in Day 7
- Structured program flow for demonstration
- Section-based output (creation, access, delete, recovery, summary)
- Final system summary display
- Improved readability and presentation